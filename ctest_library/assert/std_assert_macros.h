/**
 * Author: Artur Assis Alves
 * Date: 15/05/2021
 * Title: Assert macro file.
 */

/**
 * Description: This file contains the standard assert macros.
 */

#include "../globals/globals.h"
#include <stdio.h>
#include <stdbool.h>

//Definitions of assert macros:
/*STD assert macros for unsigned_integer type*/

#define ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL(TARGET_ARRAY,\
					    TARGET_ARRAY_SIZE,\
					    REFERENCE_ARRAY,\
					    REFERENCE_ARRAY_SIZE,\
	       				    LINE_NUMBER, CUSTOM_MESSAGE) \
{\
	/*------------------------------------------------------------------------------*/\
	/*Define and initialize the variables:*/\
	int counter;\
	const int max_error_msg_sz = 128;\
	bool error = false;\
	char function_error_message[max_error_msg_sz];\
	char assert_name[] = "ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL";\
	char std_message[] = "The target array SHOULD BE EQUAL to the reference array.";\
\
	/*Macro parameters*/\
	size_t target_array_size = (TARGET_ARRAY_SIZE), reference_array_size = (REFERENCE_ARRAY_SIZE);\
	int line_number = (LINE_NUMBER);\
	char *custom_message = (CUSTOM_MESSAGE);\
\
	/*Reset global result (reset to success with details empty):*/\
	reset_global_result();\
\
	/*------------------------------------------------------------------------------*/\
	/*Check for ignore:*/\
	if(ignore)\
		goto print;\
\
	/*------------------------------------------------------------------------------*/\
	/*Execute the test:*/\
	if(target_array_size == reference_array_size)\
	{\
		global_result.was_successful = true;\
\
		size_t i;\
		for(i = 0; i < target_array_size; i++)\
		{\
			if((TARGET_ARRAY)[i] != (REFERENCE_ARRAY)[i])\
			{\
				global_result.was_successful = false;\
				break;\
			}\
		}\
	}\
	else/*Arrays have different size*/\
	{\
		global_result.was_successful = false;\
	}\
\
	/*Check if it is necessary to generate highly verbose details in case of fail:*/\
	if(!global_result.was_successful && verbose == HIGH)\
	{\
		/*------------------------------------------------------------------------------*/\
		/*Generate the details for a highly verbose fail message:*/\
		counter = snprintf(global_result.result_details, \
					MAX_CHARS,\
					"> OK\n"\
					);\
\
		/*------------------------------------------------------------------------------*/\
		/*Check for error:*/\
		if (counter < 0) \
		{\
			/*Error creating the result message.*/\
			error = true;\
			snprintf(function_error_message, \
					max_error_msg_sz, \
					"\nError while generating the result message (at line %d).\n",\
					line_number\
					);\
			goto finish;\
		}\
		/*------------------------------------------------------------------------------*/\
	}\
\
	/*------------------------------------------------------------------------------*/\
	/*Print the result:*/\
print:\
	print_result(assert_name, std_message, custom_message, line_number);\
\
	/*------------------------------------------------------------------------------*/\
	/*Finish:*/\
finish:\
	if(error)\
	{\
		fprintf(stderr, function_error_message);\
		exit(EXIT_FAILURE);\
	}\
\
	/*------------------------------------------------------------------------------*/\
}
