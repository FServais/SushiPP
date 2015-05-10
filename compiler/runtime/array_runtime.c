#include "array_runtime.h"

#include <stdio.h>
#include <string.h> // memmove

// types
#define INT 0
#define FLOAT 1
#define BOOL 2
#define CHAR 3
#define STRING 4

static size_t array_counter = 1; 

struct array_table
{
	struct array_descriptor* head; // list head
};

struct array_descriptor
{
	size_t array_id;
	size_t array_size;
	size_t type; // type of the array 
	void* array_ptr;
	size_t ref_count;
	struct array_descriptor* next;
};

// array containing the number of bytes for each type (can be indexed with the type macros )
static size_t bytes_per_type[5] = { sizeof(int), sizeof(float), sizeof(bool), sizeof(char), sizeof(size_t) };

/**
 * @brief Create and return a unique array identifier
 * @retval size_t Return the new unique array identifier
 */
static size_t create_unique_id(); 

/**
 * @brief Create a new array descriptor
 * @param size_t id The array identifier
 * @param size_t size The array size
 * @param size_t type The type of the array (one of the type macro)
 * @param size_t ref_count The initial reference count
 */
static struct array_descriptor* new_array_descriptor(size_t, size_t, size_t, size_t);

/**
 * @brief Find the array descriptor in the table
 * @param struct array_table* The array table in which the descriptor must be searched
 * @param size_t id The id of the descriptor
 * @retval struct array_descriptor* A pointer to the array descriptor, NULL on error
 */
static struct array_descriptor* find_array_descriptor(const struct array_table*, size_t);

/**
 * @brief Deallocate the memory allocated for the given array descriptor
 * @param struct array_descriptor* desc The array descriptor
 */
static inline void array_descriptor_deallocate(struct array_descriptor*);

/**
 * @brief Insert a new descriptor in the array table (this descriptor should have a unique id)
 * @param struct array_table* table The table in which must be inserted the new descriptor
 * @param struct array_descriptor* desc The descriptor to add
 */
static inline void insert_descriptor(struct array_table*, struct array_descriptor*);

/**
 * @brief Insert a value in the array represented by the given array_descriptor
 * @param struct array_descriptor* desc A valid array descriptor
 * @param size_t pos The position where to insert the data ([0, size])
 * @param const void* val A pointer to the value to copy (must be the same number of bytes as the element of the array) 
 */
static void array_insert_value(struct array_descriptor*, size_t pos, const void*);

/**
 * @brief Return a pointer to the element at the given position in the array
 * @param struct array_descriptor* desc A valid array descriptor
 * @param size_t pos The position of the element
 * @retval void* A pointer to the value
 */
static void* array_get_value(struct array_descriptor*, size_t);

/**
 * @brief Return a pointer to the element at the given position in the array
 * @param struct array_descriptor* desc A valid array descriptor
 * @param size_t pos The position of the element
 * @param void* val A pointer to the value
 */
static void array_set_value(struct array_descriptor*, size_t, void*);

/**
 * @brief Remove a value from the given array
 * @param struct array_descriptor* desc A valid array descriptor
 * @param size_t pos The position of the element
 */
static void array_remove_value(struct array_descriptor*, size_t);

/**
 * @brief Return the number of bytes associated with the given type
 * @param size_t type One of the macro type
 * @retval size_t The number of bytes associated with the type
 */
static inline size_t num_bytes(size_t);

static size_t create_unique_id()
{
	return array_counter++;
}

static struct array_descriptor* new_array_descriptor(size_t id, size_t size, size_t type, size_t ref_count)
{
	struct array_descriptor* desc = malloc(sizeof(struct array_descriptor));

	if(!desc) 
	{
		fprintf(stderr, "Memory allocation failure in `new_array_descriptor`\n");
		exit(EXIT_FAILURE);
	}

	desc->array_id = id;
	desc->array_size = size;
	desc->ref_count = ref_count;
	desc->type = type;
	desc->next = NULL;

