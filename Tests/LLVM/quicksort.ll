%struct.array_table = type opaque
%struct.list_table = type opaque
@..array_table = internal global %struct.array_table* null, align 8
@..list_table = internal global %struct.list_table* null, align 8

declare i64 @array_get_int(%struct.array_table*, i64, i64)
declare void @array_push_int(%struct.array_table*, i64, i64)
declare void @array_set_int(%struct.array_table*, i64, i64, i64)
declare i64 @array_size_int(%struct.array_table*, i64)
declare void @array_add_reference(%struct.array_table*, i64)
declare i64 @array_allocate_int(%struct.array_table*, i64, i64*)
declare void @array_rm_reference(%struct.array_table*, i64)
declare %struct.array_table* @create_array_table(...)
declare %struct.list_table* @create_list_table(...)
declare void @list_add_reference(%struct.list_table*, i64)
declare void @list_rm_reference(%struct.list_table*, i64)
declare void @print_char(i8)
declare void @print_int(i64)

define void @.array-swap(i64 %array_arg, i64 %item1_arg, i64 %item2_arg){
entry:
	%array = alloca i64
	store i64 %array_arg, i64* %array
	%item1 = alloca i64
	store i64 %item1_arg, i64* %item1
	%item2 = alloca i64
	store i64 %item2_arg, i64* %item2
	%tmp_load_array.2 = load i64* %array
	%raw_load_tmp.2 = load %struct.array_table** @..array_table
	%tmp_load_item1 = load i64* %item1
	%ret.4 = call i64 (%struct.array_table*, i64, i64)* @array_get_int( %struct.array_table* %raw_load_tmp.2, i64 %tmp_load_array.2, i64 %tmp_load_item1 )
	%tmp_ret_addr = alloca i64
	store i64 %ret.4, i64* %tmp_ret_addr
	%tmp = alloca i64
	%tmp_load_tmp_ret_addr = load i64* %tmp_ret_addr
	store i64 %tmp_load_tmp_ret_addr, i64* %tmp
	%tmp_load_array.3 = load i64* %array
	%raw_load_tmp.3 = load %struct.array_table** @..array_table
	%tmp_load_item2 = load i64* %item2
	%ret.5 = call i64 (%struct.array_table*, i64, i64)* @array_get_int( %struct.array_table* %raw_load_tmp.3, i64 %tmp_load_array.3, i64 %tmp_load_item2 )
	%tmp_ret_addr.1 = alloca i64
	store i64 %ret.5, i64* %tmp_ret_addr.1
	%tmp_load_array.4 = load i64* %array
	%tmp_load_item1.1 = load i64* %item1
	%tmp_load_tmp_ret_addr.1 = load i64* %tmp_ret_addr.1
	%raw_load_tmp.4 = load %struct.array_table** @..array_table
	call void (%struct.array_table*, i64, i64, i64)* @array_set_int(%struct.array_table* %raw_load_tmp.4, i64 %tmp_load_array.4, i64 %tmp_load_item1.1, i64 %tmp_load_tmp_ret_addr.1)
	%tmp_load_array.5 = load i64* %array
	%tmp_load_item2.1 = load i64* %item2
	%tmp_load_tmp = load i64* %tmp
	%raw_load_tmp.5 = load %struct.array_table** @..array_table
	call void (%struct.array_table*, i64, i64, i64)* @array_set_int(%struct.array_table* %raw_load_tmp.5, i64 %tmp_load_array.5, i64 %tmp_load_item2.1, i64 %tmp_load_tmp)

	ret void
}

