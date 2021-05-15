/**
 * Author: Artur Assis Alves
 * Date: 15/05/2021
 * Title: Assert functions file.
 */

/**
 * Description:
 *
 */

//Includes:
#include "assert.h"
#include "ctest.h"
#include <stdio.h>


//Definitions of global Variables:
result global_result = {0};

//Declaration of local functions:
static void reset_global_result();

//Definitions of assert functions:
void assert_int_equal(int target, int ref)
/**
 * Description: This function compares the value of 'target' with the value of 
 * 'ref'. Then, it uses the global variable 'global_result' to save the result.
 * At the end of the execution, it calls the function 'print_result()' to send 
 * the result to the output defined by the user.
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


//Local Function definitions:
static void reset_global_result()
{
	global_result.was_successful = 0;
	global_result.result_message[0] = '\0';
}

//Debug:
int main()
{
	printf("Before: %s, %d\n", global_result.result_message, global_result.was_successful);
	assert_int_equal(1, 2);
	printf("After: %s, %d", global_result.result_message, global_result.was_successful);

}
