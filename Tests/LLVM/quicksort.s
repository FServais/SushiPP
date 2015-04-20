	.text
	.file	"quicksort.bc"
	.globl	"array-swap"
	.align	16, 0x90
	.type	"array-swap",@function
"array-swap":                           # @array-swap
	.cfi_startproc
# BB#0:
	movslq	%esi, %rax
	movl	(%rdi,%rax,4), %ecx
	movslq	%edx, %rdx
	movl	(%rdi,%rdx,4), %esi
	movl	%esi, (%rdi,%rax,4)
	movl	%ecx, (%rdi,%rdx,4)
	retq
.Ltmp0:
	.size	"array-swap", .Ltmp0-"array-swap"
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
