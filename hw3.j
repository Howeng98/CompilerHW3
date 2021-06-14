.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
	ldc 0 
	istore 0
	iload 0
	ldc 0
	istore 0
FOR_cmp_0:
	iload 0
	ldc 10
	isub 
	iflt L_cmp_0
	iconst_0 
	goto L_loop_exit
FOR_cmp2_0:
	iload 0
	iload 0
	ldc 1
	iadd 
	istore 0
	goto FOR_cmp_0
L_cmp_0:
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	goto FOR_cmp2_0
L_loop_exit:
	ldc "\n" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 0
	ldc 1
	istore 0
L_while_cmp_1:
	iload 0
	ldc 0
	isub 
	ifgt L_cmp_1
	iconst_0
	goto L_loop_exit
L_cmp_1:
	iconst_1
	goto L_cmp_1
	iload 0
	ldc 1
	isub 
	istore 0
	ldc 3
	newarray int
	astore 1
	aload 1
	ldc 0
	ldc 1
	ldc 21
	iadd 
	iastore 
	aload 1
	ldc 1
	aload 1
	ldc 0
	iaload 
	ldc 1
	isub 
	iastore 
	aload 1
	ldc 2
	aload 1
	ldc 1
	iaload 
	ldc 3
	idiv 
	iastore 
	aload 1
	ldc 2
	iaload 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\n" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 3
	ldc 4
	ldc 5
	ldc 8
	ineg 
	iadd 
	imul 
	isub 
	ldc 10
	ldc 7
	idiv 
	isub 
	ldc 4
	ineg 
	ldc 3
	irem 
	isub 
	ifgt L_cmp_1
	iconst_0
	goto L_while_end_1
L_cmp_1:
	iconst_1 
	iconst_1 
	ixor 
	iconst_0 
	iconst_1 
	ixor 
	iconst_1 
	ixor 
	iand
	ior
	ifne L_cmp_2
	ldc "false"
	goto L_cmp_3
L_cmp_2:
	ldc "true"
L_cmp_3:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

	ldc "\n" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 3
	newarray float
	astore 2
	aload 2
	ldc 0
	ldc 1.100000
	ldc 2.100000
	fadd 
	fastore 
	aload 2
	ldc 0
	faload 
	f2i 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\n" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	goto L_while_cmp_1
L_while_end_1:
	ldc 0 
	istore 3
	iload 3
	ldc 10
	iadd 
	istore 3
L_while_cmp_2:
	iload 3
	ldc 0
	isub 
	ifgt L_cmp_2
	iconst_0
	goto L_while_end_2
L_cmp_2:
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	ldc 1
	isub 
	istore 3
L_if_cmp_3:
	iload 3
	ldc 0
	ldc 3.140000
	fstore 4
	fload 4
	f2i 
	iload 3
	iadd 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	goto L_loop_exit
L_if_end_3:
	ldc 6.600000
	fstore 5
	ldc "If x == " 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	fload 5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(F)V
	goto L_while_cmp_3
L_while_end_3:
	ldc 1
	istore 6
L_while_cmp_3:
	iload 6
	ldc 3
	isub 
	ifle L_cmp_3
	iconst_0
	goto L_if_end_3
L_cmp_3:
	ifle L_cmp_3
	iconst_0
	goto L_while_end_3
L_cmp_3:
	ldc "\t" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "*" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "=" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	iload 6
	imul 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 6
	iload 6
	ldc 1
	iadd 
	istore 6
	goto L_while_cmp_3
L_while_end_3:
	ldc "\n" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
L_loop_exit:
L_loop_exit:
	return
.end method
