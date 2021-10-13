#ifndef ARRAY_H
#define ARRAY_H

//Libs
#include "types.h"
#include <stdlib.h>

//Declarations of functions:
array *create_array(void);
element *get_element(size_t index, array *current_array);
void append_element(element e, array *current_array);
element *pop(array *current_array);
void delete_array(array **ptr_to_array);
#endif
