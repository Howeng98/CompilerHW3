// TODO: Deadline 2021/05/27 23:59
%{
    #include "common.h" //Extern variables that communicate with lex
    #define codegen(...) \
        do { \
            for (int i = 0; i < INDENT; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Other global variables */
    FILE *fout = NULL;
    bool HAS_ERROR = false;
    int INDENT = 0;
    // #define YYDEBUG 1
    // int yydebug = 1;
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    extern char* yytext;

    int current_scope_level = 0;    
    int address = 0;
    char arithmetic[5];
    int index_in_each_scope[5] = {0};
    char var_name[10];
    int compare_level = 0;
    bool current_state = false;
    bool newline = false;
    char changedType[10];
    char specialVar[10];
    bool isNum = false;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Define a struct to store variables information */
    struct symbol_table{
        int index;
        int address;
        int lineno;
        int scope_level;
        int printed; // printed means the variable is dumped(printed)
        char name[10];
        char type[10];        
        char element_type[10];
        struct symbol_table* next;
    };

    struct stack{
        char name[10];
        char type[10];
        struct stack* next;
        struct stack* prev;
    };

    // symbol table pointer
    struct symbol_table* head = NULL;
    struct symbol_table* node;
    struct symbol_table* current = NULL;
    struct symbol_table symbol_table[50];

    // stack pointer
    struct stack* stack_head = NULL;
    struct stack* stack_node;
    struct stack* stack_current = NULL;


    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(void);
    static void insert_symbol(char* var_name, char* var_type, int lineno, char* element);
    static int lookup_symbol(char* var_name);
    static void dump_symbol(void);
    void printList(struct symbol_table* head);
    char* getType(char* var_name);
    bool validType(char* return_value);
    int reDeclared(char* var_name, char* var_type);
    void printmsg(char* type);
    bool isArray(char* var_name);
    static void push_stack(char* var_name, char* var_type);
    static void pop_stack(char* var_name);
    static char* get_TOS(void);
    
%}
%error-verbose
/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    char *id;
    char *boool;
    char *type;   
}
/* Token without return */
%token ADD SUB MUL QUO REM
%token INT FLOAT BOOL STRING
%token INC DEC
%token GEQ LEQ EQL NEQ LSS GTR
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token LAND LOR NOT
%token SEMICOLON 
%token IF ELSE WHILE FOR PRINT
%token TRUE FALSE

/* Precedence of derivation of token */
%right LOR 
%right LAND
%left LSS GTR GEQ LEQ NEQ EQL
%right ASSIGN
// cannot put MUL QUO REM in the same line with ADD SUB, different line show different precedence
// MUL QUO REM should have deeper level than ADD SUB!
%left ADD SUB 
%left MUL QUO REM
%left ADD_ASSIGN SUB_ASSIGN 
%left MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%right NOT INC DEC 
%left SEMICOLON
%left '[' ']' 
%left '{' '}'
%nonassoc '(' ')'

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <id> IDENT

/* Nonterminal with return, which need to sepcify type */
%type <boool> LogicalExpr CompareExpr
%type <type> Expression ConversionExpr AssignmentExpr
%type <type> BoolExpr ArithmeticExpr TermExpr Bool Num Type Bracket 
%type <id>   ID

/* Yacc will start at this nonterminal */
%start Program
/* Grammar section */
%%
Program
    : StatementList 
;
StatementList
    : StatementList Statement SEMICOLON    
    | StatementList Statement
    | Statement SEMICOLON
    | Statement
;

Statement
    : PrintStmt
    | DeclarationStmt
    | IfStmt
    | Expression
    | LoopStmt    
;

PrintStmt
    : PRINT Bracket {
        if(!strcmp($2,"TRUE") || !strcmp($2,"FALSE")){
            printf("PRINT bool\n");
        }
        printmsg($2);
    }

;

IfStmt    
    : Bracket Bracket StatementList '}' {
        dump_symbol();
        current_scope_level--;
    }
    | ELSE
;

LoopStmt
    : Bracket Bracket StatementList '}' {        
        // if and while condition
        dump_symbol();
        current_scope_level--;
    }
    | FOR '(' Expression SEMICOLON Expression SEMICOLON Expression ')' Bracket StatementList Bracket {
        // for condition
    }    
;

DeclarationStmt
    : Type IDENT {
        if(reDeclared($2, $1)==-1){
            insert_symbol($2, $1, yylineno, "-");
        }else{
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, $2, reDeclared($2, $1));
        }

        if(!strcmp($1,"int")){
            codegen("ldc 0 \n");
            codegen("istore %d\n", lookup_symbol($2));
        }
        if(!strcmp($1,"float")){
            codegen("ldc 0.000000 \n");
            codegen("fstore %d\n", lookup_symbol($2));
        }
        if(!strcmp($1,"string")){
            codegen("ldc \"\" \n");            
            codegen("astore %d\n", lookup_symbol($2));
        } 
    }
    | Type IDENT '[' Expression ']' {        
        if(reDeclared($2, $1)==-1){
            insert_symbol($2, "array", yylineno, $1);
        }else{
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, $2, reDeclared($2, "array"));
        }   

        if(!strcmp($1,"int")){            
            codegen("newarray int\n");
            codegen("astore %d\n", lookup_symbol($2));
        }
        if(!strcmp($1,"float")){            
            codegen("newarray float\n");
            codegen("astore %d\n", lookup_symbol($2));
        }
    }
    | Type IDENT ASSIGN Expression {                 
        insert_symbol($2, $1, yylineno, "-");
        if(!strcmp($1,"int")){
            codegen("istore %d\n", lookup_symbol($2));
        }
        if(!strcmp($1,"float")){
            codegen("fstore %d\n", lookup_symbol($2));
        }
        if(!strcmp($1,"string")){
            codegen("astore %d\n", lookup_symbol($2));
        }
        if(!strcmp($1,"bool")){            
            codegen("istore %d\n", lookup_symbol($2));
        }
    }    