define i64 @main(){
entry:
	%added_array_table = call %struct.array_table* (...)* @create_array_table()
	%added_list_table = call %struct.list_table* (...)* @create_list_table()
	store %struct.array_table* %added_array_table, %struct.array_table** @..array_table, align 8
	store %struct.list_table* %added_list_table, %struct.list_table** @..list_table, align 8
	%raw_load_tmp.18 = load %struct.array_table** @..array_table
	%id = call i64 (%struct.array_table*, i64, i64*)* @array_allocate_int(%struct.array_table* %raw_load_tmp.18, i64 0, i64* null)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp.18, i64 %id, i64 18)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp.18, i64 %id, i64 33)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp.18, i64 %id, i64 25)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp.18, i64 %id, i64 45)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp.18, i64 %id, i64 76)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp.18, i64 %id, i64 89)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp.18, i64 %id, i64 18)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp.18, i64 %id, i64 19)
	%tmp_id_addr = alloca i64
	store i64 %id, i64* %tmp_id_addr
	%array = alloca i64
	%tmp_load_tmp_id_addr = load i64* %tmp_id_addr
	%raw_load_tmp.19 = load %struct.list_table** @..list_table
	call void (%struct.list_table*, i64)* @list_add_reference(%struct.list_table* %raw_load_tmp.19, i64 %tmp_load_tmp_id_addr)
	store i64 %tmp_load_tmp_id_addr, i64*%array
	%tmp_load_array.19 = load i64* %array
	call void (i64)* @.print-array(i64 %tmp_load_array.19)
	%tmp_load_array.20 = load i64* %array
	call void (i64)* @.quicksort(i64 %tmp_load_array.20)
	%tmp_load_array.21 = load i64* %array
	call void (i64)* @.print-array(i64 %tmp_load_array.21)

	ret i64 0
}

