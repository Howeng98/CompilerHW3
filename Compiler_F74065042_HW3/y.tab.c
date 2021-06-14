/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "compiler_hw3.y"

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
    bool if_state = false;
    bool for_state = false;
    bool else_state = false;
    bool while_state = false;
    bool check_ary[5] = {false};

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
    

#line 161 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD = 258,
    SUB = 259,
    MUL = 260,
    QUO = 261,
    REM = 262,
    INT = 263,
    FLOAT = 264,
    BOOL = 265,
    STRING = 266,
    INC = 267,
    DEC = 268,
    GEQ = 269,
    LEQ = 270,
    EQL = 271,
    NEQ = 272,
    LSS = 273,
    GTR = 274,
    ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    MUL_ASSIGN = 278,
    QUO_ASSIGN = 279,
    REM_ASSIGN = 280,
    LAND = 281,
    LOR = 282,
    NOT = 283,
    SEMICOLON = 284,
    IF = 285,
    ELSE = 286,
    WHILE = 287,
    FOR = 288,
    PRINT = 289,
    TRUE = 290,
    FALSE = 291,
    INT_LIT = 292,
    FLOAT_LIT = 293,
    STRING_LIT = 294,
    IDENT = 295
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define QUO 261
#define REM 262
#define INT 263
#define FLOAT 264
#define BOOL 265
#define STRING 266
#define INC 267
#define DEC 268
#define GEQ 269
#define LEQ 270
#define EQL 271
#define NEQ 272
#define LSS 273
#define GTR 274
#define ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define MUL_ASSIGN 278
#define QUO_ASSIGN 279
#define REM_ASSIGN 280
#define LAND 281
#define LOR 282
#define NOT 283
#define SEMICOLON 284
#define IF 285
#define ELSE 286
#define WHILE 287
#define FOR 288
#define PRINT 289
#define TRUE 290
#define FALSE 291
#define INT_LIT 292
#define FLOAT_LIT 293
#define STRING_LIT 294
#define IDENT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 96 "compiler_hw3.y"

    int i_val;
    float f_val;
    char *s_val;
    char *id;
    char *boool;
    char *type;   