;

Type
    : INT { 
        $$ = "int";
    }
    | FLOAT { 
        $$ = "float";
    }
    | STRING { 
        $$ = "string";
    }
    | BOOL { 
        $$ = "bool";
    }
;
Expression
    : AssignmentExpr 
    | ArithmeticExpr {$$ = $1;}
    | ConversionExpr {$$ = $1;}
    | TermExpr { $$ = $1; }
    | BoolExpr { $$ = $1; }    
;
AssignmentExpr
    : ID ASSIGN Expression {
        if(validType($1) && validType($3)){
            if(strcmp($1,$3) != 0){
               printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, $1, $3);
            }
        }        
        printf("ASSIGN\n");
        if(!strcmp($1,"int") && !strcmp($3,"int")){
            if(!strcmp(changedType,"int")){
                printf("TOS:%s\n",get_TOS());
                codegen("istore %d\n", lookup_symbol(get_TOS()));
            }
            else
                codegen("istore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp($1,"float") && !strcmp($3,"float")){
            if(!strcmp(changedType,"float")){
                printf("TOS:%s\n",get_TOS());
                codegen("fstore %d\n", lookup_symbol(get_TOS()));
            }
            else
                codegen("fstore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp($1,"string") && !strcmp($3,"string")){
            codegen("astore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp($1,"bool")){
            codegen("istore %d\n",lookup_symbol(var_name));
        }

        
        
    }        
    | ID '[' Expression ']' ASSIGN Expression {                 
        printf("ASSIGN\n");
        if(!strcmp($1,"int")){
            codegen("iastore \n");
        }
        else if(!strcmp($1,"float")){
            codegen("fastore \n");
        }
    }
    | Expression ADD_ASSIGN Expression {        
        printf("ADD_ASSIGN\n");
        if(!strcmp($3,"int")){
            codegen("iadd \n");
            codegen("istore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp($3,"float")){
            codegen("fadd \n");
            codegen("fstore %d\n",lookup_symbol(var_name));
        }
    }    
    | Expression SUB_ASSIGN Expression {                        
        printf("SUB_ASSIGN\n");
        if(!strcmp($3,"int")){
            codegen("isub \n");
            codegen("istore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp($3,"float")){
            codegen("fsub \n");
            codegen("fstore %d\n",lookup_symbol(var_name));
        }
    }
    | Expression MUL_ASSIGN Expression {                
        printf("MUL_ASSIGN\n");
        if(!strcmp($3,"int")){
            codegen("imul \n");
            codegen("istore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp($3,"float")){
            codegen("fmul \n");
            codegen("fstore %d\n",lookup_symbol(var_name));
        }
    }
    | Expression QUO_ASSIGN Expression {                      
        printf("QUO_ASSIGN\n");
        if(!strcmp($3,"int")){
            codegen("idiv \n");
            codegen("istore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp($3,"float")){
            codegen("fdiv \n");
            codegen("fstore %d\n",lookup_symbol(var_name));
        }
    }
    | Expression REM_ASSIGN Expression {                        
        printf("REM_ASSIGN\n");
        if(!strcmp($3,"int")){
            codegen("irem \n");
            codegen("istore %d\n",lookup_symbol(var_name));
        }        
    }
    | Num ASSIGN Expression {                
        printf("error:%d: cannot assign to %s\n", yylineno, $1);
        printf("ASSIGN\n");
    }
    | Num ADD_ASSIGN Expression {        
        printf("error:%d: cannot assign to %s\n", yylineno, $1);
        printf("ADD_ASSIGN\n");        
    }
    | Num SUB_ASSIGN Expression {                
        printf("error:%d: cannot assign to %s\n", yylineno, $1);        
        printf("SUB_ASSIGN\n");
    }
    | Num MUL_ASSIGN Expression {        
        printf("error:%d: cannot assign to %s\n", yylineno, $1);        
        printf("MUL_ASSIGN\n");
    }
    | Num QUO_ASSIGN Expression {        
        printf("error:%d: cannot assign to %s\n", yylineno, $1);        
        printf("QUO_ASSIGN\n");
    }
    | Num REM_ASSIGN Expression {        
        printf("error:%d: cannot assign to %s\n", yylineno, $1);        
        printf("REM_ASSIGN\n");
    }    
;
ArithmeticExpr
    : Expression ADD Expression {                
        if(strcmp($1,$3) != 0){
            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, $1, $3);
        }
        printf("ADD\n");
        if(!strcmp($1, "int")){
            codegen("iadd \n");
            // printmsg("int");
        }
        if(!strcmp($1, "float")){
            codegen("fadd \n");
            // printmsg("float");
        }        
        if(var_name != NULL)
            pop_stack(var_name);
    }
    | Expression SUB Expression {
        if(strcmp($1,$3) != 0){
            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, $1, $3);
        }
        printf("SUB\n");
        if(!strcmp($1, "int")){
            codegen("isub \n");
            // printmsg("int");
        }
        if(!strcmp($1, "float")){
            codegen("fsub \n");
            // printmsg("float");
        }      
    }
    | Expression MUL Expression {
        printf("MUL\n");
        if(!strcmp($1, "int")){
            codegen("imul \n");
            // printmsg("int");
        }
        if(!strcmp($1, "float")){
            codegen("fmul \n");
            // printmsg("float");
        }     
    }
    | Expression QUO Expression {
        printf("QUO\n");
        if(!strcmp($1, "int")){
            codegen("idiv \n");
            // printmsg("int");
        }
        if(!strcmp($1, "float")){
            codegen("fdiv \n");
            // printmsg("float");
        }  
    }
    | Expression REM Expression {
        if(!strcmp($1,"float")|| !strcmp($3,"float")){
            printf("error:%d: invalid operation: (operator REM not defined on float)\n", yylineno);
        }
        printf("REM\n");
        if(!strcmp($1, "int")){
            codegen("irem \n");
            // printmsg("int");
        }
        if(!strcmp($1, "float")){
            codegen("frem \n");
            // printmsg("float");
        }       
    }
;

ConversionExpr
    : '(' INT ')' TermExpr {
        printf("F to I\n");
        codegen("f2i \n");
        strcpy(changedType,"int");
        // if(!isNum)
        pop_stack(var_name);
        // else
        //     isNum = false;
        $$ = "int";
    }
    | '(' FLOAT ')' TermExpr {        
        printf("I to F\n");
        codegen("i2f \n");
        strcpy(changedType,"float");        
        // if(!isNum)
        pop_stack(var_name);
        // else
        //     isNum = false;
        $$ = "float";
    }
;

BoolExpr
    : LogicalExpr { $$ = $$; }
    | CompareExpr { $$ = $$; }
;

LogicalExpr
    : Expression LOR Expression {
        if((strcmp($1, "TRUE") != 0) && (strcmp($1,"FALSE") != 0)){
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n", yylineno, $1);
        }
        else if((strcmp($3, "TRUE") != 0) && (strcmp($3,"FALSE") != 0)){
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n", yylineno, $3);
        }
        // printf("LOR!!!! %s\n",$1);
        // printf("LOR!!!! %s\n",$3);
        $$ = $1;
        printf("OR\n");
        codegen("ior\n");
    }
    | Expression LAND Expression {
        if((strcmp($1, "TRUE") != 0) && (strcmp($1,"FALSE")  != 0)){
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n", yylineno, $1);
        }
        else if((strcmp($3, "TRUE") != 0) && (strcmp($3,"FALSE") != 0)){
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n", yylineno, $3);
        }
        $$ = $1;
        // printf("LAND!!!! %s\n",$1);
        // printf("LAND!!!! %s\n",$3);
        printf("AND\n");
        codegen("iand\n");
    }
;

CompareExpr
    : Expression GTR Expression {   
        current_state = false;     
        printf("GTR\n");
        if(!strcmp($1,"int")){
            codegen("isub \n");
        }
        else if(!strcmp($1,"float")){
            codegen("fcmpl \n");
        }
        else{
            if(!strcmp(getType(var_name), "int")){
                codegen("isub \n");
            }
            else if(!strcmp(getType(var_name), "float")){
                codegen("fcmpl \n");
            }
        }        
        compare_level++;
        codegen("ifgt L_cmp_%d\n",compare_level);
        // if not greater than zero (less than or equal)
        codegen("iconst_0\n"); //return FALSE 0
        current_state = false;
        codegen("goto L_cmp_%d\n",compare_level+1);
        // if greater than zero
        // Print step of L_cmp_compare_level
        INDENT--;
        codegen("L_cmp_%d:\n",compare_level);
        INDENT++;
        codegen("iconst_1\n");  //return TRUE 1       
        current_state = true;
        INDENT--;
        compare_level++;
        codegen("L_cmp_%d:\n\n",compare_level); //do nothing
        INDENT++;
        if(current_state){
            $$ = "TRUE";
        }
        else if(!current_state){
            $$ = "FALSE";
        }
        
    }
    | Expression LSS Expression { 
        
        printf("LSS\n"); 
        $$ = $1;
    }
    | Expression GEQ Expression { 
        $$ = $1;
        printf("GEQ\n"); 
    }
    | Expression LEQ Expression { 
        $$ = $1;
        printf("LEQ\n"); 
    }
    | Expression EQL Expression { 
        $$ = $1;
        printf("EQL\n"); 
    }
    | Expression NEQ Expression { 
        $$ = $1;
        printf("NEQ\n"); 
    }
;

Bool
    : TRUE {
        $$ = "TRUE";
        printf("TRUE\n");
        codegen("iconst_1 \n");
    }
    | FALSE { 
        $$ = "FALSE";
        printf("FALSE\n");
        codegen("iconst_0 \n");   
    }
;

TermExpr
    : ID {
        $$ = $1;
    }
    | ID '[' Expression ']' {
        if(!strcmp($1,"int")){
            codegen("iaload \n");
        }
        else if(!strcmp($1,"float")){
            codegen("faload \n");
        }
        $$ = $1;
    }
    | STRING_LIT {        
        printf("STRING_LIT %s\n", $1);
        if(!strcmp($1, "\n"))
            newline = true;        
        else
            newline = false;
        codegen("ldc \"%s\" \n",$1);
        $$ = "string";
    }
    | Num {
        $$ = $1;        
    }
    | Bracket {
        $$ = $$;
    }
    | Bool {
        $$ = $$;        
    }
    | TermExpr INC {
        printf("INC\n");
        if(!strcmp($1, "int")){
            codegen("iload %d\n", lookup_symbol(var_name));
            codegen("ldc 1\n");
            codegen("iadd \n");        
            codegen("istore %d\n", lookup_symbol(var_name));        
        }
        if(!strcmp($1, "float")){
            codegen("fload %d\n", lookup_symbol(var_name));
            codegen("ldc 1.000000\n");
            codegen("fadd \n");        
            codegen("fstore %d\n", lookup_symbol(var_name));        
        }
        
    }
    | TermExpr DEC {
        printf("DEC\n");
        if(!strcmp($1, "int")){
            // codegen("iload %d\n", lookup_symbol(var_name));
            codegen("ldc 1\n");
            codegen("isub \n");        
            codegen("istore %d\n", lookup_symbol(var_name));        
        }
        if(!strcmp($1, "float")){
            // codegen("fload %d\n", lookup_symbol(var_name));
            codegen("ldc 1.000000\n");
            codegen("fsub \n");        
            codegen("fstore %d\n", lookup_symbol(var_name));        
        }
    }
    | ADD Num {          
        printf("POS\n");              
        $$ = $2;
    }
    | SUB Num {        
        printf("NEG\n"); 
        if(!strcmp($2, "int")){
            codegen("ineg \n");            
        }
        if(!strcmp($2, "float")){            
            codegen("fneg \n");
        }                       
        $$ = $2;        
    } 
    | NOT Expression {
        printf("NOT\n");
        if(current_state){
            $$ = "FALSE";
        }
        else{
            $$ = "TRUE";
        }
        // exclusive or (XOR)
        codegen("iconst_1 \n");
        codegen("ixor \n");
        // $$ = $2;
    }    
;

Num
    : INT_LIT {         
        printf("INT_LIT %d\n", $1);
        codegen("ldc %d\n",$1);
        // push a useless stack, can ignore
        push_stack(var_name,"int");
        isNum = true;
        $$ = "int";
    }
    | FLOAT_LIT {         
        printf("FLOAT_LIT %f\n", $1);
        codegen("ldc %f\n",$1);
        // push a useless stack, can ignore
        push_stack(var_name,"float");
        isNum = true;
        $$ = "float";
    }
;

ID
    : IDENT {
        if(lookup_symbol($1) == -2){
            printf("error:%d: undefined: %s\n", yylineno, $1);
        }
        else{
            printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1));
                                    
            push_stack($1,getType($1));
            strcpy(var_name,$1);
            $$ = getType($1);
            
            if(!isArray($1)){
                if(!strcmp(getType($1), "int")){
                    codegen("iload %d\n",lookup_symbol($1));
                }
                if(!strcmp(getType($1), "float")){
                    codegen("fload %d\n",lookup_symbol($1));
                }
                if(!strcmp(getType($1), "string")){
                    codegen("aload %d\n",lookup_symbol($1));
                }
                if(!strcmp(getType($1), "bool")){
                    codegen("iload %d\n",lookup_symbol($1));
                }
            }
            else{
                codegen("aload %d\n",lookup_symbol($1));
            }
                                            
        }                
    }
;

Bracket
    : '(' Expression ')'{        
        $$ = $2;
    }
    | '{' {        
        current_scope_level++;        
    }
    | '}' {
        dump_symbol();
        current_scope_level--;
    }
    | WHILE Bracket {
        if(strcmp($2,"bool")!=0 && strcmp($2,"TRUE")!=0 && strcmp($2,"FALSE")){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, $2);
        }
    }
    | IF Bracket {
        if(strcmp($2,"bool")!=0 && strcmp($2,"TRUE")!=0 && strcmp($2,"FALSE")){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, $2);
        }
    }
