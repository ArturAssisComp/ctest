#ifndef ASSERT_H
#define ASSERT_H
//Includes:
#include <stdlib.h>
#include <stdbool.h>

//Constants:
#define MAX_CHARS 4096 //The maximum number of chars for a message.


//Declarations of structs:
struct
{
	bool was_successful;
	char result_details[MAX_CHARS];
} global_result;

typedef long long int integer;
typedef unsigned long long int unsigned_integer;
typedef double floating_point;


//Declaration of auxiliary functions:
void print_result(char assert_name[], char std_message[], char custom_message[], int line_number);
void reset_global_result();


//Declaration of functions:

/*STD assert functions for unsigned_integer type*/
void assert_unsigned_integer_equal        (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[]);
void assert_unsigned_integer_notEqual     (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[]);
void assert_unsigned_integer_greater      (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[]);
void assert_unsigned_integer_greaterEqual (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[]);
void assert_unsigned_integer_less         (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[]);
void assert_unsigned_integer_lessEqual    (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[]);
void assert_unsigned_integer_bitMaskEqual (unsigned_integer target, unsigned_integer reference, unsigned_integer mask, int line_number, char custom_message[]);

/*STD assert functions for integer type*/
void assert_integer_equal        (integer target, integer reference, int line_number, char custom_message[]);
void assert_integer_notEqual     (integer target, integer reference, int line_number, char custom_message[]);
void assert_integer_greater      (integer target, integer reference, int line_number, char custom_message[]);
void assert_integer_greaterEqual (integer target, integer reference, int line_number, char custom_message[]);
void assert_integer_less         (integer target, integer reference, int line_number, char custom_message[]);
void assert_integer_lessEqual    (integer target, integer reference, int line_number, char custom_message[]);

/*STD assert functions for floating_point type*/
void assert_floating_point_almostEqual    (floating_point target, floating_point reference, floating_point max_diff, int line_number, char custom_message[]);
void assert_floating_point_notAlmostEqual (floating_point target, floating_point reference, floating_point min_diff, int line_number, char custom_message[]);
void assert_floating_point_greater        (floating_point target, floating_point reference, int line_number, char custom_message[]);
void assert_floating_point_greaterEqual   (floating_point target, floating_point reference, int line_number, char custom_message[]);
void assert_floating_point_less           (floating_point target, floating_point reference, int line_number, char custom_message[]);
void assert_floating_point_lessEqual      (floating_point target, floating_point reference, int line_number, char custom_message[]);


/*almostEqual*/
void assert_float_almostEqual(float target, float ref, float max_diff);
void assert_double_almostEqual(double target, double ref, double max_diff);

#endif
