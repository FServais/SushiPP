
declare i64 @string_toupper(i64)

declare i64 @string_tolower(i64)

declare void @print_string(i64)

declare void @print_float(float)

declare i8 @list_remove_char(i64, i64)

declare i64 @list_remove_string(i64, i64)

declare float @list_remove_float(i64, i64)

declare i64 @list_remove_int(i64, i64)

declare void @list_insert_char(i64, i64, i8)

declare void @list_insert_float(i64, i64, float)

declare void @list_insert_int(i64, i64, i64)

declare i64 @array_remove_string(i64, i64)

declare i64 @array_remove_int(i64, i64)

declare void @array_clear_bool(i64)

declare void @array_push_string(i64, i64)

declare i1 @list_empty_int(i64)

declare void @array_insert_bool(i64, i64, i1)

declare void @array_set_char(i64, i64, i8)

declare i64 @list_size_char(i64)

declare void @print_char(i8)

declare i1 @array_empty_int(i64)

declare void @array_set_float(i64, i64, float)

declare i64 @string_len(i64)

declare void @array_push_bool(i64, i1)

declare void @array_insert_string(i64, i64, i64)

declare i64 @array_get_string(i64, i64)

declare i1 @list_pop_back_bool(i64)

declare void @array_insert_int(i64, i64, i64)

declare i1 @array_pop_bool(i64)

declare i64 @array_pop_string(i64)

declare void @array_clear_char(i64)

declare i8 @array_pop_char(i64)

declare float @array_pop_float(i64)

declare i64 @array_pop_int(i64)

declare i8 @list_front_char(i64)

declare i64 @list_pop_back_string(i64)

declare i1 @array_get_bool(i64, i64)

declare i1 @array_empty_string(i64)

declare i1 @array_empty_float(i64)

declare float @list_pop_front_float(i64)

declare i64 @array_size_int(i64)

declare i64 @array_size_string(i64)

declare i1 @array_empty_bool(i64)

declare i64 @list_size_string(i64)

declare i64 @array_size_float(i64)

declare void @array_clear_string(i64)

declare i1 @list_empty_bool(i64)

declare i1 @list_front_bool(i64)

declare void @list_clear_bool(i64)

declare void @array_push_int(i64, i64)

declare i64 @array_size_bool(i64)

declare i1 @array_remove_bool(i64, i64)

declare void @array_insert_char(i64, i64, i8)

declare void @array_clear_float(i64)

declare i8 @array_remove_char(i64, i64)

declare void @array_set_int(i64, i64, i64)

declare i8 @array_get_char(i64, i64)

declare float @list_back_float(i64)

declare void @array_push_float(i64, float)

declare void @array_clear_int(i64)

declare i64 @list_size_float(i64)

declare i1 @list_empty_float(i64)

declare i1 @list_empty_char(i64)

declare i64 @list_front_int(i64)

declare i1 @array_empty_char(i64)

declare i1 @list_empty_string(i64)

declare void @print_int(i64)

declare void @list_clear_int(i64)

declare void @array_set_bool(i64, i64, i1)

declare i8 @list_get_char(i64, i64)

declare void @array_push_char(i64, i8)

declare void @list_clear_float(i64)

declare float @array_remove_float(i64, i64)

declare void @list_clear_string(i64)

declare float @list_front_float(i64)

declare i64 @string_reverse(i64)

declare void @list_insert_string(i64, i64, i64)

declare i64 @list_size_int(i64)

declare i1 @list_pop_front_bool(i64)

declare void @list_push_back_int(i64, i64)

declare i1 @list_back_bool(i64)

declare float @array_get_float(i64, i64)

declare i64 @list_back_int(i64)

declare i64 @list_get_string(i64, i64)

declare i8 @list_back_char(i64)

declare void @print_bool(i1)

declare i64 @list_back_string(i64)

declare i64 @list_pop_front_int(i64)

declare i64 @array_size_char(i64)

declare i8 @list_pop_front_char(i64)

declare void @list_push_back_bool(i64, i1)

declare void @list_push_front_bool(i64, i1)

declare i64 @list_pop_front_string(i64)

declare i64 @list_pop_back_int(i64)

declare i1 @list_remove_bool(i64, i64)

declare float @list_pop_back_float(i64)

declare i8 @list_pop_back_char(i64)

declare i64 @list_front_string(i64)

declare void @list_push_front_float(i64, float)

declare void @list_push_front_char(i64, i8)

declare void @array_insert_float(i64, i64, float)

declare void @list_push_front_int(i64, i64)

declare void @list_push_front_string(i64, i64)

declare void @list_push_back_float(i64, float)

declare i64 @list_size_bool(i64)

declare void @list_push_back_char(i64, i8)

declare void @array_set_string(i64, i64, i64)

declare void @list_push_back_string(i64, i64)

declare i1 @list_get_bool(i64, i64)

declare void @list_clear_char(i64)

declare i64 @list_get_int(i64, i64)

declare float @list_get_float(i64, i64)

declare i64 @array_get_int(i64, i64)

declare void @list_insert_bool(i64, i64, i1)

define i64 @main(){
entry:
	%tmp_load_a = load i64* %a
	%tmp_load_b = load i64* %b
	%tmp_div = sdiv i64 %tmp_load_a, %tmp_load_b
	%tmp_div.1 = alloca i64
	store i64 %tmp_div, i64* %tmp_div.1
	%tmp_load_tmp_div.1 = load i64* %tmp_div.1
	%ret = call i64 (i64, i64)* @.function (i64 18, i64 3)
	%ret.1 = alloca i64
	store i64 %ret, i64* %ret.1
	%tmp_load_ret.1 = load i64* %ret.1
	%tmp_add = add i64 3, %tmp_load_ret.1
	%tmp_add.1 = alloca i64
	store i64 %tmp_add, i64* %tmp_add.1
	%q = alloca i64
	%tmp_load_tmp_add.1 = load i64* %tmp_add.1
	store i64 %tmp_load_tmp_add.1, i64* %q
	%tmp_load_q = load i64* %q
	%tmp_add.2 = add i64 %tmp_load_q, 3
	%tmp_add.3 = alloca i64
	store i64 %tmp_add.2, i64* %tmp_add.3
	%tmp_load_q.1 = load i64* %q
	%tmp_sub = sub i64 %tmp_load_q.1, 3
	%tmp_sub.1 = alloca i64
	store i64 %tmp_sub, i64* %tmp_sub.1
	%tmp_load_tmp_add.3 = load i64* %tmp_add.3
	%tmp_load_tmp_sub.1 = load i64* %tmp_sub.1
	%ret.2 = call i64 (i64, i64)* @.function (i64 %tmp_load_tmp_add.3, i64 %tmp_load_tmp_sub.1)
	%ret.3 = alloca i64
	store i64 %ret.2, i64* %ret.3
	%tmp_load_ret.3 = load i64* %ret.3
	call void (i64)* @print_int (i64 %tmp_load_ret.3)

	ret i64 %tmp_load_tmp_div.1
}

define i64 @.function(i64 a, i64 b){
entry:

	ret i64 
}


