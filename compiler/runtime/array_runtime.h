#ifndef ARRAY_RUNTIME_DEFINED
#define ARRAY_RUNTIME_DEFINED 

#include <stdlib.h>
#include <stdbool.h>

// opaque type for array_table
struct array_table;

//void print_array_table(const struct array_table*);

/**
 * @brief Create an array table
 * @retval struct array_table* The array table allocated, NULL on error
 */
struct array_table* create_array_table();

/**
 * @brief Delete an array table
 * @param struct array_table* The array table to delete
 */
void delete_array_table(struct array_table*);

/**
 * @brief New T array allocation function
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_t size The size of the array
 * @param T* populate A pointer to an array of size 'size' for populating the array
 * @retval size_t The allocated array identifier
 * @note The reference count is initialized to 0
 * @note The reference count of the strings is incremented
 */
size_t array_allocate_int(struct array_table*, size_t, int*);
size_t array_allocate_float(struct array_table*, size_t, float*);
size_t array_allocate_string(struct array_table*, size_t, size_t*);
size_t array_allocate_char(struct array_table*, size_t, char*);
size_t array_allocate_bool(struct array_table*, size_t, bool*);

/**
 * @brief Record a new reference to the array having the given id
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id 
 */
void array_add_reference(struct array_table*, size_t);

/**
 * @brief Record the deletion of a reference for the given array
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id
 */
void array_rm_reference(struct array_table*, size_t);

/**
 * @brief Return the size of the array having the given id
 * @param const struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id 
 * @retval size_t The size of the array, 0 if the size is not found
 */
size_t array_size(const struct array_table*, size_t);

/**
 * @brief Return the reference count of the array having the given id
 * @param const struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id 
 * @retval size_t The ref count
 */
size_t array_ref_count(const struct array_table*, size_t);

/**
 * @brief Deallocate the memory associated with array
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id
 * @param If the array contains elements that should be deallocated they are deallocated only if their reference count reach 0
 */
void array_deallocate(struct array_table*, size_t);

/**
 * @brief Insertion an element of type T in the array having the given id
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id
 * @param T item The element to add (in the case of a string the item is and arrid)
 * @param size_t pos The position of the element to add (in [0, size], if pos == size then the size of the array is increased of one element)
 */
void array_insert_int(struct array_table*, size_t, int, size_t);
void array_insert_bool(struct array_table*, size_t, bool, size_t);
void array_insert_float(struct array_table*, size_t, float, size_t);
void array_insert_char(struct array_table*, size_t, char, size_t);
void array_insert_string(struct array_table*, size_t, size_t, size_t);

/**
 * @brief Get an element of type T in the array having the given id
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id
 * @param size_t pos The position of the element to add (in [0, size[)
 * @retval T The element at the position pos
 */
int array_get_int(struct array_table*, size_t, size_t);
float array_get_float(struct array_table*, size_t, size_t);
bool array_get_bool(struct array_table*, size_t, size_t);
char array_get_char(struct array_table*, size_t, size_t);
size_t array_get_string(struct array_table*, size_t, size_t);

/**
 * @brief Reset the size of the array having the given id to zero and deallocate the memory
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id
 */
void array_clear(struct array_table*, size_t);

/**
 * @brief Remove the nth element of the table
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_t arrid The array id
 * @param size_t pos The position of the element to remove
 */
void array_remove(struct array_table*, size_t, size_t);

/**
 * @brief Remove the nth element of the table
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_t arrid The array id
 * @param size_t pos The position of the element to remove
 * @retval T The element removed
 */
int array_remove_int(struct array_table*, size_t, size_t);
float array_remove_float(struct array_table*, size_t, size_t);
bool array_remove_bool(struct array_table*, size_t, size_t);
char array_remove_char(struct array_table*, size_t, size_t);
size_t array_remove_string(struct array_table*, size_t, size_t);

/**
 * @brief Pop a value from an array (get the last element) and erase it from the array 
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id
 * @retval T The element at the position pos
 */
int array_pop_int(struct array_table*, size_t);
float array_pop_float(struct array_table*, size_t);
bool array_pop_bool(struct array_table*, size_t);
char array_pop_char(struct array_table*, size_t);
size_t array_pop_string(struct array_table*, size_t);

/**
 * @brief Push a value in an array (increase the size of 1)
 * @param struct array_table* descriptor The array_table structure (containing information about all the arrays)
 * @param size_it arrid The array id
 * @param T item The element to push
 */
void array_push_int(struct array_table*, size_t, int);
void array_push_float(struct array_table*, size_t, float);
void array_push_bool(struct array_table*, size_t, bool);
void array_push_char(struct array_table*, size_t, char);
void array_push_string(struct array_table*, size_t, size_t);

#endif