	// allocate the array
	desc->array_ptr = size == 0 ? NULL : malloc(size * num_bytes(type));

	if(size != 0 && !desc->array_ptr)
	{
		fprintf(stderr, "Memory allocation failure in `new_array_descriptor`\n");
		exit(EXIT_FAILURE);
	}

	return desc;
}

static struct array_descriptor* find_array_descriptor(const struct array_table* table, size_t id)
{
	struct array_descriptor* current = table->head;

	while(current)
	{
		if(current->array_id == id)
			return current;
		current = current->next;
	}

	return NULL; // no found
}

static inline void array_descriptor_deallocate(struct array_descriptor* desc)
{
	if(desc)
		free(desc->array_ptr);
	free(desc);
}

static inline void insert_descriptor(struct array_table* table, struct array_descriptor* desc)
{
	desc->next = table->head;
	table->head = desc;
}

static void array_insert_value(struct array_descriptor* desc, size_t pos, const void* val)
{
	if(pos > desc->array_size)
	{
		fprintf(stderr, "Array index `%zu` out of bounds (array contains %zu element(s))\n", pos, desc->array_size);
		exit(EXIT_FAILURE);
	}

	// realloc the array for storing the new element
	desc->array_ptr = realloc(desc->array_ptr, (desc->array_size + 1) * num_bytes(desc->type));

	if(!desc->array_ptr)
	{
		fprintf(stderr, "Memory allocation failure in `array_insert_value`\n");
		exit(EXIT_FAILURE);
	}

	// move the elements of the array that should follow the ne element
	void *src = desc->array_ptr + num_bytes(desc->type) * pos,
		 *dst = src + num_bytes(desc->type);
	size_t num = num_bytes(desc->type) * (desc->array_size - pos);

	// move the value at the given position 
	memmove(dst, src, num);
	memcpy(src, val, num_bytes(desc->type));

	// increase the size of the array
	desc->array_size++;
}

static void array_set_value(struct array_descriptor* desc, size_t pos, void* val)
{
	if(pos >= desc->array_size)
	{
		fprintf(stderr, "Array index `%zu` out of bounds (array contains %zu element(s))\n", pos, desc->array_size);
		exit(EXIT_FAILURE);
	}

	// move the elements of the array that should follow the ne element
	void *dst = desc->array_ptr + num_bytes(desc->type) * pos;
	memcpy(dst,val,num_bytes(desc->type));
}

static inline size_t num_bytes(size_t type)
{
	return bytes_per_type[type];
}

static void* array_get_value(struct array_descriptor* desc, size_t pos)
{
	if(pos >= desc->array_size)
	{
		fprintf(stderr, "Array index `%zu` out of bounds (array contains %zu element(s))\n", pos, desc->array_size);
		exit(EXIT_FAILURE);
	}

	return desc->array_ptr + pos * num_bytes(desc->type);
}

static void array_remove_value(struct array_descriptor* desc, size_t pos)
{
	if(pos >= desc->array_size)
	{
		fprintf(stderr, "Array index `%zu` out of bounds (array contains %zu element(s))\n", pos, desc->array_size);
		exit(EXIT_FAILURE);
	}

	// move the end of the array over the removed element
	void *dst = desc->array_ptr + pos * num_bytes(desc->type),
		 *src = dst + num_bytes(desc->type);
	size_t num = num_bytes(desc->type) * (desc->array_size - pos - 1);
	memmove(dst, src, num);

	// reduce the amount of memory allocated
	desc->array_ptr = realloc(desc->array_ptr, num_bytes(desc->type) * (desc->array_size - 1));

	if(!desc->array_ptr)
	{
		fprintf(stderr, "Memory allocation failure in `array_remove_value`\n");
		exit(EXIT_FAILURE);
	}

	desc->array_size--;
}

/**
 * INTERFACE IMPLEMENTATION
 */

