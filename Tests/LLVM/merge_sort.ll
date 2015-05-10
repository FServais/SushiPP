%struct.array_table = type opaque
%struct.list_table = type opaque
@..array_table = internal global %struct.array_table* null, align 8
@..list_table = internal global %struct.list_table* null, align 8

declare void @array_add_reference(%struct.array_table*, i64)
declare void @array_rm_reference(%struct.array_table*, i64)
declare %struct.array_table* @create_array_table(...)
declare %struct.list_table* @create_list_table(...)
declare i64 @list_front_int(%struct.list_table*, i64)
declare i64 @list_get_int(%struct.list_table*, i64, i64)
declare i64 @list_pop_front_int(%struct.list_table*, i64)
declare void @list_push_back_int(%struct.list_table*, i64, i64)
declare i64 @list_size_int(%struct.list_table*, i64)
declare void @list_add_reference(%struct.list_table*, i64)
declare i64 @list_allocate_int(%struct.list_table*)
declare void @list_rm_reference(%struct.list_table*, i64)
declare void @print_char(i8)
declare void @print_int(i64)

define i64 @.front(i64 %list_arg){
entry:
	%list = alloca i64
	store i64 %list_arg, i64* %list
	%tmp_load_list = load i64* %list
	%raw_load_tmp = load %struct.list_table** @..list_table
	%ret = call i64 (%struct.list_table*, i64)* @list_front_int(%struct.list_table* %raw_load_tmp, i64 %tmp_load_list)
	%ret.1 = alloca i64
	store i64 %ret, i64* %ret.1
	%raw_load_tmp.1 = load %struct.array_table** @..array_table
	%raw_load_tmp.2 = load %struct.list_table** @..list_table
	%tmp_load_ret.1 = load i64* %ret.1
	ret i64 %tmp_load_ret.1

	ret i64 0
}

define i64 @main(){
entry:
	%added_array_table = call %struct.array_table* (...)* @create_array_table()
	%added_list_table = call %struct.list_table* (...)* @create_list_table()
	store %struct.array_table* %added_array_table, %struct.array_table** @..array_table, align 8
	store %struct.list_table* %added_list_table, %struct.list_table** @..list_table, align 8
	%raw_load_tmp.26 = load %struct.list_table** @..list_table
	%id.2 = call i64 (%struct.list_table*)* @list_allocate_int(%struct.list_table* %raw_load_tmp.26)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 1)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 5)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 6)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 9)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 78)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 65)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 3)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 65)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 24)
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.26, i64 %id.2, i64 54)
	%tmp_id_addr.2 = alloca i64
	store i64 %id.2, i64* %tmp_id_addr.2
	%list = alloca i64
	%tmp_load_tmp_id_addr.2 = load i64* %tmp_id_addr.2
	%raw_load_tmp.27 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64)* @list_add_reference(%struct.list_table* %raw_load_tmp.27, i64 %tmp_load_tmp_id_addr.2)
	store i64 %tmp_load_tmp_id_addr.2, i64*%list
	%tmp_load_list.10 = load i64* %list
	%ret.44 = call i64 (i64)* @.merge-sort(i64 %tmp_load_list.10)
	%ret.45 = alloca i64
	store i64 %ret.44, i64* %ret.45
	%tmp_load_ret.45 = load i64* %ret.45
	%raw_load_tmp.28 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64)* @list_add_reference(%struct.list_table* %raw_load_tmp.28, i64 %tmp_load_ret.45)
	store i64 %tmp_load_ret.45, i64*%list
	%tmp_load_list.11 = load i64* %list
	call void (i64)* @.print-list(i64 %tmp_load_list.11)

	ret i64 0
}

define i64 @.merge(i64 %list1_arg, i64 %list2_arg){
entry:
	%list1 = alloca i64
	store i64 %list1_arg, i64* %list1
	%list2 = alloca i64
	store i64 %list2_arg, i64* %list2
	%raw_load_tmp.11 = load %struct.list_table** @..list_table
	%id = call i64 (%struct.list_table*)* @list_allocate_int(%struct.list_table* %raw_load_tmp.11)
	%tmp_id_addr = alloca i64
	store i64 %id, i64* %tmp_id_addr
	%merge_list = alloca i64
	%tmp_load_tmp_id_addr = load i64* %tmp_id_addr
	%raw_load_tmp.12 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64)* @list_add_reference(%struct.list_table* %raw_load_tmp.12, i64 %tmp_load_tmp_id_addr)
	store i64 %tmp_load_tmp_id_addr, i64*%merge_list
	br label %begin_loop

