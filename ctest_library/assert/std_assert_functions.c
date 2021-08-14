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
#include <string.h>


//Local auxiliary functions:
static char *decimal_to_binary_generate_str(unsigned_integer target, size_t num_of_digits); 
static char *mask_compare_generate_str(unsigned_integer target, unsigned_integer reference, unsigned_integer mask, char equal_symbol, char diff_symbol);
static int num_of_significant_bits(unsigned_integer number);
static char *unsigned_integerArray_generate_aligned_str(unsigned_integer target_array[], size_t target_array_size, unsigned_integer reference_array[], size_t reference_array_size); 
static char *unsigned_integerArray_compared_equal_generate_str(unsigned_integer arr1[], size_t arr1_size, unsigned_integer arr2[], size_t arr2_size, char equal_symbol, char diff_symbol);
static char *unsigned_integerArray_indexes_generate_str(unsigned_integer arr1[], size_t arr1_size, unsigned_integer arr2[], size_t arr2_size);
static char *unsigned_integerArray_sorting_result_generate_str(unsigned_integer target[], size_t target_size, bool ascending_order);
static int num_of_digits(unsigned_integer number);



//Definitions of assert functions:
/*Single data types*/
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
		binary_target_str = decimal_to_binary_generate_str(target, num_of_digits);
		binary_reference_str = decimal_to_binary_generate_str(reference, num_of_digits);
		binary_mask_str = decimal_to_binary_generate_str(mask, num_of_digits);

		//Generate the string that compares target and reference:
		target_reference_comparison_str = mask_compare_generate_str(target, reference, mask, equal_symbol, diff_symbol);

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


