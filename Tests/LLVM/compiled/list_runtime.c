#include "list_runtime.h"

// types
#define INT 0
#define FLOAT 1
#define BOOL 2
#define CHAR 3
#define STRING 4

#include <stdio.h>
#include <string.h>

static size_t list_counter = 1; 

// opaque type for list_table : stores the data of every listsstruct 
struct node_t
{
	void* value;
	struct node_t* next;
	struct node_t* prev;
};

struct list_descriptor 
{
	struct node_t* list_head;
	struct node_t* list_tail;
	size_t list_id; // the lid of the list
	size_t list_size; // the list size
	size_t ref_count; // the reference count of the list
	size_t type; // store the type of the list (one of the type macro)
	struct list_descriptor* next;
};

struct list_table
{
	struct list_descriptor* head;
};

// array containing the number of bytes for each type (can be indexed with the type macros )
static size_t bytes_per_type[5] = { sizeof(int), sizeof(float), sizeof(bool), sizeof(char), sizeof(size_t) };

// STATIC FUNCTIONS

/**
 * @brief Copy a value in a newly allocated memory slot
 * @param void* value A pointer o the old value
 * @param size_t type The type of the value stored (one of the type macro)
 * @param void* a pointer to the memory slot containing a copy of the value
 */
static void* cpy_value(void*, size_t);

/**
 * @brief Return the value stored in the nth element of the list
 * @param struct list_descriptor* desc A valid pointer to the list descriptor
 * @param size_t pos The position of the element to get
 * @retval void* A pointer to the element stored
 */
static void* get_list_element(struct list_descriptor*, size_t);

/**
 * @brief Return the value stored in the nth element of the list and remove this element from the list
 * @param struct list_descriptor* desc A valid pointer to the list descriptor
 * @param size_t pos The position of the element to get
 * @retval void* A pointer to the element stored (must be free by the caller)
 */
static void* remove_list_element(struct list_descriptor*, size_t);

/**
 * @brief Insert a new element in the list
 * @param struct list_descriptor* desc A valid pointer to the list descriptor
 * @param size_t pos The position of the element to insert
 * @param void* elem A pointer to the element to insert
 */
static void insert_list_element(struct list_descriptor*, size_t, void*);

/**
 * @brief Return a unique descriptor lid
 * @retval size_t The unique descriptor lid
 */
static size_t unique_desc_id();

/**
 * @brief Insert a descriptor into the (beginning of the) list table
 * @param struct list_table* table A valid poitner to the list table
 * @param struct list_descriptor* desc A valid pointer to list descriptor to insert
 */
static void insert_descriptor(struct list_table*, struct list_descriptor*);

/**
 * @brief Find the list descriptor having the given lid
 * @param struct list_table* table A vlide pointer to a list table
 * @param size_t lid The lid of the descriptor to find
 * @retval struct list_descriptor* A pointer to the list descriptor, NULL if it was not found
 */
static struct list_descriptor* find_descriptor(struct list_table*, size_t);

/**
 * @brief Free the given list descriptor
 * @param struct list_descriptor* desc A valid pointer to a list descriptor
 */
static void free_descriptor(struct list_descriptor*);

/**
 * @brief Free the memory allocated for a given node and update the pointer of the node pointing to it
 * @param struct node_t* node A valid pointer to first node to free
 * @retval struct node_t* A pointer to node of which the next pointer was pointing on 'node', NULL if there was none
 */
static struct node_t* free_node_recur(struct node_t*);

/**
 * @brief Free the memory allocated for a given node 
 * @param struct node_t* node A valid pointer to the node to free
 */
static void free_node(struct node_t*);

/**
 * @brief Creates a new list descriptor
 * @param size_t lid The list unique lid
 * @param size_t type The type of the elements stored in the list (one of the type macro)
 * @retval struct list_descriptor* A pointer to the allocated datastructure
 * @note On memory allocation failure, the program is exited
 */
static struct list_descriptor* create_descriptor(size_t, size_t);

