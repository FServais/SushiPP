#ifndef LIST_RUNTIME_H_DEFINED
#define LIST_RUNTIME_H_DEFINED

#include <stdlib.h>
#include <stdbool.h>

// opaque type for list_table : stores the data of every lists
struct list_table; 

/**
 * @brief Construct an empty list table
 * @retval struct list_table* A pointer to the list, NULL on error
 */
struct list_table* create_list_table();

/**
 * @brief Delete the given list table
 * @param struct list_table* A pointer to the list table
 */
void delete_list_table(struct list_table*);

/**
 * @brief Return the list size
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 * @retval size_t The size of the list
 */
size_t list_size(struct list_table*, size_t);
size_t list_size_int(struct list_table*, size_t); // alias for list_size
size_t list_size_bool(struct list_table*, size_t); // alias for list_size
size_t list_size_float(struct list_table*, size_t); // alias for list_size
size_t list_size_string(struct list_table*, size_t); // alias for list_size
size_t list_size_char(struct list_table*, size_t); // alias for list_size

/**
 * @brief Check wether the given list is empty
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 * @retval bool True if the list is empty, false otherwise
 */
bool list_empty(struct list_table*, size_t);
bool list_empty_int(struct list_table*, size_t); // alias
bool list_empty_bool(struct list_table*, size_t); // alias
bool list_empty_float(struct list_table*, size_t); // alias
bool list_empty_string(struct list_table*, size_t); // alias
bool list_empty_char(struct list_table*, size_t); // alias

/**
 * @brief Clear the list 
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 */
void list_clear(struct list_table*, size_t);
void list_clear_int(struct list_table*, size_t); // alias
void list_clear_bool(struct list_table*, size_t); // alias
void list_clear_float(struct list_table*, size_t); // alias
void list_clear_string(struct list_table*, size_t); // alias
void list_clear_char(struct list_table*, size_t); // alias

/**
 * @brief Increment the reference count of the given list
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 */
void list_add_reference(struct list_table*, size_t);

/**
 * @brief Decrement the reference count of the given list
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 * @note If the reference count drops to 0, the list is deleted (and deallocated)
 */
void list_rm_reference(struct list_table*, size_t);

/**
 * @brief Deallocate the memory associated with list
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 */
void list_deallocate(struct list_table*, size_t);

/**
 * @brief Creates a new list and return its identifier
 * @param struct list_table* table A valid pointer to the list table
 * @retval size_t The new list identifier
 */
size_t list_allocate_int(struct list_table*);
size_t list_allocate_float(struct list_table*);
size_t list_allocate_bool(struct list_table*);
size_t list_allocate_char(struct list_table*);
size_t list_allocate_string(struct list_table*);

/**
 * @brief Return the element at the front of the given list (if the list is empty, the program is exited)
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 * @retval T The element at the front of the list
 */
int list_front_int(struct list_table*, size_t);
float list_front_float(struct list_table*, size_t);
bool list_front_bool(struct list_table*, size_t);
char list_front_char(struct list_table*, size_t);
size_t list_front_string(struct list_table*, size_t);

/**
 * @brief Return the element at the back of the list (if the list is empty, the program is exited)
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id  
 * @retval T The element at the back of the list
 */
int list_back_int(struct list_table*, size_t);
float list_back_float(struct list_table*, size_t);
bool list_back_bool(struct list_table*, size_t);
char list_back_char(struct list_table*, size_t);
size_t list_back_string(struct list_table*, size_t);

/**
 * @brief Return the element at the front of the given list and remove it from the list (if the list is empty, the program is exited)
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 */
int list_pop_front_int(struct list_table*, size_t);
float list_pop_front_float(struct list_table*, size_t);
bool list_pop_front_bool(struct list_table*, size_t);
char list_pop_front_char(struct list_table*, size_t);
size_t list_pop_front_string(struct list_table*, size_t);

/**
 * @brief Return the element at the back of the list and remove it from the list (if the list is empty, the program is exited)
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id  
 * @retval T The element at the back of the list
 */
int list_pop_back_int(struct list_table*, size_t);
float list_pop_back_float(struct list_table*, size_t);
bool list_pop_back_bool(struct list_table*, size_t);
char list_pop_back_char(struct list_table*, size_t);
size_t list_pop_back_string(struct list_table*, size_t);

/**
 * @brief Insert the given element at the front of the list
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 * @param T elem The element to add into the list
 */
void list_push_front_int(struct list_table*, size_t, int);
void list_push_front_float(struct list_table*, size_t, float);
void list_push_front_bool(struct list_table*, size_t, bool);
void list_push_front_char(struct list_table*, size_t, char);
void list_push_front_string(struct list_table*, size_t, size_t);

/**
 * @brief Insert the given element at the back of the list
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 * @param T elem The element to add into the list
 */
void list_push_back_int(struct list_table*, size_t, int);
void list_push_back_float(struct list_table*, size_t, float);
void list_push_back_bool(struct list_table*, size_t, bool);
void list_push_back_char(struct list_table*, size_t, char);
void list_push_back_string(struct list_table*, size_t, size_t);

/**
 * @brief Return the element at the given position of the list (if the element does not exist the program is exited)
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 * @param size_t pos The position of the element to insert (in [0, list_size[) starting from the front of the list
 * @retval T The element taken from the list
 */
int list_get_element_int(struct list_table*, size_t, size_t);
float list_get_element_float(struct list_table*, size_t, size_t);
bool list_get_element_bool(struct list_table*, size_t, size_t);
char list_get_element_char(struct list_table*, size_t, size_t);
size_t list_get_element_string(struct list_table*, size_t, size_t);

/**
 * @brief Insert the element at the given position of the list (if the position is invalid, the program is exited)
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 * @param size_t pos The position of the element to insert (in [0, list_size[) starting from the front of the list
 */
void list_insert_element_int(struct list_table*, size_t, size_t, int);
void list_insert_element_float(struct list_table*, size_t, size_t, float);
void list_insert_element_bool(struct list_table*, size_t, size_t, bool);
void list_insert_element_char(struct list_table*, size_t, size_t, char);
void list_insert_element_string(struct list_table*, size_t, size_t, size_t);

/**
 * @brief Return the element at the given position of the list and remove it from the list (if the element does not exist the program is exited)
 * @param struct list_table* table A valid pointer to the list table
 * @param size_t lid The list id 
 * @param size_t pos The position of the element to insert (in [0, list_size[) starting from the front of the list
 * @retval T The element taken from the list
 */
int list_remove_element_int(struct list_table*, size_t, size_t);
float list_remove_element_float(struct list_table*, size_t, size_t);
bool list_remove_element_bool(struct list_table*, size_t, size_t);
char list_remove_element_char(struct list_table*, size_t, size_t);
size_t list_remove_element_string(struct list_table*, size_t, size_t);

/**
 * @brief Create a list of integers ranging from a to b 
 * @param struct list_table* descriptor The list_table structure (containing information about all the lists)
 * @param size_t a The first element in the range
 * @param size_t b The last element in the range
 * @note If b < a, an empty list is returned
 */
size_t list_make_sequence(struct list_table*, size_t, size_t);

//void print_list_table(const struct list_table*);

#endif // LIST_RUNTIME_H_DEFINED