#line 302 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   564

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    43,    44,    45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   149,   149,   156,   157,   158,   159,   163,   164,   165,
     166,   167,   171,   181,   190,   196,   203,   212,   217,   229,
     246,   257,   268,   273,   286,   292,   304,   314,   323,   327,
     333,   341,   345,   365,   381,   400,   403,   406,   409,   414,
     415,   416,   417,   418,   421,   453,   462,   501,   512,   523,
     534,   541,   545,   549,   553,   557,   561,   567,   583,   597,
     608,   619,   636,   646,   659,   660,   664,   677,   693,   763,
     786,   790,   834,   890,   897,   902,   910,   913,   922,   931,
     934,   937,   940,   956,   969,   973,   983,   999,  1006,  1016,
    1051,  1054,  1057
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "QUO", "REM", "INT",
  "FLOAT", "BOOL", "STRING", "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ",
  "LSS", "GTR", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR", "NOT", "SEMICOLON", "IF",
  "ELSE", "WHILE", "FOR", "PRINT", "TRUE", "FALSE", "'['", "']'", "'{'",
  "'}'", "'('", "')'", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "IDENT",
  "$accept", "Program", "StatementList", "Statement", "PrintStmt",
  "IfStmt", "LoopStmt", "IF_OPEN1", "IF_CLOSE1", "WHILE_STAGE", "IF_STAGE",
  "IF_STAGE2", "ELSE_STAGE", "IFELSE_CLOSE", "WHILE_OPEN", "WHILE_CLOSE",
  "FIRST_SEMICOLON", "SECOND_SEMICOLON", "FOR_OPEN", "FOR_CLOSE",
  "FOR_Bracket_OPEN", "FOR_Bracket_CLOSE", "DeclarationStmt", "Type",
  "Expression", "AssignmentExpr", "ArithmeticExpr", "ConversionExpr",
  "BoolExpr", "LogicalExpr", "CompareExpr", "Bool", "TermExpr", "Num",
  "ID", "Bracket", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    91,    93,   123,
     125,    40,    41,   292,   293,   294,   295
};
# endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-93)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     121,     7,     7,   -87,   -87,   -87,   -87,   142,   -87,   -87,
     -33,   -36,   -87,   -87,   -87,   -87,   267,   -87,   -87,   -87,
     -87,    28,   121,    12,   -87,   -87,   -87,   -36,   -36,   -36,
     -87,    46,   469,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
      40,    24,    -1,   -87,   -87,   -87,   -87,   -87,   142,   142,
     -87,    32,    55,    84,   -87,    75,   -87,    73,    77,    77,
      17,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   -87,
     -87,   142,   142,   142,   142,   142,   142,   142,   142,   415,
     186,   186,   -87,   -87,   -87,   121,   -87,   121,   121,   142,
     142,   539,   539,   244,   244,   244,   114,   114,   114,   114,
     114,   114,    15,    15,   -87,   -87,   -87,   494,   469,   114,
      15,    15,   -87,   -87,   -87,   114,   340,   -87,   142,   -87,
     -87,    86,   -87,   165,   209,   253,   469,   365,   107,   442,
     142,     8,   -87,    97,   102,     8,   -87,   -87,   142,   -87,
     142,   390,   -87,   -87,   114,   311,   -87,   -87,   -36,   121,
     -87,   121,   -87,   516
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    35,    36,    38,    37,     0,    20,    19,
       0,     0,    74,    75,    91,    92,     0,    87,    88,    78,
      89,     0,     2,     6,     7,     9,    11,     0,     0,     0,
       8,     0,    10,    39,    40,    41,    43,    64,    65,    81,
      42,    79,    76,    80,    84,    85,    86,    28,     0,     0,
      12,     0,     0,     0,     1,     4,     5,     0,     0,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     3,    24,     0,    17,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    70,    71,    72,    73,
      69,    68,    46,    47,    48,    49,    50,    67,    66,    51,
      52,    53,    54,    55,    56,    44,     0,    26,     0,    62,
      79,    76,    63,     0,     0,     0,    34,     0,    77,     0,
       0,    25,    16,    92,     0,    18,    13,    33,     0,    27,
       0,     0,    22,    14,    45,     0,    77,    29,     0,     0,
      30,     0,    15,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,   -86,   -20,   -87,   -87,   -87,    81,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,    -6,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,    -7,     5,    -5,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    23,    24,    25,    26,    97,   146,    27,
      28,    29,   153,   144,    95,   142,   128,   150,    48,   158,
     159,   162,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    46,    55,    14,    15,    49,    44,    45,    47,   133,
      53,   134,   135,   -92,   -92,   -92,    57,    58,    59,    87,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,    54,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,    88,    99,    74,    75,
      76,    56,    89,    53,    81,    82,    83,    84,    85,    86,
      17,    18,    79,    80,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   161,    90,   119,   120,   121,   122,   123,
     124,   125,   126,   129,   132,   131,   131,    61,    62,    63,
      64,    65,    60,   136,   137,   130,   130,    91,    66,    67,
      68,    69,    70,    71,    93,    72,    73,    74,    75,    76,
      77,    78,    94,    55,    55,    55,    96,    61,    62,    63,
      64,    65,   139,   140,     1,     2,    92,   148,   -23,     3,
       4,     5,     6,   152,   151,    72,    73,    74,    75,    76,
      98,    55,   154,     0,   155,     1,     2,   160,     0,     7,
     163,     8,     0,     9,    10,    11,    12,    13,     0,     0,
      14,    15,    16,     0,    17,    18,    19,    20,     1,     2,
       7,     0,     0,     3,     4,     5,     6,    12,    13,     0,
       0,    14,    15,    16,     0,    17,    18,    19,    20,     1,
       2,     0,     0,     7,     0,     8,     0,     9,    10,    11,
      12,    13,     0,     0,    14,   141,    16,     0,    17,    18,
      19,    20,     1,     2,     7,     0,     0,     3,     4,     5,
       6,    12,    13,     0,     0,    14,    15,    49,     0,    17,
      18,    19,    20,     0,     0,     0,     0,     7,     0,     8,
       0,     9,    10,    11,    12,    13,     0,     0,    14,   143,
      16,     0,    17,    18,    19,    20,     1,     2,     0,     0,
       0,     3,     4,     5,     6,    72,    73,    74,    75,    76,
       1,     2,     0,     0,     0,    51,    52,     0,     0,     0,
       0,     7,     0,     8,     0,     9,    10,    11,    12,    13,
       0,     0,    14,   145,    16,     7,    17,    18,    19,    20,
       0,     0,    12,    13,     0,     0,    14,    15,    16,     0,
      17,    18,    19,    20,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,    77,    78,     0,
       0,     0,     0,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,   157,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,    77,    78,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,   138,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,    77,    78,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,   147,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,    77,    78,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,   156,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,    77,    78,     0,   127,    61,    62,    63,    64,    65,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,    77,    78,
       0,   149,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,    77,    78,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
      77,   -80,   -80,   -80,     0,     0,     0,     0,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,     0,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      11,     7,    22,    39,    40,    41,     1,     2,    41,    95,
      16,    97,    98,     5,     6,     7,    27,    28,    29,    20,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    21,
      22,    23,    24,    25,    26,    27,    37,    20,    23,    24,
      25,    29,    48,    49,    20,    21,    22,    23,    24,    25,
      43,    44,    12,    13,    37,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   159,    42,    81,    82,    83,    84,    85,
      86,    87,    88,    90,    91,    90,    91,     3,     4,     5,
       6,     7,    46,    99,   100,    90,    91,    42,    14,    15,
      16,    17,    18,    19,    29,    21,    22,    23,    24,    25,
      26,    27,    39,   133,   134,   135,    39,     3,     4,     5,
       6,     7,   128,    37,     3,     4,    42,    20,    31,     8,
       9,    10,    11,    31,   140,    21,    22,    23,    24,    25,
      59,   161,   148,    -1,   150,     3,     4,   158,    -1,    28,
     161,    30,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    41,    -1,    43,    44,    45,    46,     3,     4,
      28,    -1,    -1,     8,     9,    10,    11,    35,    36,    -1,
      -1,    39,    40,    41,    -1,    43,    44,    45,    46,     3,
       4,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    -1,    39,    40,    41,    -1,    43,    44,
      45,    46,     3,     4,    28,    -1,    -1,     8,     9,    10,
      11,    35,    36,    -1,    -1,    39,    40,    41,    -1,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    -1,    39,    40,
      41,    -1,    43,    44,    45,    46,     3,     4,    -1,    -1,
      -1,     8,     9,    10,    11,    21,    22,    23,    24,    25,
       3,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    39,    40,    41,    28,    43,    44,    45,    46,
      -1,    -1,    35,    36,    -1,    -1,    39,    40,    41,    -1,
      43,    44,    45,    46,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    42,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    38,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    38,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    38,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     8,     9,    10,    11,    28,    30,    32,
      33,    34,    35,    36,    39,    40,    41,    43,    44,    45,
      46,    48,    49,    50,    51,    52,    53,    56,    57,    58,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    80,    80,    71,    41,    65,    41,
      82,     8,     9,    71,     0,    50,    29,    82,    82,    82,
      46,     3,     4,     5,     6,     7,    14,    15,    16,    17,
      18,    19,    21,    22,    23,    24,    25,    26,    27,    12,
      13,    20,    21,    22,    23,    24,    25,    20,    37,    71,
      42,    42,    42,    29,    39,    61,    39,    54,    54,    20,
      37,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    29,    63,    79,
      80,    81,    79,    49,    49,    49,    71,    71,    38,    71,
      37,    40,    62,    40,    60,    40,    55,    38,    20,    29,
      64,    71,    31,    59,    71,    71,    38,    42,    66,    67,
      82,    49,    68,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    50,    50,    50,
      50,    50,    51,    52,    52,    53,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    69,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    81,
      82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     2,     5,     6,    11,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 149 "compiler_hw3.y"
                    {
        INDENT--;
        codegen("L_loop_exit:\n");
        INDENT++;
    }
