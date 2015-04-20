define i32 @ghty(i32 %nb)
{
	%sq = mul i32 %nb, %nb
	ret i32 %sq
}

define void @map_array(i32* %array, i32 %size, i32 (i32)* %ghty)
{

entry:	
	%n = sub i32 %size, 1
	br i1 1, label %loop, label %if_false
loop:
	%i = phi i32 [ %i.next, %loop ], [ 0, %entry ]
	%tmp = getelementptr inbounds i32* %array, i32 %i
	%tmp1 = load i32* %tmp
	%sq = call i32 @ghty(i32 %tmp1)
	store i32 %sq, i32* %tmp
	%i.next = add i32 %i, 1
	%cond = icmp ugt i32 %i, %n  ; unsigned %a > %b
	br i1 %cond, label %loop, label %if_false

if_false:
	ret void

}

define void @main(i32 %argc, i8** %argv)
{
	%1 = alloca i32, align 4
	%2 = alloca i32, align 4
	%3 = alloca i8**, align 8
	%array = alloca [4 x i32], align 4
	store i32 0, i32* %1
	store i32 %argc, i32* %2, align 4
	store i8** %argv, i8*** %3, align 8
	%4 = getelementptr inbounds [4 x i32]* %array, i32 0, i64 0
	store i32 6, i32* %4, align 4
	%5 = getelementptr inbounds [4 x i32]* %array, i32 0, i64 1
	store i32 5, i32* %5, align 4
	%6 = getelementptr inbounds [4 x i32]* %array, i32 0, i64 2
	store i32 4, i32* %6, align 4
        %7 = getelementptr inbounds [4 x i32]* %array, i32 0, i64 3
        store i32 1, i32* %7, align 4



	%arrayptr = getelementptr inbounds [4 x i32]* %array, i32 0, i32 0

	call void @map_array(i32* %arrayptr, i32 4, i32 (i32)* @ghty)

	ret void

}