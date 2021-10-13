#ifndef COUNTER_H
#define COUNTER_H

//Include libs:
#include "types.h"
#include <stdbool.h>


//Declarations of functions:
dict *create_dict(hash_type table_size);
void assign_value_to_key(element key, element value, dict *target_dict);
element *get_value(element key, dict *target_dict);
bool delete_element(element key, dict *target_dict);
void delete_dict(dict **ptr_to_dict);

#endif
