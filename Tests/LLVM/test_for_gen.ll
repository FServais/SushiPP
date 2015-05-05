define i32 @main(i32 %ac_arg, i8** %av_arg){
entry:
	%ac = alloca i32
	store i32 %ac_arg, i32* %ac
	%av = alloca i8**
	store i8** %av_arg, i8*** %av
	%i = alloca i32
	store i32 0, i32* %i
	%tmp_load_i = load i32* %i
	%tmp_add = add i32 %tmp_load_i, 4
	%tmp_add.1 = alloca i32
	store i32 %tmp_add, i32* %tmp_add.1
	%p = alloca i32
	%tmp_load_tmp_add.1 = load i32* %tmp_add.1
	store i32 %tmp_load_tmp_add.1, i32* %p
	%tmp_load_p = load i32* %p
	%tmp_add.2 = add i32 %tmp_load_p, 5
	%tmp_add.3 = alloca i32
	store i32 %tmp_add.2, i32* %tmp_add.3
	%tmp_load_tmp_add.3 = load i32* %tmp_add.3
	%tmp_load_i.1 = load i32* %i
	%tmp_add.4 = add i32 %tmp_load_tmp_add.3, %tmp_load_i.1
	%tmp_add.5 = alloca i32
	store i32 %tmp_add.4, i32* %tmp_add.5
	%q = alloca i32
	%tmp_load_tmp_add.5 = load i32* %tmp_add.5
	store i32 %tmp_load_tmp_add.5, i32* %q
	%tmp_load_q = load i32* %q
	%tmp_gt.1 = icmp sgt i32 %tmp_load_q, 6
	br i1 %tmp_gt.1, label %if_true, label %if_false

if_true:
	%tmp_add.6 = add i32 7, 8
	%tmp_add.7 = alloca i32
	store i32 %tmp_add.6, i32* %tmp_add.7
	%a = alloca i32
	%tmp_load_tmp_add.7 = load i32* %tmp_add.7
	store i32 %tmp_load_tmp_add.7, i32* %a
	br label %end_if

if_false:
	%tmp_load_q.1 = load i32* %q
	%tmp_gt.2 = icmp sgt i32 %tmp_load_q.1, 9
	br i1 %tmp_gt.2, label %elseif_true, label %elseif_false

elseif_true:
	%tmp_add.8 = add i32 10, 11
	%tmp_add.9 = alloca i32
	store i32 %tmp_add.8, i32* %tmp_add.9
	%b = alloca i32
	%tmp_load_tmp_add.9 = load i32* %tmp_add.9
	store i32 %tmp_load_tmp_add.9, i32* %b
	br label %end_if

elseif_false:
	%c = alloca i32
	store i32 12, i32* %c
	br label %end_if

end_if:

	ret i32 0
}

define i32 @func(i32 %a_arg, i32 %b_arg){
entry:
	%a = alloca i32
	store i32 %a_arg, i32* %a
	%b = alloca i32
	store i32 %b_arg, i32* %b
	%tmp_load_a = load i32* %a
	%tmp_add.10 = add i32 %tmp_load_a, 13
	%tmp_add.11 = alloca i32
	store i32 %tmp_add.10, i32* %tmp_add.11
	%c = alloca i32
	%tmp_load_tmp_add.11 = load i32* %tmp_add.11
	store i32 %tmp_load_tmp_add.11, i32* %c
	%tmp_load_c = load i32* %c
	%tmp_load_b = load i32* %b
	%tmp_add.12 = add i32 %tmp_load_c, %tmp_load_b
	%tmp_add.13 = alloca i32
	store i32 %tmp_add.12, i32* %tmp_add.13
	%d = alloca i32
	%tmp_load_tmp_add.13 = load i32* %tmp_add.13
	store i32 %tmp_load_tmp_add.13, i32* %d
	%tmp_load_c.1 = load i32* %c
	%tmp_load_d = load i32* %d
	%tmp_add.14 = add i32 %tmp_load_c.1, %tmp_load_d
	%tmp_add.15 = alloca i32
	store i32 %tmp_add.14, i32* %tmp_add.15
	%tmp_load_tmp_add.15 = load i32* %tmp_add.15

	ret i32 %tmp_load_tmp_add.15
}
