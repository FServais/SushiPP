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
define void @array-swap (i32* %array, i32 %item1, i32 %item2 ) {
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