define i32 @main(i32 %ac, i8** %av){
entry:
	%i = alloca i32
	store i32 0, i32* %i
	%temp_load_i = load i32* %i
	%tempadd = add i32 %temp_load_i, 4
	%p = alloca i32
	store i32 %tempadd, i32* %p
	%temp_load_p = load i32* %p
	%tempadd.1 = add i32 %temp_load_p, 4
	%q = alloca i32
	store i32 %tempadd.1, i32* %q

	ret i32 0
}