size_t array_allocate_int(struct array_table* table, size_t size, int* populate)
{
	if(!table) 
		return 0;

	// create the descriptor
	size_t array_id = create_unique_id();
	struct array_descriptor* new_desc = new_array_descriptor(array_id, size, INT, 0);

	// insert the new descriptor into the array table and copy the values in the array
	insert_descriptor(table, new_desc);
	memcpy(new_desc->array_ptr, populate, size * sizeof(int));

	return array_id;
}

size_t array_allocate_float(struct array_table* table, size_t size, float* populate)
{
	if(!table) 
		return 0;

	// create the descriptor
	size_t array_id = create_unique_id();
	struct array_descriptor* new_desc = new_array_descriptor(array_id, size, FLOAT, 0);

	// insert the new descriptor into the array table and copy the values in the array
	insert_descriptor(table, new_desc);
	memcpy(new_desc->array_ptr, populate, size * sizeof(float));

	return array_id;
}

size_t array_allocate_string(struct array_table* table, size_t size, size_t* populate)
{
	if(!table) 
		return 0;

	// create the descriptor
	size_t array_id = create_unique_id();
	struct array_descriptor* new_desc = new_array_descriptor(array_id, size, STRING, 0);

	// insert the new descriptor into the array table and copy the values in the array
	insert_descriptor(table, new_desc);
	memcpy(new_desc->array_ptr, populate, size * sizeof(size_t));

	// the string is added to the array its reference counter should be incremented
	// for(size_t i = 0; i < size; ++i)
	// 	array_add_reference(table, populate[i]);

	return array_id;
}

size_t array_allocate_char(struct array_table* table, size_t size, char* populate)
{
	if(!table) 
		return 0;

	// create the descriptor
	size_t array_id = create_unique_id();
	struct array_descriptor* new_desc = new_array_descriptor(array_id, size, CHAR, 0);

	// insert the new descriptor into the array table and copy the values in the array
	insert_descriptor(table, new_desc);
	memcpy(new_desc->array_ptr, populate, size * sizeof(char));

	return array_id;
}

size_t array_allocate_bool(struct array_table* table, size_t size, bool* populate)
{
	if(!table) 
		return 0;

	// create the descriptor
	size_t array_id = create_unique_id();
	struct array_descriptor* new_desc = new_array_descriptor(array_id, size, BOOL, 0);

	// insert the new descriptor into the array table and copy the values in the array
	insert_descriptor(table, new_desc);
	memcpy(new_desc->array_ptr, populate, size * sizeof(bool));

	return array_id;
}

void array_add_reference(struct array_table* table, size_t arrid)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_add_reference`\n");
		exit(EXIT_FAILURE);
	} 

	struct array_descriptor* desc = find_array_descriptor(table, arrid);

	if(!desc) // array not found
		return;

	desc->ref_count++;
}

void array_rm_reference(struct array_table* table, size_t arrid)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_rm_reference`\n");
		exit(EXIT_FAILURE);
	} 

	struct array_descriptor* desc = find_array_descriptor(table, arrid);

	if(!desc) // array not found
		return;

	desc->ref_count--;

	if(desc->ref_count == 0) // deallocate memory if the reference count drop to 0
		array_deallocate(table, arrid);
}

size_t array_size(const struct array_table* table, size_t arrid)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_size`\n");
		exit(EXIT_FAILURE);
	} 

	struct array_descriptor* desc = find_array_descriptor(table, arrid);

	if(!desc) // array not found
		return 0;

	return desc->array_size;
}

size_t array_ref_count(const struct array_table* table, size_t arrid)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_ref_count`\n");
		exit(EXIT_FAILURE);
	} 

	struct array_descriptor* desc = find_array_descriptor(table, arrid);

	if(!desc) // array not found
		return 0;

	return desc->ref_count;
}

