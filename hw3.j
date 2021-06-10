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
	goto FOR_cmp_-2
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
L_while_cmp_0:
	iload 0
	ldc 0
	isub 
	ifgt L_cmp_1
	iconst_0
	goto L_loop_exit
L_cmp_1:
	iconst_1
	goto L_cmp_2
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
L_loop_exit:
	return
.end method
