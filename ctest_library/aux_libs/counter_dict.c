#include "counter_dict.h"
#include "array.h"
#include "types.h"
#include "dict.h"
#include <stdio.h>




dict *count_elements(array *target_array)
/**
 * Description: this function counts how many times each element from 'target_array' 
 * repeats and saves each index that this repetition occurs. The 'target_array' 
 * must have only hashable elements, otherwise an error occurs. The result is 
 * returned as a dict and each item has the following format: 
 * {<element_counted>:{"count":n, "indices":[<index_0>, <index_1>, ..., <index_n-1>]}}.
 *
 * Input: (array *) target_array
 *
 * Output: (dict *)
 *
 * Time complexity: O(target_array->num_of_elements);
 * Space Complexity: O(target_array->num_of_elements);
 */
{
	//Variables:
	size_t i;
	element current_element, *current_counter_value, *count, *indices;
	array *indices_array;
	dict *counter, *element_dict;
	char *error_message;

	//Create the counter:
	counter = create_dict(target_array->num_of_elements / 10 + 5);

	//Loop through the target array:
	i = target_array->num_of_elements;
	while(i > 0)
	{
		//Decrease index:
		i--;


		current_element = *get_element(i, target_array);
		current_counter_value = get_value(current_element, counter);

		if(!current_counter_value)
		{
			//Create the element dict:
			element_dict = create_dict(1);
			assign_value_to_key((element){{.str = "count"}, STRING}, (element){{.u_i = 0}, UNSIGNED_INTEGER}, element_dict);
			indices_array = create_array();
			assign_value_to_key((element){{.str = "indices"}, STRING}, (element){{.arr = indices_array}, ARRAY}, element_dict);
			indices_array = NULL;

			//Add the key:element_dict to the counter:
			assign_value_to_key(current_element, (element){{.dct = element_dict}, DICT}, counter);
			element_dict = NULL;

			//Get the current_counter_value again:
			current_counter_value = get_value(current_element, counter);
			if(!current_counter_value)
			{
				error_message = "Error: can not add the value related to the key into the dict.";
				goto error;
			}

		}

		//Increment the counter: 
		count = get_value((element){{.str = "count"}, STRING}, current_counter_value->value.dct);
		count->value.u_i++;
		count = NULL;

		//Add the current index to the indices array:
		indices = get_value((element){{.str = "indices"}, STRING}, current_counter_value->value.dct);
		append_element((element){{.u_i = i}, UNSIGNED_INTEGER}, indices->value.arr);

		current_counter_value = NULL;
	}


result:
	return counter;

error:
	fprintf(stderr, error_message);
	exit(EXIT_FAILURE);
}


size_t pop_next_index(element key, dict *target_counter_dict)
/**
 * Description: This function pops the minimun index of the element 'key' in 
 * relation to the array that was used to create the target counter dict. If 
 * there is no item with key equals 'key', an error is raised.
 *
 * Input: (element) key
 *        (dict *) target_counter_dict
 * Output: (size_t)
 */
{
	//Variables:
	size_t result;
	element *temp_element, popped_index_element, *count_element;
	array *indices_array;
	char *error_message;


	//Get the index:
	temp_element = get_value(key, target_counter_dict);
	if(!temp_element)
	{
		error_message = "Error: The counter does not have any item with the current key.\n";
		goto error;
	}
	indices_array = get_value((element){{.str = "indices"}, STRING}, temp_element->value.dct)->value.arr;
	popped_index_element = pop(indices_array);
	result = popped_index_element.value.u_i;
	//Update the count:
	count_element = get_value((element){{.str = "count"}, STRING}, temp_element->value.dct);
	if(count_element->type != UNSIGNED_INTEGER)
	{
		error_message = "Error: count element is not an unsigned integer.\n";
		goto error;
	}
	count_element->value.u_i--;

	//Delete the item if count reaches 0:
	if(count_element->value.u_i == 0)
	{
		if(!delete_element(key, target_counter_dict))
		{
			error_message = "Error while deleting the item with count 0.\n";
			goto error;
		}
	}

	//Free the popped element:
	free_element(&popped_index_element);

result:
	return result;

error:
	fprintf(stderr, error_message);
	exit(EXIT_FAILURE);
	
}

