#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

//Libs:
#include "types.h"
#include <stdbool.h>
#include <stdlib.h>


//Declaration of functions:
bool is_hashable(element e);
hash_type generate_hash(element e, hash_type max_limit);



#endif
