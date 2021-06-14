.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
	ldc 0 
	istore 0
	ldc 1
	istore 1
L_while_cmp_1:
	iload 1
	ldc 9
	isub 
	ifle L_cmp_1
	iconst_0
	goto L_while_end_1
L_cmp_1:
	iload 0
	ldc 1
	istore 0
L_while_cmp_2:
	iload 0
	ldc 9
	isub 
	ifle L_cmp_2
	iconst_0
	goto L_while_end_2
L_cmp_2:
	iload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "*" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "=" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 1
	iload 0
	imul 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 0
	iload 0
	ldc 1
	iadd 
	istore 0
	goto L_while_cmp_2
L_while_end_2:
	ldc "\n" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 1
	iload 1
	ldc 1
	iadd 
	istore 1
	goto L_while_cmp_1
L_while_end_1:
L_loop_exit:
L_loop_exit:
	return
.end method