define i64 @.partition(i64 %array_arg, i64 %pivot_arg, i64 %boundary_index_arg, i64 %item_index_arg){
entry:
	%array = alloca i64
	store i64 %array_arg, i64* %array
	%pivot = alloca i64
	store i64 %pivot_arg, i64* %pivot
	%boundary_index = alloca i64
	store i64 %boundary_index_arg, i64* %boundary_index
	%item_index = alloca i64
	store i64 %item_index_arg, i64* %item_index
	%tmp_load_item_index = load i64* %item_index
	%tmp_load_pivot = load i64* %pivot
	%tmp_eq = icmp eq i64 %tmp_load_item_index, %tmp_load_pivot
	%tmp_eq.1 = alloca i1
	store i1 %tmp_eq, i1* %tmp_eq.1
	%tmp_load_tmp_eq.1 = load i1* %tmp_eq.1
	br i1 %tmp_load_tmp_eq.1, label %if_true, label %if_false

if_true:
	%tmp_load_array.6 = load i64* %array
	%tmp_load_boundary_index = load i64* %boundary_index
	%tmp_load_pivot.1 = load i64* %pivot
	call void (i64, i64, i64)* @.array-swap(i64 %tmp_load_array.6, i64 %tmp_load_boundary_index, i64 %tmp_load_pivot.1)
	%raw_load_tmp.6 = load %struct.array_table** @..array_table
	%raw_load_tmp.7 = load %struct.list_table** @..list_table
	%tmp_load_boundary_index.1 = load i64* %boundary_index
	ret i64 %tmp_load_boundary_index.1
	br label %end_if

if_false:
	br label %end_if

end_if:
	%tmp_load_array.7 = load i64* %array
	%raw_load_tmp.8 = load %struct.array_table** @..array_table
	%tmp_load_item_index.1 = load i64* %item_index
	%ret.6 = call i64 (%struct.array_table*, i64, i64)* @array_get_int( %struct.array_table* %raw_load_tmp.8, i64 %tmp_load_array.7, i64 %tmp_load_item_index.1 )
	%tmp_ret_addr.2 = alloca i64
	store i64 %ret.6, i64* %tmp_ret_addr.2
	%tmp_load_array.8 = load i64* %array
	%raw_load_tmp.9 = load %struct.array_table** @..array_table
	%tmp_load_pivot.2 = load i64* %pivot
	%ret.7 = call i64 (%struct.array_table*, i64, i64)* @array_get_int( %struct.array_table* %raw_load_tmp.9, i64 %tmp_load_array.8, i64 %tmp_load_pivot.2 )
	%tmp_ret_addr.3 = alloca i64
	store i64 %ret.7, i64* %tmp_ret_addr.3
	%tmp_load_tmp_ret_addr.2 = load i64* %tmp_ret_addr.2
	%tmp_load_tmp_ret_addr.3 = load i64* %tmp_ret_addr.3
	%tmp_lt.2 = icmp slt i64 %tmp_load_tmp_ret_addr.2, %tmp_load_tmp_ret_addr.3
	%tmp_lt.3 = alloca i1
	store i1 %tmp_lt.2, i1* %tmp_lt.3
	%tmp_load_tmp_lt.3 = load i1* %tmp_lt.3
	br i1 %tmp_load_tmp_lt.3, label %if_true.1, label %if_false.1

if_true.1:
	%tmp_load_array.9 = load i64* %array
	%tmp_load_boundary_index.2 = load i64* %boundary_index
	%tmp_load_item_index.2 = load i64* %item_index
	call void (i64, i64, i64)* @.array-swap(i64 %tmp_load_array.9, i64 %tmp_load_boundary_index.2, i64 %tmp_load_item_index.2)
	%tmp_load_boundary_index.3 = load i64* %boundary_index
	%tmp_add.1 = add i64 %tmp_load_boundary_index.3, 1
	store i64 %tmp_add.1, i64* %boundary_index
	%tmp_load_item_index.3 = load i64* %item_index
	%tmp_add.2 = add i64 %tmp_load_item_index.3, 1
	store i64 %tmp_add.2, i64* %item_index
	%tmp_load_array.10 = load i64* %array
	%tmp_load_pivot.3 = load i64* %pivot
	%tmp_load_boundary_index.4 = load i64* %boundary_index
	%tmp_load_item_index.4 = load i64* %item_index
	%ret.8 = call i64 (i64, i64, i64, i64)* @.partition(i64 %tmp_load_array.10, i64 %tmp_load_pivot.3, i64 %tmp_load_boundary_index.4, i64 %tmp_load_item_index.4)
	%ret.9 = alloca i64
	store i64 %ret.8, i64* %ret.9
	br label %end_if.1

if_false.1:
	%tmp_load_item_index.5 = load i64* %item_index
	%tmp_add.3 = add i64 %tmp_load_item_index.5, 1
	store i64 %tmp_add.3, i64* %item_index
	%tmp_load_array.11 = load i64* %array
	%tmp_load_pivot.4 = load i64* %pivot
	%tmp_load_boundary_index.5 = load i64* %boundary_index
	%tmp_load_item_index.6 = load i64* %item_index
	%ret.10 = call i64 (i64, i64, i64, i64)* @.partition(i64 %tmp_load_array.11, i64 %tmp_load_pivot.4, i64 %tmp_load_boundary_index.5, i64 %tmp_load_item_index.6)
	%ret.11 = alloca i64
	store i64 %ret.10, i64* %ret.11
	br label %end_if.1

end_if.1:
	%raw_load_tmp.10 = load %struct.array_table** @..array_table
	%raw_load_tmp.11 = load %struct.list_table** @..list_table
	%tmp_load_boundary_index.6 = load i64* %boundary_index
	ret i64 %tmp_load_boundary_index.6

}

define void @.print-array(i64 %array_arg){
entry:
	%array = alloca i64
	store i64 %array_arg, i64* %array
	%i = alloca i64
	store i64 0, i64* %i
	br label %begin_loop

begin_loop:
	%tmp_load_array = load i64* %array
	%raw_load_tmp = load %struct.array_table** @..array_table
	%ret = call i64 (%struct.array_table*, i64)* @array_size_int(%struct.array_table* %raw_load_tmp, i64 %tmp_load_array)
	%ret.1 = alloca i64
	store i64 %ret, i64* %ret.1
	%tmp_load_i = load i64* %i
	%tmp_load_ret.1 = load i64* %ret.1
	%tmp_lt = icmp slt i64 %tmp_load_i, %tmp_load_ret.1
	%tmp_lt.1 = alloca i1
	store i1 %tmp_lt, i1* %tmp_lt.1
	%tmp_load_tmp_lt.1 = load i1* %tmp_lt.1
	br i1 %tmp_load_tmp_lt.1, label %label_true , label %label_false

label_true:
	%tmp_load_array.1 = load i64* %array
	%tmp_load_i.1 = load i64* %i
	%raw_load_tmp.1 = load %struct.array_table** @..array_table
	%ret.2 = call i64 (%struct.array_table*, i64, i64)* @array_get_int(%struct.array_table* %raw_load_tmp.1, i64 %tmp_load_array.1, i64 %tmp_load_i.1)
	%ret.3 = alloca i64
	store i64 %ret.2, i64* %ret.3
	%tmp_load_ret.3 = load i64* %ret.3
	call void (i64)* @print_int(i64 %tmp_load_ret.3)
	call void (i8)* @print_char(i8 32)
	%tmp_load_i.2 = load i64* %i
	%tmp_add = add i64 %tmp_load_i.2, 1
	store i64 %tmp_add, i64* %i
	br label %begin_loop

label_false:
	call void (i8)* @print_char(i8 10)

	ret void
}

