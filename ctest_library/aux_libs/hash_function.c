#include "hash_function.h"
#include "types.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//Declaration of local functions:
static hash_type _generate_unsigned_integer_hash(unsigned_integer value, hash_type max_limit);
static hash_type _generate_integer_hash(integer value, hash_type max_limit);
static hash_type _generate_char_hash(char value, hash_type max_limit);
static hash_type _generate_string_hash(char *value, hash_type max_limit);
static hash_type _generate_bool_hash(bool value, hash_type max_limit);

//Definitions of the functions:
bool is_hashable(element e)
{
	//Variables:
	char *error_msg;
	bool result = false;

	//Compare the values:
	switch (e.type)
	{
		//Is hashable:
		case UNSIGNED_INTEGER:
		case INTEGER:
		case CHAR:
		case STRING:
		case BOOL:
			result = true;
			break;
		//Is not hashable:
		case _NULL:
		case FLOATING_POINT:
		case ARRAY:
		case DICT:
			break;
		default:
			break;
			
	}

	return result;
}


hash_type generate_hash(element e, hash_type max_limit)
/**
 * Description: This function calculates the hash value of the elment 'e'. If 
 * the element 'e' is not hashable, it raises an error. The max_limit is the 
 * maximum value of the hash without including it.
 * Ex.: The hash of an element 'e' with max_limit == 3 is in the set {0, 1, 2}.
 *
 * Input: (element) e --> It is a copy of the element that will have the hash 
 *         calculated.
 *        (hash_type) max_limit --> The maximum hash value that can be generated, 
 *         not including itself.
 *
 * Output: (hash_type) --> The hash value calculated.
 */
{
	//Variables:
	char *error_msg;
	hash_type hash;

	//Check if the element is hashable:
	if(is_hashable(e))
	{
		switch (e.type)
		{
			//Is hashable:
			case UNSIGNED_INTEGER:
				hash = _generate_unsigned_integer_hash(e.value.u_i, max_limit);
				break;
			case INTEGER:
				hash = _generate_integer_hash(e.value.i, max_limit);
				break;
			case CHAR:
				hash = _generate_char_hash(e.value.c, max_limit);
				break;
			case STRING:
				hash = _generate_string_hash(e.value.str, max_limit);
				break;
			case BOOL:
				hash = _generate_bool_hash(e.value.b, max_limit);
				break;
			default:
				error_msg = "The element type is not specified.\n";
				goto error;
				break;
				
		}
	}
	else
	{
		error_msg = "The element is not hashable.\n";
		goto error;
	}
	
result:
	return hash;

error:
	fprintf(stderr, error_msg);
	exit(EXIT_FAILURE);
	
}

//Definitions of local functions:
static hash_type _generate_unsigned_integer_hash(unsigned_integer value, hash_type max_limit)
{
	while(value < (unsigned_integer) max_limit) value = value * 3 + 13;
	return (hash_type) value % max_limit;
}

static hash_type _generate_integer_hash(integer value, hash_type max_limit)
{
	if(value < 0) value *= -2;
	while(value < (integer) max_limit) value = value * 3 + 13;
	return (hash_type) value % max_limit;
}

static hash_type _generate_char_hash(char value, hash_type max_limit)
{
	hash_type current_hash_type_value = (hash_type) value;
	while(current_hash_type_value <  max_limit) current_hash_type_value = current_hash_type_value * 3 + 13;
	return (hash_type) current_hash_type_value % max_limit;
}

static hash_type _generate_string_hash(char *value, hash_type max_limit)
{
	hash_type current_hash_type_value = 0;
	size_t i;
	for (i = 0; i < strlen(value); i++)
	{
		current_hash_type_value += value[i];
	}
	while(current_hash_type_value <  max_limit) current_hash_type_value = current_hash_type_value * 3 + 13;
	return (hash_type) current_hash_type_value % max_limit;
}

static hash_type _generate_bool_hash(bool value, hash_type max_limit)
{
	if(value)
		return 127 % max_limit;
	else
		return 2389 % max_limit;
}

