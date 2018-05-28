	call	clock_gettime@PLT
	xorl	%eax, %eax
	movss	.LC3(%rip), %xmm1
.L5:
	cmpl	%eax, %r12d
	jle	.L11
	movss	(%rbx,%rax,4), %xmm0
	mulss	%xmm1, %xmm0
	addss	0(%rbp,%rax,4), %xmm0
	movss	%xmm0, 0(%rbp,%rax,4)
	incq	%rax
	jmp	.L5
.L11:
	leaq	24(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
