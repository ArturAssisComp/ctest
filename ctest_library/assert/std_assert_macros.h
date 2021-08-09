/**
 * Author: Artur Assis Alves
 * Date: 09/08/2021
 * Title: Assert functions file.
 */

/**
 * Description: This file contains the standard assert macros.
 */

/*Arrays*/
/*STD assert macros for unsigned_integer type*/

/**
 * Macro Name: ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL
 * Description: This macro makes it possible to use arrays of any unsigned type 
 * as parameters. It casts each element to unsigned_integer and then calls the
 * function assert_unsigned_integerArray_equal.
 * 	The assert macro must be ended with a semicolon.
 * 	To pass literal arrays as arguments, the following conventions must be 
 * used: ((unsigned <type>[]){a1, a2, ..., an}) 
 * 	-Replace <type> with the desired type of each element of the array and 
 * replace ai with each respective element.
 * 	-The outer perenteses are necessary.
 * Ex:
 * 	ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL(((unsigned char[]){12, 3}),2,((unsigned int[]){1, 2, 3}),3, __LINE__, NULL);
 *
 * Input:
 * 	TARGET      --> Array/pointer to any unsigned integer type.
 * 	TARGET_SIZE --> The number of elements of TARGET.
 * 	REFERENCE      --> Array/pointer to any unsigned integer type.
 * 	REFERENCE_SIZE --> The number of elements of REFERENCE.
 * 	LINE_NUMBER    --> The number of the line.
 * 	CUSTOM_MESSAGE --> Custom message that will be printed if the assertion fails.
 */
#define ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL(TARGET, TARGET_SIZE, REFERENCE, REFERENCE_SIZE, LINE_NUMBER, CUSTOM_MESSAGE) \
{\
	unsigned_integer target[(TARGET_SIZE)];\
	unsigned_integer reference[(REFERENCE_SIZE)];\
\
	/*Cast each element to unsigned_integer:*/\
	int i;\
	for(i = 0; i < (TARGET_SIZE); i++)\
		target[i] = (unsigned_integer) (TARGET)[i];\
\
	for(i = 0; i < (REFERENCE_SIZE); i++)\
		reference[i] = (unsigned_integer) (REFERENCE)[i];\
\
	/*Call the assert function:*/\
	assert_unsigned_integerArray_equal(target, (TARGET_SIZE), reference, (REFERENCE_SIZE), (LINE_NUMBER), (CUSTOM_MESSAGE));\
}\
do {;} while (0)



/**
 * Macro Name: ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL
 * Description: This macro makes it possible to use arrays of any unsigned type 
 * as parameters. It casts each element to unsigned_integer and then calls the
 * function assert_unsigned_integerArray_notEqual.
 * 	The assert macro must be ended with a semicolon.
 * 	To pass literal arrays as arguments, the following conventions must be 
 * used: ((unsigned <type>[]){a1, a2, ..., an}) 
 * 	-Replace <type> with the desired type of each element of the array and 
 * replace ai with each respective element.
 * 	-The outer perenteses are necessary.
 * Ex:
 * 	ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL(((unsigned char[]){12, 3}),2,((unsigned int[]){1, 2, 3}),3, __LINE__, NULL);
 *
 * Input:
 * 	TARGET      --> Array/pointer to any unsigned integer type.
 * 	TARGET_SIZE --> The number of elements of TARGET.
 * 	REFERENCE      --> Array/pointer to any unsigned integer type.
 * 	REFERENCE_SIZE --> The number of elements of REFERENCE.
 * 	LINE_NUMBER    --> The number of the line.
 * 	CUSTOM_MESSAGE --> Custom message that will be printed if the assertion fails.
 */
#define ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL(TARGET, TARGET_SIZE, REFERENCE, REFERENCE_SIZE, LINE_NUMBER, CUSTOM_MESSAGE) \
{\
	unsigned_integer target[(TARGET_SIZE)];\
	unsigned_integer reference[(REFERENCE_SIZE)];\
\
	/*Cast each element to unsigned_integer:*/\
	int i;\
	for(i = 0; i < (TARGET_SIZE); i++)\
		target[i] = (unsigned_integer) (TARGET)[i];\
\
	for(i = 0; i < (REFERENCE_SIZE); i++)\
		reference[i] = (unsigned_integer) (REFERENCE)[i];\
\
	/*Call the assert function:*/\
	assert_unsigned_integerArray_notEqual(target, (TARGET_SIZE), reference, (REFERENCE_SIZE), (LINE_NUMBER), (CUSTOM_MESSAGE));\
}\
do {;} while (0)




/*
void assert_unsigned_integerArray_equal                    (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_notEqual                 (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_sorted                   (unsigned_integer target[], size_t target_size, bool ascending_order,  int line_number, char custom_message[]);
void assert_unsigned_integerArray_notSorted                (unsigned_integer target[], size_t target_size, bool ascending_order,  int line_number, char custom_message[]);
void assert_unsigned_integerArray_permutation              (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_notPermutation           (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_isPartialPermutation     (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_notIsPartialPermutation  (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_hasPartialPermutation    (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_notHasPartialPermutation (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_setIn                    (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_notSetIn                 (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_setHas                   (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_notSetHas                (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_isSubarray               (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_notIsSubarray            (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_hasSubarray              (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
void assert_unsigned_integerArray_notHasSubarray           (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[]);
*/
