%struct.array_table = type opaque
%struct.list_table = type opaque
@..array_table = internal global %struct.array_table* null, align 8
@..list_table = internal global %struct.list_table* null, align 8

declare void @array_add_reference(%struct.array_table*, i64)
declare void @array_rm_reference(%struct.array_table*, i64)
declare %struct.array_table* @create_array_table(...)
declare %struct.list_table* @create_list_table(...)
declare void @list_add_reference(%struct.list_table*, i64)
declare void @list_rm_reference(%struct.list_table*, i64)
declare void @print_int(i64)

define i64 @main(){
entry:
	%i = add i8 5, 0
	switch i8 %i, label %truedest  [i8 5, label %falsedest ]
truedest:
	call void (i64)* @print_int(i64 5)
	br label %end

falsedest:
	call void (i64)* @print_int(i64 9)
	br label %end
end:	
	ret i64 0
}
