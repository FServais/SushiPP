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
		%cond2 = icmp ugt i32 %tmp, %tmp3
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