/**
 * @brief Creates a node
 * @param struct node_t* next The next pointer
 * @param struct node_t* prev The prev pointer
 * @param void* value A pointer to a memory slot containing the value
 * @param size_t type The type of the variable (one of the type macro)
 * @retval struct node_t* A pointer to the allocated node
 */
static struct node_t* create_node(struct node_t*, struct node_t*, void*, size_t);

/**
 * @brief Return the number for storing the given type
 * @param size_t type The type (one of the type macro)
 * @retval size_t The number of bytes for storing one element of the given type
 */
static size_t num_bytes(size_t);

static void insert_descriptor(struct list_table* table, struct list_descriptor* desc)
{
	desc->next = table->head;
	table->head = desc;
}

static void free_descriptor(struct list_descriptor* desc)
{
	struct node_t* current = desc->list_head;

	// free the nodes of the list
	while(current)
	{
		struct node_t* next = current->next;
		free_node(current);
		current = next;
	}

	free(desc);
}

static struct list_descriptor* find_descriptor(struct list_table* table, size_t lid)
{
	struct list_descriptor* current = table->head;
	while(current)
	{
		if(current->list_id == lid)
			return current;
		current = current->next;
	}
	return NULL;
}

static void free_node(struct node_t* node)
{
	if(node)
		free(node->value);
	free(node);
}

static struct node_t* free_node_recur(struct node_t* node)
{
	// update pointer pointing to it
	struct node_t* prev = node->prev;

	if(prev)
		prev->next = NULL;

	while(node)
	{
		struct node_t* next = node->next;
		free_node(node);
		node = next;
	}

	return prev;
}

static struct list_descriptor* create_descriptor(size_t lid, size_t type)
{
	struct list_descriptor* desc = malloc(sizeof(struct list_descriptor));

	if(!desc)
	{
		fprintf(stderr, "Memory allocation failure in `create_descriptor`\n");
		exit(EXIT_FAILURE);
	}

	desc->list_id = lid;
	desc->type = type;
	desc->list_size = 0;
	desc->ref_count = 0;
	desc->list_head = desc->list_tail = NULL;
	desc->next = NULL;

	return desc;
}

static size_t unique_desc_id()
{
	return list_counter++;
}

static void* cpy_value(void* value, size_t type)
{
	// allocate
	void* cpy = malloc(num_bytes(type));

	if(!cpy)
	{
		fprintf(stderr, "Memory allocation failure in `cpy_value`\n");
		exit(EXIT_FAILURE);
	}

	memcpy(cpy, value, num_bytes(type));
	return cpy;
}

static struct node_t* create_node(struct node_t* next, struct node_t* prev, void* value, size_t type)
{
	struct node_t* node = malloc(sizeof(struct node_t));

	if(!node)
	{
		fprintf(stderr, "Memory allocation failure in `create_node`\n");
		exit(EXIT_FAILURE);
	}

	node->next = next;
	node->prev = prev;
	node->value = cpy_value(value, type);

	return node;
}

static void* get_list_element(struct list_descriptor* desc, size_t pos)
{
	if(pos >= desc->list_size)
	{
		fprintf(stderr, "Out of range error in `get_list_element`\n");
		exit(EXIT_FAILURE);
	}

	struct node_t* current = desc->list_head;
	size_t cnt = 0;

	while(current)
	{
		if(cnt++ == pos)
			return current->value;
		current = current->next;
	}

	return NULL;
}