void array_deallocate(struct array_table* table, size_t arrid)
{
	if(!table)
		return;
	struct array_descriptor *current = table->head, 
							*previous = NULL;

	while(current)
	{
		if(current->array_id == arrid)
		{
			if(previous != NULL)
				previous->next = current->next;
			else // the descriptor is the first one
				table->head = current->next;
			array_descriptor_deallocate(current);
			return;
		}

		previous = current;
		current = current->next;
	}
}

void array_insert_int(struct array_table* table, size_t arrid, int value, size_t pos)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_insert_int`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != INT)
		return;

	array_insert_value(desc, pos, (const void*) &value);
}

void array_insert_bool(struct array_table* table, size_t arrid, bool value, size_t pos)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_insert_bool`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != BOOL)
		return;

	array_insert_value(desc, pos, (const void*) &value);
}

void array_insert_float(struct array_table* table, size_t arrid, float value, size_t pos)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_insert_float`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != FLOAT)
		return;

	array_insert_value(desc, pos, (const void*) &value);
}

void array_insert_char(struct array_table* table, size_t arrid, char value, size_t pos)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_insert_char`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != CHAR)
		return;

	array_insert_value(desc, pos, (const void*) &value);
}

void array_insert_string(struct array_table* table, size_t arrid, size_t value, size_t pos)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_insert_string`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != STRING)
		return;

	array_insert_value(desc, pos, (const void*) &value);
}

int array_get_int(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != INT)
		return 0;
	return *(int*) array_get_value(desc, pos); 
}

float array_get_float(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != FLOAT)
		return 0;
	return *(float*) array_get_value(desc, pos); 
}

bool array_get_bool(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != BOOL)
		return 0;
	return *(bool*) array_get_value(desc, pos); 
}

char array_get_char(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != CHAR)
		return 0;
	return *(char*) array_get_value(desc, pos); 
}

size_t array_get_string(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != STRING)
		return 0;
	return *(size_t*) array_get_value(desc, pos); 
}

void array_clear(struct array_table* table, size_t arrid)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_clear`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc)
		return;

	free(desc->array_ptr);
	desc->array_size = 0;
	desc->array_ptr = NULL;
}

void array_remove(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_remove`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc)
		return;

	array_remove_value(desc, pos);
}

int array_remove_int(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != INT)
		return 0;

	int value = *(int*) array_get_value(desc, pos);
	array_remove_value(desc,pos);
	return value;
}

float array_remove_float(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != FLOAT)
		return 0;

	float value = *(float*) array_get_value(desc, pos);
	array_remove_value(desc,pos);
	return value;
}

bool array_remove_bool(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != BOOL)
		return 0;

	bool value = *(bool*) array_get_value(desc, pos);
	array_remove_value(desc,pos);
	return value;
}

char array_remove_char(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != CHAR)
		return 0;

	char value = *(char*) array_get_value(desc, pos);
	array_remove_value(desc,pos);
	return value;
}

size_t array_remove_string(struct array_table* table, size_t arrid, size_t pos)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != STRING)
		return 0;

	size_t value = *(size_t*) array_get_value(desc, pos);
	array_remove_value(desc,pos);
	return value;
}

int array_pop_int(struct array_table* table, size_t arrid)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != INT)
		return 0;

	size_t last_position = desc->array_size - 1;
	int value = *(int*) array_get_value(desc, last_position);
	array_remove_value(desc, last_position);
	return value;
}

float array_pop_float(struct array_table* table, size_t arrid)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != FLOAT)
		return 0;

	size_t last_position = desc->array_size - 1;
	float value = *(float*) array_get_value(desc, last_position);
	array_remove_value(desc, last_position);
	return value;
}

bool array_pop_bool(struct array_table* table, size_t arrid)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != BOOL)
		return 0;

	size_t last_position = desc->array_size - 1;
	bool value = *(bool*) array_get_value(desc, last_position);
	array_remove_value(desc, last_position);
	return value;
}

char array_pop_char(struct array_table* table, size_t arrid)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != CHAR)
		return 0;

	size_t last_position = desc->array_size - 1;
	char value = *(char*) array_get_value(desc, last_position);
	array_remove_value(desc, last_position);
	return value;
}

size_t array_pop_string(struct array_table* table, size_t arrid)
{
	if(!table)
		return 0;
	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != STRING)
		return 0;

	size_t last_position = desc->array_size - 1;
	size_t value = *(size_t*) array_get_value(desc, last_position);
	array_remove_value(desc, last_position);
	return value;
}

void array_push_int(struct array_table* table, size_t arrid, int value)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_push_int`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != INT)
		return;

	array_insert_value(desc, desc->array_size, &value);
}