begin_loop:
	%tmp_load_list1 = load i64* %list1
	%ret.6 = call i64 (i64)* @.size(i64 %tmp_load_list1)
	%ret.7 = alloca i64
	store i64 %ret.6, i64* %ret.7
	%tmp_load_ret.7 = load i64* %ret.7
	%tmp_lt = icmp slt i64 0, %tmp_load_ret.7
	%tmp_lt.1 = alloca i1
	store i1 %tmp_lt, i1* %tmp_lt.1
	%tmp_load_list2 = load i64* %list2
	%ret.8 = call i64 (i64)* @.size(i64 %tmp_load_list2)
	%ret.9 = alloca i64
	store i64 %ret.8, i64* %ret.9
	%tmp_load_ret.9 = load i64* %ret.9
	%tmp_lt.2 = icmp slt i64 0, %tmp_load_ret.9
	%tmp_lt.3 = alloca i1
	store i1 %tmp_lt.2, i1* %tmp_lt.3
	%tmp_load_tmp_lt.1 = load i1* %tmp_lt.1
	%tmp_load_tmp_lt.3 = load i1* %tmp_lt.3
	%tmp_andl = and i1 %tmp_load_tmp_lt.1, %tmp_load_tmp_lt.3
	%tmp_andl.1 = alloca i1
	store i1 %tmp_andl, i1* %tmp_andl.1
	%tmp_load_tmp_andl.1 = load i1* %tmp_andl.1
	br i1 %tmp_load_tmp_andl.1, label %label_true , label %label_false

label_true:
	%tmp_load_list1.1 = load i64* %list1
	%ret.10 = call i64 (i64)* @.front(i64 %tmp_load_list1.1)
	%ret.11 = alloca i64
	store i64 %ret.10, i64* %ret.11
	%tmp_load_list2.1 = load i64* %list2
	%ret.12 = call i64 (i64)* @.front(i64 %tmp_load_list2.1)
	%ret.13 = alloca i64
	store i64 %ret.12, i64* %ret.13
	%tmp_load_ret.11 = load i64* %ret.11
	%tmp_load_ret.13 = load i64* %ret.13
	%tmp_lt.4 = icmp slt i64 %tmp_load_ret.13, %tmp_load_ret.11
	%tmp_lt.5 = alloca i1
	store i1 %tmp_lt.4, i1* %tmp_lt.5
	%tmp_load_tmp_lt.5 = load i1* %tmp_lt.5
	br i1 %tmp_load_tmp_lt.5, label %if_true, label %if_false

if_true:
	%tmp_load_list2.2 = load i64* %list2
	%ret.14 = call i64 (i64)* @.pop-front(i64 %tmp_load_list2.2)
	%ret.15 = alloca i64
	store i64 %ret.14, i64* %ret.15
	%tmp_load_merge_list = load i64* %merge_list
	%tmp_load_ret.15 = load i64* %ret.15
	call void (i64, i64)* @.push-back(i64 %tmp_load_merge_list, i64 %tmp_load_ret.15)
	br label %end_if

if_false:
	%tmp_load_list1.2 = load i64* %list1
	%ret.16 = call i64 (i64)* @.pop-front(i64 %tmp_load_list1.2)
	%ret.17 = alloca i64
	store i64 %ret.16, i64* %ret.17
	%tmp_load_merge_list.1 = load i64* %merge_list
	%tmp_load_ret.17 = load i64* %ret.17
	call void (i64, i64)* @.push-back(i64 %tmp_load_merge_list.1, i64 %tmp_load_ret.17)
	br label %end_if

end_if:
	br label %begin_loop

label_false:
	br label %begin_loop.1

