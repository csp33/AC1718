	call	clock_gettime@PLT
	movl	$0, -124(%rbp)
	jmp	.L11
.L16:
	movl	$0, -120(%rbp)
	jmp	.L12
.L15:
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -104(%rbp)
	movl	$0, -116(%rbp)
	jmp	.L13
.L14:
	movl	-124(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-96(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-116(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movsd	(%rax), %xmm1
	movl	-116(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-120(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movsd	(%rax), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-104(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -104(%rbp)
	addl	$1, -116(%rbp)
.L13:
	movl	-116(%rbp), %eax
	cmpl	-108(%rbp), %eax
	jl	.L14
	movl	-124(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-120(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movsd	-104(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	addl	$1, -120(%rbp)
.L12:
	movl	-120(%rbp), %eax
	cmpl	-108(%rbp), %eax
	jl	.L15
	addl	$1, -124(%rbp)
.L11:
	movl	-124(%rbp), %eax
	cmpl	-108(%rbp), %eax
	jl	.L16
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
