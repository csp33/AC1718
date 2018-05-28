	call	clock_gettime@PLT
	movq	%rbp, %rdx
	shrq	$2, %rdx
	negq	%rdx
	andl	$3, %edx
	leal	3(%rdx), %eax
	cmpl	%r14d, %eax
	ja	.L21
	testl	%edx, %edx
	je	.L22
	movss	.LC5(%rip), %xmm0
	cmpl	$1, %edx
	movss	(%r12), %xmm1
	mulss	%xmm0, %xmm1
	addss	0(%rbp), %xmm1
	movss	%xmm1, 0(%rbp)
	je	.L23
	movss	4(%r12), %xmm1
	cmpl	$3, %edx
	mulss	%xmm0, %xmm1
	addss	4(%rbp), %xmm1
	movss	%xmm1, 4(%rbp)
	jne	.L13
	mulss	8(%r12), %xmm0
	movl	$3, %ebx
	addss	8(%rbp), %xmm0
	movss	%xmm0, 8(%rbp)
.L13:
	movl	%r13d, %r8d
	movaps	.LC6(%rip), %xmm1
	subl	%edx, %r8d
	salq	$2, %rdx
	xorl	%eax, %eax
	movl	%r8d, %edi
	leaq	(%r12,%rdx), %rsi
	xorl	%ecx, %ecx
	shrl	$2, %edi
	addq	%rbp, %rdx
	.p2align 4,,10
	.p2align 3
.L10:
	movups	(%rsi,%rax), %xmm0
	addl	$1, %ecx
	mulps	%xmm1, %xmm0
	addps	(%rdx,%rax), %xmm0
	movaps	%xmm0, (%rdx,%rax)
	addq	$16, %rax
	cmpl	%edi, %ecx
	jb	.L10
	movl	%r8d, %eax
	andl	$-4, %eax
	addl	%eax, %ebx
	cmpl	%eax, %r8d
	je	.L15
.L12:
	movslq	%ebx, %rdx
	movss	.LC5(%rip), %xmm0
	movss	(%r12,%rdx,4), %xmm1
	leaq	0(%rbp,%rdx,4), %rax
	mulss	%xmm0, %xmm1
	addss	(%rax), %xmm1
	movss	%xmm1, (%rax)
	leal	1(%rbx), %eax
	cmpl	%r13d, %eax
	jge	.L15
	cltq
	movss	(%r12,%rax,4), %xmm1
	leaq	0(%rbp,%rax,4), %rdx
	leal	2(%rbx), %eax
	mulss	%xmm0, %xmm1
	cmpl	%r13d, %eax
	addss	(%rdx), %xmm1
	movss	%xmm1, (%rdx)
	jge	.L15
	cltq
	movss	(%r12,%rax,4), %xmm1
	leaq	0(%rbp,%rax,4), %rdx
	leal	3(%rbx), %eax
	mulss	%xmm0, %xmm1
	cmpl	%eax, %r13d
	addss	(%rdx), %xmm1
	movss	%xmm1, (%rdx)
	jle	.L15
	cltq
	addl	$4, %ebx
	movss	(%r12,%rax,4), %xmm1
	leaq	0(%rbp,%rax,4), %rdx
	cmpl	%ebx, %r13d
	mulss	%xmm0, %xmm1
	addss	(%rdx), %xmm1
	movss	%xmm1, (%rdx)
	jle	.L15
	movslq	%ebx, %rbx
	mulss	(%r12,%rbx,4), %xmm0
	leaq	0(%rbp,%rbx,4), %rax
	addss	(%rax), %xmm0
	movss	%xmm0, (%rax)
.L15:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