static void* remove_list_element(struct list_descriptor* desc, size_t pos)
{
	if(pos >= desc->list_size)
	{
		fprintf(stderr, "Out of range error in `remove_list_element`\n");
		exit(EXIT_FAILURE);
	}

	struct node_t* current = desc->list_head;
	size_t cnt = 0;

	while(current)
	{
		if(cnt++ == pos)
		{
			// update next and previous pointers
			if(current->next && current->prev) // middle of the list
			{	
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			else if(current->next) // begiining of the list
			{
				desc->list_head = current->next;
				current->next->prev = current->prev;
			}
			else if(current->prev) // end of the list
			{
				desc->list_tail = current->prev;
				current->prev->next = current->next;
			}
			else
				desc->list_tail = desc->list_head = NULL;

			// copy the value
			void* new_value = cpy_value(current->value, desc->type);
			// free memory 
			free_node(current);
			desc->list_size--;
			return new_value;
		}	

		current = current->next;
	}

	return NULL;
}

static void insert_list_element(struct list_descriptor* desc, size_t pos, void* elem)
{
	if(pos > desc->list_size)
	{
		fprintf(stderr, "Out of range error in `insert_list_element`\n");
		exit(EXIT_FAILURE);
	}
	
	if(pos == desc->list_size) // add at the end of the list
	{
		struct node_t* new_node = create_node(NULL, NULL, elem, desc->type);

		if(desc->list_size == 0) 
			desc->list_head = new_node;
		else
			desc->list_tail->next = new_node;

		new_node->prev = desc->list_tail;
		desc->list_tail = new_node;
		desc->list_size++;

		return;
	}

	struct node_t* current = desc->list_head;
	size_t cnt = 0;

	while(current)
	{
		if(cnt++ == pos)
		{
			struct node_t* new_node = create_node(NULL, NULL, elem, desc->type);

			// update next and previous pointers
			if(current->prev) // middle of the list
			{	
				new_node->prev = current->prev;
				new_node->next = current;
				current->prev->next = new_node;
				current->prev = new_node;
			}
			else if(!current->prev) // first element
			{
				new_node->prev = current->prev;
				new_node->next = current;
				desc->list_head = new_node;
				current->prev = new_node;
			}
			else
				desc->list_tail = desc->list_head = new_node;

			desc->list_size++;
			return;
		}	

		current = current->next;
	}
}

static size_t num_bytes(size_t type)
{
	return bytes_per_type[type];
}

// IMPLEMENTATION OF THE INTERFACE 
struct list_table* create_list_table()
{
	struct list_table* table = malloc(sizeof(struct list_table));

	if(!table)
	{
		fprintf(stderr, "Memory allocation failure in `create_list_table`\n");
		exit(EXIT_FAILURE);
	}

	table->head = NULL;
	return table;
}

void delete_list_table(struct list_table* table)
{
	if(!table)
		return;

	struct list_descriptor* current = table->head;

	while(current)
	{
		struct list_descriptor* next = current->next;
		free_descriptor(current);
		current = next;
	}

	free(table);
}

size_t list_size(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	return desc->list_size;
}

bool list_empty(struct list_table* table, size_t lid)
{
	return list_size(table, lid) == 0;
}

void list_clear(struct list_table* table, size_t lid)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	if(!desc->list_head) // list is already empty
		return;

	// set to null the head and the tail
	desc->list_head = desc->list_tail = free_node_recur(desc->list_head);
	desc->list_size = 0;
}

void list_add_reference(struct list_table* table, size_t lid)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	desc->ref_count++;
}

void list_rm_reference(struct list_table* table, size_t lid)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	desc->ref_count--;

	if(desc->ref_count == 0) // list shouldn't be freed
		list_deallocate(table, lid);
}

void list_deallocate(struct list_table* table, size_t lid)
{
	if(!table) return;

	struct list_descriptor* current = table->head, *prev = NULL;

	while(current)
	{
		if(current->list_id == lid)
		{
			if(prev) // has a previous
				prev->next = current->next;
			else // otherwise make point the table_list head on the scnd element
				table->head = current->next;
			free_descriptor(current);
			return;
		}

		prev = current;
		current = current->next;
	}
}

size_t list_allocate_int(struct list_table* table)
{
	if(!table) return 0;
	struct list_descriptor* desc = create_descriptor(unique_desc_id(), INT);
	insert_descriptor(table, desc);
	return desc->list_id;
}

size_t list_allocate_float(struct list_table* table)
{
	if(!table) return 0;
	struct list_descriptor* desc = create_descriptor(unique_desc_id(), FLOAT);
	insert_descriptor(table, desc);
	return desc->list_id;
}

