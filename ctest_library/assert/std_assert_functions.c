/**
 * Author: Artur Assis Alves
 * Date: 15/05/2021
 * Title: Assert functions file.
 */

/**
 * Description: This file contains the standard assert functions.
 */

//Includes:
#include "assert.h"
#include "../globals/globals.h"
#include <stdio.h>
#include <stdbool.h>




//Definitions of assert functions:
/*Built-in single types*/
void assert_unsigned_integer_equal(unsigned_integer target, unsigned_integer ref)
/**
 * Description: This function compares the values of two 'unsigned_integer' numbers. 
 * Then, it returns the result.
 *
 * Input: (unsigned_integer) target --> Value that will be compared with the reference in 
 *                         order to test some function.
 *        (unsigned_integer) ref --> The reference value.
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
		global_result.was_successful = true;
		global_result.result_message[0] = '\0';
	}else
	{
		//Failed test:
		global_result.was_successful = false;

		//Generate the error message:
		n = snprintf(global_result.result_message, 
					MAX_CHARS,
					"The target value is not equal to the reference value.\n--> %llu != %llu (target != reference)\n", 
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