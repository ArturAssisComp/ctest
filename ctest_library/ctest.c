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
#include "text_formatting.h"
#include <stdio.h>

//Defines:
#define MAX_RESULTS 500 //Maximum number of results per each module.
#define MAX_NAME 32 //Maximum number of chars per name.
#define MAX_DESCRIPTION 1024 //Maximum number of chars per description.


//Global Variables:
char bool_print_progress = TRUE; //Says if it is necessary to print 'Progress: %s'.
char progress[MAX_RESULTS + 1] = "\0";
char suite_progress[MAX_RESULTS + 1] = "\0";
char suite_name[MAX_NAME], module_name[MAX_NAME];
int num_of_suite_results   = 0;
int num_of_results         = 0;
int num_of_suite_fails  = 0;
int num_of_fails        = 0;
int total_results = 0;
int total_fails   = 0;
int num_of_ignored = 0, num_of_suite_ignored = 0, total_ignored = 0;
int ignore = FALSE;

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


	//Print the first 'Progress':
	if(bool_print_progress)
	{
		fprintf(stdout, "\n>>> Progress: %s", progress);
		bool_print_progress = FALSE;
	}

	//Check if this result will be ignored:
	if(ignore)
	{
		num_of_ignored++;
		total_ignored++;
		total_results++;
		n = fprintf(stdout, "I");
		if (n < 0)
		{
			fprintf(stderr, "Error while printing the result.\n");
			exit(EXIT_FAILURE);
		}
		progress[num_of_results++] = 'I';
		progress[num_of_results] = '\0';
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
		total_fails++;

		//Keep the progress:
		fprintf(stdout, "\n>>> Progress: %s", progress);
	}

	//Increment total results:
	total_results++;
}


void start_suite(char *name, char *description, char *func_ids[])
/**
 * Description: This function starts a new suite of tests. It reads the name of
 * the suite, the description and the IDs of the functions that will be tested.
 * 	The body of the test suite must be nested between a start_suite() and 
 * end_suite().
 *
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
	char suite_description[MAX_DESCRIPTION], *aux_str, *merged_str;
	int n, line_length = 80;

	//Reset global variables related to the suite:
	num_of_results = 0;
	num_of_fails   = 0;
	num_of_ignored = 0;
 	total_results = 0;
	total_fails   = 0;
	total_ignored = 0;
	progress[0]    = '\0';
	
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
	n = fprintf(stdout, "%s%s\n\n", aux_str, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite functions ids.\n");
		exit(EXIT_FAILURE);
	}
	free(merged_str);
	free(aux_str);
}


void end_suite()
/**
 * Description: This function ends a suite, printing its summary of results.
 * 
 * Input: (void)
 *
 * Output: (void)
 *
 * Time/Space Complexity: -
 */
{
	char *thick_line = "================================================================================"; // Repeat '=' 80 times.
	char *thin_line = "--------------------------------------------------------------------------------"; // Repeat '=' 80 times.
	int n;

	//Print the starting informations:
	n = fprintf(stdout, "\n\n%s\n|    SUMMARY OF THE SUITE: %-51s |\n%s\n", thin_line, suite_name, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite summary.\n");
		exit(EXIT_FAILURE);
	}

	n = fprintf(stdout, "|    -> TOTAL OF CASES: %-54d |\n%s\n", total_results, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite summary.\n");
		exit(EXIT_FAILURE);
	}

	n = fprintf(stdout, "|    -> SUCCESSES: %-59d |\n%s\n", total_results - total_fails - total_ignored, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite summary.\n");
		exit(EXIT_FAILURE);
	}

	n = fprintf(stdout, "|    -> FAILS: %-63d |\n%s\n", total_fails, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite summary.\n");
		exit(EXIT_FAILURE);
	}

	n = fprintf(stdout, "|    -> IGNORED: %-61d |\n%s\n\n", total_ignored, thick_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite summary.\n");
		exit(EXIT_FAILURE);
	}
	//Reset global variables related to the suite:
	num_of_results = 0;
	num_of_fails   = 0;
 	total_results = 0;
	total_fails   = 0;
	suite_name[0]  = '\0';
}



