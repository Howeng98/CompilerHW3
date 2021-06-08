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
	isub 
	ifeq L_cmp_1
	iconst_0
	goto L_cmp_2
L_cmp_1:
	iconst_1
L_cmp_2:
	ldc "Hello" 
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	return
.end method