;

%%


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    codegen(".source hw3.j\n");
    codegen(".class public Main\n");
    codegen(".super java/lang/Object\n");
    codegen(".method public static main([Ljava/lang/String;)V\n");
    codegen(".limit stack 100\n");
    codegen(".limit locals 100\n");
    INDENT++;

    create_symbol();
    yyparse();
    
    dump_symbol();
	printf("Total lines: %d\n", yylineno);
    /* Codegen end */
    codegen("return\n");
    INDENT--;
    codegen(".end method\n");
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }
    return 0;
}

static void create_symbol(void){
    ;
}

static void insert_symbol(char* var_name, char* var_type, int lineno, char* element){    
    node = (struct symbol_table*)malloc(sizeof(struct symbol_table));
    node->next = NULL;
    node->scope_level = current_scope_level;
    /* node->index = index_in_each_scope[current_scope_level]; */
    /* index_in_each_scope[current_scope_level]++;     */
    strcpy(node->name, var_name);
    strcpy(node->type, var_type);
    node->address = address;
    address++;
    node->lineno = lineno;
    node->printed = 0;
    strcpy(node->element_type,element);
    if(head == NULL){
        head = node;
    }
    else{
        current = head;
        while(current->next != NULL){
            current = current->next;            
        }
        current->next = node;
    }
    printf("> Insert {%s} into symbol table (scope level: %d)\n",node->name, node->scope_level); 
}