void start_module(char *name, char *description, char *func_ids[])
/**
 * Description: This function starts a new module (modules may be nested inside 
 * suites) of tests. It reads the name of the module, the description and the 
 * IDs of the functions that will be tested.
 * 	The body of the test module must be nested between a start_module() and 
 * end_module() and nested inside a suite. A module body outside a suite generates
 * an undefined behavior.
 *
 *
 * Input: (char *) name --> The name of the module;
 *        (char *) description --> The description of the module;
 *        (char *[]) func_ids --> An array with the strings of the IDs of the 
 *        functions that will be tested in the module. The last ID must be NULL
 *        in order to indicate the end of the array. If the pointer 'func_ids'
 *        is NULL, it is equivalent to receive no ID.;
 *
 * Output: (void)
 *
 * Time/Space Complexity: -
 */
{
	char *thick_line = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"; // Repeat '~' 80 times.
	char *thin_line = "................................................................................"; // Repeat '.' 80 times.
	char module_description[MAX_DESCRIPTION], *aux_str, *merged_str;
	int n, line_length = 80;

	//Keep track of the suite results:
	num_of_suite_results = num_of_results;
	num_of_suite_fails = num_of_fails;
	num_of_suite_ignored = num_of_ignored;
	suite_progress[0] = '\0';
	strcat(suite_progress, progress);

	//Reset global variables related to the suite:
	num_of_results = 0;
	num_of_fails   = 0;
	num_of_ignored = 0;
	bool_print_progress = TRUE;
	module_name[0] = '\0';
	progress[0]    = '\0';
	
	//Initialize variables:
	n = snprintf(module_name, MAX_NAME, name);
	if (n < 0)
	{
		fprintf(stderr, "Error while initializing module_name.\n");
		exit(EXIT_FAILURE);
	}

	n = snprintf(module_description, MAX_DESCRIPTION, description);
	if (n < 0)
	{
		fprintf(stderr, "Error while initializing module_description.\n");
		exit(EXIT_FAILURE);
	}

	//Print the starting informations:
	n = fprintf(stdout, "\n\n%s\n.    START MODULE: %-59s .\n%s\n", thick_line, module_name, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite name.\n");
		exit(EXIT_FAILURE);
	}

	aux_str = break_line(module_description, MAX_DESCRIPTION, ".    DESCRIPTION: ", ".    ", " .", line_length);
	n = fprintf(stdout, "%s%s\n", aux_str, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite description.\n");
		exit(EXIT_FAILURE);
	}
	free(aux_str);

	merged_str = merge_str(func_ids, ", ", ".");
	aux_str = break_line(merged_str, strlen(merged_str), ".    FUNCTIONS COVERED: ", ".    ", " .", line_length);
	n = fprintf(stdout, "%s%s", aux_str, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the suite functions ids.\n");
		exit(EXIT_FAILURE);
	}
	free(merged_str);
	free(aux_str);
}



void end_module()
/**
 * Description: This function ends a module, printing its summary of results.
 * 
 * Input: (void)
 *
 * Output: (void)
 *
 * Time/Space Complexity: -
 */
{
	char *thick_line = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"; // Repeat '~' 80 times.
	char *thin_line = "................................................................................"; // Repeat '.' 80 times.
	int n;

	//Print the starting informations:
	n = fprintf(stdout, "\n%s\n.    SUMMARY OF THE MODULE: %-50s .\n%s\n", thin_line, module_name, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the module summary.\n");
		exit(EXIT_FAILURE);
	}

	n = fprintf(stdout, ".    -> TOTAL OF CASES: %-54d .\n%s\n", num_of_results, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the module summary.\n");
		exit(EXIT_FAILURE);
	}

	n = fprintf(stdout, ".    -> SUCCESSES: %-59d .\n%s\n", num_of_results - num_of_fails - num_of_ignored, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the module summary.\n");
		exit(EXIT_FAILURE);
	}

	n = fprintf(stdout, ".    -> FAILS: %-63d .\n%s\n", num_of_fails, thin_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the module summary.\n");
		exit(EXIT_FAILURE);
	}

	n = fprintf(stdout, ".    -> IGNORED: %-61d .\n%s\n\n", num_of_ignored, thick_line);
	if (n < 0)
	{
		fprintf(stderr, "Error while printing the module summary.\n");
		exit(EXIT_FAILURE);
	}

	//Reset global variables related to the module:
	num_of_results = num_of_suite_results;
	num_of_fails   = num_of_suite_fails;
	num_of_ignored = num_of_suite_ignored;
	progress[0] = '\0';
	strcat(progress, suite_progress);
	module_name[0]  = '\0';
	bool_print_progress = TRUE;
}

