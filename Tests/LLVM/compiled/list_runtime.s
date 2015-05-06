	.file	"list_runtime.bc"
	.text
	.globl	create_list_table
	.align	16, 0x90
	.type	create_list_table,@function
create_list_table:                      # @create_list_table
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
	movl	$8, %edi
	callq	malloc
	movq	%rax, -8(%rbp)
	testq	%rax, %rax
	je	.LBB0_2
# BB#1:                                 # %if.end
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	ret
.LBB0_2:                                # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp5:
	.size	create_list_table, .Ltmp5-create_list_table
	.cfi_endproc

	.globl	delete_list_table
	.align	16, 0x90
	.type	delete_list_table,@function
delete_list_table:                      # @delete_list_table
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
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	testq	%rdi, %rdi
	je	.LBB1_5
# BB#1:                                 # %if.end
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	jmp	.LBB1_2
	.align	16, 0x90
.LBB1_3:                                # %while.body
                                        #   in Loop: Header=BB1_2 Depth=1
	movq	-16(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rdi
	callq	free_descriptor
	movq	-24(%rbp), %rax
.LBB1_2:                                # %if.end
                                        # =>This Inner Loop Header: Depth=1
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.LBB1_3
# BB#4:                                 # %while.end
	movq	-8(%rbp), %rdi
	callq	free
.LBB1_5:                                # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp11:
	.size	delete_list_table, .Ltmp11-delete_list_table
	.cfi_endproc

	.align	16, 0x90
	.type	free_descriptor,@function
free_descriptor:                        # @free_descriptor
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
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	(%rdi), %rax
	jmp	.LBB2_1
	.align	16, 0x90
.LBB2_2:                                # %while.body
                                        #   in Loop: Header=BB2_1 Depth=1
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rdi
	callq	free_node
	movq	-24(%rbp), %rax
.LBB2_1:                                # %entry
                                        # =>This Inner Loop Header: Depth=1
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.LBB2_2
# BB#3:                                 # %while.end
	movq	-8(%rbp), %rdi
	callq	free
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp17:
	.size	free_descriptor, .Ltmp17-free_descriptor
	.cfi_endproc

	.globl	list_size
	.align	16, 0x90
	.type	list_size,@function
list_size:                              # @list_size
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
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB3_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB3_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB3_5
.LBB3_1:                                # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB3_5
.LBB3_3:                                # %if.then2
	movq	$0, -8(%rbp)
.LBB3_5:                                # %return
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp23:
	.size	list_size, .Ltmp23-list_size
	.cfi_endproc

	.align	16, 0x90
	.type	find_descriptor,@function
find_descriptor:                        # @find_descriptor
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
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	jmp	.LBB4_1
	.align	16, 0x90
.LBB4_4:                                # %if.end
                                        #   in Loop: Header=BB4_1 Depth=1
	movq	-32(%rbp), %rax
	movq	48(%rax), %rax
.LBB4_1:                                # %entry
                                        # =>This Inner Loop Header: Depth=1
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	je	.LBB4_5
# BB#2:                                 # %while.body
                                        #   in Loop: Header=BB4_1 Depth=1
	movq	-32(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	-24(%rbp), %rax
	jne	.LBB4_4
# BB#3:                                 # %if.then
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB4_6
.LBB4_5:                                # %while.end
	movq	$0, -8(%rbp)
.LBB4_6:                                # %return
	movq	-8(%rbp), %rax
	popq	%rbp
	ret
.Ltmp29:
	.size	find_descriptor, .Ltmp29-find_descriptor
	.cfi_endproc

	.globl	list_empty
	.align	16, 0x90
	.type	list_empty,@function
list_empty:                             # @list_empty
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp32:
	.cfi_def_cfa_offset 16
.Ltmp33:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp34:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	callq	list_size
	testq	%rax, %rax
	sete	%al
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp35:
	.size	list_empty, .Ltmp35-list_empty
	.cfi_endproc

	.globl	list_clear
	.align	16, 0x90
	.type	list_clear,@function
list_clear:                             # @list_clear
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp38:
	.cfi_def_cfa_offset 16
.Ltmp39:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp40:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB6_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -24(%rbp)
	testq	%rax, %rax
	je	.LBB6_4
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rax
	cmpq	$0, (%rax)
	je	.LBB6_4
# BB#3:                                 # %if.end6
	movq	-24(%rbp), %rax
	movq	(%rax), %rdi
	callq	free_node_recur
	movq	-24(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-24(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-24(%rbp), %rax
	movq	$0, 24(%rax)
.LBB6_4:                                # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp41:
	.size	list_clear, .Ltmp41-list_clear
	.cfi_endproc

	.align	16, 0x90
	.type	free_node_recur,@function
free_node_recur:                        # @free_node_recur
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp44:
	.cfi_def_cfa_offset 16
.Ltmp45:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp46:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	16(%rdi), %rax
	movq	%rax, -16(%rbp)
	testq	%rax, %rax
	je	.LBB7_2
# BB#1:                                 # %if.then
	movq	-16(%rbp), %rax
	movq	$0, 8(%rax)
	jmp	.LBB7_2
	.align	16, 0x90
.LBB7_3:                                # %while.body
                                        #   in Loop: Header=BB7_2 Depth=1
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rdi
	callq	free_node
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB7_2:                                # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	jne	.LBB7_3
# BB#4:                                 # %while.end
	movq	-16(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp47:
	.size	free_node_recur, .Ltmp47-free_node_recur
	.cfi_endproc

	.globl	list_add_reference
	.align	16, 0x90
	.type	list_add_reference,@function
list_add_reference:                     # @list_add_reference
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp50:
	.cfi_def_cfa_offset 16
.Ltmp51:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp52:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB8_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -24(%rbp)
	testq	%rax, %rax
	je	.LBB8_3
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rax
	incq	32(%rax)
.LBB8_3:                                # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp53:
	.size	list_add_reference, .Ltmp53-list_add_reference
	.cfi_endproc

	.globl	list_rm_reference
	.align	16, 0x90
	.type	list_rm_reference,@function
list_rm_reference:                      # @list_rm_reference
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp56:
	.cfi_def_cfa_offset 16
.Ltmp57:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp58:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB9_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -24(%rbp)
	testq	%rax, %rax
	je	.LBB9_4
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rax
	decq	32(%rax)
	movq	-24(%rbp), %rax
	cmpq	$0, 32(%rax)
	jne	.LBB9_4
# BB#3:                                 # %if.then5
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	list_deallocate
.LBB9_4:                                # %if.end6
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp59:
	.size	list_rm_reference, .Ltmp59-list_rm_reference
	.cfi_endproc

	.globl	list_deallocate
	.align	16, 0x90
	.type	list_deallocate,@function
list_deallocate:                        # @list_deallocate
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp62:
	.cfi_def_cfa_offset 16
.Ltmp63:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp64:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB10_8
# BB#1:                                 # %if.end
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	$0, -32(%rbp)
	jmp	.LBB10_2
	.align	16, 0x90
.LBB10_9:                               # %if.end9
                                        #   in Loop: Header=BB10_2 Depth=1
	movq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -24(%rbp)
.LBB10_2:                               # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpq	$0, -24(%rbp)
	je	.LBB10_8
# BB#3:                                 # %while.body
                                        #   in Loop: Header=BB10_2 Depth=1
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	-16(%rbp), %rax
	jne	.LBB10_9
# BB#4:                                 # %if.then2
	cmpq	$0, -32(%rbp)
	je	.LBB10_6
# BB#5:                                 # %if.then4
	movq	-24(%rbp), %rax
	movq	48(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rax, 48(%rcx)
	jmp	.LBB10_7
.LBB10_6:                               # %if.else
	movq	-24(%rbp), %rax
	movq	48(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
.LBB10_7:                               # %if.end8
	movq	-24(%rbp), %rdi
	callq	free_descriptor
.LBB10_8:                               # %while.end
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp65:
	.size	list_deallocate, .Ltmp65-list_deallocate
	.cfi_endproc

	.globl	list_allocate_int
	.align	16, 0x90
	.type	list_allocate_int,@function
list_allocate_int:                      # @list_allocate_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp68:
	.cfi_def_cfa_offset 16
.Ltmp69:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp70:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	testq	%rdi, %rdi
	je	.LBB11_1
# BB#2:                                 # %if.end
	callq	unique_desc_id
	movq	%rax, %rdi
	xorl	%esi, %esi
	callq	create_descriptor
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB11_3
.LBB11_1:                               # %if.then
	movq	$0, -8(%rbp)
.LBB11_3:                               # %return
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp71:
	.size	list_allocate_int, .Ltmp71-list_allocate_int
	.cfi_endproc

	.align	16, 0x90
	.type	create_descriptor,@function
create_descriptor:                      # @create_descriptor
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp74:
	.cfi_def_cfa_offset 16
.Ltmp75:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp76:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$56, %edi
	callq	malloc
	movq	%rax, -24(%rbp)
	testq	%rax, %rax
	je	.LBB12_2
# BB#1:                                 # %if.end
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	%rcx, 16(%rax)
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	%rcx, 40(%rax)
	movq	-24(%rbp), %rax
	movq	$0, 24(%rax)
	movq	-24(%rbp), %rax
	movq	$0, 32(%rax)
	movq	-24(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-24(%rbp), %rax
	movq	$0, (%rax)
	movq	-24(%rbp), %rax
	movq	$0, 48(%rax)
	movq	-24(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.LBB12_2:                               # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str6, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp77:
	.size	create_descriptor, .Ltmp77-create_descriptor
	.cfi_endproc

	.align	16, 0x90
	.type	insert_descriptor,@function
insert_descriptor:                      # @insert_descriptor
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp80:
	.cfi_def_cfa_offset 16
.Ltmp81:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp82:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, 48(%rsi)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	%rcx, (%rax)
	popq	%rbp
	ret
.Ltmp83:
	.size	insert_descriptor, .Ltmp83-insert_descriptor
	.cfi_endproc

	.globl	list_allocate_float
	.align	16, 0x90
	.type	list_allocate_float,@function
list_allocate_float:                    # @list_allocate_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp86:
	.cfi_def_cfa_offset 16
.Ltmp87:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp88:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	testq	%rdi, %rdi
	je	.LBB14_1
# BB#2:                                 # %if.end
	callq	unique_desc_id
	movq	%rax, %rdi
	movl	$1, %esi
	callq	create_descriptor
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB14_3
.LBB14_1:                               # %if.then
	movq	$0, -8(%rbp)
.LBB14_3:                               # %return
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp89:
	.size	list_allocate_float, .Ltmp89-list_allocate_float
	.cfi_endproc

	.globl	list_allocate_bool
	.align	16, 0x90
	.type	list_allocate_bool,@function
list_allocate_bool:                     # @list_allocate_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp92:
	.cfi_def_cfa_offset 16
.Ltmp93:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp94:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	testq	%rdi, %rdi
	je	.LBB15_1
# BB#2:                                 # %if.end
	callq	unique_desc_id
	movq	%rax, %rdi
	movl	$2, %esi
	callq	create_descriptor
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB15_3
.LBB15_1:                               # %if.then
	movq	$0, -8(%rbp)
.LBB15_3:                               # %return
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp95:
	.size	list_allocate_bool, .Ltmp95-list_allocate_bool
	.cfi_endproc

	.globl	list_allocate_char
	.align	16, 0x90
	.type	list_allocate_char,@function
list_allocate_char:                     # @list_allocate_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp98:
	.cfi_def_cfa_offset 16
.Ltmp99:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp100:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	testq	%rdi, %rdi
	je	.LBB16_1
# BB#2:                                 # %if.end
	callq	unique_desc_id
	movq	%rax, %rdi
	movl	$3, %esi
	callq	create_descriptor
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB16_3
.LBB16_1:                               # %if.then
	movq	$0, -8(%rbp)
.LBB16_3:                               # %return
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp101:
	.size	list_allocate_char, .Ltmp101-list_allocate_char
	.cfi_endproc

	.globl	list_allocate_string
	.align	16, 0x90
	.type	list_allocate_string,@function
list_allocate_string:                   # @list_allocate_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp104:
	.cfi_def_cfa_offset 16
.Ltmp105:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp106:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	testq	%rdi, %rdi
	je	.LBB17_1
# BB#2:                                 # %if.end
	callq	unique_desc_id
	movq	%rax, %rdi
	movl	$4, %esi
	callq	create_descriptor
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB17_3
.LBB17_1:                               # %if.then
	movq	$0, -8(%rbp)
.LBB17_3:                               # %return
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp107:
	.size	list_allocate_string, .Ltmp107-list_allocate_string
	.cfi_endproc

	.globl	list_front_int
	.align	16, 0x90
	.type	list_front_int,@function
list_front_int:                         # @list_front_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp110:
	.cfi_def_cfa_offset 16
.Ltmp111:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp112:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB18_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB18_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB18_5
.LBB18_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB18_5
.LBB18_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB18_5:                               # %return
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp113:
	.size	list_front_int, .Ltmp113-list_front_int
	.cfi_endproc

	.align	16, 0x90
	.type	get_list_element,@function
get_list_element:                       # @get_list_element
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp116:
	.cfi_def_cfa_offset 16
.Ltmp117:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp118:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rax
	cmpq	24(%rax), %rsi
	jae	.LBB19_8
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	$0, -40(%rbp)
	jmp	.LBB19_2
	.align	16, 0x90
.LBB19_5:                               # %if.end3
                                        #   in Loop: Header=BB19_2 Depth=1
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
.LBB19_2:                               # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpq	$0, -32(%rbp)
	je	.LBB19_6
# BB#3:                                 # %while.body
                                        #   in Loop: Header=BB19_2 Depth=1
	movq	-40(%rbp), %rax
	leaq	1(%rax), %rcx
	movq	%rcx, -40(%rbp)
	cmpq	-24(%rbp), %rax
	jne	.LBB19_5
# BB#4:                                 # %if.then2
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB19_7
.LBB19_6:                               # %while.end
	movq	$0, -8(%rbp)
.LBB19_7:                               # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.LBB19_8:                               # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str5, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp119:
	.size	get_list_element, .Ltmp119-get_list_element
	.cfi_endproc

	.globl	list_front_float
	.align	16, 0x90
	.type	list_front_float,@function
list_front_float:                       # @list_front_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp122:
	.cfi_def_cfa_offset 16
.Ltmp123:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp124:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB20_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB20_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movss	(%rax), %xmm0
	movss	%xmm0, -4(%rbp)
	jmp	.LBB20_5
.LBB20_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB20_5
.LBB20_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB20_5:                               # %return
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp125:
	.size	list_front_float, .Ltmp125-list_front_float
	.cfi_endproc

	.globl	list_front_bool
	.align	16, 0x90
	.type	list_front_bool,@function
list_front_bool:                        # @list_front_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp128:
	.cfi_def_cfa_offset 16
.Ltmp129:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp130:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB21_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB21_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movb	(%rax), %al
	andb	$1, %al
	movb	%al, -1(%rbp)
	jmp	.LBB21_5
.LBB21_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB21_5
.LBB21_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB21_5:                               # %return
	movb	-1(%rbp), %al
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp131:
	.size	list_front_bool, .Ltmp131-list_front_bool
	.cfi_endproc

	.globl	list_front_char
	.align	16, 0x90
	.type	list_front_char,@function
list_front_char:                        # @list_front_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp134:
	.cfi_def_cfa_offset 16
.Ltmp135:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp136:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB22_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB22_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movb	(%rax), %al
	movb	%al, -1(%rbp)
	jmp	.LBB22_5
.LBB22_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB22_5
.LBB22_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB22_5:                               # %return
	movsbl	-1(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp137:
	.size	list_front_char, .Ltmp137-list_front_char
	.cfi_endproc

	.globl	list_front_string
	.align	16, 0x90
	.type	list_front_string,@function
list_front_string:                      # @list_front_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp140:
	.cfi_def_cfa_offset 16
.Ltmp141:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp142:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB23_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB23_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB23_5
.LBB23_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB23_5
.LBB23_3:                               # %if.then2
	movq	$0, -8(%rbp)
.LBB23_5:                               # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp143:
	.size	list_front_string, .Ltmp143-list_front_string
	.cfi_endproc

	.globl	list_back_int
	.align	16, 0x90
	.type	list_back_int,@function
list_back_int:                          # @list_back_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp146:
	.cfi_def_cfa_offset 16
.Ltmp147:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp148:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB24_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB24_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB24_5
.LBB24_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB24_5
.LBB24_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB24_5:                               # %return
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp149:
	.size	list_back_int, .Ltmp149-list_back_int
	.cfi_endproc

	.globl	list_back_float
	.align	16, 0x90
	.type	list_back_float,@function
list_back_float:                        # @list_back_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp152:
	.cfi_def_cfa_offset 16
.Ltmp153:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp154:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB25_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB25_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movss	(%rax), %xmm0
	movss	%xmm0, -4(%rbp)
	jmp	.LBB25_5
.LBB25_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB25_5
.LBB25_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB25_5:                               # %return
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp155:
	.size	list_back_float, .Ltmp155-list_back_float
	.cfi_endproc

	.globl	list_back_bool
	.align	16, 0x90
	.type	list_back_bool,@function
list_back_bool:                         # @list_back_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp158:
	.cfi_def_cfa_offset 16
.Ltmp159:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp160:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB26_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB26_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movb	(%rax), %al
	andb	$1, %al
	movb	%al, -1(%rbp)
	jmp	.LBB26_5
.LBB26_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB26_5
.LBB26_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB26_5:                               # %return
	movb	-1(%rbp), %al
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp161:
	.size	list_back_bool, .Ltmp161-list_back_bool
	.cfi_endproc

	.globl	list_back_char
	.align	16, 0x90
	.type	list_back_char,@function
list_back_char:                         # @list_back_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp164:
	.cfi_def_cfa_offset 16
.Ltmp165:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp166:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB27_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB27_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movb	(%rax), %al
	movb	%al, -1(%rbp)
	jmp	.LBB27_5
.LBB27_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB27_5
.LBB27_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB27_5:                               # %return
	movsbl	-1(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp167:
	.size	list_back_char, .Ltmp167-list_back_char
	.cfi_endproc

	.globl	list_back_string
	.align	16, 0x90
	.type	list_back_string,@function
list_back_string:                       # @list_back_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp170:
	.cfi_def_cfa_offset 16
.Ltmp171:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp172:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB28_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB28_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	get_list_element
	movq	%rax, -40(%rbp)
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB28_5
.LBB28_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB28_5
.LBB28_3:                               # %if.then2
	movq	$0, -8(%rbp)
.LBB28_5:                               # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp173:
	.size	list_back_string, .Ltmp173-list_back_string
	.cfi_endproc

	.globl	list_pop_front_int
	.align	16, 0x90
	.type	list_pop_front_int,@function
list_pop_front_int:                     # @list_pop_front_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp176:
	.cfi_def_cfa_offset 16
.Ltmp177:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp178:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB29_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB29_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movl	(%rax), %eax
	movl	%eax, -44(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movl	-44(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB29_5
.LBB29_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB29_5
.LBB29_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB29_5:                               # %return
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp179:
	.size	list_pop_front_int, .Ltmp179-list_pop_front_int
	.cfi_endproc

	.align	16, 0x90
	.type	remove_list_element,@function
remove_list_element:                    # @remove_list_element
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp182:
	.cfi_def_cfa_offset 16
.Ltmp183:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp184:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rax
	cmpq	24(%rax), %rsi
	jae	.LBB30_17
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	$0, -40(%rbp)
	jmp	.LBB30_2
	.align	16, 0x90
.LBB30_14:                              # %if.end36
                                        #   in Loop: Header=BB30_2 Depth=1
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
.LBB30_2:                               # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpq	$0, -32(%rbp)
	je	.LBB30_15
# BB#3:                                 # %while.body
                                        #   in Loop: Header=BB30_2 Depth=1
	movq	-40(%rbp), %rax
	leaq	1(%rax), %rcx
	movq	%rcx, -40(%rbp)
	cmpq	-24(%rbp), %rax
	jne	.LBB30_14
# BB#4:                                 # %if.then2
	movq	-32(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	.LBB30_8
# BB#5:                                 # %land.lhs.true
	movq	-32(%rbp), %rax
	cmpq	$0, 16(%rax)
	je	.LBB30_8
# BB#6:                                 # %if.then5
	movq	-32(%rbp), %rax
	movq	8(%rax), %rcx
	movq	16(%rax), %rax
	movq	%rcx, 8(%rax)
	jmp	.LBB30_7
.LBB30_15:                              # %while.end
	movq	$0, -8(%rbp)
	jmp	.LBB30_16
.LBB30_8:                               # %if.else
	movq	-32(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	.LBB30_10
# BB#9:                                 # %if.then14
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	-16(%rbp), %rcx
	movq	%rax, (%rcx)
.LBB30_7:                               # %if.then5
	movq	-32(%rbp), %rax
	movq	8(%rax), %rcx
	movq	16(%rax), %rax
	movq	%rax, 16(%rcx)
.LBB30_13:                              # %if.end33
	movq	-16(%rbp), %rax
	movq	40(%rax), %rsi
	movq	-32(%rbp), %rax
	movq	(%rax), %rdi
	callq	cpy_value
	movq	%rax, -48(%rbp)
	movq	-32(%rbp), %rdi
	callq	free_node
	movq	-16(%rbp), %rax
	decq	24(%rax)
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB30_16:                              # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.LBB30_10:                              # %if.else20
	movq	-32(%rbp), %rax
	cmpq	$0, 16(%rax)
	je	.LBB30_12
# BB#11:                                # %if.then23
	movq	-32(%rbp), %rax
	movq	16(%rax), %rax
	movq	-16(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rcx
	movq	16(%rax), %rax
	movq	%rcx, 8(%rax)
	jmp	.LBB30_13
.LBB30_12:                              # %if.else28
	movq	-16(%rbp), %rax
	movq	$0, (%rax)
	movq	-16(%rbp), %rax
	movq	$0, 8(%rax)
	jmp	.LBB30_13
.LBB30_17:                              # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str4, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp185:
	.size	remove_list_element, .Ltmp185-remove_list_element
	.cfi_endproc

	.globl	list_pop_front_float
	.align	16, 0x90
	.type	list_pop_front_float,@function
list_pop_front_float:                   # @list_pop_front_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp188:
	.cfi_def_cfa_offset 16
.Ltmp189:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp190:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB31_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB31_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movss	(%rax), %xmm0
	movss	%xmm0, -44(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movss	-44(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
	jmp	.LBB31_5
.LBB31_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB31_5
.LBB31_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB31_5:                               # %return
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp191:
	.size	list_pop_front_float, .Ltmp191-list_pop_front_float
	.cfi_endproc

	.globl	list_pop_front_bool
	.align	16, 0x90
	.type	list_pop_front_bool,@function
list_pop_front_bool:                    # @list_pop_front_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp194:
	.cfi_def_cfa_offset 16
.Ltmp195:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp196:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB32_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB32_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movb	(%rax), %al
	andb	$1, %al
	movb	%al, -41(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movb	-41(%rbp), %al
	andb	$1, %al
	movb	%al, -1(%rbp)
	jmp	.LBB32_5
.LBB32_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB32_5
.LBB32_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB32_5:                               # %return
	movb	-1(%rbp), %al
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp197:
	.size	list_pop_front_bool, .Ltmp197-list_pop_front_bool
	.cfi_endproc

	.globl	list_pop_front_char
	.align	16, 0x90
	.type	list_pop_front_char,@function
list_pop_front_char:                    # @list_pop_front_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp200:
	.cfi_def_cfa_offset 16
.Ltmp201:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp202:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB33_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB33_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movb	(%rax), %al
	movb	%al, -41(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movb	-41(%rbp), %al
	movb	%al, -1(%rbp)
	jmp	.LBB33_5
.LBB33_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB33_5
.LBB33_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB33_5:                               # %return
	movsbl	-1(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp203:
	.size	list_pop_front_char, .Ltmp203-list_pop_front_char
	.cfi_endproc

	.globl	list_pop_front_string
	.align	16, 0x90
	.type	list_pop_front_string,@function
list_pop_front_string:                  # @list_pop_front_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp206:
	.cfi_def_cfa_offset 16
.Ltmp207:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp208:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB34_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB34_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	xorl	%esi, %esi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movq	(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB34_5
.LBB34_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB34_5
.LBB34_3:                               # %if.then2
	movq	$0, -8(%rbp)
.LBB34_5:                               # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp209:
	.size	list_pop_front_string, .Ltmp209-list_pop_front_string
	.cfi_endproc

	.globl	list_pop_back_int
	.align	16, 0x90
	.type	list_pop_back_int,@function
list_pop_back_int:                      # @list_pop_back_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp212:
	.cfi_def_cfa_offset 16
.Ltmp213:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp214:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB35_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB35_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movl	(%rax), %eax
	movl	%eax, -44(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movl	-44(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB35_5
.LBB35_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB35_5
.LBB35_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB35_5:                               # %return
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp215:
	.size	list_pop_back_int, .Ltmp215-list_pop_back_int
	.cfi_endproc

	.globl	list_pop_back_float
	.align	16, 0x90
	.type	list_pop_back_float,@function
list_pop_back_float:                    # @list_pop_back_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp218:
	.cfi_def_cfa_offset 16
.Ltmp219:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp220:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB36_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB36_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movss	(%rax), %xmm0
	movss	%xmm0, -44(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movss	-44(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
	jmp	.LBB36_5
.LBB36_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB36_5
.LBB36_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB36_5:                               # %return
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp221:
	.size	list_pop_back_float, .Ltmp221-list_pop_back_float
	.cfi_endproc

	.globl	list_pop_back_bool
	.align	16, 0x90
	.type	list_pop_back_bool,@function
list_pop_back_bool:                     # @list_pop_back_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp224:
	.cfi_def_cfa_offset 16
.Ltmp225:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp226:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB37_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB37_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movb	(%rax), %al
	andb	$1, %al
	movb	%al, -41(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movb	-41(%rbp), %al
	andb	$1, %al
	movb	%al, -1(%rbp)
	jmp	.LBB37_5
.LBB37_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB37_5
.LBB37_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB37_5:                               # %return
	movb	-1(%rbp), %al
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp227:
	.size	list_pop_back_bool, .Ltmp227-list_pop_back_bool
	.cfi_endproc

	.globl	list_pop_back_char
	.align	16, 0x90
	.type	list_pop_back_char,@function
list_pop_back_char:                     # @list_pop_back_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp230:
	.cfi_def_cfa_offset 16
.Ltmp231:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp232:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB38_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB38_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movb	(%rax), %al
	movb	%al, -41(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movb	-41(%rbp), %al
	movb	%al, -1(%rbp)
	jmp	.LBB38_5
.LBB38_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB38_5
.LBB38_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB38_5:                               # %return
	movsbl	-1(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp233:
	.size	list_pop_back_char, .Ltmp233-list_pop_back_char
	.cfi_endproc

	.globl	list_pop_back_string
	.align	16, 0x90
	.type	list_pop_back_string,@function
list_pop_back_string:                   # @list_pop_back_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp236:
	.cfi_def_cfa_offset 16
.Ltmp237:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp238:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB39_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB39_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	decq	%rsi
	callq	remove_list_element
	movq	%rax, -40(%rbp)
	movq	(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-40(%rbp), %rdi
	callq	free
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB39_5
.LBB39_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB39_5
.LBB39_3:                               # %if.then2
	movq	$0, -8(%rbp)
.LBB39_5:                               # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp239:
	.size	list_pop_back_string, .Ltmp239-list_pop_back_string
	.cfi_endproc

	.globl	list_push_front_int
	.align	16, 0x90
	.type	list_push_front_int,@function
list_push_front_int:                    # @list_push_front_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp242:
	.cfi_def_cfa_offset 16
.Ltmp243:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp244:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB40_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB40_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	leaq	-20(%rbp), %rdx
	xorl	%esi, %esi
	callq	insert_list_element
.LBB40_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp245:
	.size	list_push_front_int, .Ltmp245-list_push_front_int
	.cfi_endproc

	.align	16, 0x90
	.type	insert_list_element,@function
insert_list_element:                    # @insert_list_element
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp248:
	.cfi_def_cfa_offset 16
.Ltmp249:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp250:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	cmpq	24(%rax), %rcx
	ja	.LBB41_17
# BB#1:                                 # %if.end
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	cmpq	24(%rax), %rcx
	jne	.LBB41_6
# BB#2:                                 # %if.then3
	movq	-8(%rbp), %rax
	movq	40(%rax), %rcx
	movq	-24(%rbp), %rdx
	xorl	%edi, %edi
	xorl	%esi, %esi
	callq	create_node
	movq	%rax, -32(%rbp)
	movq	-8(%rbp), %rax
	cmpq	$0, 24(%rax)
	je	.LBB41_3
# BB#4:                                 # %if.else
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, 8(%rax)
	jmp	.LBB41_5
.LBB41_6:                               # %if.end12
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -40(%rbp)
	movq	$0, -48(%rbp)
	jmp	.LBB41_7
	.align	16, 0x90
.LBB41_18:                              # %if.end45
                                        #   in Loop: Header=BB41_7 Depth=1
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
.LBB41_7:                               # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpq	$0, -40(%rbp)
	je	.LBB41_16
# BB#8:                                 # %while.body
                                        #   in Loop: Header=BB41_7 Depth=1
	movq	-48(%rbp), %rax
	leaq	1(%rax), %rcx
	movq	%rcx, -48(%rbp)
	cmpq	-16(%rbp), %rax
	jne	.LBB41_18
# BB#9:                                 # %if.then16
	movq	-8(%rbp), %rax
	movq	40(%rax), %rcx
	movq	-24(%rbp), %rdx
	xorl	%edi, %edi
	xorl	%esi, %esi
	callq	create_node
	movq	%rax, -56(%rbp)
	movq	-40(%rbp), %rax
	cmpq	$0, 16(%rax)
	je	.LBB41_11
# BB#10:                                # %if.then22
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-56(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	-56(%rbp), %rcx
	movq	%rcx, 8(%rax)
	jmp	.LBB41_13
.LBB41_3:                               # %if.then7
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, (%rax)
.LBB41_5:                               # %if.end8
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, 8(%rax)
	jmp	.LBB41_15
.LBB41_11:                              # %if.else29
	movq	-40(%rbp), %rax
	cmpq	$0, 16(%rax)
	je	.LBB41_12
# BB#14:                                # %if.else38
	movq	-8(%rbp), %rcx
	movq	-56(%rbp), %rax
	movq	%rax, (%rcx)
	movq	-8(%rbp), %rcx
	movq	%rax, 8(%rcx)
	jmp	.LBB41_15
.LBB41_12:                              # %if.then32
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	-56(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-56(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rcx, (%rax)
.LBB41_13:                              # %if.then32
	movq	-40(%rbp), %rax
	movq	-56(%rbp), %rcx
	movq	%rcx, 16(%rax)
.LBB41_15:                              # %if.end42
	movq	-8(%rbp), %rax
	incq	24(%rax)
.LBB41_16:                              # %while.end
	addq	$64, %rsp
	popq	%rbp
	ret
.LBB41_17:                              # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str1, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp251:
	.size	insert_list_element, .Ltmp251-insert_list_element
	.cfi_endproc

	.globl	list_push_front_float
	.align	16, 0x90
	.type	list_push_front_float,@function
list_push_front_float:                  # @list_push_front_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp254:
	.cfi_def_cfa_offset 16
.Ltmp255:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp256:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movss	%xmm0, -20(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB42_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB42_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	leaq	-20(%rbp), %rdx
	xorl	%esi, %esi
	callq	insert_list_element
.LBB42_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp257:
	.size	list_push_front_float, .Ltmp257-list_push_front_float
	.cfi_endproc

	.globl	list_push_front_bool
	.align	16, 0x90
	.type	list_push_front_bool,@function
list_push_front_bool:                   # @list_push_front_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp260:
	.cfi_def_cfa_offset 16
.Ltmp261:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp262:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movb	%dl, -17(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB43_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB43_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	leaq	-17(%rbp), %rdx
	xorl	%esi, %esi
	callq	insert_list_element
.LBB43_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp263:
	.size	list_push_front_bool, .Ltmp263-list_push_front_bool
	.cfi_endproc

	.globl	list_push_front_char
	.align	16, 0x90
	.type	list_push_front_char,@function
list_push_front_char:                   # @list_push_front_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp266:
	.cfi_def_cfa_offset 16
.Ltmp267:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp268:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movb	%dl, -17(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB44_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB44_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	leaq	-17(%rbp), %rdx
	xorl	%esi, %esi
	callq	insert_list_element
.LBB44_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp269:
	.size	list_push_front_char, .Ltmp269-list_push_front_char
	.cfi_endproc

	.globl	list_push_front_string
	.align	16, 0x90
	.type	list_push_front_string,@function
list_push_front_string:                 # @list_push_front_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp272:
	.cfi_def_cfa_offset 16
.Ltmp273:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp274:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB45_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB45_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	leaq	-24(%rbp), %rdx
	xorl	%esi, %esi
	callq	insert_list_element
.LBB45_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp275:
	.size	list_push_front_string, .Ltmp275-list_push_front_string
	.cfi_endproc

	.globl	list_push_back_int
	.align	16, 0x90
	.type	list_push_back_int,@function
list_push_back_int:                     # @list_push_back_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp278:
	.cfi_def_cfa_offset 16
.Ltmp279:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp280:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB46_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB46_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	leaq	-20(%rbp), %rdx
	callq	insert_list_element
.LBB46_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp281:
	.size	list_push_back_int, .Ltmp281-list_push_back_int
	.cfi_endproc

	.globl	list_push_back_float
	.align	16, 0x90
	.type	list_push_back_float,@function
list_push_back_float:                   # @list_push_back_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp284:
	.cfi_def_cfa_offset 16
.Ltmp285:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp286:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movss	%xmm0, -20(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB47_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB47_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	leaq	-20(%rbp), %rdx
	callq	insert_list_element
.LBB47_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp287:
	.size	list_push_back_float, .Ltmp287-list_push_back_float
	.cfi_endproc

	.globl	list_push_back_bool
	.align	16, 0x90
	.type	list_push_back_bool,@function
list_push_back_bool:                    # @list_push_back_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp290:
	.cfi_def_cfa_offset 16
.Ltmp291:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp292:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movb	%dl, -17(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB48_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB48_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	leaq	-17(%rbp), %rdx
	callq	insert_list_element
.LBB48_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp293:
	.size	list_push_back_bool, .Ltmp293-list_push_back_bool
	.cfi_endproc

	.globl	list_push_back_char
	.align	16, 0x90
	.type	list_push_back_char,@function
list_push_back_char:                    # @list_push_back_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp296:
	.cfi_def_cfa_offset 16
.Ltmp297:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp298:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movb	%dl, -17(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB49_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB49_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	leaq	-17(%rbp), %rdx
	callq	insert_list_element
.LBB49_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp299:
	.size	list_push_back_char, .Ltmp299-list_push_back_char
	.cfi_endproc

	.globl	list_push_back_string
	.align	16, 0x90
	.type	list_push_back_string,@function
list_push_back_string:                  # @list_push_back_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp302:
	.cfi_def_cfa_offset 16
.Ltmp303:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp304:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB50_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB50_3
# BB#2:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	24(%rdi), %rsi
	leaq	-24(%rbp), %rdx
	callq	insert_list_element
.LBB50_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp305:
	.size	list_push_back_string, .Ltmp305-list_push_back_string
	.cfi_endproc

	.globl	list_get_element_int
	.align	16, 0x90
	.type	list_get_element_int,@function
list_get_element_int:                   # @list_get_element_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp308:
	.cfi_def_cfa_offset 16
.Ltmp309:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp310:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB51_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB51_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	get_list_element
	movq	%rax, -48(%rbp)
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB51_5
.LBB51_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB51_5
.LBB51_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB51_5:                               # %return
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp311:
	.size	list_get_element_int, .Ltmp311-list_get_element_int
	.cfi_endproc

	.globl	list_get_element_float
	.align	16, 0x90
	.type	list_get_element_float,@function
list_get_element_float:                 # @list_get_element_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp314:
	.cfi_def_cfa_offset 16
.Ltmp315:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp316:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB52_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB52_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	get_list_element
	movq	%rax, -48(%rbp)
	movss	(%rax), %xmm0
	movss	%xmm0, -4(%rbp)
	jmp	.LBB52_5
.LBB52_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB52_5
.LBB52_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB52_5:                               # %return
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp317:
	.size	list_get_element_float, .Ltmp317-list_get_element_float
	.cfi_endproc

	.globl	list_get_element_bool
	.align	16, 0x90
	.type	list_get_element_bool,@function
list_get_element_bool:                  # @list_get_element_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp320:
	.cfi_def_cfa_offset 16
.Ltmp321:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp322:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB53_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB53_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	get_list_element
	movq	%rax, -48(%rbp)
	movb	(%rax), %al
	andb	$1, %al
	movb	%al, -1(%rbp)
	jmp	.LBB53_5
.LBB53_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB53_5
.LBB53_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB53_5:                               # %return
	movb	-1(%rbp), %al
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp323:
	.size	list_get_element_bool, .Ltmp323-list_get_element_bool
	.cfi_endproc

	.globl	list_get_element_char
	.align	16, 0x90
	.type	list_get_element_char,@function
list_get_element_char:                  # @list_get_element_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp326:
	.cfi_def_cfa_offset 16
.Ltmp327:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp328:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB54_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB54_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	get_list_element
	movq	%rax, -48(%rbp)
	movb	(%rax), %al
	movb	%al, -1(%rbp)
	jmp	.LBB54_5
.LBB54_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB54_5
.LBB54_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB54_5:                               # %return
	movsbl	-1(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp329:
	.size	list_get_element_char, .Ltmp329-list_get_element_char
	.cfi_endproc

	.globl	list_get_element_string
	.align	16, 0x90
	.type	list_get_element_string,@function
list_get_element_string:                # @list_get_element_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp332:
	.cfi_def_cfa_offset 16
.Ltmp333:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp334:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB55_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB55_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	get_list_element
	movq	%rax, -48(%rbp)
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB55_5
.LBB55_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB55_5
.LBB55_3:                               # %if.then2
	movq	$0, -8(%rbp)
.LBB55_5:                               # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp335:
	.size	list_get_element_string, .Ltmp335-list_get_element_string
	.cfi_endproc

	.globl	list_insert_element_int
	.align	16, 0x90
	.type	list_insert_element_int,@function
list_insert_element_int:                # @list_insert_element_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp338:
	.cfi_def_cfa_offset 16
.Ltmp339:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp340:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movl	%ecx, -28(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB56_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB56_3
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-28(%rbp), %rdx
	callq	insert_list_element
.LBB56_3:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp341:
	.size	list_insert_element_int, .Ltmp341-list_insert_element_int
	.cfi_endproc

	.globl	list_insert_element_float
	.align	16, 0x90
	.type	list_insert_element_float,@function
list_insert_element_float:              # @list_insert_element_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp344:
	.cfi_def_cfa_offset 16
.Ltmp345:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp346:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movss	%xmm0, -28(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB57_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB57_3
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-28(%rbp), %rdx
	callq	insert_list_element
.LBB57_3:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp347:
	.size	list_insert_element_float, .Ltmp347-list_insert_element_float
	.cfi_endproc

	.globl	list_insert_element_bool
	.align	16, 0x90
	.type	list_insert_element_bool,@function
list_insert_element_bool:               # @list_insert_element_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp350:
	.cfi_def_cfa_offset 16
.Ltmp351:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp352:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movb	%cl, -25(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB58_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB58_3
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-25(%rbp), %rdx
	callq	insert_list_element
.LBB58_3:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp353:
	.size	list_insert_element_bool, .Ltmp353-list_insert_element_bool
	.cfi_endproc

	.globl	list_insert_element_char
	.align	16, 0x90
	.type	list_insert_element_char,@function
list_insert_element_char:               # @list_insert_element_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp356:
	.cfi_def_cfa_offset 16
.Ltmp357:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp358:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movb	%cl, -25(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB59_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB59_3
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-25(%rbp), %rdx
	callq	insert_list_element
.LBB59_3:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp359:
	.size	list_insert_element_char, .Ltmp359-list_insert_element_char
	.cfi_endproc

	.globl	list_insert_element_string
	.align	16, 0x90
	.type	list_insert_element_string,@function
list_insert_element_string:             # @list_insert_element_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp362:
	.cfi_def_cfa_offset 16
.Ltmp363:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp364:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB60_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB60_3
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-32(%rbp), %rdx
	callq	insert_list_element
.LBB60_3:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp365:
	.size	list_insert_element_string, .Ltmp365-list_insert_element_string
	.cfi_endproc

	.globl	list_remove_element_int
	.align	16, 0x90
	.type	list_remove_element_int,@function
list_remove_element_int:                # @list_remove_element_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp368:
	.cfi_def_cfa_offset 16
.Ltmp369:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp370:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB61_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB61_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	remove_list_element
	movq	%rax, -48(%rbp)
	movl	(%rax), %eax
	movl	%eax, -52(%rbp)
	movq	-48(%rbp), %rdi
	callq	free
	movl	-52(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB61_5
.LBB61_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB61_5
.LBB61_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB61_5:                               # %return
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	ret
.Ltmp371:
	.size	list_remove_element_int, .Ltmp371-list_remove_element_int
	.cfi_endproc

	.globl	list_remove_element_float
	.align	16, 0x90
	.type	list_remove_element_float,@function
list_remove_element_float:              # @list_remove_element_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp374:
	.cfi_def_cfa_offset 16
.Ltmp375:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp376:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB62_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB62_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	remove_list_element
	movq	%rax, -48(%rbp)
	movss	(%rax), %xmm0
	movss	%xmm0, -52(%rbp)
	movq	-48(%rbp), %rdi
	callq	free
	movss	-52(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
	jmp	.LBB62_5
.LBB62_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB62_5
.LBB62_3:                               # %if.then2
	movl	$0, -4(%rbp)
.LBB62_5:                               # %return
	movss	-4(%rbp), %xmm0
	addq	$64, %rsp
	popq	%rbp
	ret
.Ltmp377:
	.size	list_remove_element_float, .Ltmp377-list_remove_element_float
	.cfi_endproc

	.globl	list_remove_element_bool
	.align	16, 0x90
	.type	list_remove_element_bool,@function
list_remove_element_bool:               # @list_remove_element_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp380:
	.cfi_def_cfa_offset 16
.Ltmp381:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp382:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB63_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB63_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	remove_list_element
	movq	%rax, -48(%rbp)
	movb	(%rax), %al
	andb	$1, %al
	movb	%al, -49(%rbp)
	movq	-48(%rbp), %rdi
	callq	free
	movb	-49(%rbp), %al
	andb	$1, %al
	movb	%al, -1(%rbp)
	jmp	.LBB63_5
.LBB63_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB63_5
.LBB63_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB63_5:                               # %return
	movb	-1(%rbp), %al
	addq	$64, %rsp
	popq	%rbp
	ret
.Ltmp383:
	.size	list_remove_element_bool, .Ltmp383-list_remove_element_bool
	.cfi_endproc

	.globl	list_remove_element_char
	.align	16, 0x90
	.type	list_remove_element_char,@function
list_remove_element_char:               # @list_remove_element_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp386:
	.cfi_def_cfa_offset 16
.Ltmp387:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp388:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB64_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB64_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	remove_list_element
	movq	%rax, -48(%rbp)
	movb	(%rax), %al
	movb	%al, -49(%rbp)
	movq	-48(%rbp), %rdi
	callq	free
	movb	-49(%rbp), %al
	movb	%al, -1(%rbp)
	jmp	.LBB64_5
.LBB64_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB64_5
.LBB64_3:                               # %if.then2
	movb	$0, -1(%rbp)
.LBB64_5:                               # %return
	movsbl	-1(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	ret
.Ltmp389:
	.size	list_remove_element_char, .Ltmp389-list_remove_element_char
	.cfi_endproc

	.globl	list_remove_element_string
	.align	16, 0x90
	.type	list_remove_element_string,@function
list_remove_element_string:             # @list_remove_element_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp392:
	.cfi_def_cfa_offset 16
.Ltmp393:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp394:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB65_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB65_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	remove_list_element
	movq	%rax, -48(%rbp)
	movq	(%rax), %rax
	movq	%rax, -56(%rbp)
	movq	-48(%rbp), %rdi
	callq	free
	movq	-56(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB65_5
.LBB65_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB65_5
.LBB65_3:                               # %if.then2
	movq	$0, -8(%rbp)
.LBB65_5:                               # %return
	movq	-8(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	ret
.Ltmp395:
	.size	list_remove_element_string, .Ltmp395-list_remove_element_string
	.cfi_endproc

	.align	16, 0x90
	.type	create_node,@function
create_node:                            # @create_node
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp398:
	.cfi_def_cfa_offset 16
.Ltmp399:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp400:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movl	$24, %edi
	callq	malloc
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB66_2
# BB#1:                                 # %if.end
	movq	-40(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	%rcx, 16(%rax)
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rdi
	callq	cpy_value
	movq	-40(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-40(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.LBB66_2:                               # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str2, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp401:
	.size	create_node, .Ltmp401-create_node
	.cfi_endproc

	.align	16, 0x90
	.type	cpy_value,@function
cpy_value:                              # @cpy_value
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp405:
	.cfi_def_cfa_offset 16
.Ltmp406:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp407:
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	subq	$32, %rsp
.Ltmp408:
	.cfi_offset %rbx, -32
.Ltmp409:
	.cfi_offset %r14, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rsi, %rdi
	callq	num_bytes
	movq	%rax, %rdi
	callq	malloc
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB67_2
# BB#1:                                 # %if.end
	movq	-24(%rbp), %r14
	movq	-40(%rbp), %rbx
	movq	-32(%rbp), %rdi
	callq	num_bytes
	movq	%rbx, %rdi
	movq	%r14, %rsi
	movq	%rax, %rdx
	callq	memcpy
	movq	-40(%rbp), %rax
	addq	$32, %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	ret
.LBB67_2:                               # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str3, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp410:
	.size	cpy_value, .Ltmp410-cpy_value
	.cfi_endproc

	.align	16, 0x90
	.type	num_bytes,@function
num_bytes:                              # @num_bytes
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp413:
	.cfi_def_cfa_offset 16
.Ltmp414:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp415:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	bytes_per_type(,%rdi,8), %rax
	popq	%rbp
	ret
.Ltmp416:
	.size	num_bytes, .Ltmp416-num_bytes
	.cfi_endproc

	.align	16, 0x90
	.type	free_node,@function
free_node:                              # @free_node
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp419:
	.cfi_def_cfa_offset 16
.Ltmp420:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp421:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	testq	%rdi, %rdi
	je	.LBB69_2
# BB#1:                                 # %if.then
	movq	-8(%rbp), %rax
	movq	(%rax), %rdi
	callq	free
.LBB69_2:                               # %if.end
	movq	-8(%rbp), %rdi
	callq	free
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp422:
	.size	free_node, .Ltmp422-free_node
	.cfi_endproc

	.align	16, 0x90
	.type	unique_desc_id,@function
unique_desc_id:                         # @unique_desc_id
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp425:
	.cfi_def_cfa_offset 16
.Ltmp426:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp427:
	.cfi_def_cfa_register %rbp
	movq	list_counter(%rip), %rax
	leaq	1(%rax), %rcx
	movq	%rcx, list_counter(%rip)
	popq	%rbp
	ret
.Ltmp428:
	.size	unique_desc_id, .Ltmp428-unique_desc_id
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "Memory allocation failure in `create_list_table`\n"
	.size	.L.str, 50

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "Out of range error in `insert_list_element`\n"
	.size	.L.str1, 45

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	 "Memory allocation failure in `create_node`\n"
	.size	.L.str2, 44

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	 "Memory allocation failure in `cpy_value`\n"
	.size	.L.str3, 42

	.type	bytes_per_type,@object  # @bytes_per_type
	.data
	.align	16
bytes_per_type:
	.quad	4                       # 0x4
	.quad	4                       # 0x4
	.quad	1                       # 0x1
	.quad	1                       # 0x1
	.quad	8                       # 0x8
	.size	bytes_per_type, 40

	.type	.L.str4,@object         # @.str4
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str4:
	.asciz	 "Out of range error in `remove_list_element`\n"
	.size	.L.str4, 45

	.type	.L.str5,@object         # @.str5
.L.str5:
	.asciz	 "Out of range error in `get_list_element`\n"
	.size	.L.str5, 42

	.type	list_counter,@object    # @list_counter
	.data
	.align	8
list_counter:
	.quad	1                       # 0x1
	.size	list_counter, 8

	.type	.L.str6,@object         # @.str6
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str6:
	.asciz	 "Memory allocation failure in `create_descriptor`\n"
	.size	.L.str6, 50


	.section	".note.GNU-stack","",@progbits
