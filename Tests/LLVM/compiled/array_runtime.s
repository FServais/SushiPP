	.file	"array_runtime.bc"
	.text
	.globl	array_allocate_int
	.align	16, 0x90
	.type	array_allocate_int,@function
array_allocate_int:                     # @array_allocate_int
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
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB0_1
# BB#2:                                 # %if.end
	callq	create_unique_id
	movq	%rax, -40(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rax, %rdi
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	callq	new_array_descriptor
	movq	%rax, -48(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-48(%rbp), %rax
	movq	24(%rax), %rdi
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rdx
	shlq	$2, %rdx
	callq	memcpy
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB0_3
.LBB0_1:                                # %if.then
	movq	$0, -8(%rbp)
.LBB0_3:                                # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp5:
	.size	array_allocate_int, .Ltmp5-array_allocate_int
	.cfi_endproc

	.align	16, 0x90
	.type	new_array_descriptor,@function
new_array_descriptor:                   # @new_array_descriptor
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp9:
	.cfi_def_cfa_offset 16
.Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp11:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	subq	$40, %rsp
.Ltmp12:
	.cfi_offset %rbx, -24
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movl	$48, %edi
	callq	malloc
	movq	%rax, -48(%rbp)
	testq	%rax, %rax
	je	.LBB1_5
# BB#1:                                 # %if.end
	movq	-48(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	%rcx, (%rax)
	movq	-48(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rcx, 8(%rax)
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	%rcx, 32(%rax)
	xorl	%eax, %eax
	movq	-48(%rbp), %rcx
	movq	-32(%rbp), %rdx
	movq	%rdx, 16(%rcx)
	movq	-48(%rbp), %rcx
	movq	$0, 40(%rcx)
	cmpq	$0, -24(%rbp)
	je	.LBB1_3
# BB#2:                                 # %cond.false
	movq	-24(%rbp), %rbx
	movq	-32(%rbp), %rdi
	callq	num_bytes
	imulq	%rax, %rbx
	movq	%rbx, %rdi
	callq	malloc
.LBB1_3:                                # %cond.end
	movq	-48(%rbp), %rcx
	movq	%rax, 24(%rcx)
	movq	-48(%rbp), %rax
	cmpq	$0, 24(%rax)
	je	.LBB1_5
# BB#4:                                 # %if.end10
	movq	-48(%rbp), %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
.LBB1_5:                                # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str3, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp13:
	.size	new_array_descriptor, .Ltmp13-new_array_descriptor
	.cfi_endproc

	.align	16, 0x90
	.type	insert_descriptor,@function
insert_descriptor:                      # @insert_descriptor
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp16:
	.cfi_def_cfa_offset 16
.Ltmp17:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp18:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, 40(%rsi)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	%rcx, (%rax)
	popq	%rbp
	ret
.Ltmp19:
	.size	insert_descriptor, .Ltmp19-insert_descriptor
	.cfi_endproc

	.globl	array_allocate_float
	.align	16, 0x90
	.type	array_allocate_float,@function
array_allocate_float:                   # @array_allocate_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp22:
	.cfi_def_cfa_offset 16
.Ltmp23:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp24:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB3_1
# BB#2:                                 # %if.end
	callq	create_unique_id
	movq	%rax, -40(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rax, %rdi
	movl	$1, %edx
	xorl	%ecx, %ecx
	callq	new_array_descriptor
	movq	%rax, -48(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-48(%rbp), %rax
	movq	24(%rax), %rdi
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rdx
	shlq	$2, %rdx
	callq	memcpy
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB3_3
.LBB3_1:                                # %if.then
	movq	$0, -8(%rbp)
.LBB3_3:                                # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp25:
	.size	array_allocate_float, .Ltmp25-array_allocate_float
	.cfi_endproc

	.globl	array_allocate_string
	.align	16, 0x90
	.type	array_allocate_string,@function
array_allocate_string:                  # @array_allocate_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp28:
	.cfi_def_cfa_offset 16
.Ltmp29:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp30:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB4_1
# BB#2:                                 # %if.end
	callq	create_unique_id
	movq	%rax, -40(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rax, %rdi
	movl	$4, %edx
	xorl	%ecx, %ecx
	callq	new_array_descriptor
	movq	%rax, -48(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-48(%rbp), %rax
	movq	24(%rax), %rdi
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rdx
	shlq	$3, %rdx
	callq	memcpy
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB4_3
.LBB4_1:                                # %if.then
	movq	$0, -8(%rbp)
.LBB4_3:                                # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp31:
	.size	array_allocate_string, .Ltmp31-array_allocate_string
	.cfi_endproc

	.globl	array_allocate_char
	.align	16, 0x90
	.type	array_allocate_char,@function
array_allocate_char:                    # @array_allocate_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp34:
	.cfi_def_cfa_offset 16
.Ltmp35:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp36:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB5_1
# BB#2:                                 # %if.end
	callq	create_unique_id
	movq	%rax, -40(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rax, %rdi
	movl	$3, %edx
	xorl	%ecx, %ecx
	callq	new_array_descriptor
	movq	%rax, -48(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-48(%rbp), %rax
	movq	24(%rax), %rdi
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rsi
	callq	memcpy
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB5_3
.LBB5_1:                                # %if.then
	movq	$0, -8(%rbp)
.LBB5_3:                                # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp37:
	.size	array_allocate_char, .Ltmp37-array_allocate_char
	.cfi_endproc

	.globl	array_allocate_bool
	.align	16, 0x90
	.type	array_allocate_bool,@function
array_allocate_bool:                    # @array_allocate_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp40:
	.cfi_def_cfa_offset 16
.Ltmp41:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp42:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB6_1
# BB#2:                                 # %if.end
	callq	create_unique_id
	movq	%rax, -40(%rbp)
	movq	-24(%rbp), %rsi
	movq	%rax, %rdi
	movl	$2, %edx
	xorl	%ecx, %ecx
	callq	new_array_descriptor
	movq	%rax, -48(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rax, %rsi
	callq	insert_descriptor
	movq	-48(%rbp), %rax
	movq	24(%rax), %rdi
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rsi
	callq	memcpy
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB6_3
.LBB6_1:                                # %if.then
	movq	$0, -8(%rbp)
.LBB6_3:                                # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp43:
	.size	array_allocate_bool, .Ltmp43-array_allocate_bool
	.cfi_endproc

	.globl	array_add_reference
	.align	16, 0x90
	.type	array_add_reference,@function
array_add_reference:                    # @array_add_reference
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp46:
	.cfi_def_cfa_offset 16
.Ltmp47:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp48:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB7_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -24(%rbp)
	testq	%rax, %rax
	je	.LBB7_3
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rax
	incq	32(%rax)
.LBB7_3:                                # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp49:
	.size	array_add_reference, .Ltmp49-array_add_reference
	.cfi_endproc

	.align	16, 0x90
	.type	find_array_descriptor,@function
find_array_descriptor:                  # @find_array_descriptor
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp52:
	.cfi_def_cfa_offset 16
.Ltmp53:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp54:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	jmp	.LBB8_1
	.align	16, 0x90
.LBB8_4:                                # %if.end
                                        #   in Loop: Header=BB8_1 Depth=1
	movq	-32(%rbp), %rax
	movq	40(%rax), %rax
.LBB8_1:                                # %entry
                                        # =>This Inner Loop Header: Depth=1
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	je	.LBB8_5
# BB#2:                                 # %while.body
                                        #   in Loop: Header=BB8_1 Depth=1
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	cmpq	-24(%rbp), %rax
	jne	.LBB8_4
# BB#3:                                 # %if.then
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB8_6
.LBB8_5:                                # %while.end
	movq	$0, -8(%rbp)
.LBB8_6:                                # %return
	movq	-8(%rbp), %rax
	popq	%rbp
	ret
.Ltmp55:
	.size	find_array_descriptor, .Ltmp55-find_array_descriptor
	.cfi_endproc

	.globl	array_rm_reference
	.align	16, 0x90
	.type	array_rm_reference,@function
array_rm_reference:                     # @array_rm_reference
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp58:
	.cfi_def_cfa_offset 16
.Ltmp59:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp60:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB9_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
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
	callq	array_deallocate
.LBB9_4:                                # %if.end6
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp61:
	.size	array_rm_reference, .Ltmp61-array_rm_reference
	.cfi_endproc

	.globl	array_deallocate
	.align	16, 0x90
	.type	array_deallocate,@function
array_deallocate:                       # @array_deallocate
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp64:
	.cfi_def_cfa_offset 16
.Ltmp65:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp66:
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
	movq	40(%rax), %rax
	movq	%rax, -24(%rbp)
.LBB10_2:                               # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpq	$0, -24(%rbp)
	je	.LBB10_8
# BB#3:                                 # %while.body
                                        #   in Loop: Header=BB10_2 Depth=1
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	-16(%rbp), %rax
	jne	.LBB10_9
# BB#4:                                 # %if.then2
	cmpq	$0, -32(%rbp)
	je	.LBB10_6
# BB#5:                                 # %if.then4
	movq	-24(%rbp), %rax
	movq	40(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rax, 40(%rcx)
	jmp	.LBB10_7
.LBB10_6:                               # %if.else
	movq	-24(%rbp), %rax
	movq	40(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
.LBB10_7:                               # %if.end8
	movq	-24(%rbp), %rdi
	callq	array_descriptor_deallocate
.LBB10_8:                               # %while.end
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp67:
	.size	array_deallocate, .Ltmp67-array_deallocate
	.cfi_endproc

	.globl	array_size
	.align	16, 0x90
	.type	array_size,@function
array_size:                             # @array_size
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp70:
	.cfi_def_cfa_offset 16
.Ltmp71:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp72:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB11_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB11_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB11_5
.LBB11_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB11_5
.LBB11_3:                               # %if.then2
	movq	$0, -8(%rbp)
.LBB11_5:                               # %return
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp73:
	.size	array_size, .Ltmp73-array_size
	.cfi_endproc

	.globl	array_ref_count
	.align	16, 0x90
	.type	array_ref_count,@function
array_ref_count:                        # @array_ref_count
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp76:
	.cfi_def_cfa_offset 16
.Ltmp77:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp78:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB12_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB12_3
# BB#4:                                 # %if.end3
	movq	-32(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB12_5
.LBB12_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB12_5
.LBB12_3:                               # %if.then2
	movq	$0, -8(%rbp)
.LBB12_5:                               # %return
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp79:
	.size	array_ref_count, .Ltmp79-array_ref_count
	.cfi_endproc

	.align	16, 0x90
	.type	array_descriptor_deallocate,@function
array_descriptor_deallocate:            # @array_descriptor_deallocate
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp82:
	.cfi_def_cfa_offset 16
.Ltmp83:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp84:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	testq	%rdi, %rdi
	je	.LBB13_2
# BB#1:                                 # %if.then
	movq	-8(%rbp), %rax
	movq	24(%rax), %rdi
	callq	free
.LBB13_2:                               # %if.end
	movq	-8(%rbp), %rdi
	callq	free
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp85:
	.size	array_descriptor_deallocate, .Ltmp85-array_descriptor_deallocate
	.cfi_endproc

	.globl	array_insert_int
	.align	16, 0x90
	.type	array_insert_int,@function
array_insert_int:                       # @array_insert_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp88:
	.cfi_def_cfa_offset 16
.Ltmp89:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp90:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	%rcx, -32(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB14_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB14_4
# BB#2:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$0, 16(%rax)
	jne	.LBB14_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-20(%rbp), %rdx
	callq	array_insert_value
.LBB14_4:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp91:
	.size	array_insert_int, .Ltmp91-array_insert_int
	.cfi_endproc

	.align	16, 0x90
	.type	array_insert_value,@function
array_insert_value:                     # @array_insert_value
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp95:
	.cfi_def_cfa_offset 16
.Ltmp96:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp97:
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	subq	$48, %rsp
.Ltmp98:
	.cfi_offset %rbx, -32
.Ltmp99:
	.cfi_offset %r14, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	24(%rax), %r14
	movq	8(%rax), %rbx
	movq	16(%rax), %rdi
	incq	%rbx
	callq	num_bytes
	imulq	%rax, %rbx
	movq	%r14, %rdi
	movq	%rbx, %rsi
	callq	realloc
	movq	-24(%rbp), %rcx
	movq	%rax, 24(%rcx)
	movq	-24(%rbp), %rax
	cmpq	$0, 24(%rax)
	je	.LBB15_2
# BB#1:                                 # %if.end
	movq	-24(%rbp), %rax
	movq	16(%rax), %rdi
	movq	24(%rax), %r14
	callq	num_bytes
	movq	%rax, %rbx
	imulq	-32(%rbp), %rbx
	addq	%r14, %rbx
	movq	%rbx, -48(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rdi
	callq	num_bytes
	addq	%rbx, %rax
	movq	%rax, -56(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rdi
	callq	num_bytes
	movq	-24(%rbp), %rcx
	movq	8(%rcx), %rdx
	subq	-32(%rbp), %rdx
	imulq	%rax, %rdx
	movq	%rdx, -64(%rbp)
	movq	-48(%rbp), %rsi
	movq	-56(%rbp), %rdi
	callq	memmove
	movq	-24(%rbp), %rax
	movq	16(%rax), %rdi
	movq	-40(%rbp), %r14
	movq	-48(%rbp), %rbx
	callq	num_bytes
	movq	%rbx, %rdi
	movq	%r14, %rsi
	movq	%rax, %rdx
	callq	memcpy
	movq	-24(%rbp), %rax
	incq	8(%rax)
	addq	$48, %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	ret
.LBB15_2:                               # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str2, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp100:
	.size	array_insert_value, .Ltmp100-array_insert_value
	.cfi_endproc

	.globl	array_insert_bool
	.align	16, 0x90
	.type	array_insert_bool,@function
array_insert_bool:                      # @array_insert_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp103:
	.cfi_def_cfa_offset 16
.Ltmp104:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp105:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movb	%dl, -17(%rbp)
	movq	%rcx, -32(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB16_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB16_4
# BB#2:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$2, 16(%rax)
	jne	.LBB16_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-17(%rbp), %rdx
	callq	array_insert_value
.LBB16_4:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp106:
	.size	array_insert_bool, .Ltmp106-array_insert_bool
	.cfi_endproc

	.globl	array_insert_float
	.align	16, 0x90
	.type	array_insert_float,@function
array_insert_float:                     # @array_insert_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp109:
	.cfi_def_cfa_offset 16
.Ltmp110:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp111:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movss	%xmm0, -20(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB17_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB17_4
# BB#2:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$1, 16(%rax)
	jne	.LBB17_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-20(%rbp), %rdx
	callq	array_insert_value
.LBB17_4:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp112:
	.size	array_insert_float, .Ltmp112-array_insert_float
	.cfi_endproc

	.globl	array_insert_char
	.align	16, 0x90
	.type	array_insert_char,@function
array_insert_char:                      # @array_insert_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp115:
	.cfi_def_cfa_offset 16
.Ltmp116:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp117:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movb	%dl, -17(%rbp)
	movq	%rcx, -32(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB18_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB18_4
# BB#2:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$3, 16(%rax)
	jne	.LBB18_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-17(%rbp), %rdx
	callq	array_insert_value
.LBB18_4:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp118:
	.size	array_insert_char, .Ltmp118-array_insert_char
	.cfi_endproc

	.globl	array_insert_string
	.align	16, 0x90
	.type	array_insert_string,@function
array_insert_string:                    # @array_insert_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp121:
	.cfi_def_cfa_offset 16
.Ltmp122:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp123:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB19_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB19_4
# BB#2:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$4, 16(%rax)
	jne	.LBB19_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	leaq	-24(%rbp), %rdx
	callq	array_insert_value
.LBB19_4:                               # %return
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp124:
	.size	array_insert_string, .Ltmp124-array_insert_string
	.cfi_endproc

	.globl	array_get_int
	.align	16, 0x90
	.type	array_get_int,@function
array_get_int:                          # @array_get_int
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp127:
	.cfi_def_cfa_offset 16
.Ltmp128:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp129:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB20_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB20_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$0, 16(%rax)
	je	.LBB20_5
.LBB20_4:                               # %if.then2
	movl	$0, -4(%rbp)
	jmp	.LBB20_6
.LBB20_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB20_6
.LBB20_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
.LBB20_6:                               # %return
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp130:
	.size	array_get_int, .Ltmp130-array_get_int
	.cfi_endproc

	.align	16, 0x90
	.type	array_get_value,@function
array_get_value:                        # @array_get_value
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
	pushq	%r14
	pushq	%rbx
	subq	$16, %rsp
.Ltmp137:
	.cfi_offset %rbx, -32
.Ltmp138:
	.cfi_offset %r14, -24
	movq	%rsi, %rbx
	movq	%rdi, -24(%rbp)
	movq	%rbx, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rdi
	movq	24(%rax), %r14
	callq	num_bytes
	imulq	%rbx, %rax
	addq	%r14, %rax
	addq	$16, %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	ret
.Ltmp139:
	.size	array_get_value, .Ltmp139-array_get_value
	.cfi_endproc

	.globl	array_get_float
	.align	16, 0x90
	.type	array_get_float,@function
array_get_float:                        # @array_get_float
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp142:
	.cfi_def_cfa_offset 16
.Ltmp143:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp144:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB22_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB22_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$1, 16(%rax)
	je	.LBB22_5
.LBB22_4:                               # %if.then2
	movl	$0, -4(%rbp)
	jmp	.LBB22_6
.LBB22_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB22_6
.LBB22_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movss	(%rax), %xmm0
	movss	%xmm0, -4(%rbp)
.LBB22_6:                               # %return
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp145:
	.size	array_get_float, .Ltmp145-array_get_float
	.cfi_endproc

	.globl	array_get_bool
	.align	16, 0x90
	.type	array_get_bool,@function
array_get_bool:                         # @array_get_bool
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp148:
	.cfi_def_cfa_offset 16
.Ltmp149:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp150:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB23_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB23_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$2, 16(%rax)
	je	.LBB23_5
.LBB23_4:                               # %if.then2
	movb	$0, -1(%rbp)
	jmp	.LBB23_6
.LBB23_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB23_6
.LBB23_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movb	(%rax), %al
	andb	$1, %al
	movb	%al, -1(%rbp)
.LBB23_6:                               # %return
	movb	-1(%rbp), %al
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp151:
	.size	array_get_bool, .Ltmp151-array_get_bool
	.cfi_endproc

	.globl	array_get_char
	.align	16, 0x90
	.type	array_get_char,@function
array_get_char:                         # @array_get_char
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp154:
	.cfi_def_cfa_offset 16
.Ltmp155:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp156:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB24_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB24_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$3, 16(%rax)
	je	.LBB24_5
.LBB24_4:                               # %if.then2
	movb	$0, -1(%rbp)
	jmp	.LBB24_6
.LBB24_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB24_6
.LBB24_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movb	(%rax), %al
	movb	%al, -1(%rbp)
.LBB24_6:                               # %return
	movsbl	-1(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp157:
	.size	array_get_char, .Ltmp157-array_get_char
	.cfi_endproc

	.globl	array_get_string
	.align	16, 0x90
	.type	array_get_string,@function
array_get_string:                       # @array_get_string
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp160:
	.cfi_def_cfa_offset 16
.Ltmp161:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp162:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB25_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB25_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$4, 16(%rax)
	je	.LBB25_5
.LBB25_4:                               # %if.then2
	movq	$0, -8(%rbp)
	jmp	.LBB25_6
.LBB25_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB25_6
.LBB25_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
.LBB25_6:                               # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp163:
	.size	array_get_string, .Ltmp163-array_get_string
	.cfi_endproc

	.globl	array_clear
	.align	16, 0x90
	.type	array_clear,@function
array_clear:                            # @array_clear
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp166:
	.cfi_def_cfa_offset 16
.Ltmp167:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp168:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB26_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -24(%rbp)
	testq	%rax, %rax
	je	.LBB26_3
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rax
	movq	24(%rax), %rdi
	callq	free
	movq	-24(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-24(%rbp), %rax
	movq	$0, 24(%rax)
.LBB26_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp169:
	.size	array_clear, .Ltmp169-array_clear
	.cfi_endproc

	.globl	array_remove
	.align	16, 0x90
	.type	array_remove,@function
array_remove:                           # @array_remove
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp172:
	.cfi_def_cfa_offset 16
.Ltmp173:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp174:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB27_3
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB27_3
# BB#2:                                 # %if.end3
	movq	-24(%rbp), %rsi
	movq	-32(%rbp), %rdi
	callq	array_remove_value
.LBB27_3:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp175:
	.size	array_remove, .Ltmp175-array_remove
	.cfi_endproc

	.align	16, 0x90
	.type	array_remove_value,@function
array_remove_value:                     # @array_remove_value
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp179:
	.cfi_def_cfa_offset 16
.Ltmp180:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp181:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	subq	$40, %rsp
.Ltmp182:
	.cfi_offset %rbx, -40
.Ltmp183:
	.cfi_offset %r14, -32
.Ltmp184:
	.cfi_offset %r15, -24
	movq	%rsi, %r14
	movq	%rdi, -32(%rbp)
	movq	%r14, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	16(%rax), %rdi
	movq	24(%rax), %r15
	callq	num_bytes
	movq	%rax, %rbx
	imulq	%r14, %rbx
	addq	%r15, %rbx
	movq	%rbx, -48(%rbp)
	movq	-32(%rbp), %rax
	movq	16(%rax), %rdi
	callq	num_bytes
	addq	%rbx, %rax
	movq	%rax, -56(%rbp)
	movq	-32(%rbp), %rax
	movq	16(%rax), %rdi
	callq	num_bytes
	movq	-32(%rbp), %rcx
	movq	8(%rcx), %rdx
	subq	-40(%rbp), %rdx
	decq	%rdx
	imulq	%rax, %rdx
	movq	%rdx, -64(%rbp)
	movq	-56(%rbp), %rsi
	movq	-48(%rbp), %rdi
	callq	memmove
	movq	-32(%rbp), %rax
	movq	16(%rax), %rdi
	movq	24(%rax), %rbx
	callq	num_bytes
	movq	-32(%rbp), %rcx
	movq	8(%rcx), %rsi
	decq	%rsi
	imulq	%rax, %rsi
	movq	%rbx, %rdi
	callq	realloc
	movq	-32(%rbp), %rcx
	movq	%rax, 24(%rcx)
	movq	-32(%rbp), %rax
	cmpq	$0, 24(%rax)
	je	.LBB28_2
# BB#1:                                 # %if.end
	movq	-32(%rbp), %rax
	decq	8(%rax)
	addq	$40, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.LBB28_2:                               # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str1, %esi
	xorb	%al, %al
	callq	fprintf
	movl	$1, %edi
	callq	exit
.Ltmp185:
	.size	array_remove_value, .Ltmp185-array_remove_value
	.cfi_endproc

	.globl	array_remove_int
	.align	16, 0x90
	.type	array_remove_int,@function
array_remove_int:                       # @array_remove_int
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
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB29_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB29_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$0, 16(%rax)
	je	.LBB29_5
.LBB29_4:                               # %if.then2
	movl	$0, -4(%rbp)
	jmp	.LBB29_6
.LBB29_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB29_6
.LBB29_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movl	(%rax), %eax
	movl	%eax, -44(%rbp)
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_remove_value
	movl	-44(%rbp), %eax
	movl	%eax, -4(%rbp)
.LBB29_6:                               # %return
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp191:
	.size	array_remove_int, .Ltmp191-array_remove_int
	.cfi_endproc

	.globl	array_remove_float
	.align	16, 0x90
	.type	array_remove_float,@function
array_remove_float:                     # @array_remove_float
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
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB30_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB30_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$1, 16(%rax)
	je	.LBB30_5
.LBB30_4:                               # %if.then2
	movl	$0, -4(%rbp)
	jmp	.LBB30_6
.LBB30_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB30_6
.LBB30_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movss	(%rax), %xmm0
	movss	%xmm0, -44(%rbp)
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_remove_value
	movss	-44(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
.LBB30_6:                               # %return
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp197:
	.size	array_remove_float, .Ltmp197-array_remove_float
	.cfi_endproc

	.globl	array_remove_bool
	.align	16, 0x90
	.type	array_remove_bool,@function
array_remove_bool:                      # @array_remove_bool
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
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB31_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB31_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$2, 16(%rax)
	je	.LBB31_5
.LBB31_4:                               # %if.then2
	movb	$0, -1(%rbp)
	jmp	.LBB31_6
.LBB31_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB31_6
.LBB31_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movb	(%rax), %al
	andb	$1, %al
	movb	%al, -41(%rbp)
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_remove_value
	movb	-41(%rbp), %al
	andb	$1, %al
	movb	%al, -1(%rbp)
.LBB31_6:                               # %return
	movb	-1(%rbp), %al
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp203:
	.size	array_remove_bool, .Ltmp203-array_remove_bool
	.cfi_endproc

	.globl	array_remove_char
	.align	16, 0x90
	.type	array_remove_char,@function
array_remove_char:                      # @array_remove_char
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
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB32_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB32_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$3, 16(%rax)
	je	.LBB32_5
.LBB32_4:                               # %if.then2
	movb	$0, -1(%rbp)
	jmp	.LBB32_6
.LBB32_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB32_6
.LBB32_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movb	(%rax), %al
	movb	%al, -41(%rbp)
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_remove_value
	movb	-41(%rbp), %al
	movb	%al, -1(%rbp)
.LBB32_6:                               # %return
	movsbl	-1(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp209:
	.size	array_remove_char, .Ltmp209-array_remove_char
	.cfi_endproc

	.globl	array_remove_string
	.align	16, 0x90
	.type	array_remove_string,@function
array_remove_string:                    # @array_remove_string
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
	movq	%rdx, -32(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB33_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -40(%rbp)
	testq	%rax, %rax
	je	.LBB33_4
# BB#3:                                 # %lor.lhs.false
	movq	-40(%rbp), %rax
	cmpq	$4, 16(%rax)
	je	.LBB33_5
.LBB33_4:                               # %if.then2
	movq	$0, -8(%rbp)
	jmp	.LBB33_6
.LBB33_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB33_6
.LBB33_5:                               # %if.end3
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_get_value
	movq	(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-32(%rbp), %rsi
	movq	-40(%rbp), %rdi
	callq	array_remove_value
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB33_6:                               # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp215:
	.size	array_remove_string, .Ltmp215-array_remove_string
	.cfi_endproc

	.globl	array_pop_int
	.align	16, 0x90
	.type	array_pop_int,@function
array_pop_int:                          # @array_pop_int
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
	je	.LBB34_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB34_4
# BB#3:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$0, 16(%rax)
	je	.LBB34_5
.LBB34_4:                               # %if.then2
	movl	$0, -4(%rbp)
	jmp	.LBB34_6
.LBB34_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB34_6
.LBB34_5:                               # %if.end3
	movq	-32(%rbp), %rax
	movq	8(%rax), %rsi
	decq	%rsi
	movq	%rsi, -40(%rbp)
	movq	-32(%rbp), %rdi
	callq	array_get_value
	movl	(%rax), %eax
	movl	%eax, -44(%rbp)
	movq	-40(%rbp), %rsi
	movq	-32(%rbp), %rdi
	callq	array_remove_value
	movl	-44(%rbp), %eax
	movl	%eax, -4(%rbp)
.LBB34_6:                               # %return
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp221:
	.size	array_pop_int, .Ltmp221-array_pop_int
	.cfi_endproc

	.globl	array_pop_float
	.align	16, 0x90
	.type	array_pop_float,@function
array_pop_float:                        # @array_pop_float
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
	je	.LBB35_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB35_4
# BB#3:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$1, 16(%rax)
	je	.LBB35_5
.LBB35_4:                               # %if.then2
	movl	$0, -4(%rbp)
	jmp	.LBB35_6
.LBB35_1:                               # %if.then
	movl	$0, -4(%rbp)
	jmp	.LBB35_6
.LBB35_5:                               # %if.end3
	movq	-32(%rbp), %rax
	movq	8(%rax), %rsi
	decq	%rsi
	movq	%rsi, -40(%rbp)
	movq	-32(%rbp), %rdi
	callq	array_get_value
	movss	(%rax), %xmm0
	movss	%xmm0, -44(%rbp)
	movq	-40(%rbp), %rsi
	movq	-32(%rbp), %rdi
	callq	array_remove_value
	movss	-44(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
.LBB35_6:                               # %return
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp227:
	.size	array_pop_float, .Ltmp227-array_pop_float
	.cfi_endproc

	.globl	array_pop_bool
	.align	16, 0x90
	.type	array_pop_bool,@function
array_pop_bool:                         # @array_pop_bool
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
	je	.LBB36_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB36_4
# BB#3:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$2, 16(%rax)
	je	.LBB36_5
.LBB36_4:                               # %if.then2
	movb	$0, -1(%rbp)
	jmp	.LBB36_6
.LBB36_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB36_6
.LBB36_5:                               # %if.end3
	movq	-32(%rbp), %rax
	movq	8(%rax), %rsi
	decq	%rsi
	movq	%rsi, -40(%rbp)
	movq	-32(%rbp), %rdi
	callq	array_get_value
	movb	(%rax), %al
	andb	$1, %al
	movb	%al, -41(%rbp)
	movq	-40(%rbp), %rsi
	movq	-32(%rbp), %rdi
	callq	array_remove_value
	movb	-41(%rbp), %al
	andb	$1, %al
	movb	%al, -1(%rbp)
.LBB36_6:                               # %return
	movb	-1(%rbp), %al
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp233:
	.size	array_pop_bool, .Ltmp233-array_pop_bool
	.cfi_endproc

	.globl	array_pop_char
	.align	16, 0x90
	.type	array_pop_char,@function
array_pop_char:                         # @array_pop_char
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
	je	.LBB37_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB37_4
# BB#3:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$3, 16(%rax)
	je	.LBB37_5
.LBB37_4:                               # %if.then2
	movb	$0, -1(%rbp)
	jmp	.LBB37_6
.LBB37_1:                               # %if.then
	movb	$0, -1(%rbp)
	jmp	.LBB37_6
.LBB37_5:                               # %if.end3
	movq	-32(%rbp), %rax
	movq	8(%rax), %rsi
	decq	%rsi
	movq	%rsi, -40(%rbp)
	movq	-32(%rbp), %rdi
	callq	array_get_value
	movb	(%rax), %al
	movb	%al, -41(%rbp)
	movq	-40(%rbp), %rsi
	movq	-32(%rbp), %rdi
	callq	array_remove_value
	movb	-41(%rbp), %al
	movb	%al, -1(%rbp)
.LBB37_6:                               # %return
	movsbl	-1(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp239:
	.size	array_pop_char, .Ltmp239-array_pop_char
	.cfi_endproc

	.globl	array_pop_string
	.align	16, 0x90
	.type	array_pop_string,@function
array_pop_string:                       # @array_pop_string
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
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB38_1
# BB#2:                                 # %if.end
	movq	-24(%rbp), %rsi
	movq	-16(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB38_4
# BB#3:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$4, 16(%rax)
	je	.LBB38_5
.LBB38_4:                               # %if.then2
	movq	$0, -8(%rbp)
	jmp	.LBB38_6
.LBB38_1:                               # %if.then
	movq	$0, -8(%rbp)
	jmp	.LBB38_6
.LBB38_5:                               # %if.end3
	movq	-32(%rbp), %rax
	movq	8(%rax), %rsi
	decq	%rsi
	movq	%rsi, -40(%rbp)
	movq	-32(%rbp), %rdi
	callq	array_get_value
	movq	(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-40(%rbp), %rsi
	movq	-32(%rbp), %rdi
	callq	array_remove_value
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB38_6:                               # %return
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
.Ltmp245:
	.size	array_pop_string, .Ltmp245-array_pop_string
	.cfi_endproc

	.globl	array_push_int
	.align	16, 0x90
	.type	array_push_int,@function
array_push_int:                         # @array_push_int
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
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	cmpq	$0, -8(%rbp)
	je	.LBB39_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB39_4
# BB#2:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$0, 16(%rax)
	jne	.LBB39_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	8(%rdi), %rsi
	leaq	-20(%rbp), %rdx
	callq	array_insert_value
.LBB39_4:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp251:
	.size	array_push_int, .Ltmp251-array_push_int
	.cfi_endproc

	.globl	array_push_float
	.align	16, 0x90
	.type	array_push_float,@function
array_push_float:                       # @array_push_float
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
	je	.LBB40_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB40_4
# BB#2:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$1, 16(%rax)
	jne	.LBB40_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	8(%rdi), %rsi
	leaq	-20(%rbp), %rdx
	callq	array_insert_value
.LBB40_4:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp257:
	.size	array_push_float, .Ltmp257-array_push_float
	.cfi_endproc

	.globl	array_push_bool
	.align	16, 0x90
	.type	array_push_bool,@function
array_push_bool:                        # @array_push_bool
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
	je	.LBB41_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB41_4
# BB#2:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$2, 16(%rax)
	jne	.LBB41_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	8(%rdi), %rsi
	leaq	-17(%rbp), %rdx
	callq	array_insert_value
.LBB41_4:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp263:
	.size	array_push_bool, .Ltmp263-array_push_bool
	.cfi_endproc

	.globl	array_push_char
	.align	16, 0x90
	.type	array_push_char,@function
array_push_char:                        # @array_push_char
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
	je	.LBB42_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB42_4
# BB#2:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$3, 16(%rax)
	jne	.LBB42_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	8(%rdi), %rsi
	leaq	-17(%rbp), %rdx
	callq	array_insert_value
.LBB42_4:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp269:
	.size	array_push_char, .Ltmp269-array_push_char
	.cfi_endproc

	.globl	array_push_string
	.align	16, 0x90
	.type	array_push_string,@function
array_push_string:                      # @array_push_string
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
	je	.LBB43_4
# BB#1:                                 # %if.end
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	callq	find_array_descriptor
	movq	%rax, -32(%rbp)
	testq	%rax, %rax
	je	.LBB43_4
# BB#2:                                 # %lor.lhs.false
	movq	-32(%rbp), %rax
	cmpq	$4, 16(%rax)
	jne	.LBB43_4
# BB#3:                                 # %if.end3
	movq	-32(%rbp), %rdi
	movq	8(%rdi), %rsi
	leaq	-24(%rbp), %rdx
	callq	array_insert_value
.LBB43_4:                               # %return
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp275:
	.size	array_push_string, .Ltmp275-array_push_string
	.cfi_endproc

	.globl	create_array_table
	.align	16, 0x90
	.type	create_array_table,@function
create_array_table:                     # @create_array_table
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
	subq	$16, %rsp
	movl	$8, %edi
	callq	malloc
	movq	%rax, -8(%rbp)
	testq	%rax, %rax
	jne	.LBB44_2
# BB#1:                                 # %if.then
	movq	stderr(%rip), %rdi
	movl	$.L.str, %esi
	xorb	%al, %al
	callq	fprintf
.LBB44_2:                               # %if.end
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp281:
	.size	create_array_table, .Ltmp281-create_array_table
	.cfi_endproc

	.globl	delete_array_table
	.align	16, 0x90
	.type	delete_array_table,@function
delete_array_table:                     # @delete_array_table
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
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	callq	free
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp287:
	.size	delete_array_table, .Ltmp287-delete_array_table
	.cfi_endproc

	.align	16, 0x90
	.type	num_bytes,@function
num_bytes:                              # @num_bytes
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
	movq	%rdi, -8(%rbp)
	movq	bytes_per_type(,%rdi,8), %rax
	popq	%rbp
	ret
.Ltmp293:
	.size	num_bytes, .Ltmp293-num_bytes
	.cfi_endproc

	.align	16, 0x90
	.type	create_unique_id,@function
create_unique_id:                       # @create_unique_id
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
	movq	array_counter(%rip), %rax
	leaq	1(%rax), %rcx
	movq	%rcx, array_counter(%rip)
	popq	%rbp
	ret
.Ltmp299:
	.size	create_unique_id, .Ltmp299-create_unique_id
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "Memory allocation failure in `create_array_table`\n"
	.size	.L.str, 51

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "Memory allocation failure in `array_remove_value`\n"
	.size	.L.str1, 51

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

	.type	.L.str2,@object         # @.str2
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str2:
	.asciz	 "Memory allocation failure in `array_insert_value`\n"
	.size	.L.str2, 51

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	 "Memory allocation failure in `new_array_descriptor`\n"
	.size	.L.str3, 53

	.type	array_counter,@object   # @array_counter
	.data
	.align	8
array_counter:
	.quad	1                       # 0x1
	.size	array_counter, 8


	.section	".note.GNU-stack","",@progbits
