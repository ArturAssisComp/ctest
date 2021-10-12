//Libs:
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "linked_list.h"


//Declaration of local functions:
static void _delete_next_element(linked_list_element *previous_element, linked_list *target_linked_list);
static void _delete_head_element(linked_list *target_linked_list);



//Definition of functions:
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
		error_msg = "Error while allocating memory for the linked list.\n";
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



linked_list_element *insert_item(dict_item item, linked_list *target_linked_list)
/**
 * Description: This function inserts a copy of the 'item' into the linked list 
 * pointed by 'target_linked_list', after its head. The user may not free the
 * element returned.
 *
 * Input: (dict_item) item --> The item that will be inserted into the 
 *        linked list.
 *        (linked_list *) target_linked_list --> Pointer to the linked list into
 *        which the new item will be added.
 *
 * Output: (dict_item *) --> Pointer to the interted element.
 */
{

	//Variables:
	linked_list_element *lk_element;
	char *error_msg;

	//Allocate memory:
	lk_element = malloc(sizeof (*lk_element));
	if(!lk_element)
	{
		error_msg = "Error while allocating memory for the linked list element.\n";
		goto error;
	}

	//Initialize the new element:
	lk_element->item = item;
	lk_element->next_element = target_linked_list->head;

	//Add the element:
	target_linked_list->head = lk_element;
	target_linked_list->num_of_elements++;

	//Return the result:
result:
	return lk_element;


error:
	//Error:
	fprintf(stderr, error_msg);
	exit(EXIT_FAILURE);
}


linked_list_element *get_linked_list_element(element key, linked_list *target_linked_list)
/**
 * Description: This function returns a pointer to the first element into the 
 * target linked list that has key equals to 'key' during a traverse through 
 * the linked list, starting from the head until its tail.
 *
 * Input: (element) key --> The reference value for the key.
 *        (linked_list *) target_linked_list
 *
 * Output: (linked_list_element) --> If an element with the key equals to 'key'
 *         was found, its pointer will be returned. NULL is returned otherwise.
 */
{
	//Variables:
	linked_list_element *found_element = NULL;
	linked_list_element *current_element;

	//Search for the element:
	current_element = target_linked_list->head;
	while(current_element)
	{
		if (is_equal(key, current_element->item.key))
		{
			found_element = current_element;
			break;
		}
		else current_element = current_element->next_element;
	}

result:
	return found_element;
}


linked_list_element *get_and_delete_linked_list_element(element key, linked_list *target_linked_list)
/**
 * Description: This function returns a pointer to the first element into the 
 * target linked list that has key equals to 'key' during a traverse through 
 * the linked list, starting from the head until its tail. It deletes this
 * element after finding it.
 *
 * Input: (element) key --> The reference value for the key.
 *        (linked_list *) target_linked_list
 *
 * Output: (linked_list_element) --> If an element with the key equals to 'key'
 *         was found, its pointer will be returned. NULL is returned otherwise.
 */
{
	//Variables:
	linked_list_element *found_element = NULL;
	linked_list_element *previous_element, *head_element;

	//Search for the element:
	head_element = target_linked_list->head;
	/*Check for the first element*/
	if(head_element && is_equal(key, head_element->item.key))
	{
		found_element = head_element;
		_delete_head_element(target_linked_list);
		goto result;
	}

	/*Check for the remaining elements*/
	previous_element = head_element;
	while(previous_element->next_element)
	{
		if (is_equal(key, previous_element->next_element->item.key))
		{
			found_element = previous_element->next_element;
			//Deletes the element:
			_delete_next_element(previous_element, target_linked_list);
			goto result;
		}
		else previous_element = previous_element->next_element;
	}

result:
	return found_element;
}


//Definition of local functions:
static void _delete_next_element(linked_list_element *previous_element, linked_list *target_linked_list)
{
	previous_element->next_element = previous_element->next_element->next_element;
	target_linked_list->num_of_elements--;
}



static void _delete_head_element(linked_list *target_linked_list)
{
	target_linked_list->head = target_linked_list->head->next_element;
	target_linked_list->num_of_elements--;
}
