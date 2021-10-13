#ifndef COUNTER_DICT_H
#define COUNTER_DICT_H

//Include libs:
#include "types.h"



//Macro constants:

//Declaration of types:

//Declaration of functions:
dict *count_elements(array *target_array);
size_t get_next_index(element key, dict *target_dict);
size_t get_count(element key, dict *target_dict);

#endif
