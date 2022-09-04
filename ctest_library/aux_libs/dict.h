#ifndef _CTEST_DICT_H
#define _CTEST_DICT_H

//Include libs:
#include "types.h"
#include <stdbool.h>


//Declarations of functions:
T_dict *D_create_dict(T_hash_type table_size);
void D_assign_value_to_key(T_element key, T_element value, T_dict *target_dict);
T_element *D_get_value(T_element key, T_dict *target_dict);
bool D_delete_element(T_element key, T_dict *target_dict);
T_array *D_dict_to_array(T_dict *target_dict);
void D_delete_dict(T_dict **ptr_to_dict);

#endif
