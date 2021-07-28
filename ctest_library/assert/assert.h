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
typedef long double floating_point;


//Declaration of auxiliary functions:
void print_result(char assert_name[], char std_message[], char custom_message[], int line_number);
void reset_global_result();


//Declaration of functions:

/*STD assert functions for unsigned_integer type*/
void assert_unsigned_integer_equal   (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[]);
void assert_unsigned_integer_notEqual(unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[]);
void assert_unsigned_integer_greater (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[]);




/*equal*/
void assert_int_equal(int target, int ref);
void assert_integer_equal(integer target, integer ref);

void assert_char_equal(char target, char ref);

/*notEqual*/
//...

/*almostEqual*/
void assert_float_almostEqual(float target, float ref, float max_diff);
void assert_double_almostEqual(double target, double ref, double max_diff);

/*notAlmostEqual*/
//...

/*greater*/
//...

/*greaterEqual*/
//...

/*less*/
//...

/*lessEqual*/
//...

/*isPositive*/
//...

/*isNegative*/
void assert_double_isNegative(double target);

/*is true/false -> bool*/
void assert_bool_equal(bool target, bool ref);
void assert_bool_true(bool target);
void assert_bool_false(bool target);

/*isIn*/
//Element in an array

/*isNotIn*/
//element is not in an array

/*isRegex*/
//some regular expression is in the ref ex: [1, 2, 3] --> [2, 3, 4, 5, 5, 1, 2, 3, 4] is true (from i = 5 to 7)

/*isNotRegex*/
//...

/*isPartialPermutation*/ 
void assert_intArraySlice_isPartialPermutation(int target[], size_t start, size_t end, int ref[], size_t ref_size);
void assert_integerArraySlice_isPartialPermutation(integer target[], size_t start, size_t end, integer ref[], size_t ref_size);
void assert_charArraySlice_isPartialPermutation(char target[], size_t start, size_t end, char ref[], size_t ref_size);
void assert_floatArraySlice_isPartialPermutation(float target[], size_t start, size_t end, float ref[], size_t ref_size);
void assert_doubleArraySlice_isPartialPermutation(double target[], size_t start, size_t end, double ref[], size_t ref_size);

/*isPermutation*/
void assert_intArray_isPermutation(int target[], size_t target_size, int ref[], size_t ref_size);
void assert_integerArray_isPermutation(integer target[], size_t target_size, integer ref[], size_t ref_size);
void assert_charArray_isPermutation(char target[], size_t target_size, char ref[], size_t ref_size);
void assert_floatArray_isPermutation(float target[], size_t target_size, float ref[], size_t ref_size);
void assert_doubleArray_isPermutation(double target[], size_t target_size, double ref[], size_t ref_size);

/*isSorted*/
void assert_intArraySlice_isSorted(int target[], size_t start, size_t end);
void assert_integerArraySlice_isSorted(integer target[], size_t start, size_t end);
void assert_charArraySlice_isSorted(char target[], size_t start, size_t end);
void assert_floatArraySlice_isSorted(float target[], size_t start, size_t end);
void assert_doubleArraySlice_isSorted(double target[], size_t start, size_t end);
void assert_intArray_isSorted(int target[], size_t size);
void assert_integerArray_isSorted(integer target[], size_t size);
void assert_charArray_isSorted(char target[], size_t size);
void assert_floatArray_isSorted(float target[], size_t size);
void assert_doubleArray_isSorted(double target[], size_t size);

/*
 * List to implement:
 * unsigned long long int
 * */


#endif