size_t list_allocate_bool(struct list_table* table)
{
	if(!table) return 0;
	struct list_descriptor* desc = create_descriptor(unique_desc_id(), BOOL);
	insert_descriptor(table, desc);
	return desc->list_id;
}

size_t list_allocate_char(struct list_table* table)
{
	if(!table) return 0;
	struct list_descriptor* desc = create_descriptor(unique_desc_id(), CHAR);
	insert_descriptor(table, desc);
	return desc->list_id;
}

size_t list_allocate_string(struct list_table* table)
{
	if(!table) return 0;
	struct list_descriptor* desc = create_descriptor(unique_desc_id(), STRING);
	insert_descriptor(table, desc);
	return desc->list_id;
}

int list_front_int(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, 0);
	return *((int*)value);
}

float list_front_float(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, 0);
	return *((float*)value);
}

bool list_front_bool(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, 0);
	return *((bool*)value);
}

char list_front_char(struct list_table* table, size_t lid)
{
	if(!table) return '\0';

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return '\0';

	void* value = get_list_element(desc, 0);
	return *((char*)value);
}

size_t list_front_string(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, 0);
	return *((size_t*)value);
}

int list_back_int(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, desc->list_size - 1);
	return *((int*)value);
}

float list_back_float(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, desc->list_size - 1);
	return *((float*)value);
}

bool list_back_bool(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, desc->list_size - 1);
	return *((bool*)value);
}

char list_back_char(struct list_table* table, size_t lid)
{
	if(!table) return '\0';

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return '\0';

	void* value = get_list_element(desc, desc->list_size - 1);
	return *((char*)value);
}

size_t list_back_string(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, desc->list_size - 1);
	return *((size_t*)value);
}

int list_pop_front_int(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, 0);
	int casted_value = *((int*)value);
	free(value);
	return casted_value;
}

float list_pop_front_float(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, 0);
	float casted_value = *((float*)value);
	free(value);
	return casted_value;
}

bool list_pop_front_bool(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, 0);
	bool casted_value = *((bool*)value);
	free(value);
	return casted_value;
}

char list_pop_front_char(struct list_table* table, size_t lid)
{
	if(!table) return '\0';

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return '\0';

	void* value = remove_list_element(desc, 0);
	char casted_value = *((char*)value);
	free(value);
	return casted_value;
}

size_t list_pop_front_string(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, 0);
	size_t casted_value = *((size_t*)value);
	free(value);
	return casted_value;
}

int list_pop_back_int(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, desc->list_size - 1);
	int casted_value = *((int*)value);
	free(value);
	return casted_value;
}

float list_pop_back_float(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, desc->list_size - 1);
	float casted_value = *((float*)value);
	free(value);
	return casted_value;
}

bool list_pop_back_bool(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, desc->list_size - 1);
	bool casted_value = *((bool*)value);
	free(value);
	return casted_value;
}

char list_pop_back_char(struct list_table* table, size_t lid)
{
	if(!table) return '\0';

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return '\0';

	void* value = remove_list_element(desc, desc->list_size - 1);
	char casted_value = *((char*)value);
	free(value);
	return casted_value;
}

size_t list_pop_back_string(struct list_table* table, size_t lid)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, desc->list_size - 1);
	size_t casted_value = *((size_t*)value);
	free(value);
	return casted_value;
}

void list_push_front_int(struct list_table* table, size_t lid, int value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, 0, &value);
}

void list_push_front_float(struct list_table* table, size_t lid, float value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, 0, &value);
}

void list_push_front_bool(struct list_table* table, size_t lid, bool value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, 0, &value);
}

void list_push_front_char(struct list_table* table, size_t lid, char value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, 0, &value);
}

void list_push_front_string(struct list_table* table, size_t lid, size_t value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, 0, &value);
}

void list_push_back_int(struct list_table* table, size_t lid, int value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, desc->list_size, &value);
}

