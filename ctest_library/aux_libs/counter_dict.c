#include "counter_dict.h"
#include "array.h"
#include "types.h"
#include "dict.h"
#include <stdio.h>




T_dict *CD_count_elements(T_array *target_array)
/**
 * Description: this function counts how many times each T_element from 'target_array' 
 * repeats and saves each index that this repetition occurs. The 'target_array' 
 * must have only hashable elements, otherwise an error occurs. The result is 
 * returned as a T_dict and each item has the following format: 
 * {<element_counted>:{"count":n, "indices":[<index_0>, <index_1>, ..., <index_n-1>]}}.
 *
 * Input: (T_array *) target_array
 *
 * Output: (T_dict *)
 *
 * Time complexity: O(target_array->num_of_elements);
 * Space Complexity: O(target_array->num_of_elements);
 */
{
	//Variables:
	size_t i;
	T_element current_element, *current_counter_value, *count, *indices;
	T_array *indices_array;
	T_dict *counter, *element_dict;
	char *error_message;

	//Create the counter:
	counter = D_create_dict(target_array->num_of_elements / 10 + 5);

	//Loop through the target T_array:
	i = target_array->num_of_elements;
	while(i > 0)
	{
		//Decrease index:
		i--;


		current_element = *A_get_element(i, target_array);
		current_counter_value = D_get_value(current_element, counter);

		if(!current_counter_value)
		{
			//Create the T_element T_dict:
			element_dict = D_create_dict(1);
			D_assign_value_to_key((T_element){{.str = "count"}, STRING}, (T_element){{.u_i = 0}, UNSIGNED_INTEGER}, element_dict);
			indices_array = A_create_array();
			D_assign_value_to_key((T_element){{.str = "indices"}, STRING}, (T_element){{.arr = indices_array}, ARRAY}, element_dict);
			indices_array = NULL;

			//Add the key:element_dict to the counter:
			D_assign_value_to_key(current_element, (T_element){{.dct = element_dict}, DICT}, counter);
			element_dict = NULL;

			//Get the current_counter_value again:
			current_counter_value = D_get_value(current_element, counter);
			if(!current_counter_value)
			{
				error_message = "Error: can not add the value related to the key into the T_dict.";
				goto error;
			}

		}

		//Increment the counter: 
		count = D_get_value((T_element){{.str = "count"}, STRING}, current_counter_value->value.dct);
		count->value.u_i++;
		count = NULL;

		//Add the current index to the indices T_array:
		indices = D_get_value((T_element){{.str = "indices"}, STRING}, current_counter_value->value.dct);
		A_append_element((T_element){{.u_i = i}, UNSIGNED_INTEGER}, indices->value.arr);

		current_counter_value = NULL;
	}


result:
	return counter;

error:
	fprintf(stderr, error_message);
	exit(EXIT_FAILURE);
}


size_t CD_pop_next_index(T_element key, T_dict *target_counter_dict)
/**
 * Description: This function pops the minimun index of the T_element 'key' in 
 * relation to the T_array that was used to create the target counter T_dict. If 
 * there is no item with key equals 'key', an error is raised. If an element
 * is deleted and count becomes 0, the element is removed from the dictionary.
 *
 * Input: (T_element) key
 *        (T_dict *) target_counter_dict
 * Output: (size_t)
 */
{
	//Variables:
	size_t result;
	T_element *temp_element, popped_index_element, *count_element;
	T_array *indices_array;
	char *error_message;


	//Get the index:
	temp_element = D_get_value(key, target_counter_dict);
	if(!temp_element)
	{
		error_message = "Error: The counter does not have any item with the current key.\n";
		goto error;
	}
	indices_array = D_get_value((T_element){{.str = "indices"}, STRING}, temp_element->value.dct)->value.arr;
	popped_index_element = A_pop(indices_array);
	result = popped_index_element.value.u_i;
	//Update the count:
	count_element = D_get_value((T_element){{.str = "count"}, STRING}, temp_element->value.dct);
	if(count_element->type != UNSIGNED_INTEGER)
	{
		error_message = "Error: count T_element is not an unsigned integer.\n";
		goto error;
	}
	count_element->value.u_i--;

	//Delete the item if count reaches 0:
	if(count_element->value.u_i == 0)
	{
		if(!D_delete_element(key, target_counter_dict))
		{
			error_message = "Error while deleting the item with count 0.\n";
			goto error;
		}
	}

	//Free the popped T_element:
	T_free_element(&popped_index_element);

result:
	return result;

error:
	fprintf(stderr, error_message);
	exit(EXIT_FAILURE);
	
}

size_t CD_get_count(T_element key, T_dict *target_dict)
/**
 * Description: This function returns the current "count" related to the T_element 
 * 'key' in the target_dict. It returns 0 if the T_element is not found.
 *
 * Input: (T_element) key
 *        (T_dict *) target_dict
 *
 * Output: (size_t)
 */
{
	//Variables:
	T_element *intermediate_dict, *result_element;
	size_t result;
	char *error_message;

	//Get the count value:
	intermediate_dict = D_get_value(key, target_dict);
	if(!intermediate_dict)
	{
		result = 0;
	}
	else
	{
		if(intermediate_dict->type != DICT)
		{
			error_message = "Target T_dict corrupted.\n";
			goto error;
		}
		result_element = D_get_value((T_element){{.str = "count"}, STRING}, intermediate_dict->value.dct);
		if(result_element->type != UNSIGNED_INTEGER)
		{
			error_message = "Target T_dict corrupted.\n";
			goto error;
		}
		result = result_element->value.u_i;
	}

result:
	return result;

error:
	fprintf(stderr, error_message);
	exit(EXIT_FAILURE);

}
