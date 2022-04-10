#ifndef SET_H
#define SET_H

#include "types.h"
#include <stdbool.h>


//Declarations of functions:
T_set *S_create_set(T_hash_type table_size);
bool S_has_element(T_element element, T_set *target_set);
bool S_remove_element(T_element element, T_set *target_set);
void S_add_element(T_element element, T_set *target_set);
bool S_is_subset(T_set *set1, T_set *set2);
bool S_is_equal(T_set *set1, T_set *set2);
T_array *S_set_to_array(T_set *current_set);
T_set *S_array_to_set(T_array *current_array);
void S_delete_set(T_set **ptr_to_set);

#endif