#line 1681 "y.tab.c"
    break;

  case 12:
#line 171 "compiler_hw3.y"
                    {
        // printf("Print!!!!!:%s\n", $2);
        if(!strcmp((yyvsp[0].type),"TRUE") || !strcmp((yyvsp[0].type),"FALSE")){
            printf("PRINT bool\n");
        }
        printmsg((yyvsp[0].type));
    }
#line 1693 "y.tab.c"
    break;

  case 13:
#line 181 "compiler_hw3.y"
                                                         {
        // if condition without else                
        codegen("Here without else\n");

        if(strcmp((yyvsp[-3].type),"bool")!=0 && strcmp((yyvsp[-3].type),"TRUE")!=0 && strcmp((yyvsp[-3].type),"FALSE")){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, (yyvsp[-3].type));
        }            
        if_state = true;
    }
#line 1707 "y.tab.c"
    break;

  case 14:
#line 190 "compiler_hw3.y"
                                                                     {                
        if_state = true;
    }
#line 1715 "y.tab.c"
    break;

  case 15:
#line 196 "compiler_hw3.y"
                                                                                                                                                {
        // for condition
        codegen("goto FOR_cmp2_%d\n", compare_level);
        INDENT--;        
        codegen("L_loop_exit:\n");
        INDENT++;
    }
#line 1727 "y.tab.c"
    break;

  case 16:
#line 203 "compiler_hw3.y"
                                                              {
        if(strcmp((yyvsp[-3].type),"bool")!=0 && strcmp((yyvsp[-3].type),"TRUE")!=0 && strcmp((yyvsp[-3].type),"FALSE")){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, (yyvsp[-3].type));
        }                        
    }
#line 1737 "y.tab.c"
    break;

  case 17:
#line 212 "compiler_hw3.y"
          {
        current_scope_level++;
    }
#line 1745 "y.tab.c"
    break;

  case 18:
#line 217 "compiler_hw3.y"
          {
        dump_symbol();
        current_scope_level--;        
        codegen("goto L_loop_exit\n");
        INDENT--;
        codegen("L_if_end_%d:\n", compare_level);
        INDENT++;
        if_state = false;
    }
#line 1759 "y.tab.c"
    break;

  case 19:
#line 229 "compiler_hw3.y"
            {
        
        if(check_ary[compare_level] == false)
            check_ary[compare_level] = true;
        else{
            compare_level++;
            check_ary[compare_level] = true;
        }
        compare_level++;
        while_state = true; 
        INDENT--;
        codegen("L_while_cmp_%d:\n",compare_level);
        INDENT++;
    }
#line 1778 "y.tab.c"
    break;

  case 20:
#line 246 "compiler_hw3.y"
         {
        compare_level++;
        INDENT--;
        codegen("L_if_cmp_%d:\n",compare_level);
        INDENT++;
        if_state = true;
        else_state =true;        
    }
#line 1791 "y.tab.c"
    break;

  case 21:
#line 257 "compiler_hw3.y"
         {
        compare_level++;
        INDENT--;
        codegen("L_if_cmp_%d:\n",compare_level);
        INDENT++;
        if_state = true;
        else_state =false;        
    }
#line 1804 "y.tab.c"
    break;

  case 22:
#line 268 "compiler_hw3.y"
           {
        else_state = false;
    }
#line 1812 "y.tab.c"
    break;

  case 23:
#line 273 "compiler_hw3.y"
          {
        dump_symbol();
        current_scope_level--;
        // if(else_state == true)
        codegen("goto L_loop_exit\n");
        INDENT--;
        codegen("L_if_end_%d:\n", compare_level);
        INDENT++;
        if_state = false;
    }
#line 1827 "y.tab.c"
    break;

  case 24:
#line 286 "compiler_hw3.y"
          {
        current_scope_level++;        
    }
#line 1835 "y.tab.c"
    break;

  case 25:
#line 292 "compiler_hw3.y"
          {    
        codegen("goto L_while_cmp_%d\n", compare_level);
        INDENT--;
        codegen("L_while_end_%d:\n", compare_level);
        INDENT++;
        compare_level--;
        dump_symbol();
        current_scope_level--;    
    }
#line 1849 "y.tab.c"
    break;

  case 26:
#line 304 "compiler_hw3.y"
                {
        // FOR comparision
        for_state = true;
        INDENT--;
        codegen("FOR_cmp_%d:\n",compare_level);
        INDENT++;
    }
#line 1861 "y.tab.c"
    break;

  case 27:
#line 314 "compiler_hw3.y"
                {
        // FOR INC/ DEC  (e.g.: i++ , i--)
        INDENT--;
        codegen("FOR_cmp2_%d:\n",compare_level);
        INDENT++;
    }
#line 1872 "y.tab.c"
    break;

  case 29:
#line 327 "compiler_hw3.y"
          {
        codegen("goto FOR_cmp_%d\n", compare_level);
    }
#line 1880 "y.tab.c"
    break;

  case 30:
