	.file	"support.bc"
	.text
	.globl	print_int
	.align	16, 0x90
	.type	print_int,@function
print_int:                              # @print_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp2:
	.cfi_def_cfa_offset 16
.Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, %rax
	movq	%rax, -8(%rbp)
	movl	$.L.str, %edi
	movq	%rax, %rsi
	xorb	%al, %al
	callq	printf
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp5:
	.size	print_int, .Ltmp5-print_int
	.cfi_endproc

	.globl	print_float
	.align	16, 0x90
	.type	print_float,@function
print_float:                            # @print_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp8:
	.cfi_def_cfa_offset 16
.Ltmp9:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp10:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movss	%xmm0, -4(%rbp)
	movss	-4(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	$.L.str1, %edi
	movb	$1, %al
	callq	printf
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp11:
	.size	print_float, .Ltmp11-print_float
	.cfi_endproc

	.globl	print_char
	.align	16, 0x90
	.type	print_char,@function
print_char:                             # @print_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp14:
	.cfi_def_cfa_offset 16
.Ltmp15:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp16:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movb	%dil, -1(%rbp)
	movsbl	-1(%rbp), %esi
	movl	$.L.str2, %edi
	xorb	%al, %al
	callq	printf
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp17:
	.size	print_char, .Ltmp17-print_char
	.cfi_endproc

	.globl	print_bool
	.align	16, 0x90
	.type	print_bool,@function
print_bool:                             # @print_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp20:
	.cfi_def_cfa_offset 16
.Ltmp21:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp22:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movb	%dil, -1(%rbp)
	movl	$.L.str4, %eax
	movl	$.L.str5, %esi
	testb	%dil, %dil
	cmovneq	%rax, %rsi
	movl	$.L.str3, %edi
	xorb	%al, %al
	callq	printf
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp23:
	.size	print_bool, .Ltmp23-print_bool
	.cfi_endproc

	.globl	print_string
	.align	16, 0x90
	.type	print_string,@function
print_string:                           # @print_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp26:
	.cfi_def_cfa_offset 16
.Ltmp27:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp28:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, %rax
	movq	%rax, -8(%rbp)
	movl	$.L.str6, %edi
	movq	%rax, %rsi
	xorb	%al, %al
	callq	printf
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp29:
	.size	print_string, .Ltmp29-print_string
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "%ld\n"
	.size	.L.str, 5

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "%f\n"
	.size	.L.str1, 4

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	 "%c\n"
	.size	.L.str2, 4

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	 "%s\n"
	.size	.L.str3, 4

	.type	.L.str4,@object         # @.str4
.L.str4:
	.asciz	 "true"
	.size	.L.str4, 5

	.type	.L.str5,@object         # @.str5
.L.str5:
	.asciz	 "false"
	.size	.L.str5, 6

	.type	.L.str6,@object         # @.str6
.L.str6:
	.asciz	 "String id : %zu\n"
	.size	.L.str6, 17


	.section	".note.GNU-stack","",@progbits
