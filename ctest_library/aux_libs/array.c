#include "types.h"
#include "array.h"
#include <stdlib.h>
#include <stdio.h>


//Definitions of functions:
array *create_array(void)
/**
 * Description: This function creates an array and returns the pointer to that 
 * array. After using, the user must call delete_array unless this array will 
 * be an element of another element that will be deleted.
 *
 * Input: (void)
 *
 * Output: (array *)
 */
{
	//Variables:
	array *new_array;
	char *error_msg;

	//Allocate memory:
	new_array = malloc(sizeof *new_array);

	if(!new_array)
	{
		error_msg = "Error while allocating memory for the array.";
		goto error;
	}

	//Initialize the array:
	new_array->el_array = NULL;
	new_array->num_of_elements = 0;
	new_array->capacity = 0;

result:
	return new_array;

error:
	fprintf(stderr, error_msg);
	exit(EXIT_FAILURE);
}
