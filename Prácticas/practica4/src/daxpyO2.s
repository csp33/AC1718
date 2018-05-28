	call	clock_gettime@PLT
	xorl	%eax, %eax
	movss	.LC3(%rip), %xmm1
	.p2align 4,,10
	.p2align 3
.L6:
	movss	(%r12,%rax), %xmm0
	mulss	%xmm1, %xmm0
	addss	0(%rbp,%rax), %xmm0
	movss	%xmm0, 0(%rbp,%rax)
	addq	$4, %rax
	cmpq	%rax, %rbx
	jne	.L6
.L7:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