void array_push_float(struct array_table* table, size_t arrid, float value)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_push_float`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != FLOAT)
		return;

	array_insert_value(desc, desc->array_size, &value);
}

void array_push_bool(struct array_table* table, size_t arrid, bool value)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_push_bool`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != BOOL)
		return;

	array_insert_value(desc, desc->array_size, &value);
}

void array_push_char(struct array_table* table, size_t arrid, char value)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_push_char`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != CHAR)
		return;

	array_insert_value(desc, desc->array_size, &value);
}

void array_push_string(struct array_table* table, size_t arrid, size_t value)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_push_string`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != STRING)
		return;

	array_insert_value(desc, desc->array_size, &value);
}

struct array_table* create_array_table()
{
	struct array_table* table = malloc(sizeof(struct array_table));

	if(!table)
	{
		fprintf(stderr, "Memory allocation failure in `create_array_table`\n");
		exit(EXIT_FAILURE);
	}

	table->head = NULL;

	return table;
}

void delete_array_table(struct array_table* table)
{
	free(table);
}

bool array_empty(const struct array_table* table, size_t id)
{
	return array_size(table, id) == 0;
}

size_t array_make_sequence(struct array_table* table, size_t a, size_t b)
{
	size_t id = array_allocate_int(table, 0, NULL);
	struct array_descriptor* desc = find_array_descriptor(table, id);
	for(size_t i = a; i <= b; ++i)
		array_insert_value(desc, desc->array_size, &i);
	return id;
}

void array_set_int(struct array_table* table, size_t arrid, size_t pos, int val)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_set_int`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != INT)
		return;

	array_set_value(desc, pos, &val);
}

void array_set_float(struct array_table* table, size_t arrid, size_t pos, float val)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_set_float`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != FLOAT)
		return;

	array_set_value(desc, pos, &val);
}

void array_set_bool(struct array_table* table, size_t arrid, size_t pos, bool val)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_set_bool`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != BOOL)
		return;

	array_set_value(desc, pos, &val);
}

void array_set_char(struct array_table* table, size_t arrid, size_t pos, char val)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_set_char`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != CHAR)
		return;

	array_set_value(desc, pos, &val);
}

void array_set_string(struct array_table* table, size_t arrid, size_t pos, size_t val)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `array_set_string`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != STRING)
		return;

	array_set_value(desc, pos, &val);
}

char string_get_char(struct array_table* table, size_t arrid, size_t pos)
{
	return array_get_char(table, arrid, pos);
}

size_t string_concat(struct array_table* table, size_t arrid1, size_t arrid2)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `string_concat`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor *desc1 = find_array_descriptor(table, arrid1),
							*desc2 = find_array_descriptor(table, arrid2);

	if(!desc1 || desc1->type != CHAR || !desc2 || desc2->type != CHAR)
	{
		fprintf(stderr, "Invalid array id or type in `string_concat`\n");
		exit(EXIT_FAILURE);
	}

	size_t new_array = array_allocate_char(table, desc1->array_size, (char*) desc1->array_ptr);
	struct array_descriptor* new_desc = find_array_descriptor(table, new_array);

	for(size_t i = 0; i < desc2->array_size; ++i)
		array_insert_value(new_desc, new_desc->array_size, ((char*)desc2->array_ptr) + i);

	return new_array;
}

