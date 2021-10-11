//Libs:
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "linked_list.h"

//Declaration of functions:
linked_list *create_linked_list()
/**
 * Description: This function creates a new linked list allocating memory and 
 * initializing it with 0 elements. The user must delete the linked list calling 
 * the function delete_linked_list after using it.
 *
 * Input: (none)
 *
 * Output: (linked_list *) --> Pointer to the linked list that was created.
 */
{
	//Variables:
	linked_list *new_linked_list;
	char *error_msg;

	//Allocate memory:
	new_linked_list = malloc(sizeof (*new_linked_list));
	if(!new_linked_list)
	{
		error_msg = "Error while allocating memory for the linked list.";
		goto error;
	}

	//Initialize the allocated linked list:
	new_linked_list->head = NULL;
	new_linked_list->num_of_elements = 0;

	//Return the result:
result:
	return new_linked_list;


error:
	//Error:
	fprintf(stderr, error_msg);
	exit(EXIT_FAILURE);
	
}


