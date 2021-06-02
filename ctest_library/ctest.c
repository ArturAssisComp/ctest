/**
 * Author: Artur Assis Alves
 * Date: 15/05/2021
 * Title: CTEST
 */

/**
 * Description: This file contains the implementation of all functions that are
 * responsible for the management of the test suites.
 */


//Includes:
#include "ctest.h"
#include "assert.h"
#include "text_formatting.h"
#include <stdio.h>

//Defines:
#define MAX_RESULTS 500 //Maximum number of results per each module.
#define MAX_NAME 32 //Maximum number of chars per name.
#define MAX_DESCRIPTION 1024 //Maximum number of chars per description.


//Global Variables:
char progress[MAX_RESULTS + 1] = "\0";
char module_progress[MAX_RESULTS + 1] = "\0";
char suite_progress[MAX_RESULTS + 1] = "\0";
int num_of_suite_results   = 0;
int num_of_module_results  = 0;
int num_of_results         = 0;
int num_of_suite_fails  = 0;
int num_of_module_fails = 0;
int num_of_fails        = 0;

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
	else //Fail
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
		num_of_fails++;

		//Keep the progress:
		fprintf(stdout, "\nProgress: %s", progress);
	}
}


void start_suite(char *name, char *description, char *func_ids[])
/**
 * Description: This function starts a new suite of tests. It reads the name of
 * the suite, the description and the IDs of the functions that will be tested.
 *
 * Input: (char *) name --> The name of the suite;
 *        (char *) description --> The description of the suite;
 *        (char *[]) func_ids --> An array with the strings of the IDs of the 
 *        functions that will be tested in the suite. The last ID must be NULL
 *        in order to indicate the end of the array. If the pointer 'func_ids'
 *        is NULL, it is equivalent to receive no ID.;
 *
 * Output: (void)
 *
 * Time/Space Complexity: -
 */
{
	char *thick_line = "================================================================================"; // Repeat '=' 80 times.
	char *thin_line = "--------------------------------------------------------------------------------"; // Repeat '=' 80 times.
	char suite_name[MAX_NAME], suite_description[MAX_DESCRIPTION], id[MAX_NAME], *aux_str, *merged_str;
	int num_of_ids = -1, n, line_length = 80;

	//Reset global variables related to the suite:
	num_of_suite_results = 0;
	num_of_suite_fails   = 0;
	num_of_results = num_of_suite_results;
	num_of_fails   = num_of_suite_fails;
	progress[0] = suite_progress[0] = '\0';
	
	//Initialize variables:
	n = snprintf(suite_name, MAX_NAME, name);
	if (n < 0)
	{
		fprintf(stderr, "Error while initializing suite_name.\n");
		exit(EXIT_FAILURE);
	}

	n = snprintf(suite_description, MAX_DESCRIPTION, description);
	if (n < 0)
	{
		fprintf(stderr, "Error while initializing suite_description.\n");
		exit(EXIT_FAILURE);
	}

	//Count the number of ids:
	if (func_ids != NULL)
		while(func_ids[++num_of_ids] != NULL);

	//Print the starting informations:
	n = fprintf(stdout, "%s\n|    START SUITE: %-60s |\n%s\n", thick_line, suite_name, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite name.\n");
		exit(EXIT_FAILURE);
	}

	aux_str = break_line(suite_description, MAX_DESCRIPTION, "|    DESCRIPTION: ", "|    ", " |", line_length);
	n = fprintf(stdout, "%s%s\n", aux_str, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite description.\n");
		exit(EXIT_FAILURE);
	}
	free(aux_str);

	merged_str = merge_str(func_ids, ", ", ".");
	aux_str = break_line(merged_str, strlen(merged_str), "|    FUNCTIONS COVERED: ", "|    ", " |", line_length);
	n = fprintf(stdout, "%s%s\n", aux_str, thick_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite functions ids.\n");
		exit(EXIT_FAILURE);
	}
	free(merged_str);
	free(aux_str);
}