static int lookup_symbol(char* var_name){
    int temp_scope_level = current_scope_level;
    current = head;
    if(head == NULL){
        return -1;
    }
    else{
        // go through the whole linkedList with scope_level == current_scope_level (local variable)
        while(current->next != NULL){
            if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level) && current->printed == 0){
                return current->address;
            }                                                
            current = current->next;
        }                
        if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level) && current->printed == 0){
            return current->address;
        }
        
        // go through the whole linkedList again with scope_level == temp_scope_level (global variable)
        while(temp_scope_level >= 0){
            current = head;
            while(current->next != NULL){
                /* printf("Loop tracking: scope:%d\n", temp_scope_level); */
                if(!strcmp(current->name, var_name) && (current->scope_level == temp_scope_level) && current->printed == 0){
                    return current->address;
                }
                current = current->next;
            }
            if(!strcmp(current->name, var_name) && (current->scope_level == temp_scope_level) && current->printed == 0){
                return current->address;
            }
            temp_scope_level--;
        }
        
        return -2;// ident not found, return -2
    }    
}

static void dump_symbol(void){                                                  
    printf("> Dump symbol table (scope level: %d)\n", current_scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");    
    printList(head);
}

void printList(struct symbol_table* head){    
    int index = 0;
    if(head == NULL){
        /* perror("Error:Head is NULL"); */
        return;
    }
    else{
        current = head;
        while(current->next != NULL){
            // printed means the variable is dumped(printed)
            if(current->scope_level == current_scope_level && current->printed == 0){
                printf("%-10d%-10s%-10s%-10d%-10d%s\n", index++, current->name, current->type, current->address, current->lineno, current->element_type);
                current->printed = 1;            
            }
            current = current->next;
        }
        if(current->scope_level == current_scope_level && current->printed == 0){
            printf("%-10d%-10s%-10s%-10d%-10d%s\n", index++, current->name, current->type, current->address, current->lineno, current->element_type);            
            current->printed = 1;
        }
    }
}

char* getType(char* var_name){
    if(head == NULL){
        perror("Error: Head is NULL！！！");
        exit(EXIT_FAILURE);
    }
    else{        
        current = head;
        int temp_scope_level = current_scope_level;
        // go through the whole linkedList with scope_level == current_scope_level (local variable)
        while(current->next != NULL){
            if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level) && current->printed == 0){
                if(!strcmp(current->type, "array")){
                    return current->element_type;
                }                
                else{
                    return current->type;
                }
            }                                                
            current = current->next;
        }                
        if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level) && current->printed == 0){
            if(!strcmp(current->type, "array")){
                return current->element_type;
            }                
            else{
                return current->type;
            }
        }
        
        // go through the whole linkedList again with scope_level == temp_scope_level (global variable)
        while(temp_scope_level >= 0){
            current = head;
            while(current->next != NULL){
                /* printf("Loop tracking: scope:%d\n", temp_scope_level); */
                if(!strcmp(current->name, var_name) && (current->scope_level == temp_scope_level) && current->printed == 0){
                    if(!strcmp(current->type, "array")){
                        return current->element_type;
                    }                
                    else{
                        return current->type;
                    }
                }
                current = current->next;
            }
            if(!strcmp(current->name, var_name) && (current->scope_level == temp_scope_level) && current->printed == 0){
                if(!strcmp(current->type, "array")){
                    return current->element_type;
                }                
                else{
                    return current->type;
                }
            }
            temp_scope_level--;
        }        
    }
    return NULL;
}

