	call	clock_gettime@PLT
	movl	$0, -88(%rbp)
	jmp	.L2
.L9:
	movl	$0, -80(%rbp)
	movl	$0, -76(%rbp)
	movl	$0, -84(%rbp)
	jmp	.L3
.L4:
	movl	-84(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	s(%rip), %rax
	movl	(%rdx,%rax), %eax
	leal	(%rax,%rax), %edx
	movl	-88(%rbp), %eax
	addl	%edx, %eax
	addl	%eax, -80(%rbp)
	addl	$1, -84(%rbp)
.L3:
	movl	-84(%rbp), %eax
	cmpl	-68(%rbp), %eax
	jl	.L4
	movl	$0, -84(%rbp)
	jmp	.L5
.L6:
	movl	-84(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	4+s(%rip), %rax
	movl	(%rdx,%rax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	-88(%rbp), %eax
	addl	%eax, -76(%rbp)
	addl	$1, -84(%rbp)
.L5:
	movl	-84(%rbp), %eax
	cmpl	-68(%rbp), %eax
	jl	.L6
	movl	-80(%rbp), %eax
	cmpl	-76(%rbp), %eax
	jge	.L7
	movl	-88(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rax, %rdx
	movl	-80(%rbp), %eax
	movl	%eax, (%rdx)
	jmp	.L8
.L7:
	movl	-88(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rax, %rdx
	movl	-76(%rbp), %eax
	movl	%eax, (%rdx)
.L8:
	addl	$1, -88(%rbp)
.L2:
	movl	-88(%rbp), %eax
	cmpl	-72(%rbp), %eax
	jl	.L9
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
