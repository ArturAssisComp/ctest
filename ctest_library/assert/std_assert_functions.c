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
/*STD assert functions for unsigned_integer type*/

void assert_unsigned_integer_equal(unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if they are equal.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
	//------------------------------------------------------------------------------
	//Define and initialize the variables:
	int counter;
	const int max_error_msg_sz = 128;
	bool error = false;
	char function_error_message[max_error_msg_sz];
	char assert_name[] = "assert_unsigned_integer_equal";
	char std_message[] = "The target value SHOULD BE EQUAL to the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target == reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %20llu != %-20llu\n",
				        "target",
			               	"reference",       
					target, 
					reference
					);
			   
		//------------------------------------------------------------------------------
		//Check for error:
		if (counter < 0) 
		{
			//Error creating the result message.
			error = true;
			snprintf(function_error_message, 
					max_error_msg_sz, 
					"\nError while generating the result message (at line %d).\n",
					line_number
					);
			goto finish;
		}
		//------------------------------------------------------------------------------
	}

	
	//------------------------------------------------------------------------------
	//Print the result:
print:
	print_result(assert_name, std_message, custom_message, line_number);
	
	//------------------------------------------------------------------------------
	//Finish:
finish:
	if(error)
	{
		fprintf(stderr, function_error_message);
		exit(EXIT_FAILURE);
	}

	//------------------------------------------------------------------------------
}



void assert_unsigned_integer_notEqual(unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if they are different.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
	//------------------------------------------------------------------------------
	//Define and initialize the variables:
	int counter;
	const int max_error_msg_sz = 128;
	bool error = false;
	char function_error_message[max_error_msg_sz];
	char assert_name[] = "assert_unsigned_integer_notEqual";
	char std_message[] = "The target value SHOULD NOT BE EQUAL to the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target != reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %20llu == %-20llu\n",
				        "target",
			               	"reference",       
					target, 
					reference
					);
			   
		//------------------------------------------------------------------------------
		//Check for error:
		if (counter < 0) 
		{
			//Error creating the result message.
			error = true;
			snprintf(function_error_message, 
					max_error_msg_sz, 
					"\nError while generating the result message (at line %d).\n",
					line_number
					);
			goto finish;
		}
		//------------------------------------------------------------------------------
	}

	
	//------------------------------------------------------------------------------
	//Print the result:
print:
	print_result(assert_name, std_message, custom_message, line_number);
	
	//------------------------------------------------------------------------------
	//Finish:
finish:
	if(error)
	{
		fprintf(stderr, function_error_message);
		exit(EXIT_FAILURE);
	}

	//------------------------------------------------------------------------------
}


void assert_unsigned_integer_greater(unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater than 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater than the latter.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
	//------------------------------------------------------------------------------
	//Define and initialize the variables:
	int counter;
	const int max_error_msg_sz = 128;
	bool error = false;
	char function_error_message[max_error_msg_sz];
	char assert_name[] = "assert_unsigned_integer_greater";
	char std_message[] = "The target value SHOULD BE GREATER than the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target > reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %20llu <= %-20llu\n",
				        "target",
			               	"reference",       
					target, 
					reference
					);
			   
		//------------------------------------------------------------------------------
		//Check for error:
		if (counter < 0) 
		{
			//Error creating the result message.
			error = true;
			snprintf(function_error_message, 
					max_error_msg_sz, 
					"\nError while generating the result message (at line %d).\n",
					line_number
					);
			goto finish;
		}
		//------------------------------------------------------------------------------
	}

	
	//------------------------------------------------------------------------------
	//Print the result:
print:
	print_result(assert_name, std_message, custom_message, line_number);
	
	//------------------------------------------------------------------------------
	//Finish:
finish:
	if(error)
	{
		fprintf(stderr, function_error_message);
		exit(EXIT_FAILURE);
	}

	//------------------------------------------------------------------------------
}