int reDeclared(char* var_name, char* var_type){
    if(head == NULL){        
        return -1;
    }
    else{
        current = head;
        // we can ignore to check type at here because redeclared is only work on same variable name
        while(current->next != NULL){
            if(!strcmp(current->name, var_name) && current->scope_level == current_scope_level){
                return current->lineno;
            }
            current = current->next;
        }
        if(!strcmp(current->name, var_name) && current->scope_level == current_scope_level){
            return current->lineno;
        }
    }
    return -1;
}

bool validType(char* return_value){
    // return TRUE means that return_value $$ is var_type,not variable name
    if(!strcmp(return_value, "int"))
        return true;    
    else if(!strcmp(return_value, "float"))
        return true;    
    else
        return false;
}

bool isArray(char* var_name){
    if(head == NULL){
        perror("isArray error!\n");        
        exit(EXIT_FAILURE);
    }
    else{        
        current = head;
        int temp_scope_level = current_scope_level;
        // go through the whole linkedList with scope_level == current_scope_level (local variable)
        while(current->next != NULL){
            if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level) && current->printed == 0){
                if(!strcmp(current->type, "array"))
                    return true;                   
                else
                    return false;             
            }                                                
            current = current->next;
        }                
        if(!strcmp(current->name, var_name) && (current->scope_level == current_scope_level) && current->printed == 0){
            if(!strcmp(current->type, "array"))
                return true;                   
            else
                return false;
        }
        
        // go through the whole linkedList again with scope_level == temp_scope_level (global variable)
        while(temp_scope_level >= 0){
            current = head;
            while(current->next != NULL){
                /* printf("Loop tracking: scope:%d\n", temp_scope_level); */
                if(!strcmp(current->name, var_name) && (current->scope_level == temp_scope_level) && current->printed == 0){
                    if(!strcmp(current->type, "array"))
                        return true;                   
                    else
                        return false;             
                }
                current = current->next;
            }
            if(!strcmp(current->name, var_name) && (current->scope_level == temp_scope_level) && current->printed == 0){
                if(!strcmp(current->type, "array"))
                    return true;                   
                else
                    return false;             
            }
            temp_scope_level--;
        }        
    }
    return false;
}