begin_loop.1:
	%tmp_load_list1.3 = load i64* %list1
	%ret.18 = call i64 (i64)* @.size(i64 %tmp_load_list1.3)
	%ret.19 = alloca i64
	store i64 %ret.18, i64* %ret.19
	%tmp_load_ret.19 = load i64* %ret.19
	%tmp_lt.6 = icmp slt i64 0, %tmp_load_ret.19
	%tmp_lt.7 = alloca i1
	store i1 %tmp_lt.6, i1* %tmp_lt.7
	%tmp_load_tmp_lt.7 = load i1* %tmp_lt.7
	br i1 %tmp_load_tmp_lt.7, label %label_true.1 , label %label_false.1

label_true.1:
	%tmp_load_list1.4 = load i64* %list1
	%ret.20 = call i64 (i64)* @.pop-front(i64 %tmp_load_list1.4)
	%ret.21 = alloca i64
	store i64 %ret.20, i64* %ret.21
	%tmp_load_merge_list.2 = load i64* %merge_list
	%tmp_load_ret.21 = load i64* %ret.21
	call void (i64, i64)* @.push-back(i64 %tmp_load_merge_list.2, i64 %tmp_load_ret.21)
	br label %begin_loop.1

label_false.1:
	br label %begin_loop.2

begin_loop.2:
	%tmp_load_list2.3 = load i64* %list2
	%ret.22 = call i64 (i64)* @.size(i64 %tmp_load_list2.3)
	%ret.23 = alloca i64
	store i64 %ret.22, i64* %ret.23
	%tmp_load_ret.23 = load i64* %ret.23
	%tmp_lt.8 = icmp slt i64 0, %tmp_load_ret.23
	%tmp_lt.9 = alloca i1
	store i1 %tmp_lt.8, i1* %tmp_lt.9
	%tmp_load_tmp_lt.9 = load i1* %tmp_lt.9
	br i1 %tmp_load_tmp_lt.9, label %label_true.2 , label %label_false.2

label_true.2:
	%tmp_load_list2.4 = load i64* %list2
	%ret.24 = call i64 (i64)* @.pop-front(i64 %tmp_load_list2.4)
	%ret.25 = alloca i64
	store i64 %ret.24, i64* %ret.25
	%tmp_load_merge_list.3 = load i64* %merge_list
	%tmp_load_ret.25 = load i64* %ret.25
	call void (i64, i64)* @.push-back(i64 %tmp_load_merge_list.3, i64 %tmp_load_ret.25)
	br label %begin_loop.2

label_false.2:
	%raw_load_tmp.13 = load %struct.array_table** @..array_table
	%raw_load_tmp.14 = load %struct.list_table** @..list_table
	%tmp_load_merge_list.4 = load i64* %merge_list
	ret i64 %tmp_load_merge_list.4

	ret i64 0
}

define i64 @.merge-sort(i64 %list_arg){
entry:
	%list = alloca i64
	store i64 %list_arg, i64* %list
	%tmp_load_list.5 = load i64* %list
	%ret.26 = call i64 (i64)* @.size(i64 %tmp_load_list.5)
	%ret.27 = alloca i64
	store i64 %ret.26, i64* %ret.27
	%tmp_load_ret.27 = load i64* %ret.27
	%tmp_lt.10 = icmp sle i64 %tmp_load_ret.27, 1
	%tmp_lt.11 = alloca i1
	store i1 %tmp_lt.10, i1* %tmp_lt.11
	%tmp_load_tmp_lt.11 = load i1* %tmp_lt.11
	br i1 %tmp_load_tmp_lt.11, label %if_true.1, label %if_false.1

if_true.1:
	%raw_load_tmp.15 = load %struct.array_table** @..array_table
	%raw_load_tmp.16 = load %struct.list_table** @..list_table
	%tmp_load_list.6 = load i64* %list
	ret i64 %tmp_load_list.6
	br label %end_if.1

if_false.1:
	br label %end_if.1

end_if.1:
	%right = alloca i64
	%tmp_load_list.7 = load i64* %list
	%raw_load_tmp.17 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64)* @list_add_reference(%struct.list_table* %raw_load_tmp.17, i64 %tmp_load_list.7)
	store i64 %tmp_load_list.7, i64*%right
	%raw_load_tmp.18 = load %struct.list_table** @..list_table
	%id.1 = call i64 (%struct.list_table*)* @list_allocate_int(%struct.list_table* %raw_load_tmp.18)
	%tmp_id_addr.1 = alloca i64
	store i64 %id.1, i64* %tmp_id_addr.1
	%left = alloca i64
	%tmp_load_tmp_id_addr.1 = load i64* %tmp_id_addr.1
	%raw_load_tmp.19 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64)* @list_add_reference(%struct.list_table* %raw_load_tmp.19, i64 %tmp_load_tmp_id_addr.1)
	store i64 %tmp_load_tmp_id_addr.1, i64*%left
	br label %begin_loop.3

