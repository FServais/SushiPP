	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 14, 3
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:                                ## %entry
	movl	$0, -4(%rsp)
	movl	$4, -8(%rsp)
	movl	$8, -12(%rsp)
	xorl	%eax, %eax
	retq
	.cfi_endproc


.subsections_via_symbols