void printmsg(char* type){    
    if(!strcmp(type, "int")){        
        codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        codegen("swap\n");
        codegen("invokevirtual java/io/PrintStream/print(I)V\n");
    }
    else if(!strcmp(type, "float")){
        codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        codegen("swap\n");
        codegen("invokevirtual java/io/PrintStream/print(F)V\n");
    }
    else if(!strcmp(type, "TRUE") || !strcmp(type, "FALSE") || !strcmp(type, "bool")){
        compare_level++;
        /* codegen("iconst_1\n"); */
        codegen("ifne L_cmp_%d\n",compare_level);
        codegen("ldc \"false\"\n");        
        codegen("goto L_cmp_%d\n",compare_level+1);

        INDENT--;
        codegen("L_cmp_%d:\n",compare_level);
        INDENT++;
        
        codegen("ldc \"true\"\n");        

        compare_level++;
        INDENT--;
        codegen("L_cmp_%d:\n",compare_level);
        INDENT++;
        codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        codegen("swap\n");
        codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n\n");
        
    }
    else if(!strcmp(type, "string")){
        if(newline){
            codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            codegen("swap\n");
            codegen("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n\n");
        }
        else{
            codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            codegen("swap\n");
            codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
        
    }    
}

static void push_stack(char* var_name, char* var_type){
    stack_node = (struct stack*)malloc(sizeof(struct stack));
    strcpy(stack_node->name,var_name);
    strcpy(stack_node->type,var_type);
    stack_node->next = NULL;

    if(stack_head == NULL){
        stack_head = stack_node;
        stack_node->prev = NULL;
    }
    else{
        stack_current = stack_head;
        while(stack_current->next != NULL){
            stack_current = stack_current->next;            
        }
        stack_node->prev = stack_current;
        stack_current->next = stack_node;
    }
}

static void pop_stack(char* var_name){
    if(head == NULL){        
        return;
    }
    else{
        stack_current = stack_head;
        while(stack_current->next != NULL){
            stack_current = stack_current->next;
        }
        // check the Top of Stack's name is same with var_name, if yes then pop
        stack_current->prev->next = NULL;            
    }
}

static char* get_TOS(void){
    if(head == NULL){        
        return NULL;
    }
    else{
        stack_current = stack_head;
        while(stack_current->next != NULL){
            stack_current = stack_current->next;
        }
        return stack_current->name;
    }
}