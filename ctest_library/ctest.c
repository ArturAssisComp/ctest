/**
 * Author: Artur Assis Alves
 * Date: 15/05/2021
 * Title: CTEST
 */

/**
 * Description:
 *
 */


//Includes:
#include "ctest.h"
#include "assert.h"
#include <stdio.h>

//Defines:
#define MAX_RESULTS 500 //Maximum number of results per each module.

//Global Variables:
char progress[MAX_RESULTS + 1] = "\0";
int num_of_results = 0;

//Function definitions:
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

	if (global_result.was_successful == TRUE)
	{
		//Print the result:
		n = fprintf(stdout, ".");
		if (n < 0)
		{
			fprintf(stderr, "Error while printing the result.\n");
			exit(EXIT_FAILURE);
		}

		//Update the progress:
		if(num_of_results > MAX_RESULTS)
		{
			fprintf(stderr, "Error: number of results exceeded the maximum allowed.\n");
			exit(EXIT_FAILURE);
		}
		progress[num_of_results++] = '.';
		progress[num_of_results] = '\0';
	}
	else
	{
		//Print the result:
		n = fprintf(stdout, "F\n\nFAILURE MESSAGE (Assert number %d):\n%s", num_of_results + 1, global_result.result_message);
		if (n < 0)
		{
			fprintf(stderr, "Error while printing the result.\n");
			exit(EXIT_FAILURE);
		}

		//Update the progress:
		if(num_of_results > MAX_RESULTS)
		{
			fprintf(stderr, "Error: number of results exceeded the maximum allowed.\n");
			exit(EXIT_FAILURE);
		}
		progress[num_of_results++] = 'F';
		progress[num_of_results] = '\0';

		//Keep the progress:
		fprintf(stdout, "\nProgress: %s", progress);
	}
}