begin_loop.3:
	%tmp_load_right = load i64* %right
	%ret.28 = call i64 (i64)* @.size(i64 %tmp_load_right)
	%ret.29 = alloca i64
	store i64 %ret.28, i64* %ret.29
	%tmp_load_left = load i64* %left
	%ret.30 = call i64 (i64)* @.size(i64 %tmp_load_left)
	%ret.31 = alloca i64
	store i64 %ret.30, i64* %ret.31
	%tmp_load_ret.29 = load i64* %ret.29
	%tmp_load_ret.31 = load i64* %ret.31
	%tmp_sub = sub i64 %tmp_load_ret.29, %tmp_load_ret.31
	%tmp_sub.1 = alloca i64
	store i64 %tmp_sub, i64* %tmp_sub.1
	%tmp_load_tmp_sub.1 = load i64* %tmp_sub.1
	%tmp_lt.12 = icmp sle i64 1, %tmp_load_tmp_sub.1
	%tmp_lt.13 = alloca i1
	store i1 %tmp_lt.12, i1* %tmp_lt.13
	%tmp_load_tmp_lt.13 = load i1* %tmp_lt.13
	br i1 %tmp_load_tmp_lt.13, label %label_true.3 , label %label_false.3

label_true.3:
	%tmp_load_right.1 = load i64* %right
	%ret.32 = call i64 (i64)* @.pop-front(i64 %tmp_load_right.1)
	%ret.33 = alloca i64
	store i64 %ret.32, i64* %ret.33
	%tmp_load_left.1 = load i64* %left
	%tmp_load_ret.33 = load i64* %ret.33
	call void (i64, i64)* @.push-back(i64 %tmp_load_left.1, i64 %tmp_load_ret.33)
	br label %begin_loop.3

label_false.3:
	%tmp_load_left.2 = load i64* %left
	%ret.34 = call i64 (i64)* @.merge-sort(i64 %tmp_load_left.2)
	%ret.35 = alloca i64
	store i64 %ret.34, i64* %ret.35
	%tmp_load_ret.35 = load i64* %ret.35
	%raw_load_tmp.20 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64)* @list_add_reference(%struct.list_table* %raw_load_tmp.20, i64 %tmp_load_ret.35)
	store i64 %tmp_load_ret.35, i64*%left
	%tmp_load_right.2 = load i64* %right
	%ret.36 = call i64 (i64)* @.merge-sort(i64 %tmp_load_right.2)
	%ret.37 = alloca i64
	store i64 %ret.36, i64* %ret.37
	%tmp_load_ret.37 = load i64* %ret.37
	%raw_load_tmp.21 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64)* @list_add_reference(%struct.list_table* %raw_load_tmp.21, i64 %tmp_load_ret.37)
	store i64 %tmp_load_ret.37, i64*%right
	%tmp_load_left.3 = load i64* %left
	%tmp_load_right.3 = load i64* %right
	%ret.38 = call i64 (i64, i64)* @.merge(i64 %tmp_load_left.3, i64 %tmp_load_right.3)
	%ret.39 = alloca i64
	store i64 %ret.38, i64* %ret.39
	%raw_load_tmp.22 = load %struct.array_table** @..array_table
	%raw_load_tmp.23 = load %struct.list_table** @..list_table
	%tmp_load_ret.39 = load i64* %ret.39
	ret i64 %tmp_load_ret.39

	ret i64 0
}

