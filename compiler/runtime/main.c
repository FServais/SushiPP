#include "list_runtime.h"
#include <stdio.h>

int main()
{
	struct list_table* table = create_list_table();

/*	int list[5] = {1, 2, 3, 4, 5};
	float arr2[10] = { 2.5, 2.6, 2.7, 2.555, 5.19, 18.3, 19.5, 2.9, 2.7, 2.1 };
	char arr3[12] = { 'a', 'b', 'c', 'd', 'e', 'e', '3', ',', ';', 'p', 'k', '*' };
	bool arr4[3] = { true, true, false }; */

	size_t id1 = list_allocate_int(table),
		   id2 = list_allocate_float(table),
		   id3 = list_allocate_char(table),
		   id4 = list_allocate_bool(table);

	list_add_reference(table, id1);
	list_add_reference(table, id2);
	list_add_reference(table, id3);
	list_add_reference(table, id4);

	list_push_back_int(table, id1, 5);
	list_push_back_int(table, id1, 3);
	list_push_back_int(table, id1, 18);
	list_push_back_int(table, id1, 6);

	list_push_front_float(table, id2, 5.25);
	list_push_front_float(table, id2, 3.25);
	list_push_front_float(table, id2, 18.25);
	list_push_front_float(table, id2, 6.25);

	list_insert_element_bool(table, id4, 0, true);
	list_insert_element_bool(table, id4, 1, false);
	list_insert_element_bool(table, id4, 0, true);
	list_insert_element_bool(table, id4, 2, false);

	list_push_back_char(table, id3, 'a');
	list_push_back_char(table, id3, 'b');
	list_push_back_char(table, id3, 'c');
	list_push_back_char(table, id3, 'd');
	list_push_back_char(table, id3, 'e');
	list_push_back_char(table, id3, 'f');
	list_push_back_char(table, id3, 'g');
	list_push_back_char(table, id3, 'h');
	list_push_back_char(table, id3, 'i');
	list_push_back_char(table, id3, 'j');
	list_push_back_char(table, id3, 'k');
	list_push_back_char(table, id3, 'l');
	list_push_back_char(table, id3, 'a');

	print_list_table(table);

	printf("Front/back :\n");
	printf("  List %zu front : %c\n", id3, list_front_char(table, id3));
	printf("  List %zu back : %c\n", id3, list_back_char(table, id3));
	printf("  List %zu front : %d\n", id1, list_front_int(table, id1));
	printf("  List %zu back : %d\n", id1, list_back_int(table, id1));
	printf("  List %zu front : %lf\n", id2, list_front_float(table, id2));
	printf("  List %zu back : %lf\n", id2, list_back_float(table, id2));
	printf("  List %zu front : %d\n", id4, list_front_bool(table, id4));
	printf("  List %zu back : %d\n", id4, list_back_bool(table, id4));

	printf("PopFront/PopBack :\n");
	printf("  List %zu front : %c\n", id3, list_pop_front_char(table, id3));
	printf("  List %zu back : %c\n", id3, list_pop_back_char(table, id3));
	printf("  List %zu front : %d\n", id1, list_pop_front_int(table, id1));
	printf("  List %zu back : %d\n", id1, list_pop_back_int(table, id1));
	printf("  List %zu front : %lf\n", id2, list_pop_front_float(table, id2));
	printf("  List %zu back : %lf\n", id2, list_pop_back_float(table, id2));
	printf("  List %zu front : %d\n", id4, list_pop_front_bool(table, id4));
	printf("  List %zu back : %d\n", id4, list_pop_back_bool(table, id4));

	print_list_table(table);

	list_clear(table, id2);

	printf("Empty/size:");
	printf("  List %zu empty : %d\n", id3, list_empty(table, id3));
	printf("  List %zu size : %zu\n", id3, list_size(table, id3));
	printf("  List %zu empty : %d\n", id1, list_empty(table, id1));
	printf("  List %zu size : %zu\n", id1, list_size(table, id1));
	printf("  List %zu empty : %d\n", id2, list_empty(table, id2));
	printf("  List %zu size : %zu\n", id2, list_size(table, id2));
	printf("  List %zu empty : %d\n", id4, list_empty(table, id4));
	printf("  List %zu size : %zu\n", id4, list_size(table, id4));

	print_list_table(table);
	
	list_rm_reference(table, id1);
	list_deallocate(table, id3);

	print_list_table(table);
	delete_list_table(table);
	// struct array_table* table = create_array_table();

	// int array[5] = {1, 2, 3, 4, 5};
	// float arr2[10] = { 2.5, 2.6, 2.7, 2.555, 5.19, 18.3, 19.5, 2.9, 2.7, 2.1 };
	// char arr3[12] = { 'a', 'b', 'c', 'd', 'e', 'e', '3', ',', ';', 'p', 'k', '*' };
	// bool arr4[3] = { true, true, false }; 

	// size_t id1 = array_allocate_int(table, 5, array),
	// 	   id2 = array_allocate_float(table, 10, arr2),
	// 	   id3 = array_allocate_char(table, 12, arr3),
	// 	   id4 = array_allocate_bool(table, 3, arr4);

	// array_add_reference(table, id1);
	// array_add_reference(table, id2);
	// array_add_reference(table, id3);
	// array_add_reference(table, id4);

	// print_array_table(table);

	// printf("\nTest sizes : \n");
	// printf("Array 1 size : %zu\n", array_size(table, id1));
	// printf("Array 2 size : %zu\n", array_size(table, id2));
	// printf("Array 3 size : %zu\n", array_size(table, id3));
	// printf("Array 4 size : %zu\n", array_size(table, id4));

	// printf("\nTest ref count : \n");
	// printf("Array 1 ref count : %zu\n", array_ref_count(table, id1));
	// printf("Array 2 ref count : %zu\n", array_ref_count(table, id2));
	// printf("Array 3 ref count : %zu\n", array_ref_count(table, id3));
	// printf("Array 4 ref count : %zu\n", array_ref_count(table, id4));

	// printf("\nTest insert : \n");
	// array_insert_int(table, id1, 162, 5);
	// array_insert_float(table, id2, 25.065, 2);
	// array_insert_char(table, id3, '/', 0);
	// array_insert_bool(table, id4, true, 3);

	// print_array_table(table);

	// printf("\nTest get : \n");
	// printf("Array 1 get 2nd : %d\n", array_get_int(table, id1, 1));
	// printf("Array 2 get 2nd : %f\n", array_get_float(table, id2, 1));
	// printf("Array 3 get 2nd : %c\n", array_get_char(table, id3, 1));
	// printf("Array 4 get 2nd : %d\n", array_get_bool(table, id4, 1));


	// printf("\nTest remove : \n");
	// printf("Array 1 rm 2nd : %d\n", array_remove_int(table, id1, 1));
	// printf("Array 2 rm 2nd : %f\n", array_remove_float(table, id2, 1));
	// printf("Array 3 rm 2nd : %c\n", array_remove_char(table, id3, 1));
	// printf("Array 4 rm 2nd : %d\n", array_remove_bool(table, id4, 1));

	// print_array_table(table);

	// printf("\nTest pop : \n");
	// printf("Array 1 rm 2nd : %d\n", array_pop_int(table, id1));
	// printf("Array 2 rm 2nd : %f\n", array_pop_float(table, id2));
	// printf("Array 3 rm 2nd : %c\n", array_pop_char(table, id3));
	// printf("Array 4 rm 2nd : %d\n", array_pop_bool(table, id4));

	// print_array_table(table);

	// printf("\nTest push : \n");
	// array_push_int(table, id1, 162);
	// array_push_float(table, id2, 25.065);
	// array_push_char(table, id3, '/');
	// array_push_bool(table, id4, true);

	// print_array_table(table);

	// printf("\nTest clear : \n");
	// array_clear(table, id2);
	// array_clear(table, id4);

	// print_array_table(table);

	// array_rm_reference(table, id1);
	// array_add_reference(table, id2);
	// array_rm_reference(table, id3);
	// array_rm_reference(table, id4);

	// printf("\nTest last print: \n");
	// print_array_table(table);
	// array_rm_reference(table, id2);
	// array_rm_reference(table, id2);

	// delete_array_table(table);
	return 0;
}
