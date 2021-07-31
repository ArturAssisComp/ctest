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
#include <math.h>

//Local auxiliary functions:
static char *decimal_to_binary_str(unsigned_integer target, size_t num_of_digits); 
static char *mask_compare(unsigned_integer target, unsigned_integer reference, unsigned_integer mask, char equal_symbol, char diff_symbol);
static int num_of_significant_bits(unsigned_integer number);



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


void assert_unsigned_integer_greaterEqual (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater or equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater or equal to the latter.
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
	char assert_name[] = "assert_unsigned_integer_greaterEqual";
	char std_message[] = "The target value SHOULD BE GREATER OR EQUAL to the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target >= reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %20llu <  %-20llu\n",
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


void assert_unsigned_integer_less (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less than the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less than the latter.
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
	char assert_name[] = "assert_unsigned_integer_less";
	char std_message[] = "The target value SHOULD BE LESS than the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target < reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %20llu >= %-20llu\n",
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

void assert_unsigned_integer_lessEqual (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less or equal to the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less or equal to the latter.
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
	char assert_name[] = "assert_unsigned_integer_lessEqual";
	char std_message[] = "The target value SHOULD BE LESS OR EQUAL to the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target <= reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %20llu >  %-20llu\n",
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

void assert_unsigned_integer_bitMaskEqual (unsigned_integer target, unsigned_integer reference, unsigned_integer mask, int line_number, char custom_message[])
/**
 * Description: This function checks if the bits selected by the bit mask 'mask' 
 * from the 'target' are respectively equal to the bits selected by the same mask 
 * from the 'reference'. If the 'mask' is 0, the result will be true. 
 * 	The details of the high verbose result only shows the number of bits that
 * are necessary to show all sibnificant bits from 'mask'.
 * 	The details are presented using binary representation of the numbers.
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less or equal to the latter.
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
	char assert_name[] = "assert_unsigned_integer_bitMaskEqual";
	char std_message[] = "The bits selected by the bit mask from the target and the reference values SHOULD BE RESPECTIVELY EQUAL.";

 
	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (~(target ^ reference) & mask) == mask;

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		size_t num_of_digits = num_of_significant_bits(mask);
		char equal_symbol = '|', diff_symbol = ':';
		char *binary_target_str, *binary_reference_str, *binary_mask_str;
		char *target_reference_comparison_str;

		//Generate the binary form of each number:
		binary_target_str = decimal_to_binary_str(target, num_of_digits);
		binary_reference_str = decimal_to_binary_str(reference, num_of_digits);
		binary_mask_str = decimal_to_binary_str(mask, num_of_digits);

		//Generate the string that compares target and reference:
		target_reference_comparison_str = mask_compare(target, reference, mask, equal_symbol, diff_symbol);

		//Create the datailed message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					">            <binary>  (<hexadecimal>)\n"\
					"> target:    0b%s (0x%llX)\n"\
					">              %s\n"\
					"> reference: 0b%s (0x%llX)\n"\
					"> bit-mask:  0b%s (0x%llX)\n",
					binary_target_str, 
					target,
					target_reference_comparison_str,
					binary_reference_str,
					reference,
					binary_mask_str,
					mask
					);

		//Free the buffers:
		free(binary_target_str);
		free(binary_reference_str);
		free(binary_mask_str);
		free(target_reference_comparison_str);

			   
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




//------------------------------------------------------------------------------
/*STD assert functions for integer type*/
void assert_integer_equal(integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if they are equal.
 *        (integer) reference --> The reference value.
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
	char assert_name[] = "assert_integer_equal";
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
					"> %+20lld != %+-20lld\n",
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

void assert_integer_notEqual     (integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if they are different.
 *        (integer) reference --> The reference value.
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
	char assert_name[] = "assert_integer_notEqual";
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
					"> %+20lld == %+-20lld\n",
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


void assert_integer_greater(integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater than 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater than the latter.
 *        (integer) reference --> The reference value.
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
	char assert_name[] = "assert_integer_greater";
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
					"> %+20lld <= %+-20lld\n",
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



void assert_integer_greaterEqual (integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater or equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater or equal to the latter.
 *        (integer) reference --> The reference value.
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
	char assert_name[] = "assert_integer_greaterEqual";
	char std_message[] = "The target value SHOULD BE GREATER OR EQUAL to the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target >= reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %+20lld <  %+-20lld\n",
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



void assert_integer_less (integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less than the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less than the latter.
 *        (integer) reference --> The reference value.
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
	char assert_name[] = "assert_integer_less";
	char std_message[] = "The target value SHOULD BE LESS than the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target < reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %+20lld >= %+-20lld\n",
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



void assert_integer_lessEqual (integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less or equal to the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less or equal to the latter.
 *        (integer) reference --> The reference value.
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
	char assert_name[] = "assert_integer_lessEqual";
	char std_message[] = "The target value SHOULD BE LESS OR EQUAL to the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target <= reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %+20lld >  %+-20lld\n",
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


/*STD assert functions for floating_point type*/

void assert_floating_point_almostEqual(floating_point target, floating_point reference, floating_point max_diff, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is almost equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	-If 'ignore' is true, this function will not test anything.
 * 	-'target' is considered almost equal to 'reference' if:
 * 	fabs(target - reference) < max_diff
 * 	-max_diff >= 0.000000000001 (1e-12)
 *
 * 	WARNING: This function uses absolute difference to check if two floating 
 * point numbers are almost equal. This technique may result in inaccurate results. 
 * This is caused by the intrinsic problems that exist while doing  floating point 
 * arithmetic. 
 *
 * Input: (floating_point) target    --> Value that will be compared to the reference in 
 *                         order to test if they are almost equal.
 *        (floating_point) reference --> The reference value.
 *        (floating_point) max_diff  --> The maximum difference between 'target' and 'reference' 
 *        allowed in order to consider both almost equal. 
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message   --> Personalized message that will be printed if the test fails.
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
	char assert_name[] = "assert_floating_point_almostEqual";
	char std_message[] = "The target value SHOULD BE ALMOST EQUAL to the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Check the input max_diff:
	if(max_diff < 1e-12) 
	{
		//Error with the input.
		error = true;
		snprintf(function_error_message, 
				max_error_msg_sz, 
				"\nError: max_diff must be greater than 1e-12 (at line %d).\n",
				line_number
				);
		goto finish;
	}
	
	//Execute the test:
	global_result.was_successful = fabs(target - reference) < max_diff;

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{

		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %15s     %-15s\n"\
					"> %+15lg !~= %+-15lg\n"\
					">\n"\
					"> %20s    %-15s\n"\
					"> %20lg >= %-15lg\n",
				        "target",
			               	"reference",       
					target, 
					reference,
					"|target - reference|",
					"max_diff",
					fabs(target - reference),
					max_diff
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


void assert_floating_point_notAlmostEqual(floating_point target, floating_point reference, floating_point min_diff, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not almost equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	-If 'ignore' is true, this function will not test anything.
 * 	-'target' is considered not almost equal to 'reference' if:
 * 	fabs(target - reference) >= min_diff
 * 	-min_diff >= 0.000000000001 (1e-12)
 *
 * 	WARNING: This function uses absolute difference to check if two floating 
 * point numbers are almost equal. This technique may result in inaccurate results. 
 * This is caused by the intrinsic problems that exist while doing  floating point 
 * arithmetic. 
 *
 * Input: (floating_point) target    --> Value that will be compared to the reference in 
 *                         order to test if they are not almost equal.
 *        (floating_point) reference --> The reference value.
 *        (floating_point) min_diff  --> The minimum difference between 'target' and 'reference' 
 *        needed in order to consider both are not almost equal. 
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message   --> Personalized message that will be printed if the test fails.
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
	char assert_name[] = "assert_floating_point_notAlmostEqual";
	char std_message[] = "The target value SHOULD BE NOT ALMOST EQUAL to the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Check the input min_diff:
	if(min_diff < 1e-12) 
	{
		//Error with the input.
		error = true;
		snprintf(function_error_message, 
				max_error_msg_sz, 
				"\nError: min_diff must be greater than 1e-12 (at line %d).\n",
				line_number
				);
		goto finish;
	}
	
	//Execute the test:
	global_result.was_successful = fabs(target - reference) >= min_diff;

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{

		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %15s    %-15s\n"\
					"> %+15lg ~= %+-15lg\n"\
					">\n"\
					"> %20s    %-15s\n"\
					"> %20lg <  %-15lg\n",
				        "target",
			               	"reference",       
					target, 
					reference,
					"|target - reference|",
					"min_diff",
					fabs(target - reference),
					min_diff
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


void assert_floating_point_greater(floating_point target, floating_point reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater than 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (floating_point) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater than the latter.
 *        (floating_point) reference --> The reference value.
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
	char assert_name[] = "assert_floating_point_greater";
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
					"> %20lg <= %-20lg\n",
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


void assert_floating_point_greaterEqual (floating_point target, floating_point reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater or equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (floating_point) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater or equal to the latter.
 *        (floating_point) reference --> The reference value.
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
	char assert_name[] = "assert_floating_point_greaterEqual";
	char std_message[] = "The target value SHOULD BE GREATER OR EQUAL to the reference value.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target >= reference);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %20s    %-20s\n"\
					"> %20lg <  %-20lg\n",
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







//------------------------------------------------------------------------------
//Definitions for the local auxiliary functions:
static char *decimal_to_binary_str(unsigned_integer target, size_t num_of_digits)
/**
 * Description: This function transforms the decimal number 'target' into its 
 * binary form and returns the result as a string. 
 * 	After using the string, the user must call free to liberate the memory 
 * allocated. 
 * 	The string will have exactly 'num_of_digits' rightmost digits of 
 * the binary representation of 'target'.
 * 
 * Ex1: if target == 0b01101 and num_of_digits == 3, the result is "101".
 * Ex2: if target == 0b01101 and num_of_digits == 6, the result is "001101".
 *
 * Input: (unsigned_integer) target --> Decimal number that will be transformed to 
 * 	  binary number.
 * 	  (int) num_of_digits --> The number of rightmost digits that 
 * 	  will be transformed to string and returned to the user of the function.
 * 
 * Output: (char *) --> The memory to the string allocated. This string contains
 *         the rightmost 'num_of_digits' of the binary representation of 'target'.
 */
{
	//------------------------------------------------------------------------------
	//Allocate memory for the binary digits:
	char *buffer;
	buffer = calloc(num_of_digits + 1, sizeof *buffer);

	//------------------------------------------------------------------------------
	//Check for error during the memory allocation:
	if(!buffer)
	{
		fprintf(stderr, "\nERROR while allocating memory in function decimal_to_binary_str.\n");
		exit(EXIT_FAILURE);
	}

	//------------------------------------------------------------------------------
	//Fill the buffer with the binary characters:
	buffer[num_of_digits] = '\0';
	while(num_of_digits > 0)
	{
		buffer[--num_of_digits] = (target & 1)? '1':'0';
		target >>= 1;
	}

	//------------------------------------------------------------------------------
	//Return the result:
	return buffer;

	//------------------------------------------------------------------------------
}

static char *mask_compare(unsigned_integer target, unsigned_integer reference, unsigned_integer mask, char equal_symbol, char diff_symbol)
{
	//------------------------------------------------------------------------------
	//Allocate memory for the binary digits:
	char *buffer;
	size_t num_of_digits = num_of_significant_bits(mask);
	unsigned_integer digit_mask = 1;

	/*The bitwise operation "not (A xor B)" gives us the bits that are equal in A and B.*/
	unsigned_integer xnor_target_reference = ~ (target ^ reference);
	buffer = calloc(num_of_digits + 1, sizeof *buffer);

	//------------------------------------------------------------------------------
	//Check for error during the memory allocation:
	if(!buffer)
	{
		fprintf(stderr, "\nERROR while allocating memory in function mask_compare.\n");
		exit(EXIT_FAILURE);
	}

	//------------------------------------------------------------------------------
	//Fill the buffer with the binary characters:
	buffer[num_of_digits] = '\0';
	while(num_of_digits)
	{
		if(mask & digit_mask) //Check if the digits of target and reference are equal.
		{
			buffer[--num_of_digits] = (digit_mask & xnor_target_reference)? equal_symbol:diff_symbol;
		}
		else //Ignore this digit
		{
			buffer[--num_of_digits] = ' ';
		}

		digit_mask <<= 1;
	}

	//------------------------------------------------------------------------------
	//Return the result:
	return buffer;

	//------------------------------------------------------------------------------
}


static int num_of_significant_bits(unsigned_integer number)
/**
 * Description: This function calculates the number of significant bits of 'number'.
 * Ex.: if 'number' is 0b00001101, the result will be 4, not 8.
 */
{
	int counter = 0;
	//Invariant relation: {counter = 0; number * 2 ^ counter}
	while(number)
	{
		number >>= 1;
		counter++;
	}

	//Return the result:
	return counter;
}

//------------------------------------------------------------------------------
