	.text
	.file	"fibonacci.bc"
	.globl	ghty
	.align	16, 0x90
	.type	ghty,@function
ghty:                                   # @ghty
	.cfi_startproc
# BB#0:
	imull	%edi, %edi
	movl	%edi, %eax
	retq
.Ltmp0:
	.size	ghty, .Ltmp0-ghty
	.cfi_endproc

	.globl	map_array
	.align	16, 0x90
	.type	map_array,@function
map_array:                              # @map_array
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp1:
	.cfi_def_cfa_offset 16
	pushq	%r15
.Ltmp2:
	.cfi_def_cfa_offset 24
	pushq	%r14
.Ltmp3:
	.cfi_def_cfa_offset 32
	pushq	%rbx
.Ltmp4:
	.cfi_def_cfa_offset 40
	pushq	%rax
.Ltmp5:
	.cfi_def_cfa_offset 48
.Ltmp6:
	.cfi_offset %rbx, -40
.Ltmp7:
	.cfi_offset %r14, -32
.Ltmp8:
	.cfi_offset %r15, -24
.Ltmp9:
	.cfi_offset %rbp, -16
	movl	%esi, %r14d
	movq	%rdi, %r15
	decl	%r14d
	movl	$-1, %ebp
	.align	16, 0x90
.LBB1_1:                                # %loop
                                        # =>This Inner Loop Header: Depth=1
	incl	%ebp
	movslq	%ebp, %rbx
	movl	(%r15,%rbx,4), %edi
	callq	ghty
	movl	%eax, (%r15,%rbx,4)
	cmpl	%r14d, %ebx
	ja	.LBB1_1
# BB#2:                                 # %if_false
	addq	$8, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Ltmp10:
	.size	map_array, .Ltmp10-map_array
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	subq	$40, %rsp
.Ltmp11:
	.cfi_def_cfa_offset 48
	movl	$0, 36(%rsp)
	movl	%edi, 32(%rsp)
	movq	%rsi, 24(%rsp)
	movabsq	$21474836486, %rax      # imm = 0x500000006
	movq	%rax, 8(%rsp)
	movabsq	$4294967300, %rax       # imm = 0x100000004
	movq	%rax, 16(%rsp)
	leaq	8(%rsp), %rdi
	movl	$4, %esi
	movl	$ghty, %edx
	callq	map_array
	addq	$40, %rsp
	retq
.Ltmp12:
	.size	main, .Ltmp12-main
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
