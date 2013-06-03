	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movl	$0, -12(%rbp)
	movl	$5, -48(%rbp)
	movl	-48(%rbp), %ecx
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rax
	movl	%ecx, -52(%rbp)         ## 4-byte Spill
	jne	LBB0_2
## BB#1:                                ## %SP_return
	movl	-52(%rbp), %eax         ## 4-byte Reload
	addq	$64, %rsp
	popq	%rbp
	ret
LBB0_2:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc


.subsections_via_symbols