#line 333 "compiler_hw3.y"
              {
        INDENT--;
        codegen("L_cmp_%d:\n", compare_level);
        INDENT++;
    }
#line 1890 "y.tab.c"
    break;

  case 32:
#line 345 "compiler_hw3.y"
                 {
        if(reDeclared((yyvsp[0].id), (yyvsp[-1].type))==-1){
            insert_symbol((yyvsp[0].id), (yyvsp[-1].type), yylineno, "-");
        }else{
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, (yyvsp[0].id), reDeclared((yyvsp[0].id), (yyvsp[-1].type)));
        }

        if(!strcmp((yyvsp[-1].type),"int")){
            codegen("ldc 0 \n");
            codegen("istore %d\n", lookup_symbol((yyvsp[0].id)));
        }
        if(!strcmp((yyvsp[-1].type),"float")){
            codegen("ldc 0.000000 \n");
            codegen("fstore %d\n", lookup_symbol((yyvsp[0].id)));
        }
        if(!strcmp((yyvsp[-1].type),"string")){
            codegen("ldc \"\" \n");            
            codegen("astore %d\n", lookup_symbol((yyvsp[0].id)));
        } 
    }
#line 1915 "y.tab.c"
    break;

  case 33:
#line 365 "compiler_hw3.y"
                                    {        
        if(reDeclared((yyvsp[-3].id), (yyvsp[-4].type))==-1){
            insert_symbol((yyvsp[-3].id), "array", yylineno, (yyvsp[-4].type));
        }else{
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, (yyvsp[-3].id), reDeclared((yyvsp[-3].id), "array"));
        }   

        if(!strcmp((yyvsp[-4].type),"int")){            
            codegen("newarray int\n");
            codegen("astore %d\n", lookup_symbol((yyvsp[-3].id)));
        }
        if(!strcmp((yyvsp[-4].type),"float")){            
            codegen("newarray float\n");
            codegen("astore %d\n", lookup_symbol((yyvsp[-3].id)));
        }
    }
#line 1936 "y.tab.c"
    break;

  case 34:
#line 381 "compiler_hw3.y"
                                   {                 
        // printf("checked\n");
        insert_symbol((yyvsp[-2].id), (yyvsp[-3].type), yylineno, "-");
        if(!strcmp((yyvsp[-3].type),"int")){
            codegen("istore %d\n", lookup_symbol((yyvsp[-2].id)));
        }
        if(!strcmp((yyvsp[-3].type),"float")){
            codegen("fstore %d\n", lookup_symbol((yyvsp[-2].id)));
        }
        if(!strcmp((yyvsp[-3].type),"string")){
            codegen("astore %d\n", lookup_symbol((yyvsp[-2].id)));
        }
        if(!strcmp((yyvsp[-3].type),"bool")){            
            codegen("istore %d\n", lookup_symbol((yyvsp[-2].id)));
        }
    }
#line 1957 "y.tab.c"
    break;

  case 35:
#line 400 "compiler_hw3.y"
          { 
        (yyval.type) = "int";
    }
#line 1965 "y.tab.c"
    break;

  case 36:
#line 403 "compiler_hw3.y"
            { 
        (yyval.type) = "float";
    }
#line 1973 "y.tab.c"
    break;

  case 37:
#line 406 "compiler_hw3.y"
             { 
        (yyval.type) = "string";
    }
#line 1981 "y.tab.c"
    break;

  case 38:
#line 409 "compiler_hw3.y"
           { 
        (yyval.type) = "bool";
    }
#line 1989 "y.tab.c"
    break;

  case 40:
#line 415 "compiler_hw3.y"
                     {(yyval.type) = (yyvsp[0].type);}
#line 1995 "y.tab.c"
    break;

  case 41:
#line 416 "compiler_hw3.y"
                     {(yyval.type) = (yyvsp[0].type);}
#line 2001 "y.tab.c"
    break;

  case 42:
#line 417 "compiler_hw3.y"
               { (yyval.type) = (yyvsp[0].type); }
#line 2007 "y.tab.c"
    break;

  case 43:
#line 418 "compiler_hw3.y"
               { (yyval.type) = (yyvsp[0].type); }
#line 2013 "y.tab.c"
    break;

  case 44:
