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

typedef long long int integer;

//Declaration of global variables:
extern result global_result;


//Declaration of functions:
/*Built-in single types*/
void assert_int_equal(int target, int ref);
void assert_integer_equal(integer target, integer ref);
void assert_char_equal(char target, char ref);

//Auxiliary functions:
void reset_global_result();
#endif
