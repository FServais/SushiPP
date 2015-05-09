%struct.array_table = type opaque
%struct.list_table = type opaque
@..array_table = internal global %struct.array_table* null, align 8
@..list_table = internal global %struct.list_table* null, align 8

declare void @array_push_int(%struct.array_table*, i64, i64)
declare i64 @array_size_int(%struct.array_table*, i64)
declare i64 @array_allocate_int(%struct.array_table*, i64, i64*)
declare %struct.array_table* @create_array_table(...)
declare %struct.list_table* @create_list_table(...)
declare void @print_int(i64)

define i64 @main(){
entry:
	%added_array_table = call %struct.array_table* (...)* @create_array_table()
	%added_list_table = call %struct.list_table* (...)* @create_list_table()
	store %struct.array_table* %added_array_table, %struct.array_table** @..array_table, align 8
	store %struct.list_table* %added_list_table, %struct.list_table** @..list_table, align 8
	%raw_load_tmp = load %struct.array_table** @..array_table
	%id = call i64 (%struct.array_table*, i64, i64*)* @array_allocate_int(%struct.array_table* %raw_load_tmp, i64 0, i64* null)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp, i64 %id, i64 2)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp, i64 %id, i64 3)
	call void (%struct.array_table*, i64, i64)* @array_push_int(%struct.array_table* %raw_load_tmp, i64 %id, i64 5)
	%tmp_id_addr = alloca i64
	store i64 %id, i64* %tmp_id_addr
	%a = alloca i64
	%tmp_load_tmp_id_addr = load i64* %tmp_id_addr
	store i64 %tmp_load_tmp_id_addr, i64* %a
	%tmp_load_a = load i64* %a
	%raw_load_tmp.1 = load %struct.array_table** @..array_table
	%ret = call i64 (%struct.array_table*, i64)* @array_size_int(%struct.array_table* %raw_load_tmp.1, i64 %tmp_load_a)
	%ret.1 = alloca i64
	store i64 %ret, i64* %ret.1
	%tmp_load_ret.1 = load i64* %ret.1
	call void (i64)* @print_int(i64 %tmp_load_ret.1)

	ret i64 0
}


