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


void append_element(element e, array *current_array)
/**
 * Description: This function appends the element 'e' at the end of the array 
 * 'current_array'. If the array does not have the capacity to receive this new 
 * element, it allocates more memory.
 *
 * Input: (element) e
 *        (array *) current_array
 *
 * Output: (void)
 */
{

	//Variables:
	size_t new_capacity, index;
	char *error_message;
	element *temp;
	

	//Check if capacity is enough:
	if(current_array->num_of_elements + 1 > current_array->capacity)
	{
		//Allocate more memory:
		new_capacity = 2 * current_array->capacity + 5;
		temp = realloc(current_array->el_array, new_capacity * sizeof *current_array->el_array);

		if(temp)
		{
			current_array->el_array = temp;
			current_array->capacity = new_capacity;
		}
		else
		{
			delete_array(&current_array);
			error_message = "Error while expanding the capacity of the array.\n";
			goto error;
		}
	}

	//Add the new element:
	index = current_array->num_of_elements;
	current_array->el_array[index] = e;
	current_array->num_of_elements++;

result:
	return;

error:
	fprintf(stderr, error_message);
	exit(EXIT_FAILURE);
}


void delete_array(array **ptr_to_array)
{
	;
}
