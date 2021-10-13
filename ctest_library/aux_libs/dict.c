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
	created_dict->num_of_items = 0;
	
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



void assign_value_to_key(element key, element value, dict *target_dict)
/**
 * Description: This function assigns the value 'value' to the key 'key' into 
 * the dict 'target_dict'. If key is not hashable, an error occurs.
 *
 * Input: (element) key, value --> A copy of the key and the value that will be 
 *         used as reference to create an item key:value and to add it into the 
 *         target dict.
 *         (dict *) target_dict;
 *
 * Output: (void)
 */
{
	//Variables:
	dict_item dict_item_to_add;
	hash_type hash_value;
	linked_list *current_linked_list;
	linked_list_element *found_element;

	//Generate the hash value:
	hash_value  = generate_hash(key, target_dict->table_size);
	

	//Check if the element already exist:
	current_linked_list = target_dict->table[hash_value];
	found_element = get_linked_list_element(key, current_linked_list);
	if(found_element)
	{
		free_element(found_element->item.value);
		found_element->item.value = value;
	}
	else
	{
		//Initialize the dict that will be added:
		dict_item_to_add.hash  = hash_value;
		dict_item_to_add.key   = key;
		dict_item_to_add.value = value;

		//Add the element into the linked list of the dict:
		insert_item(dict_item_to_add, current_linked_list);
		target_dict->num_of_items++;
	}


}

element *get_value(element key, dict *target_dict)
/**
 * Description: This function returns a pointer to the value of the item of 
 * 'target_dict' that has key equals to 'key'. If the element with key 'key'
 * is not found, NULL is returned. 'key' must be a hashable element, otherwise
 * an error is raised.
 *
 * Input: (element) key
 *        (dict *) target_dict
 *
 * Output: (element *)
 */
{
	//Variables:
	element *found_value = NULL;
	linked_list_element *found_linked_list_element;
	hash_type hash_value;

	//Calculate the hash:
	hash_value  = generate_hash(key, target_dict->table_size);

	//Get the element:
	found_linked_list_element = get_linked_list_element(key, target_dict->table[hash_value]);

	if(found_linked_list_element) found_value = &(found_linked_list_element->item.value);

	return found_value;
}
