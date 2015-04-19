;
; =====================================
; 				Quicksort
; =====================================
;
; Written by
; - Floriane Magera
; - Romain Mormont
; - Fabrice Servais
;
; DESCRIPTION: 
; This file contains the llvm code corresponding to a Sushi++ Quicksort code for intergers.
;


; array-swap
; Swap elements array[item1] and array[item2]
define void @array-swap(i32* %array, i32 %item1, i32 %item2 ) {
	; maki tmp = array[item1]
	%tmp1 = getelementptr inbounds i32* %array, i32 %item1 ; int* tmp1 = &array[item1]
	%tmp = load i32* %tmp1 ; int temp1value = *tmp1

	; array[item1] = array[item2]
	%tmp2 = getelementptr inbounds i32* %array, i32 %item2 ; int* tmp2 = &array[item2]
	%tmp2_value = load i32* %tmp2 ; int tmp2_value = *tmp2
	store i32 %tmp2_value, i32* %tmp1 ; array[item1] = tmp2_value

	; array[item2] = tmp
	store i32 %tmp, i32* %tmp2

	ret void
}

define i32 @partition(i32* %array, i32 %pivot, i32 %boundary_index, i32 %item_index)
{
	%cond1 = icmp eq i32 %pivot, %item_index
	br i1 %cond1, label %if_true, label %if_false
	if_true: 
		call void @array-swap(i32* %array, i32 %boundary_index, i32 %pivot)
		ret i32 %boundary_index

	if_false: 	
		%tmp1 = getelementptr inbounds i32* %array, i32 %item_index
		%tmp = load i32* %tmp1
		%tmp2 = getelementptr inbounds i32* %array, i32 %pivot
		%tmp3 = load i32* %tmp2
		%cond2 = icmp ugt i32 %tmp3, %tmp
		br i1 %cond2, label %if_truer, label %if_falser

	if_truer:
		call void @array-swap(i32* %array, i32 %boundary_index, i32 %item_index)
		%tmp1.1 = add i32 %boundary_index, 1
		%tmp2.1 = add i32 %item_index, 1
		%ret = call i32 @partition(i32* %array, i32 %pivot, i32 %tmp1.1, i32 %tmp2.1)
		ret i32 %ret

	if_falser:
		%tmp2.3 = add i32 %item_index, 1
		%ret.1 = call i32 @partition(i32* %array, i32 %pivot, i32 %boundary_index, i32 %tmp2.3)
		ret i32 %ret.1

} 

; quicksort_aux
; Sort the array range with the quicksort algorithm
define void @quicksort_aux ( i32* %array, i32 %start, i32 %end) {
	; if (end - start) <= 1
	%tmp1 = sub i32 %end, %start
	%cmp1 = icmp ult i32 %tmp1, 1
	br i1 %cmp1, label %iftrue, label %iffalse

iftrue:
	; nori
	ret void

iffalse:
	; maki pivot_index = (end - start)
	%tmp.2 = sub i32 %end, %start
	%tmp.3 = udiv i32 %tmp.2, 2
	%pivot_index = add i32 %tmp.3, %start

	; maki last_index = end - 1
	%last_index = sub i32 %end, 1

	; array-swap array pivot_index last_index
	call void @array-swap( i32* %array, i32 %pivot_index, i32 %last_index )	

	; pivot = (partition array last_index start start)
	%pivot = call i32 @partition( i32* %array, i32 %last_index, i32 %start, i32 %start )

	; quicksort_aux array start pivot
	call void @quicksort_aux( i32* %array, i32 %start, i32 %pivot )

	; quicksort_aux array (++pivot) end 
	%pivot.1 = add i32 %pivot, 1
	call void @quicksort_aux( i32* %array, i32 %pivot.1, i32 %end )

	ret void
}

declare i32 @printf(i8*, ...) nounwind

@.text = internal constant [20 x i8] c"Argument count: %d\0A\00"



define i32 @main(i32 %argc, i8** %argv) {
	%1 = alloca i32, align 4
	%2 = alloca i32, align 4
	%3 = alloca i8**, align 8
	%array = alloca [4 x i32], align 4
	store i32 0, i32* %1
	store i32 %argc, i32* %2, align 4
	store i8** %argv, i8*** %3, align 8
	%4 = getelementptr inbounds [3 x i32]* %array, i32 0, i64 0
	store i32 6, i32* %4, align 4
	%5 = getelementptr inbounds [3 x i32]* %array, i32 0, i64 1
	store i32 5, i32* %5, align 4
	%6 = getelementptr inbounds [3 x i32]* %array, i32 0, i64 2
	store i32 4, i32* %6, align 4

	%arrayptr = getelementptr inbounds [3 x i32]* %array, i32 0, i32 0

	call void @quicksort_aux( i32* %arrayptr, i32 0, i32 2 )

	%val.1 = load i32* %4
	%val.2 = load i32* %5
	%val.3 = load i32* %6

	%7 = call i32 (i8*, ...)* @printf(i8* getelementptr([20 x i8]* @.text, i32 0, i32 0), i32 %val.1, i32 %val.2, i32 %val.3)

	ret i32 0
}