#line 421 "compiler_hw3.y"
                           {
        if(validType((yyvsp[-2].id)) && validType((yyvsp[0].type))){
            if(strcmp((yyvsp[-2].id),(yyvsp[0].type)) != 0){
               printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, (yyvsp[-2].id), (yyvsp[0].type));
            }
        }        
        printf("ASSIGN\n");
        if(!strcmp((yyvsp[-2].id),"int") && !strcmp((yyvsp[0].type),"int")){
            if(!strcmp(changedType,"int")){
                printf("TOS:%s\n",get_TOS());
                codegen("istore %d\n", lookup_symbol(get_TOS()));
            }
            else
                codegen("istore %d\n",lookup_symbol(var_name));                
        }
        else if(!strcmp((yyvsp[-2].id),"float") && !strcmp((yyvsp[0].type),"float")){
            if(!strcmp(changedType,"float")){
                printf("TOS:%s\n",get_TOS());
                codegen("fstore %d\n", lookup_symbol(get_TOS()));
            }
            else
                codegen("fstore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp((yyvsp[-2].id),"string") && !strcmp((yyvsp[0].type),"string")){
            codegen("astore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp((yyvsp[-2].id),"bool")){
            codegen("istore %d\n",lookup_symbol(var_name));
        }
        
        
    }
#line 2050 "y.tab.c"
    break;

  case 45:
#line 453 "compiler_hw3.y"
                                              {                 
        printf("ASSIGN\n");
        if(!strcmp((yyvsp[-5].id),"int")){
            codegen("iastore \n");
        }
        else if(!strcmp((yyvsp[-5].id),"float")){
            codegen("fastore \n");
        }
    }
#line 2064 "y.tab.c"
    break;

  case 46:
#line 462 "compiler_hw3.y"
                                       {        
        printf("ADD_ASSIGN\n");
        if(!strcmp((yyvsp[0].type),"int")){
            codegen("iadd \n");
            // codegen("istore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp((yyvsp[0].type),"float")){
            codegen("fadd \n");
            // codegen("fstore %d\n",lookup_symbol(var_name));
        }

        if(!strcmp((yyvsp[-2].type),"int") && !strcmp((yyvsp[0].type),"int")){
            if(!strcmp(changedType,"int")){
                printf("TOS:%s\n",get_TOS());
                codegen("istore %d\n", lookup_symbol(get_TOS()));
            }
            else
                codegen("istore %d\n",lookup_symbol(var_name));
                // if(checknum == 10){
                //     INDENT--;
                //     codegen("L_for_start:\n");
                //     INDENT++;
                // }        
        }
        else if(!strcmp((yyvsp[-2].type),"float") && !strcmp((yyvsp[0].type),"float")){
            if(!strcmp(changedType,"float")){
                printf("TOS:%s\n",get_TOS());
                codegen("fstore %d\n", lookup_symbol(get_TOS()));
            }
            else
                codegen("fstore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp((yyvsp[-2].type),"string") && !strcmp((yyvsp[0].type),"string")){
            codegen("astore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp((yyvsp[-2].type),"bool")){
            codegen("istore %d\n",lookup_symbol(var_name));
        }
    }
#line 2108 "y.tab.c"
    break;

  case 47:
#line 501 "compiler_hw3.y"
                                       {                        
        printf("SUB_ASSIGN\n");
        if(!strcmp((yyvsp[0].type),"int")){
            codegen("isub \n");
            codegen("istore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp((yyvsp[0].type),"float")){
            codegen("fsub \n");
            codegen("fstore %d\n",lookup_symbol(var_name));
        }
    }
#line 2124 "y.tab.c"
    break;

  case 48:
#line 512 "compiler_hw3.y"
                                       {                
        printf("MUL_ASSIGN\n");
        if(!strcmp((yyvsp[0].type),"int")){
            codegen("imul \n");
            codegen("istore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp((yyvsp[0].type),"float")){
            codegen("fmul \n");
            codegen("fstore %d\n",lookup_symbol(var_name));
        }
    }
#line 2140 "y.tab.c"
    break;

  case 49:
#line 523 "compiler_hw3.y"
                                       {                      
        printf("QUO_ASSIGN\n");
        if(!strcmp((yyvsp[0].type),"int")){
            codegen("idiv \n");
            codegen("istore %d\n",lookup_symbol(var_name));
        }
        else if(!strcmp((yyvsp[0].type),"float")){
            codegen("fdiv \n");
            codegen("fstore %d\n",lookup_symbol(var_name));
        }
    }
#line 2156 "y.tab.c"
    break;

  case 50:
#line 534 "compiler_hw3.y"
                                       {                        
        printf("REM_ASSIGN\n");
        if(!strcmp((yyvsp[0].type),"int")){
            codegen("irem \n");
            codegen("istore %d\n",lookup_symbol(var_name));
        }        
    }
#line 2168 "y.tab.c"
    break;

  case 51:
#line 541 "compiler_hw3.y"
                            {                
        printf("error:%d: cannot assign to %s\n", yylineno, (yyvsp[-2].type));
        printf("ASSIGN\n");
    }
#line 2177 "y.tab.c"
    break;

  case 52:
#line 545 "compiler_hw3.y"
                                {        
        printf("error:%d: cannot assign to %s\n", yylineno, (yyvsp[-2].type));
        printf("ADD_ASSIGN\n");        
    }
#line 2186 "y.tab.c"
    break;

  case 53:
#line 549 "compiler_hw3.y"
                                {                
        printf("error:%d: cannot assign to %s\n", yylineno, (yyvsp[-2].type));        
        printf("SUB_ASSIGN\n");
    }
#line 2195 "y.tab.c"
    break;

  case 54:
#line 553 "compiler_hw3.y"
                                {        
        printf("error:%d: cannot assign to %s\n", yylineno, (yyvsp[-2].type));        
        printf("MUL_ASSIGN\n");
    }
#line 2204 "y.tab.c"
    break;

  case 55:
#line 557 "compiler_hw3.y"
                                {        
        printf("error:%d: cannot assign to %s\n", yylineno, (yyvsp[-2].type));        
        printf("QUO_ASSIGN\n");
    }
#line 2213 "y.tab.c"
    break;

  case 56:
#line 561 "compiler_hw3.y"
                                {        
        printf("error:%d: cannot assign to %s\n", yylineno, (yyvsp[-2].type));        
        printf("REM_ASSIGN\n");
    }
#line 2222 "y.tab.c"
    break;

  case 57:
#line 567 "compiler_hw3.y"
                                {                
        if(strcmp((yyvsp[-2].type),(yyvsp[0].type)) != 0){
            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, (yyvsp[-2].type), (yyvsp[0].type));
        }
        printf("ADD\n");
        if(!strcmp((yyvsp[-2].type), "int")){
            codegen("iadd \n");
            // printmsg("int");
        }
        if(!strcmp((yyvsp[-2].type), "float")){
            codegen("fadd \n");
            // printmsg("float");
        }        
        if(var_name != NULL)
            pop_stack(var_name);
    }
#line 2243 "y.tab.c"
    break;

  case 58:
#line 583 "compiler_hw3.y"
                                {
        if(strcmp((yyvsp[-2].type),(yyvsp[0].type)) != 0){
            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, (yyvsp[-2].type), (yyvsp[0].type));
        }
        printf("SUB\n");
        if(!strcmp((yyvsp[-2].type), "int")){
            codegen("isub \n");
            // printmsg("int");
        }
        if(!strcmp((yyvsp[-2].type), "float")){
            codegen("fsub \n");
            // printmsg("float");
        }      
    }
#line 2262 "y.tab.c"
    break;

  case 59:
#line 597 "compiler_hw3.y"
                                {
        printf("MUL\n");
        if(!strcmp((yyvsp[-2].type), "int")){
            codegen("imul \n");
            // printmsg("int");
        }
        if(!strcmp((yyvsp[-2].type), "float")){
            codegen("fmul \n");
            // printmsg("float");
        }     
    }
#line 2278 "y.tab.c"
    break;

  case 60:
#line 608 "compiler_hw3.y"
                                {
        printf("QUO\n");
        if(!strcmp((yyvsp[-2].type), "int")){
            codegen("idiv \n");
            // printmsg("int");
        }
        if(!strcmp((yyvsp[-2].type), "float")){
            codegen("fdiv \n");
            // printmsg("float");
        }  
    }
#line 2294 "y.tab.c"
    break;

  case 61:
#line 619 "compiler_hw3.y"
                                {
        if(!strcmp((yyvsp[-2].type),"float")|| !strcmp((yyvsp[0].type),"float")){
            printf("error:%d: invalid operation: (operator REM not defined on float)\n", yylineno);
        }
        printf("REM\n");
        if(!strcmp((yyvsp[-2].type), "int")){
            codegen("irem \n");
            // printmsg("int");
        }
        if(!strcmp((yyvsp[-2].type), "float")){
            codegen("frem \n");
            // printmsg("float");
        }       
    }
#line 2313 "y.tab.c"
    break;

  case 62:
#line 636 "compiler_hw3.y"
                           {
        printf("F to I\n");
        codegen("f2i \n");
        strcpy(changedType,"int");
        // if(!isNum)
        pop_stack(var_name);
        // else
        //     isNum = false;
        (yyval.type) = "int";
    }
#line 2328 "y.tab.c"
    break;

  case 63:
#line 646 "compiler_hw3.y"
                             {        
        printf("I to F\n");
        codegen("i2f \n");
        strcpy(changedType,"float");        
        // if(!isNum)
        pop_stack(var_name);
        // else
        //     isNum = false;
        (yyval.type) = "float";
    }
#line 2343 "y.tab.c"
    break;

  case 64:
#line 659 "compiler_hw3.y"
                  { (yyval.type) = (yyval.type); }
#line 2349 "y.tab.c"
    break;

  case 65:
#line 660 "compiler_hw3.y"
                  { (yyval.type) = (yyval.type); }
#line 2355 "y.tab.c"
    break;

  case 66:
#line 664 "compiler_hw3.y"
                                {
        if((strcmp((yyvsp[-2].type), "TRUE") != 0) && (strcmp((yyvsp[-2].type),"FALSE") != 0)){
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n", yylineno, (yyvsp[-2].type));
        }
        else if((strcmp((yyvsp[0].type), "TRUE") != 0) && (strcmp((yyvsp[0].type),"FALSE") != 0)){
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n", yylineno, (yyvsp[0].type));
        }
        // printf("LOR!!!! %s\n",$1);
        // printf("LOR!!!! %s\n",$3);
        (yyval.boool) = (yyvsp[-2].type);
        printf("OR\n");
        codegen("ior\n");
    }
#line 2373 "y.tab.c"
    break;

  case 67:
#line 677 "compiler_hw3.y"
                                 {
        if((strcmp((yyvsp[-2].type), "TRUE") != 0) && (strcmp((yyvsp[-2].type),"FALSE")  != 0)){
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n", yylineno, (yyvsp[-2].type));
        }
        else if((strcmp((yyvsp[0].type), "TRUE") != 0) && (strcmp((yyvsp[0].type),"FALSE") != 0)){
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n", yylineno, (yyvsp[0].type));
        }
        (yyval.boool) = (yyvsp[-2].type);
        // printf("LAND!!!! %s\n",$1);
        // printf("LAND!!!! %s\n",$3);
        printf("AND\n");
        codegen("iand\n");
    }
#line 2391 "y.tab.c"
    break;

  case 68:
#line 693 "compiler_hw3.y"
                                {
        current_state = false;     
        printf("GTR\n");

        if(!strcmp((yyvsp[-2].type),"int")){
            codegen("isub \n");
        }
        else if(!strcmp((yyvsp[-2].type),"float")){
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

        if(for_state == true){
            codegen("ifgt L_cmp_%d\n",compare_level);                
            codegen("iconst_0\n");
            current_state = false;        
            codegen("goto L_loop_exit\n");
            INDENT--;
            codegen("L_cmp_%d:\n",compare_level);
            INDENT++;
            codegen("iconst_1\n");
            codegen("goto L_cmp_%d\n",compare_level);
            for_state = false;
        }
        else if(while_state == true){
            // compare_level++;
            codegen("ifgt L_cmp_%d\n", compare_level);
            codegen("iconst_0\n");
            codegen("goto L_while_end_%d\n", compare_level);
            // while_state = false;
            INDENT--;
            codegen("L_cmp_%d:\n", compare_level);
            INDENT++;
            
        }
        else{            
            compare_level++;
            codegen("ifgt L_cmp_%d\n",compare_level);                
            codegen("iconst_0\n");            
            codegen("goto L_cmp_%d\n",compare_level+1);

            INDENT--;
            codegen("L_cmp_%d:\n",compare_level);
            INDENT++;

            codegen("iconst_1\n");
            INDENT--;
            codegen("L_cmp_%d:\n",compare_level+1);
            INDENT++;
            compare_level++;
            current_state = true;
        }
                                
        // current_state = true;

        if(current_state){
            (yyval.boool) = "TRUE";
        }
        else if(!current_state){
            (yyval.boool) = "FALSE";
        }
        
    }
#line 2466 "y.tab.c"
    break;

  case 69:
#line 763 "compiler_hw3.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("LSS\n"); 
        
        if(!strcmp((yyvsp[-2].type),"int")){
            codegen("isub \n");
        }
        else if(!strcmp((yyvsp[-2].type),"float")){
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

        codegen("iflt L_cmp_%d\n", compare_level);
        codegen("iconst_0 \n");        
        codegen("goto L_loop_exit\n");
    }
#line 2494 "y.tab.c"
    break;

  case 70:
#line 786 "compiler_hw3.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("GEQ\n"); 
    }
#line 2503 "y.tab.c"
    break;

  case 71:
#line 790 "compiler_hw3.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("LEQ\n");

        if(!strcmp((yyvsp[-2].type),"int")){
            codegen("isub \n");
        }
        else if(!strcmp((yyvsp[-2].type),"float")){
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


        if(if_state == true){
            codegen("ifle L_cmp_%d\n",compare_level);
            codegen("iconst_0\n");
            //FIXME:  check else_state!!!!!!!!!!!11
            // if(else_state == true){
                //got else

            codegen("goto L_if_end_%d\n",compare_level);
            // }
            INDENT--;
            codegen("L_cmp_%d:\n", compare_level);
            INDENT++;            
        }
        
        if(while_state == true){
            codegen("ifle L_cmp_%d\n", compare_level);
            codegen("iconst_0\n");
            codegen("goto L_while_end_%d\n", compare_level);
            // while_state = false;
            INDENT--;
            codegen("L_cmp_%d:\n", compare_level);
            INDENT++;            
        }        
    }
#line 2552 "y.tab.c"
    break;

  case 72:
#line 834 "compiler_hw3.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("EQL\n");
        if(!strcmp((yyvsp[-2].type),"int")){
            codegen("isub \n");
        }
        else if(!strcmp((yyvsp[-2].type),"float")){
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

        if(if_state == true){
            codegen("ifeq L_cmp_%d\n", compare_level);
            codegen("iconst_0\n");
            
            if(else_state == false){
                //if checker show that it is not if-else clause, then goto L_loop_exit when condition result is false
                codegen("goto L_loop_exit\n");
            }
            else{
                codegen("goto L_if_cmp_%d\n", compare_level);
            }
            //FIXME: check else_state!!!
            // codegen("goto L_if_end_%d\n",compare_level);


            INDENT--;
            codegen("L_cmp_%d:\n", compare_level);
            INDENT++;
            codegen("iconst_1\n");            
        }
        else{
            compare_level++;        
            codegen("ifeq L_cmp_%d\n",compare_level);
            codegen("iconst_0\n");
            codegen("goto L_cmp_%d\n",compare_level+1);
            
            INDENT--;
            codegen("L_cmp_%d:\n",compare_level);
            INDENT++;
            codegen("iconst_1\n");

            compare_level++;
            INDENT--;
            codegen("L_cmp_%d:\n",compare_level);
            INDENT++;
        }

    }
#line 2613 "y.tab.c"
    break;

  case 73:
#line 890 "compiler_hw3.y"
                                { 
        (yyval.boool) = (yyvsp[-2].type);
        printf("NEQ\n"); 
    }
#line 2622 "y.tab.c"
    break;

  case 74:
#line 897 "compiler_hw3.y"
           {
        (yyval.type) = "TRUE";
        printf("TRUE\n");        
        codegen("iconst_1 \n");
    }
#line 2632 "y.tab.c"
    break;

  case 75:
#line 902 "compiler_hw3.y"
            { 
        (yyval.type) = "FALSE";
        printf("FALSE\n");
        codegen("iconst_0 \n");   
    }
#line 2642 "y.tab.c"
    break;

  case 76:
#line 910 "compiler_hw3.y"
         {
        (yyval.type) = (yyvsp[0].id);
    }
#line 2650 "y.tab.c"
    break;

  case 77:
#line 913 "compiler_hw3.y"
                            {
        if(!strcmp((yyvsp[-3].id),"int")){
            codegen("iaload \n");
        }
        else if(!strcmp((yyvsp[-3].id),"float")){
            codegen("faload \n");
        }
        (yyval.type) = (yyvsp[-3].id);
    }
#line 2664 "y.tab.c"
    break;

  case 78:
#line 922 "compiler_hw3.y"
                 {        
        printf("STRING_LIT %s\n", (yyvsp[0].s_val));
        if(!strcmp((yyvsp[0].s_val), "\n"))
            newline = true;        
        else
            newline = false;
        codegen("ldc \"%s\" \n",(yyvsp[0].s_val));
        (yyval.type) = "string";
    }
#line 2678 "y.tab.c"
    break;

  case 79:
#line 931 "compiler_hw3.y"
          {
        (yyval.type) = (yyvsp[0].type);        
    }
#line 2686 "y.tab.c"
    break;

  case 80:
#line 934 "compiler_hw3.y"
              {
        (yyval.type) = (yyval.type);
    }
#line 2694 "y.tab.c"
    break;

  case 81:
#line 937 "compiler_hw3.y"
           {
        (yyval.type) = (yyval.type);        
    }
#line 2702 "y.tab.c"
    break;

  case 82:
#line 940 "compiler_hw3.y"
                   {
        printf("INC\n");
        if(!strcmp((yyvsp[-1].type), "int")){
            codegen("iload %d\n", lookup_symbol(var_name));
            codegen("ldc 1\n");
            codegen("iadd \n");        
            codegen("istore %d\n", lookup_symbol(var_name));        
        }
        if(!strcmp((yyvsp[-1].type), "float")){
            codegen("fload %d\n", lookup_symbol(var_name));
            codegen("ldc 1.000000\n");
            codegen("fadd \n");        
            codegen("fstore %d\n", lookup_symbol(var_name));        
        }
        
    }
#line 2723 "y.tab.c"
    break;

  case 83:
#line 956 "compiler_hw3.y"
                   {
        printf("DEC\n");
        if(!strcmp((yyvsp[-1].type), "int")){            
            codegen("ldc 1\n");
            codegen("isub \n");        
            codegen("istore %d\n", lookup_symbol(var_name));           
        }
        if(!strcmp((yyvsp[-1].type), "float")){            
            codegen("ldc 1.000000\n");
            codegen("fsub \n");        
            codegen("fstore %d\n", lookup_symbol(var_name));        
        }
    }
#line 2741 "y.tab.c"
    break;

  case 84:
#line 969 "compiler_hw3.y"
              {          
        printf("POS\n");              
        (yyval.type) = (yyvsp[0].type);
    }
#line 2750 "y.tab.c"
    break;

  case 85:
#line 973 "compiler_hw3.y"
              {        
        printf("NEG\n"); 
        if(!strcmp((yyvsp[0].type), "int")){
            codegen("ineg \n");            
        }
        if(!strcmp((yyvsp[0].type), "float")){            
            codegen("fneg \n");
        }                       
        (yyval.type) = (yyvsp[0].type);        
    }
#line 2765 "y.tab.c"
    break;

  case 86:
#line 983 "compiler_hw3.y"
                     {
        printf("NOT\n");
        if(current_state){
            (yyval.type) = "FALSE";
        }
        else{
            (yyval.type) = "TRUE";
        }
        // exclusive or (XOR)
        codegen("iconst_1 \n");
        codegen("ixor \n");
        // $$ = $2;
    }
#line 2783 "y.tab.c"
    break;

  case 87:
#line 999 "compiler_hw3.y"
              {         
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        codegen("ldc %d\n",(yyvsp[0].i_val));
        // push a useless stack, can ignore
        push_stack(var_name,"int");        
        (yyval.type) = "int";        
    }
#line 2795 "y.tab.c"
    break;

  case 88:
#line 1006 "compiler_hw3.y"
                {         
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
        codegen("ldc %f\n",(yyvsp[0].f_val));
        // push a useless stack, can ignore
        push_stack(var_name,"float");        
        (yyval.type) = "float";
    }
#line 2807 "y.tab.c"
    break;

  case 89:
#line 1016 "compiler_hw3.y"
            {
        if(lookup_symbol((yyvsp[0].id)) == -2){
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[0].id));
            codegen("goto L_error_stage:\n");
        }
        else{
            printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id), lookup_symbol((yyvsp[0].id)));
                                    
            push_stack((yyvsp[0].id),getType((yyvsp[0].id)));
            strcpy(var_name,(yyvsp[0].id));
            (yyval.id) = getType((yyvsp[0].id));
            
            if(!isArray((yyvsp[0].id))){
                if(!strcmp(getType((yyvsp[0].id)), "int")){
                    codegen("iload %d\n",lookup_symbol((yyvsp[0].id)));
                }
                if(!strcmp(getType((yyvsp[0].id)), "float")){
                    codegen("fload %d\n",lookup_symbol((yyvsp[0].id)));
                }
                if(!strcmp(getType((yyvsp[0].id)), "string")){
                    codegen("aload %d\n",lookup_symbol((yyvsp[0].id)));
                }
                if(!strcmp(getType((yyvsp[0].id)), "bool")){
                    codegen("iload %d\n",lookup_symbol((yyvsp[0].id)));
                }
            }
            else{
                codegen("aload %d\n",lookup_symbol((yyvsp[0].id)));
            }
                                            
        }                
    }
