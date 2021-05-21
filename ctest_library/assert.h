#ifndef ASSERT_H
#define ASSERT_H
//Includes:
#include <stdlib.h>

//Constants:
#define TRUE 1
#define FALSE 0
#define MAX_CHARS 256 //The maximum number of chars for a message.

//Definitions of structs:
typedef struct
{
	int was_successful;
	char result_message[MAX_CHARS];
} result;

//Declaration of global variables:
extern result global_result;


//Declaration of functions:
void assert_int_equal(int target, int ref);
void assert_double_equal(double target, double ref);
void assert_intArray_equal(int target[], size_t size_target, int ref[], size_t size_ref);

//Auxiliary functions:
void reset_global_result();
#endif