define void @.print-dbg(i64 %n_arg){
entry:
	%n = alloca i64
	store i64 %n_arg, i64* %n
	call void (i8)* @print_char(i8 91)
	call void (i8)* @print_char(i8 68)
	call void (i8)* @print_char(i8 66)
	call void (i8)* @print_char(i8 71)
	%tmp_load_n = load i64* %n
	call void (i64)* @print_int(i64 %tmp_load_n)
	call void (i8)* @print_char(i8 93)
	call void (i8)* @print_char(i8 58)
	call void (i8)* @print_char(i8 32)

	ret void
}

define void @.quicksort(i64 %array_arg){
entry:
	%array = alloca i64
	store i64 %array_arg, i64* %array
	%tmp_load_array.16 = load i64* %array
	%raw_load_tmp.14 = load %struct.array_table** @..array_table
	%ret.14 = call i64 (%struct.array_table*, i64)* @array_size_int(%struct.array_table* %raw_load_tmp.14, i64 %tmp_load_array.16)
	%ret.15 = alloca i64
	store i64 %ret.14, i64* %ret.15
	%tmp_load_ret.15 = load i64* %ret.15
	%tmp_lt.6 = icmp sle i64 %tmp_load_ret.15, 1
	%tmp_lt.7 = alloca i1
	store i1 %tmp_lt.6, i1* %tmp_lt.7
	%tmp_load_tmp_lt.7 = load i1* %tmp_lt.7
	br i1 %tmp_load_tmp_lt.7, label %if_true.3, label %if_false.3

if_true.3:
	%raw_load_tmp.15 = load %struct.array_table** @..array_table
	%raw_load_tmp.16 = load %struct.list_table** @..list_table
	ret void
	br label %end_if.3

if_false.3:
	br label %end_if.3

end_if.3:
	%tmp_load_array.17 = load i64* %array
	%raw_load_tmp.17 = load %struct.array_table** @..array_table
	%ret.16 = call i64 (%struct.array_table*, i64)* @array_size_int(%struct.array_table* %raw_load_tmp.17, i64 %tmp_load_array.17)
	%ret.17 = alloca i64
	store i64 %ret.16, i64* %ret.17
	%tmp_load_array.18 = load i64* %array
	%tmp_load_ret.17 = load i64* %ret.17
	call void (i64, i64, i64)* @.quicksort_aux(i64 %tmp_load_array.18, i64 0, i64 %tmp_load_ret.17)

	ret void
}