void assert_floating_point_less (floating_point target, floating_point reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less than the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (floating_point) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less than the latter.
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
	char assert_name[] = "assert_floating_point_less";
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
					"> %20lg >= %-20lg\n",
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


void assert_floating_point_lessEqual (floating_point target, floating_point reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less or equal to the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (floating_point) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less or equal to the latter.
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
	char assert_name[] = "assert_floating_point_lessEqual";
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
					"> %20lg >  %-20lg\n",
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



/*STD assert functions for bool type*/

void assert_bool_equal(bool target, bool reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (bool) target --> Value that will be compared to the reference in 
 *                         order to test if they are equal.
 *        (bool) reference --> The reference value.
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
	char assert_name[] = "assert_bool_equal";
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
					"> %10s    %-10s\n"\
					"> %10s != %-10s\n",
				        "target",
			               	"reference",       
					target ? "true":"false", 
					reference ? "true":"false"
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


void assert_bool_notEqual(bool target, bool reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (bool) target --> Value that will be compared to the reference in 
 *                         order to test if they are different.
 *        (bool) reference --> The reference value.
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
	char assert_name[] = "assert_bool_notEqual";
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
					"> %10s    %-10s\n"\
					"> %10s == %-10s\n",
				        "target",
			               	"reference",       
					target ? "true":"false", 
					reference ? "true":"false"
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


void assert_bool_true(bool target, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is true. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (bool) target --> Value that will be checked for true. 
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
	char assert_name[] = "assert_bool_true";
	char std_message[] = "The target value SHOULD BE true.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target == true);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %10s == %-10s\n",
				        "target",
					target ? "true":"false" 
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


void assert_bool_false(bool target, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is false. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (bool) target --> Value that will be checked for false. 
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
	char assert_name[] = "assert_bool_false";
	char std_message[] = "The target value SHOULD BE false.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = (target == false);

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> %10s == %-10s\n",
				        "target",
					target ? "true":"false" 
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



/*Array data type*/
/*STD assert functions for unsigned_integerArray type*/
void assert_unsigned_integerArray_equal (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if each element of the array 'target' is 
 * respectively equal to each element of the array 'reference'. The comparisons
 * will be done from the first element (index 0) until the element of number
 * min(target_size - 1, reference_size - 1).
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> Array with values that will be compared to the respective 
 *        values of the reference array in order to test if they are equal.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
	//------------------------------------------------------------------------------
	//Define and initialize the variables:
	int counter;
	const int max_error_msg_sz = 128;
	bool error = false;
	char function_error_message[max_error_msg_sz];
	char assert_name[] = "assert_unsigned_integerArray_equal";
	char std_message[] = "Each element of the target array SHOULD BE EQUAL to each respective element of the reference array.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = true; //Start with the default value

	if(target_size != reference_size)
		global_result.was_successful = false;
	else
	{
		//Check each element:
		size_t i;
		for(i = 0; i < target_size; i++)
		{
			if(target[i] != reference[i])
			{
				global_result.was_successful = false;
				break;
			}
		}
	}

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		char equal_symbol = '|', diff_symbol = ':';
		char *target_array_str, *reference_array_str;
		char *target_reference_comparison_str;
		char *target_reference_aligned_indexes_str;

		//Generate the string form of each array:
		target_array_str    = unsigned_integerArray_generate_aligned_str(target, target_size, reference, reference_size);
		reference_array_str = unsigned_integerArray_generate_aligned_str(reference, reference_size, target, target_size);

		//Generate the string that compares target and reference:
		target_reference_comparison_str = unsigned_integerArray_compared_equal_generate_str(target, target_size, reference, reference_size, equal_symbol, diff_symbol);

		//Generate the string for indexes:
		target_reference_aligned_indexes_str = unsigned_integerArray_indexes_generate_str(target, target_size, reference, reference_size);

		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> target_array:    %s\n"\
					">                  %s\n"\
					"> reference_array: %s\n"\
					"> (index)          %s\n",
					target_array_str,
					target_reference_comparison_str,
					reference_array_str,
					target_reference_aligned_indexes_str
					);
			   
		//Free the buffers:
		free(target_array_str);
		free(target_reference_comparison_str);
		free(reference_array_str);
		free(target_reference_aligned_indexes_str);

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


void assert_unsigned_integerArray_notEqual (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if each element of the array 'target' is 
 * respectively different from each element of the array 'reference'. The comparisons
 * will be done from the first element (index 0) until the element of number
 * min(target_size - 1, reference_size - 1).
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 * 	If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> Array with values that will be compared to the respective 
 *        values of the reference array in order to test if they are different.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
	//------------------------------------------------------------------------------
	//Define and initialize the variables:
	int counter;
	const int max_error_msg_sz = 128;
	bool error = false;
	char function_error_message[max_error_msg_sz];
	char assert_name[] = "assert_unsigned_integerArray_notEqual";
	char std_message[] = "The target array SHOULD NOT BE EQUAL to the reference array.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = false; //Start with the default value false

	if(target_size != reference_size)
		global_result.was_successful = true;
	else
	{
		//Check each element:
		size_t i;
		for(i = 0; i < target_size; i++)
		{
			if(target[i] != reference[i])
			{
				global_result.was_successful = true;
				break;
			}
		}
	}

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		char equal_symbol = '|', diff_symbol = ':';
		char *target_array_str, *reference_array_str;
		char *target_reference_comparison_str;
		char *target_reference_aligned_indexes_str;

		//Generate the string form of each array:
		target_array_str    = unsigned_integerArray_generate_aligned_str(target, target_size, reference, reference_size);
		reference_array_str = unsigned_integerArray_generate_aligned_str(reference, reference_size, target, target_size);

		//Generate the string that compares target and reference:
		target_reference_comparison_str = unsigned_integerArray_compared_equal_generate_str(target, target_size, reference, reference_size, equal_symbol, diff_symbol);

		//Generate the string for indexes:
		target_reference_aligned_indexes_str = unsigned_integerArray_indexes_generate_str(target, target_size, reference, reference_size);

		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> target_array:    %s\n"\
					">                  %s\n"\
					"> reference_array: %s\n"\
					"> (index)          %s\n",
					target_array_str,
					target_reference_comparison_str,
					reference_array_str,
					target_reference_aligned_indexes_str
					);
			   
		//Free the buffers:
		free(target_array_str);
		free(target_reference_comparison_str);
		free(reference_array_str);
		free(target_reference_aligned_indexes_str);

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

void assert_unsigned_integerArray_sorted(unsigned_integer target[], size_t target_size, bool ascending_order,  int line_number, char custom_message[])
/**
 * Description: This function checks if the array 'target' is sorted in ascending 
 * order if 'acsending_order' is true. Otherwise, it checks if 'target' is sorted
 * in descending order. The size of 'target' is 'target_size' and the elements
 * that will be checked are those with index from 0 to target_size - 1.
 *
 * Input: (unsigned_integer []) target --> Array that will be checked. 
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (bool) ascending_order --> true for checking ascending order sorting. Otherwise, 
 *        descending order.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(target_size)
 *
 * Space Complexity: O(target_size)
 */
{
	//------------------------------------------------------------------------------
	//Define and initialize the variables:
	int counter;
	const int max_error_msg_sz = 128;
	bool error = false;
	char function_error_message[max_error_msg_sz];
	char assert_name[] = "assert_unsigned_integerArray_sorted";
	char std_message_asc[] = "The target array SHOULD BE SORTED IN ASCENDING ORDER.";
	char std_message_dsc[] = "The target array SHOULD BE SORTED IN DESCENDING ORDER.";

	//Reset global result (reset to success with details empty):
	reset_global_result();


	//------------------------------------------------------------------------------
	//Check for ignore:
	if(ignore)
		goto print;

	//------------------------------------------------------------------------------
	//Execute the test:
	global_result.was_successful = true; //Start with the default value true 

	//Check if the array is sorted only if it has more than 1 element:
	if(target_size > 1)
	{
		size_t i;
		for(i = 1; i < target_size; i++)
		{
			if(ascending_order)
			{
				if(target[i] < target[i - 1])
				{
					global_result.was_successful = false;
					break;
				}
			}
			else
			{
				if(target[i] > target[i - 1])
				{
					global_result.was_successful = false;
					break;
				}
			}
		}
	}

	//Check if it is necessary to generate highly verbose details in case of fail:
	if(!global_result.was_successful && verbose == HIGH)
	{
		//------------------------------------------------------------------------------
		//Generate the details for a highly verbose fail message:
		char *target_array_str;
		char *target_sort_result_str;
		char *target_aligned_indexes_str;

		//Generate the string form of each array:
		target_array_str    = unsigned_integerArray_generate_aligned_str(target, target_size, NULL, 0);

		//Generate the string that compares target and reference:
		target_sort_result_str = unsigned_integerArray_sorting_result_generate_str(target, target_size, ascending_order);

		//Generate the string for indexes:
		target_aligned_indexes_str = unsigned_integerArray_indexes_generate_str(target, target_size, target, target_size);

		counter = snprintf(global_result.result_details, 
					MAX_CHARS,
					"> target_array:    %s\n"\
					">                  %s\n"\
					"> (index)          %s\n",
					target_array_str,
					target_sort_result_str,
					target_aligned_indexes_str
					);
			   
		//Free the buffers:
		free(target_array_str);
		free(target_sort_result_str);
		free(target_aligned_indexes_str);

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
	if(ascending_order)
		print_result(assert_name, std_message_asc, custom_message, line_number);
	else
		print_result(assert_name, std_message_dsc, custom_message, line_number);

	
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
static char *decimal_to_binary_generate_str(unsigned_integer target, size_t num_of_digits)
/**
 * Description: This function transforms the decimal number 'target' into its 
 * binary form and returns the result as a string. 
 * 	After using the string, the user must call free to liberate the memory 
 * allocated. 
 * 	The string will have exactly 'num_of_digits' rightmost digits of 
 * the binary representation of 'target'.
 * 
 * WARNING: The user must call free for the result returned by this function
 * after using it.
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
	if(!buffer)
	{
		fprintf(stderr, "\nERROR while allocating memory in function decimal_to_binary_generate_str.\n");
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

static char *mask_compare_generate_str(unsigned_integer target, unsigned_integer reference, unsigned_integer mask, char equal_symbol, char diff_symbol)
/**
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 */
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
		fprintf(stderr, "\nERROR while allocating memory in function mask_compare_generate_str.\n");
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




static char *unsigned_integerArray_generate_aligned_str(unsigned_integer target_array[], size_t target_array_size, unsigned_integer reference_array[], size_t reference_array_size) 
/**
 * Description: This function generates the string of the array 'target_array' 
 * of unsigned_integer's with size 'target_array_size'. The string is 
 * generated in such a way that each element will be aligned with each 
 * respective element of 'reference_array'. The alignment will take place 
 * only if there is a respective element in the reference array, otherwise, it 
 * will be used the minimum space necessary to accommodate each element plus one 
 * extra space. 
 * 	The alignment is done in the following way: 
 * 	(1) - If the respective element of the reference array has more digits, 
 * 	aditional spaces are added to the target array element;
 * 	(2) - Otherwise, no additional spaces are added.
 *
 * 	The reference array may be NULL. In that situation, the reference_array_size
 * will be ignored.
 * 	If the size of the array is different from the size passed as argument, the 
 * behavior is undefined.
 *
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex:
 * --> target_array:    [ 12, 34, 5, 123]
 * --> reference_array: [ 12334, 2343, 5, 4, 9]
 * --> result:          [    12,   34, 5, 123]
 * If this functions is called again but exchanging the reference array with the 
 * target array, the following result would be generated for the reference array:
 * -->                  [ 12334, 2343, 5,   4, 9]
 *  In conclusion, if this function is applied to both arrays (exchanging them 
 *  between target and reference), they will the generated strings would have 
 *  each respective element vertically aligned.
 *
 * Input: (unsigned_integer[]) target_array
 *        (size_t) target_array_size
 *        (unsigned_integer[]) reference_array
 *        (size_t) reference_array_size 
 *
 * Output: (char *) --> The formatted string.
 *
 * Time Complexity: O(n^2) --> This function uses strcat in 
 * a inefficient way.
 */
{
	//------------------------------------------------------------------------------
	//Declare local varibles:
	char *result;
	char number_buffer[50];
	size_t current_buffer_size = 100, buffer_chars_used = 0;


	//------------------------------------------------------------------------------
	//Allocate memory for the buffer:
	result = calloc(current_buffer_size, sizeof *result);
	if(!result)
	{
		fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
		exit(EXIT_FAILURE);
	}
	
	//------------------------------------------------------------------------------
	//Initialize the buffer:
	strcat(result, "[");
	buffer_chars_used += 2; //'[' + '\0'

	//------------------------------------------------------------------------------
	//Fill the buffer with the target_array elements:

	size_t i, n; 
	int number_of_digits;
	char intermediate_buffer[20] = "   %llu,";
	for(i = 0; i < target_array_size; i++)
	{
		//Create the string of the number that will be concatenated to the result:
		if (reference_array != NULL && i < reference_array_size)
			number_of_digits = num_of_digits(reference_array[i]);
		else 
			number_of_digits = 0;

		n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "   %%%dllu,",  number_of_digits);
		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		n = snprintf(number_buffer, sizeof number_buffer / sizeof number_buffer[0], intermediate_buffer,  target_array[i]);
		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		//Check if there is enough space:
		if(buffer_chars_used + n >= current_buffer_size)
		{
			//Allocate more memory:
			current_buffer_size = buffer_chars_used;
			current_buffer_size *= 2;
			result = realloc(result, sizeof *result * current_buffer_size);
			if(!result)
			{
				fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
				exit(EXIT_FAILURE);
			}
		}

		//Add the next number to the result:
		strcat(result, number_buffer);
		buffer_chars_used += n;
	}	

	//------------------------------------------------------------------------------
	//Add ']' in the end:
	result[buffer_chars_used - 2] = ']';

	//------------------------------------------------------------------------------
	//Return the result:
	return result;

	//------------------------------------------------------------------------------

}

static char *unsigned_integerArray_compared_equal_generate_str(unsigned_integer arr1[], size_t arr1_size, unsigned_integer arr2[], size_t arr2_size, char equal_symbol, char diff_symbol)
/**
 * Description: This function generates a string that compares each element of 
 * arr1 with each respertive element of arr2. If each respective pair of elements 
 * are equal, the 'equal_symbol' is used. Otherwise, the 'diff_symbol' is used. 
 * The symbol is aligned with the biggest element. If one of the arrays is greater
 * that the other, the 'diff_symbol' will be used for the rest of the elements.
 *
 * 	If the size of the array is different from the size passed as argument, the 
 * behavior is undefined.
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex:
 * --> arr1:    [ 12, 34, 5, 123]
 * --> arr2     [ 12334, 2343, 5, 4, 9]
 * --> equal_symbol : '|'
 * --> diff_symbol: ':'
 * -->           [    12,   34, 5, 123]
 * --> result:         :     :  |    :  :      
 * -->           [ 12334, 2343, 5,   4, 9]
 *
 * Input: (unsigned_integer[]) arr1
 *        (size_t) arr1_size
 *        (unsigned_integer[]) arr2
 *        (size_t) arr2_size 
 *        (char)   equal_symbol
 *        (char)   diff_symbol
 *
 * Output: (char *) --> The formatted string.
 *
 * Time Complexity: O(n^2) --> This function uses strcat in 
 * a inefficient way.
 */
{
	//------------------------------------------------------------------------------
	//Declare local varibles:
	char *result;
	char symbol_buffer[50];
	size_t current_buffer_size = 100, buffer_chars_used = 0;


	//------------------------------------------------------------------------------
	//Allocate memory for the buffer:
	result = calloc(current_buffer_size, sizeof *result);
	if(!result)
	{
		fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
		exit(EXIT_FAILURE);
	}
	
	//------------------------------------------------------------------------------
	//Initialize the buffer:
	strcat(result, " ");
	buffer_chars_used += 2; //' ' + '\0'

	//------------------------------------------------------------------------------
	//Fill the buffer with the arr1 elements:

	size_t i, n; 
	size_t max_array_size = (arr1_size >= arr2_size)?arr1_size:arr2_size;
	int number_of_digits_element_arr1, number_of_digits_element_arr2, number_of_digits;
	char intermediate_buffer[20]; 
	for(i = 0; i < max_array_size; i++)
	{
		//Create the string of the char that will be concatenated to the result:
		number_of_digits_element_arr1 = (i < arr1_size)?num_of_digits(arr1[i]) : 0;
		number_of_digits_element_arr2 = (i < arr2_size)?num_of_digits(arr2[i]) : 0;

		number_of_digits = (number_of_digits_element_arr1 >= number_of_digits_element_arr2)? number_of_digits_element_arr1 : number_of_digits_element_arr2;


		n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "   %%%dc ",  number_of_digits);
		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		if(i < arr1_size && i < arr2_size)
			n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], intermediate_buffer,  (arr1[i] == arr2[i])?equal_symbol : diff_symbol);
		else
			n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], intermediate_buffer,  diff_symbol);

		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		//Check if there is enough space:
		if(buffer_chars_used + n >= current_buffer_size)
		{
			//Allocate more memory:
			current_buffer_size = buffer_chars_used;
			current_buffer_size *= 2;
			result = realloc(result, sizeof *result * current_buffer_size);
			if(!result)
			{
				fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
				exit(EXIT_FAILURE);
			}
		}

		//Add the next number to the result:
		strcat(result, symbol_buffer);
		buffer_chars_used += n;
	}	

	//------------------------------------------------------------------------------
	//Return the result:
	return result;

	//------------------------------------------------------------------------------
}


static char *unsigned_integerArray_indexes_generate_str(unsigned_integer arr1[], size_t arr1_size, unsigned_integer arr2[], size_t arr2_size)
/**
 * Description: This function generates a string with indexes for each element of 
 * arr1/arr2. The indexes are vertically aligned with the greatest of elements 
 * from arr1 or arr2. 
 *
 * 	If the size of the array is different from the size passed as argument, the 
 * behavior is undefined.
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex:
 * --> arr1:    [ 12, 34, 5, 123]
 * --> arr2     [ 12334, 2343, 5, 4, 29]
 * -->           [      12,     34,   5, 123]
 * -->           [   12334,   2343,   5,   4,   29]
 * --> result:          (0)     (1)  (2)  (3)   (4) 
 *
 * Input: (unsigned_integer[]) arr1
 *        (size_t) arr1_size
 *        (unsigned_integer[]) arr2
 *        (size_t) arr2_size 
 *
 * Output: (char *) --> The formatted string with indexes.
 *
 * Time Complexity: O(n^2) --> This function uses strcat in 
 * a inefficient way.
 */
{
	//------------------------------------------------------------------------------
	//Declare local varibles:
	char *result;
	char formatted_index_buffer[50];
	size_t current_buffer_size = 100, buffer_chars_used = 0;


	//------------------------------------------------------------------------------
	//Allocate memory for the buffer:
	result = calloc(current_buffer_size, sizeof *result);
	if(!result)
	{
		fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
		exit(EXIT_FAILURE);
	}
	
	//------------------------------------------------------------------------------
	//Initialize the buffer:
	strcat(result, " ");
	buffer_chars_used += 2; //' ' + '\0'

	//------------------------------------------------------------------------------
	//Fill the buffer with the arr1 elements:

	size_t i, n; 
	size_t max_array_size = (arr1_size >= arr2_size)?arr1_size:arr2_size;
	int number_of_digits_element_arr1, number_of_digits_element_arr2, number_of_digits;
	char intermediate_buffer[20]; 
	char index_buffer[20];
	for(i = 0; i < max_array_size; i++)
	{
		//Create the string of the char that will be concatenated to the result:
		number_of_digits_element_arr1 = (i < arr1_size)?num_of_digits(arr1[i]) : 0;
		number_of_digits_element_arr2 = (i < arr2_size)?num_of_digits(arr2[i]) : 0;

		number_of_digits = (number_of_digits_element_arr1 >= number_of_digits_element_arr2)? number_of_digits_element_arr1 : number_of_digits_element_arr2;


		n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "%%%ds",  number_of_digits + 4);
		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		n = snprintf(index_buffer, sizeof index_buffer / sizeof index_buffer[0], "(%d)",  i);
		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		n = snprintf(formatted_index_buffer, sizeof formatted_index_buffer / sizeof formatted_index_buffer[0], intermediate_buffer,  index_buffer);
		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		//Check if there is enough space:
		if(buffer_chars_used + n >= current_buffer_size)
		{
			//Allocate more memory:
			current_buffer_size = buffer_chars_used;
			current_buffer_size *= 2;
			result = realloc(result, sizeof *result * current_buffer_size);
			if(!result)
			{
				fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
				exit(EXIT_FAILURE);
			}
		}

		//Add the next number to the result:
		strcat(result, formatted_index_buffer);
		buffer_chars_used += n;
	}	

	//------------------------------------------------------------------------------
	//Return the result:
	return result;

	//------------------------------------------------------------------------------
}


static char *unsigned_integerArray_sorting_result_generate_str(unsigned_integer target[], size_t target_size, bool ascending_order)
/**
 * Description: This function generates a string that makes it easier to see that 
 * the 'target' array is NOT sorted in ascending_order if 'ascending_order' is 
 * true and in descending_order otherwise. It generates symbols that are aligned 
 * with the current element from target and indicates if this element is <=, <, 
 * >= or > than the next element. The first element that violates the sorting 
 * requirements is checked with a '*' symbol.
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex1: 
 * The array [ 12, 23, 34, 4, 23] is not sorted in ascending order. The string
 * that will be generated by this function in this case is:
 * target: [   12,   23,   34,   4,   23]
 *             <=    <=     >    *
 *
 * Ex2:
 * The array [ 0, 0, 0, 1] is not sorted in descending order. The string 
 * generated by this function is:
 * target: [   0,   0,   0,   1]
 *            >=   >=    <    *
 *
 * Inputs: (unsigned_integer[]) target --> The array that will be checked for 
 *         being sorted.
 *         (size_t) target_size --> The size of the array 'target'.
 *         (bool) ascending_order --> If true, means that the target array
 *         should be sorted in ascending order, but is not. Otherwise, it means
 *         that the array 'target' should be sorted in descending order but
 *         it is not.
 *
 * Output: (char *) --> The string generated in order to make it easier to 
 *         see that the array is not sorted.
 *
 *
 * Time Complexity: O(n^2) --> This function uses strcat in 
 * a inefficient way.
 */
{
	//------------------------------------------------------------------------------
	//Declare local varibles:
	char *result;
	char formatted_symbol_buffer[50];
	size_t current_buffer_size = 100, buffer_chars_used = 0;


	//------------------------------------------------------------------------------
	//Allocate memory for the buffer:
	result = calloc(current_buffer_size, sizeof *result);
	if(!result)
	{
		fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
		exit(EXIT_FAILURE);
	}
	
	//------------------------------------------------------------------------------
	//Initialize the buffer:
	strcat(result, " ");
	buffer_chars_used += 2; //' ' + '\0'

	//------------------------------------------------------------------------------
	//Fill the buffer with the arr1 elements:

	size_t i, n, remaining_loops = target_size; 
	int number_of_digits;
	char intermediate_buffer[20]; 
	char symbol_buffer[20];
	for(i = 0; i < target_size && remaining_loops > 0; i++, remaining_loops--)
	{
		//Create the string of the char that will be concatenated to the result:
		number_of_digits = num_of_digits(target[i]);


		n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "%%%ds",  number_of_digits + 4);
		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		if(remaining_loops == 1)
		{
			n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "%s",  "* ");
		}
		else if(ascending_order)
		{
			if(target[i] <= target[i + 1])
			{
				n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "<= ");
			}
			else
			{
				remaining_loops = 2;
				n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "> ");
			}
		}
		else /*Descending order*/
		{
			if(target[i] >= target[i + 1])
			{
				n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], ">= ");
			}
			else
			{
				remaining_loops = 2;
				n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "< ");
			}
		}

		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		n = snprintf(formatted_symbol_buffer, sizeof formatted_symbol_buffer / sizeof formatted_symbol_buffer[0], intermediate_buffer,  symbol_buffer);
		if(n < 0)
		{
			fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
			exit(EXIT_FAILURE);
		}

		//Check if there is enough space:
		if(buffer_chars_used + n >= current_buffer_size)
		{
			//Allocate more memory:
			current_buffer_size = buffer_chars_used;
			current_buffer_size *= 2;
			result = realloc(result, sizeof *result * current_buffer_size);
			if(!result)
			{
				fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
				exit(EXIT_FAILURE);
			}
		}

		//Add the next number to the result:
		strcat(result, formatted_symbol_buffer);
		buffer_chars_used += n;
	}	

	//------------------------------------------------------------------------------
	//Return the result:
	return result;

	//------------------------------------------------------------------------------
}



static int num_of_digits(unsigned_integer number)
{
	int result = 1; //Already count the first digit.

	//While the number has at least 2 digits:
	while(number >= 10)
	{
		number = number/10;
		result++;
	}

	return result;
}

//------------------------------------------------------------------------------