define i64 @.pop-front(i64 %list_arg){
entry:
	%list = alloca i64
	store i64 %list_arg, i64* %list
	%tmp_load_list.2 = load i64* %list
	%raw_load_tmp.6 = load %struct.list_table** @..list_table
	%ret.4 = call i64 (%struct.list_table*, i64)* @list_pop_front_int(%struct.list_table* %raw_load_tmp.6, i64 %tmp_load_list.2)
	%ret.5 = alloca i64
	store i64 %ret.4, i64* %ret.5
	%raw_load_tmp.7 = load %struct.array_table** @..array_table
	%raw_load_tmp.8 = load %struct.list_table** @..list_table
	%tmp_load_ret.5 = load i64* %ret.5
	ret i64 %tmp_load_ret.5

	ret i64 0
}

define void @.print-list(i64 %list_arg){
entry:
	%list = alloca i64
	store i64 %list_arg, i64* %list
	%i = alloca i64
	store i64 0, i64* %i
	br label %begin_loop.4

begin_loop.4:
	%tmp_load_list.8 = load i64* %list
	%raw_load_tmp.24 = load %struct.list_table** @..list_table
	%ret.40 = call i64 (%struct.list_table*, i64)* @list_size_int(%struct.list_table* %raw_load_tmp.24, i64 %tmp_load_list.8)
	%ret.41 = alloca i64
	store i64 %ret.40, i64* %ret.41
	%tmp_load_i = load i64* %i
	%tmp_load_ret.41 = load i64* %ret.41
	%tmp_lt.14 = icmp slt i64 %tmp_load_i, %tmp_load_ret.41
	%tmp_lt.15 = alloca i1
	store i1 %tmp_lt.14, i1* %tmp_lt.15
	%tmp_load_tmp_lt.15 = load i1* %tmp_lt.15
	br i1 %tmp_load_tmp_lt.15, label %label_true.4 , label %label_false.4

label_true.4:
	%tmp_load_list.9 = load i64* %list
	%tmp_load_i.1 = load i64* %i
	%raw_load_tmp.25 = load %struct.list_table** @..list_table
	%ret.42 = call i64 (%struct.list_table*, i64, i64)* @list_get_int(%struct.list_table* %raw_load_tmp.25, i64 %tmp_load_list.9, i64 %tmp_load_i.1)
	%ret.43 = alloca i64
	store i64 %ret.42, i64* %ret.43
	%tmp_load_ret.43 = load i64* %ret.43
	call void (i64)* @print_int(i64 %tmp_load_ret.43)
	call void (i8)* @print_char(i8 32)
	%tmp_load_i.2 = load i64* %i
	%tmp_add = add i64 %tmp_load_i.2, 1
	store i64 %tmp_add, i64* %i
	br label %begin_loop.4

label_false.4:

	ret void
}

define void @.push-back(i64 %list_arg, i64 %value_arg){
entry:
	%list = alloca i64
	store i64 %list_arg, i64* %list
	%value = alloca i64
	store i64 %value_arg, i64* %value
	%tmp_load_list.3 = load i64* %list
	%tmp_load_value = load i64* %value
	%raw_load_tmp.9 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.9, i64 %tmp_load_list.3, i64 %tmp_load_value)

	ret void
}

define void @.push-front(i64 %list_arg, i64 %value_arg){
entry:
	%list = alloca i64
	store i64 %list_arg, i64* %list
	%value = alloca i64
	store i64 %value_arg, i64* %value
	%tmp_load_list.4 = load i64* %list
	%tmp_load_value.1 = load i64* %value
	%raw_load_tmp.10 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64, i64)* @list_push_back_int(%struct.list_table* %raw_load_tmp.10, i64 %tmp_load_list.4, i64 %tmp_load_value.1)

	ret void
}

define i64 @.size(i64 %list_arg){
entry:
	%list = alloca i64
	store i64 %list_arg, i64* %list
	%tmp_load_list.1 = load i64* %list
	%raw_load_tmp.3 = load %struct.list_table** @..list_table
	%ret.2 = call i64 (%struct.list_table*, i64)* @list_size_int(%struct.list_table* %raw_load_tmp.3, i64 %tmp_load_list.1)
	%ret.3 = alloca i64
	store i64 %ret.2, i64* %ret.3
	%raw_load_tmp.4 = load %struct.array_table** @..array_table
	%raw_load_tmp.5 = load %struct.list_table** @..list_table
	%tmp_load_ret.3 = load i64* %ret.3
	ret i64 %tmp_load_ret.3

	ret i64 0
}


