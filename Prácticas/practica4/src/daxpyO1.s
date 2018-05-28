	.file	"daxpy.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Falta tamanio"
.LC5:
	.string	"\nTiempo (seg): %11.9f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB41:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$56, %rsp
	.cfi_def_cfa_offset 96
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	cmpl	$2, %edi
	jne	.L14
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol@PLT
	movq	%rax, %r13
	movslq	%eax, %rbx
	salq	$2, %rbx
	movq	%rbx, %rdi
	call	malloc@PLT
	movq	%rax, %r12
	movq	%rbx, %rdi
	call	malloc@PLT
	movq	%rax, %rbp
	testl	%r13d, %r13d
	jle	.L3
	leal	-1(%r13), %eax
	leaq	4(,%rax,4), %rax
	movl	$0, %ebx
	movss	.LC1(%rip), %xmm1
	movss	.LC2(%rip), %xmm0
.L4:
	movss	%xmm1, (%r12,%rbx)
	movss	%xmm0, 0(%rbp,%rbx)
	addq	$4, %rbx
	cmpq	%rax, %rbx
	jne	.L4
	movq	%rsp, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movl	$0, %eax
	movss	.LC3(%rip), %xmm1
.L6:
	movaps	%xmm1, %xmm0
	mulss	(%r12,%rax), %xmm0
	addss	0(%rbp,%rax), %xmm0
	movss	%xmm0, 0(%rbp,%rax)
	addq	$4, %rax
	cmpq	%rbx, %rax
	jne	.L6
.L7:
	leaq	16(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC4(%rip), %xmm0
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	addsd	%xmm1, %xmm0
	leaq	.LC5(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	movq	%r12, %rdi
	call	free@PLT
	movq	%rbp, %rdi
	call	free@PLT
	movl	$0, %eax
	movq	40(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L15
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L14:
	.cfi_restore_state
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$-1, %edi
	call	exit@PLT
.L3:
	movq	%rsp, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	jmp	.L7
.L15:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE41:
	.size	main, .-main
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC1:
	.long	1102646527
	.align 4
.LC2:
	.long	1113206176
	.align 4
.LC3:
	.long	1084551499
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC4:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
