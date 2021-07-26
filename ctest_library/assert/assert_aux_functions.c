#include "assert.h"
#include "..\globals\globals.h"
#include <stdio.h>
#include <stdbool.h>

//Define global variables:
int verbose;
bool ignore;


//Definitions:
void print_result()
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
	int n;


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
	if (global_result.was_successful)
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
		//Print the result:
		n = fprintf(stdout, "F\n\nFAILURE MESSAGE (Assert number %d):\n%s", ctest_info.num_of_results + 1, global_result.result_message);
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


void reset_global_result()
/*This function resets the global_result struct*/
{
	global_result.was_successful = 0;
	global_result.result_message[0] = '\0';
}