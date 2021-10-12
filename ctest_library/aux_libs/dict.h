#ifndef COUNTER_H
#define COUNTER_H

//Include libs:
#include "types.h"
#include <stdbool.h>


//Declarations of functions:
dict *create_dict(hash_type table_size);
//void assign_value_to_key(key, value, dict)
//get_value(key, dict)
//delete_element(key, dict)
void delete_dict(dict **ptr_to_dict);

#endif