void list_push_back_float(struct list_table* table, size_t lid, float value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, desc->list_size, &value);
}

void list_push_back_bool(struct list_table* table, size_t lid, bool value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, desc->list_size, &value);
}

void list_push_back_char(struct list_table* table, size_t lid, char value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, desc->list_size, &value);
}

void list_push_back_string(struct list_table* table, size_t lid, size_t value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, desc->list_size, &value);
}

int list_get_element_int(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, pos);
	return *((int*)value);
}

float list_get_element_float(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, pos);
	return *((float*)value);
}

bool list_get_element_bool(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, pos);
	return *((bool*)value);
}

char list_get_element_char(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return '\0';

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return '\0';

	void* value = get_list_element(desc, pos);
	return *((char*)value);
}

size_t list_get_element_string(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = get_list_element(desc, pos);
	return *((size_t*)value);
}

void list_insert_element_int(struct list_table* table, size_t lid, size_t pos, int value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, pos, &value);
}

void list_insert_element_float(struct list_table* table, size_t lid, size_t pos, float value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, pos, &value);
}

void list_insert_element_bool(struct list_table* table, size_t lid, size_t pos, bool value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, pos, &value);
}

void list_insert_element_char(struct list_table* table, size_t lid, size_t pos, char value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, pos, &value);
}

void list_insert_element_string(struct list_table* table, size_t lid, size_t pos, size_t value)
{
	if(!table) return;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return;

	insert_list_element(desc, pos, &value);
}

int list_remove_element_int(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, pos);
	int casted_value = *((int*)value);
	free(value);
	return casted_value;
}

float list_remove_element_float(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, pos);
	float casted_value = *((float*)value);
	free(value);
	return casted_value;
}

bool list_remove_element_bool(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, pos);
	bool casted_value = *((bool*)value);
	free(value);
	return casted_value;
}

char list_remove_element_char(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, pos);
	char casted_value = *((char*)value);
	free(value);
	return casted_value;
}

size_t list_remove_element_string(struct list_table* table, size_t lid, size_t pos)
{
	if(!table) return 0;

	struct list_descriptor* desc = find_descriptor(table, lid);

	if(!desc) return 0;

	void* value = remove_list_element(desc, pos);
	size_t casted_value = *((size_t*)value);
	free(value);
	return casted_value;
}

// void print_list_table(const struct list_table* table)
// {
// 	const struct list_descriptor* current = table->head;

// 	int cnt = 1;
// 	while(current)
// 	{
// 		printf("\n---------------------------------------------\n");
// 		printf("List number %d (lid: %zu)\n", cnt, current->list_id);
// 		printf("   Type : ");

// 		switch(current->type)
// 		{
// 		case BOOL: printf("bool\n"); break;
// 		case INT : printf("integer\n"); break;
// 		case STRING : printf("string\n"); break;
// 		case CHAR: printf("char\n"); break;
// 		case FLOAT: printf("float\n"); break;
// 		}

// 		printf("   Size : %zu\n", current->list_size);
// 		printf("   Reference count : %zu\n", current->ref_count);
// 		printf("   Head : %p\n", current->list_head);
// 		printf("   Tail : %p\n", current->list_tail);
// 		printf("   Values : \n    ");

// 		struct node_t* node = current->list_head;
// 		int i = 0;
// 		while(node)
// 		{
// 			switch(current->type)
// 			{
// 			case BOOL: printf("%s", *((bool*) node->value) ? "true" : "false"); break;
// 			case INT : printf("%d", *((int*) node->value)); break;
// 			case STRING : printf("%zu", *((size_t*) node->value)); break;
// 			case CHAR: printf("%c", *((char*) node->value)); break;
// 			case FLOAT: printf("%f", *((float*) node->value)); break;
// 			}
			
// 			if((i + 1) % 10)
// 				printf(" ");
// 			else
// 				printf("\n    ");

// 			node = node->next;
// 			i++;
// 		}

// 		current = current->next;
// 	}

// 	printf("\n");
// }