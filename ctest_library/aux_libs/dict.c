#include "types.h"
#include "dict.h"
#include "linked_list.h"
#include "hash_function.h"
#include <stdio.h>
#include <stdlib.h>


//Definitions of the functions:
dict *create_dict(hash_type table_size)
/**
 * Description: This function creates a dict, allocating the memory necessary. 
 * The user must call delete_dict after using it.
 *
 * Input: (hash_type) table_size --> The size of the table that will be used to 
 *         store the elements. The table is an array of linked lists.
 *
 * Output: (dict *) --> The created dict.
 */
{
	//Variables:
	dict *created_dict;
	char *error_message;
	hash_type i;

	//Allocate memory for the dict:
	created_dict = malloc(sizeof (*created_dict));
	if(!created_dict)
	{
		error_message = "Problems while allocating memory for the dict.\n";
		goto error;
	}

	//Initialize the dict:
	created_dict->table = calloc(table_size, sizeof (linked_list*));
	if(!created_dict->table)
	{
		error_message = "Problems while allocating memory for the table of the dict.\n";
		goto error;
	}

	for(i = 0; i < table_size; i++)
	{
		created_dict->table[i] = create_linked_list();
		if(!created_dict->table[i])
		{
			error_message = "Problems while allocating memory for the linked list of the table of the dict.\n";
			goto error;
		}

	}
	
	created_dict->table_size = table_size;
	
result:
	return created_dict;

error:
	fprintf(stderr, error_message);
	exit(EXIT_FAILURE);

}

void delete_dict(dict **ptr_to_dict)
{
	;
}


