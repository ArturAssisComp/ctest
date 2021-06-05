/**
 * Author: Artur Assis Alves
 * Date: 15/05/2021
 * Title: Assert functions file.
 */

/**
 * Description: This file contains the standard assert functions.
 */

//Includes:
#include "ctest.h"
#include <stdio.h>


//Definitions of global Variables:
result global_result = {0};


//Definitions of assert functions:
/*Built-in types:*/
void assert_int_equal(int target, int ref)
/**
 * Description: This function compares the values of two 'int' numbers. 
 * Then, it returns the result.
 *
 * Input: (int) target --> Value that will be compared with the reference in 
 *                         order to test some function.
 *        (int) ref --> The reference value.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
	int n;

	if (target == ref)
	{
		//Successful test:
		global_result.was_successful = TRUE;
		global_result.result_message[0] = '\0';
	}else
	{
		//Failed test:
		global_result.was_successful = FALSE;

		//Generate the error message:
		n = snprintf(global_result.result_message, 
					MAX_CHARS,
					"The target value is not equal to the reference value.\n %d != %d (target != reference)\n", 
					target, 
					ref
			    );
			   
		if (n < 0) //Error creating the result message.
		{
			fprintf(stderr, "Error while generating the result message.\n");
			exit(EXIT_FAILURE);
		}
	}

	//Print the results:
	print_result();
	
	//Reset global variable:
	reset_global_result();
}



void assert_integer_equal(integer target, integer ref)
/**
 * Description: This function compares the values of two 'integer' numbers. The 
 * 'integer' type is the same as 'long long int'. Then, it returns the result.
 *
 * Input: (integer) target --> Value that will be compared with the reference in 
 *                         order to test some function.
 *        (integer) ref --> The reference value.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
	int n;

	if (target == ref)
	{
		//Successful test:
		global_result.was_successful = TRUE;
		global_result.result_message[0] = '\0';
	}else
	{
		//Failed test:
		global_result.was_successful = FALSE;

		//Generate the error message:
		n = snprintf(global_result.result_message, 
					MAX_CHARS,
					"The target value is not equal to the reference value.\n %lld != %lld (target != reference)\n", 
					target, 
					ref
			    );
			   
		if (n < 0) //Error creating the result message.
		{
			fprintf(stderr, "Error while generating the result message.\n");
			exit(EXIT_FAILURE);
		}
	}

	//Print the results:
	print_result();
	
	//Reset global variable:
	reset_global_result();
}



//Auxiliary Function definitions:
void reset_global_result()
{
	global_result.was_successful = 0;
	global_result.result_message[0] = '\0';
}