#line 2844 "y.tab.c"
    break;

  case 90:
#line 1051 "compiler_hw3.y"
                        {        
        (yyval.type) = (yyvsp[-1].type);        
    }
#line 2852 "y.tab.c"
    break;

  case 91:
#line 1054 "compiler_hw3.y"
          {        
        current_scope_level++;        
    }
#line 2860 "y.tab.c"
    break;

  case 92:
#line 1057 "compiler_hw3.y"
          {
        dump_symbol();
        current_scope_level--;                      
    }
#line 2869 "y.tab.c"
    break;


#line 2873 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1063 "compiler_hw3.y"



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
    INDENT--;
    codegen("L_loop_exit:\n");
    INDENT++;
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
        printf("PRINT int\n");
        codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        codegen("swap\n");
        codegen("invokevirtual java/io/PrintStream/print(I)V\n");
    }
    else if(!strcmp(type, "float")){
        printf("PRINT float\n");
        codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        codegen("swap\n");
        codegen("invokevirtual java/io/PrintStream/print(F)V\n");
    }
    else if(!strcmp(type, "TRUE") || !strcmp(type, "FALSE") || !strcmp(type, "bool")){
        compare_level++;        
        codegen("ifne L_cmp_%d\n",compare_level);
        codegen("ldc \"false\"\n");        
        codegen("goto L_cmp_%d\n",compare_level+1);

        INDENT--;
        codegen("L_cmp_%d:\n",compare_level);
        INDENT++;        
        codegen("ldc \"true\"\n");        
        
        INDENT--;
        codegen("L_cmp_%d:\n",compare_level+1);
        INDENT++;
        codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        codegen("swap\n");
        codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n\n");
        
        compare_level++;
        if(while_state || for_state || if_state){
            compare_level = compare_level - 2;    
        }
        
        
    }
    else if(!strcmp(type, "string")){
        printf("PRINT string\n");
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
        /* newline = false; */
        
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
