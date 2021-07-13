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
#include <math.h>


//Definitions of global Variables:
result global_result = {0};


//Definitions of assert functions:
/*Built-in single types*/
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
					"The target value is not equal to the reference value.\n--> %d != %d (target != reference)\n", 
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
					"The target value is not equal to the reference value.\n--> %lld != %lld (target != reference)\n", 
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

void assert_unsigned_integer_equal(unsigned_integer target, unsigned_integer ref)
/**
 * Description: This function compares the values of two 'unsigned_integer' numbers. The 
 * 'unsigned_integer' type is the same as 'unsigned long long int'. Then, it returns the result.
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
		global_result.was_successful = TRUE;
		global_result.result_message[0] = '\0';
	}else
	{
		//Failed test:
		global_result.was_successful = FALSE;

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

void assert_char_equal(char target, char ref)
/**
 * Description: This function compares the values of two 'char' numbers.  
 * Then, it returns the result.
 *
 * Input: (char) target --> Value that will be compared with the reference in 
 *                         order to test some function.
 *        (char) ref --> The reference value.
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
					"The target value is not equal to the reference value.\n--> %c != %c (target != reference)\n", 
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



void assert_float_almostEqual(float target, float ref, float max_diff)
/**
 * Description: This function asserts if the floats 'target' and 'ref' are 
 * almost equal. The maximum difference allowed must be less than (<) the 
 * positive value (> 0) max_diff.
 *
 * WARNING: the maximum precision sugested is 0.00001. Thus, max_diff should be
 * a multiple of 0.00001. This is a very naive implementation for floating point 
 * comparison because it uses absolute error! 
 *
 *
 * Input: (float) target --> Value that will be compared with the reference.
 *        (float) ref --> The reference value.
 *        (float) max_diff --> Upper bound for the module of the difference 
 *        between target and ref in order to consider target == ref. For 
 *        example, if the user wants the precision to be 2 decimal cases, 
 *        then max_diff must be 0.01.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
	int n;
	float diff = fabsf(target - ref);
	float min = 0.00001;

	//Check max_diff:
	if (!(max_diff >= min))
	{
		fprintf(stderr, "ERROR: The third argument must be greater than %f.\n", min);
		exit(EXIT_FAILURE);
	}


	if (diff < max_diff)
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
					"The target value is not almost equal to the reference value.\n--> %f != %f (target != reference)\n--> |target - reference| (%f) >= max diff (%f)\n", 
					target, 
					ref,
					diff,
					max_diff
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


void assert_double_almostEqual(double target, double ref, double max_diff)
/**
 * Description: This function asserts if the doubles 'target' and 'ref' are 
 * almost equal. The maximum difference allowed is must be less than (<) the 
 * positive value (> 0) of max_diff.
 *
 *
 * WARNING: the maximum precision sugested is 0.000000000001. Thus, max_diff should be
 * a multiple of 0.000000000001. This is a very naive implementation for floating point 
 * comparison because it uses absolute error! 
 *
 * Input: (double) target --> Value that will be compared with the reference.
 *        (double) ref --> The reference value.
 *        (double) max_diff --> Upper bound for the module of the difference 
 *        between target and ref in order to consider target == ref. For 
 *        example, if the user wants the precision to be 2 decimal cases, 
 *        then max_diff must be 0.01.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
	int n;
	double diff = fabs(target - ref);
	double min = 0.000000000001;

	//Check max_diff:
	if (!(max_diff >= min))
	{
		fprintf(stderr, "ERROR: The third argument must be greater than %.13lf.\n", min);
		exit(EXIT_FAILURE);
	}


	if (diff < max_diff)
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
					"The target value is not almost equal to the reference value.\n--> %.13lf != %.13lf (target != reference)\n--> |target - reference| (%.13lf) >= max diff (%.13lf)\n", 
					target, 
					ref,
					diff,
					max_diff
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

