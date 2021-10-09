#include "assert.h"
#include "..\globals\globals.h"
#include "../aux_libs/text_formatting.h"
#include <stdio.h>
#include <stdbool.h>

//Define global variables:
int verbose = HIGH;
bool ignore = false;


//Definitions:

void print_assert_result(assert_result_struct assert_result)
/**
 * Description: This function must be called after each assertion. It prints 
 * the result using the stdout stream.
 *
 * Input: (void)
 *
 * Output: (void)
 *
 * Time Complexity: -
 *
 * Space Complexity: -
 */
{
	int n, line_length = 80;
	char *buffer_str;


	//Print the first 'Progress':
	if(ctest_info.print_progress)
	{
		fprintf(stdout, "\n>>> Progress: %s", ctest_info.progress);
		ctest_info.print_progress = false;
	}

	//Check if this result will be ignored:
	if(ignore)
	{
		ctest_info.num_of_ignored++;
		ctest_info.total_ignored++;
		ctest_info.total_results++;
		n = fprintf(stdout, "I");
		if (n < 0)
		{
			fprintf(stderr, "Error while printing the result.\n");
			exit(EXIT_FAILURE);
		}
		ctest_info.progress[ctest_info.num_of_results++] = 'I';
		ctest_info.progress[ctest_info.num_of_results] = '\0';
		return;
	}

	//Handle the result:
	if (assert_result.was_successful)
	{
		//Print the result:
		n = fprintf(stdout, ".");
		if (n < 0)
		{
			fprintf(stderr, "Error while printing the result.\n");
			exit(EXIT_FAILURE);
		}

		//Update the progress:
		if(ctest_info.num_of_results > MAX_RESULTS)
		{
			fprintf(stderr, "Error: number of results exceeded the maximum allowed.\n");
			exit(EXIT_FAILURE);
		}
		ctest_info.progress[ctest_info.num_of_results++] = '.';
		ctest_info.progress[ctest_info.num_of_results] = '\0';
	}
	else //Fail
	{
		//Print the header:
		n = fprintf(stdout, "F\n\nFAILURE MESSAGE (Assert number %d at LINE %d):\n", ctest_info.num_of_results + 1, assert_result.line_number);
		if (n < 0)
		{
			fprintf(stderr, "Error while printing the header of the result.\n");
			exit(EXIT_FAILURE);
		}

		//Print the assert name:
		n = fprintf(stdout, "<assert name> --> %s\n", assert_result.assert_name);
		if (n < 0)
		{
			fprintf(stderr, "Error while printing the assert name of the result.\n");
			exit(EXIT_FAILURE);
		}

		//Print the std message:
		if(verbose == MEDIUM || verbose == HIGH)
		{
			buffer_str = break_line(assert_result.std_message, MAX_CHARS, "<std msg>     --> ", "    ", "", line_length);
			n = fprintf(stdout, "%s", buffer_str );
			if (n < 0)
			{
				fprintf(stderr, "Error while printing the stantard message of the result.\n");
				exit(EXIT_FAILURE);
			}
			free(buffer_str);
		}

		//Print the custom message:
		if(assert_result.custom_message != NULL && (verbose == MEDIUM || verbose == HIGH))
		{
			buffer_str = break_line(assert_result.custom_message, MAX_CHARS, "<custom msg>  --> ", "    ", "", line_length);
			n = fprintf(stdout, "%s", buffer_str);
			if (n < 0)
			{
				fprintf(stderr, "Error while printing the custom message of the result.\n");
				exit(EXIT_FAILURE);
			}
			free(buffer_str);
		}

		//Print the details of the failure:
		if(verbose == HIGH)
		{
			n = fprintf(stdout, "<details>     -->\n%s", assert_result.result_details);
			if (n < 0)
			{
				fprintf(stderr, "Error while printing the custom message of the result.\n");
				exit(EXIT_FAILURE);
			}
		}



		//Update the progress:
		if(ctest_info.num_of_results > MAX_RESULTS)
		{
			fprintf(stderr, "Error: number of results exceeded the maximum allowed.\n");
			exit(EXIT_FAILURE);
		}
		ctest_info.progress[ctest_info.num_of_results++] = 'F';
		ctest_info.progress[ctest_info.num_of_results] = '\0';
		ctest_info.num_of_fails++;
		ctest_info.total_fails++;

		//Keep the progress:
		fprintf(stdout, "\n>>> Progress: %s", ctest_info.progress);
	}

	//Increment total results:
	ctest_info.total_results++;
}