define void @.quicksort_aux(i64 %array_arg, i64 %start_arg, i64 %end_arg){
entry:
	%array = alloca i64
	store i64 %array_arg, i64* %array
	%start = alloca i64
	store i64 %start_arg, i64* %start
	%end = alloca i64
	store i64 %end_arg, i64* %end
	%tmp_load_end = load i64* %end
	%tmp_load_start = load i64* %start
	%tmp_sub = sub i64 %tmp_load_end, %tmp_load_start
	%tmp_sub.1 = alloca i64
	store i64 %tmp_sub, i64* %tmp_sub.1
	%tmp_load_tmp_sub.1 = load i64* %tmp_sub.1
	%tmp_lt.4 = icmp sle i64 %tmp_load_tmp_sub.1, 1
	%tmp_lt.5 = alloca i1
	store i1 %tmp_lt.4, i1* %tmp_lt.5
	%tmp_load_tmp_lt.5 = load i1* %tmp_lt.5
	br i1 %tmp_load_tmp_lt.5, label %if_true.2, label %if_false.2

if_true.2:
	%raw_load_tmp.12 = load %struct.array_table** @..array_table
	%raw_load_tmp.13 = load %struct.list_table** @..list_table
	ret void
	br label %end_if.2

if_false.2:
	br label %end_if.2

end_if.2:
	%tmp_load_end.1 = load i64* %end
	%tmp_load_start.1 = load i64* %start
	%tmp_sub.2 = sub i64 %tmp_load_end.1, %tmp_load_start.1
	%tmp_sub.3 = alloca i64
	store i64 %tmp_sub.2, i64* %tmp_sub.3
	%tmp_load_tmp_sub.3 = load i64* %tmp_sub.3
	%tmp_div = sdiv i64 %tmp_load_tmp_sub.3, 2
	%tmp_div.1 = alloca i64
	store i64 %tmp_div, i64* %tmp_div.1
	%tmp_load_tmp_div.1 = load i64* %tmp_div.1
	%tmp_load_start.2 = load i64* %start
	%tmp_add.4 = add i64 %tmp_load_tmp_div.1, %tmp_load_start.2
	%tmp_add.5 = alloca i64
	store i64 %tmp_add.4, i64* %tmp_add.5
	%pivot_index = alloca i64
	%tmp_load_tmp_add.5 = load i64* %tmp_add.5
	store i64 %tmp_load_tmp_add.5, i64* %pivot_index
	%tmp_load_end.2 = load i64* %end
	%tmp_sub.4 = sub i64 %tmp_load_end.2, 1
	%tmp_sub.5 = alloca i64
	store i64 %tmp_sub.4, i64* %tmp_sub.5
	%last_index = alloca i64
	%tmp_load_tmp_sub.5 = load i64* %tmp_sub.5
	store i64 %tmp_load_tmp_sub.5, i64* %last_index
	%tmp_load_array.12 = load i64* %array
	%tmp_load_pivot_index = load i64* %pivot_index
	%tmp_load_last_index = load i64* %last_index
	call void (i64, i64, i64)* @.array-swap(i64 %tmp_load_array.12, i64 %tmp_load_pivot_index, i64 %tmp_load_last_index)
	%tmp_load_array.13 = load i64* %array
	%tmp_load_last_index.1 = load i64* %last_index
	%tmp_load_start.3 = load i64* %start
	%tmp_load_start.4 = load i64* %start
	%ret.12 = call i64 (i64, i64, i64, i64)* @.partition(i64 %tmp_load_array.13, i64 %tmp_load_last_index.1, i64 %tmp_load_start.3, i64 %tmp_load_start.4)
	%ret.13 = alloca i64
	store i64 %ret.12, i64* %ret.13
	%pivot = alloca i64
	%tmp_load_ret.13 = load i64* %ret.13
	store i64 %tmp_load_ret.13, i64* %pivot
	%tmp_load_array.14 = load i64* %array
	%tmp_load_start.5 = load i64* %start
	%tmp_load_pivot.5 = load i64* %pivot
	call void (i64, i64, i64)* @.quicksort_aux(i64 %tmp_load_array.14, i64 %tmp_load_start.5, i64 %tmp_load_pivot.5)
	%tmp_load_pivot.6 = load i64* %pivot
	%tmp_add.6 = add i64 %tmp_load_pivot.6, 1
	store i64 %tmp_add.6, i64* %pivot
	%tmp_load_array.15 = load i64* %array
	%tmp_load_pivot.7 = load i64* %pivot
	%tmp_load_end.3 = load i64* %end
	call void (i64, i64, i64)* @.quicksort_aux(i64 %tmp_load_array.15, i64 %tmp_load_pivot.7, i64 %tmp_load_end.3)

	ret void
}


