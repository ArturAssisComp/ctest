#include "types.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


bool is_equal(element e1, element e2)
/**
 * Description: This function returns true if e1 is equal to e2. It returns false 
 * otherwise.
 *
 * Input: (element) e1, e2 --> Elements that will be compared for equality.
 *
 * Output: (bool) --> Boolean that says if e1 is equal to e2.
 */
{
	//Variables:
	bool result = false;
	char *error_msg;

	//Check if they have different type:
	if (e1.type != e2.type) goto result;

	//Compare the values:
	switch (e1.type)
	{
		case UNSIGNED_INTEGER:
			result = (e1.value.u_i == e2.value.u_i);
			break;
		case INTEGER:
			result = (e1.value.i == e2.value.i);
			break;
		case CHAR:
			result = (e1.value.c == e2.value.c);
			break;
		case STRING:
			result = (strcmp(e1.value.str, e2.value.str) == 0);
			break;
		case BOOL:
			result = (e1.value.b == e2.value.b);
			break;
		case _NULL:
			result = true;
			break;
		case FLOATING_POINT:
		case ARRAY:
		case DICT:
			error_msg = "Comparison for equality is not implemented.";
			goto error;
			break;
		default:
			break;
			
	}

result:
	return result;

error:
	fprintf(stderr, error_msg);
	exit(EXIT_FAILURE);
}

void free_element(element e)
{
	//Variables:
	char *error_msg;

	//Compare the values:
	switch (e.type)
	{
		case UNSIGNED_INTEGER:
		case INTEGER:
		case CHAR:
		case STRING:
		case BOOL:
			e.type = _NULL;
			break;
		case _NULL:
			error_msg = "Calling free_element for a _NULL element.";
			goto error;
			break;
		case FLOATING_POINT:
		case ARRAY:
		case DICT:
			error_msg = "Comparison for equality is not implemented.";
			goto error;
			break;
		default:
			break;
			
	}

result:
	return;

error:
	fprintf(stderr, error_msg);
	exit(EXIT_FAILURE);
}