void print_string(struct array_table* table, size_t arrid)
{
	if(!table)
	{
		fprintf(stderr, "Invalid pointer to the array table in `print_string`\n");
		exit(EXIT_FAILURE);
	}

	struct array_descriptor* desc = find_array_descriptor(table, arrid);
	if(!desc || desc->type != CHAR)
	{
		fprintf(stderr, "Invalid array id or type in `print_string`\n");
		exit(EXIT_FAILURE);
	}

	for(size_t i = 0; i < desc->array_size; ++i)
		printf("%c", ((char*)desc->array_ptr)[i]);
}

size_t string_len(struct array_table* table, size_t arrid)
{
	return array_size_char(table, arrid);
}

void println_string(struct array_table* table, size_t arrid)
{
	print_string(table, arrid);
	printf("\n");
}

bool array_empty_int(const struct array_table* table, size_t id) { return array_empty(table, id); }
bool array_empty_float(const struct array_table* table, size_t id) { return array_empty(table, id); }
bool array_empty_double(const struct array_table* table, size_t id) { return array_empty(table, id); }
bool array_empty_char(const struct array_table* table, size_t id) { return array_empty(table, id); }
bool array_empty_string(const struct array_table* table, size_t id) { return array_empty(table, id); }

size_t array_size_int(const struct array_table* table, size_t id) { return array_size(table, id); }
size_t array_size_float(const struct array_table* table, size_t id) { return array_size(table, id); }
size_t array_size_double(const struct array_table* table, size_t id) { return array_size(table, id); }
size_t array_size_char(const struct array_table* table, size_t id) { return array_size(table, id); }
size_t array_size_string(const struct array_table* table, size_t id) { return array_size(table, id); }

void array_clear_int(struct array_table* table, size_t id) { array_clear(table, id); }
void array_clear_float(struct array_table* table, size_t id) { array_clear(table, id); }
void array_clear_double(struct array_table* table, size_t id) { array_clear(table, id); }
void array_clear_char(struct array_table* table, size_t id) { array_clear(table, id); }
void array_clear_string(struct array_table* table, size_t id) { array_clear(table, id); }


// void print_array_table(const struct array_table* table)
// {
// 	const struct array_descriptor* current = table->head;

// 	int cnt = 1;
// 	while(current)
// 	{
// 		printf("\n---------------------------------------------\n");
// 		printf("Array number %d (id: %zu)\n", cnt, current->array_id);
// 		printf("   Type : ");

// 		switch(current->type)
// 		{
// 		case BOOL: printf("bool\n"); break;
// 		case INT : printf("integer\n"); break;
// 		case STRING : printf("string\n"); break;
// 		case CHAR: printf("char\n"); break;
// 		case FLOAT: printf("float\n"); break;
// 		}

// 		printf("   Size : %zu\n", current->array_size);
// 		printf("   Reference count : %zu\n", current->ref_count);
// 		printf("   Values : \n    ");

// 		for(size_t i = 0; i < current->array_size; ++i)
// 		{
// 			switch(current->type)
// 			{
// 			case BOOL: printf("%s", *(((bool*) current->array_ptr ) + i) ? "true" : "false"); break;
// 			case INT : printf("%d", *(((int*) current->array_ptr ) + i)); break;
// 			case STRING : printf("%zu", *(((size_t*) current->array_ptr ) + i)); break;
// 			case CHAR: printf("%c", *(((char*) current->array_ptr ) + i)); break;
// 			case FLOAT: printf("%f", *(((float*) current->array_ptr ) + i)); break;
// 			}

// 			if((i + 1) % 10)
// 				printf(" ");
// 			else
// 				printf("\n    ");
// 		}

// 		printf("\n");
// 		current = current->next;
// 	}
// }