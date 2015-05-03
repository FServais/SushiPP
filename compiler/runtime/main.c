#include "array_runtime.h"
#include <stdio.h>

int main()
{
	struct array_table* table = create_array_table();

	int array[5] = {1, 2, 3, 4, 5};
	float arr2[10] = { 2.5, 2.6, 2.7, 2.555, 5.19, 18.3, 19.5, 2.9, 2.7, 2.1 };

	size_t id1 = array_allocate_int(table, 5, array),
		   id2 = array_allocate_float(table, 10, arr2);

	print_array_table(table);
	return 0;
}
