/**
 * Author: Artur Assis Alves
 * Date: 15/05/2021
 * Title: Assert functions file.
 */

/**
 * Description: This file contains the standard assert functions.
 */

//Includes:
#include "assert.h"
#include "globals.h"
#include "types.h"
#include "array.h"
#include "counter_dict.h"
#include "dict.h"
#include "text_formatting.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


//Constants:
#define MAX_ERROR_MSG_SZ 128

//Local auxiliary functions:
static char *decimal_to_binary_generate_str(unsigned_integer target, size_t num_of_digits); 
static char *mask_compare_generate_str(unsigned_integer target, unsigned_integer reference, unsigned_integer mask, char equal_symbol, char diff_symbol);
static int num_of_significant_bits(unsigned_integer number);
static char *unsigned_integerArray_generate_aligned_str(unsigned_integer target_array[], size_t target_array_size, unsigned_integer reference_array[], size_t reference_array_size); 
static char *unsigned_integerArray_compared_equal_generate_str(unsigned_integer arr1[], size_t arr1_size, unsigned_integer arr2[], size_t arr2_size, char equal_symbol, char diff_symbol);
static char *unsigned_integerArray_indexes_generate_str(unsigned_integer arr1[], size_t arr1_size, unsigned_integer arr2[], size_t arr2_size);
static char *unsigned_integerArray_notSorted_result_generate_str(unsigned_integer target[], size_t target_size, bool ascending_order);
static char *unsigned_integerArray_sorted_result_generate_str(unsigned_integer target[], size_t target_size, bool ascending_order);
static int num_of_digits(unsigned_integer number);
static void size_tArray_to_array_of_sizes(size_t arr[], size_t arr_size, size_t *array_of_sizes[], size_t offset);
static void unsigned_integerArray_to_array_of_sizes(unsigned_integer arr[], size_t arr_size, size_t *array_of_sizes[], size_t offset);
static void free_size_t_pointer_list(size_t *array_of_sizes[]);
static char *unsigned_integerArray_to_str(unsigned_integer target_array[], size_t target_array_size, size_t array_of_size_reference[]); 
static char *size_tArray_to_index_str(size_t index_array[], size_t index_array_size, size_t array_of_size_reference[], size_t max_limit);


static T_element unsigned_integer_to_T_element(unsigned_integer n);
static T_array *unsigned_integerArray_to_T_array(unsigned_integer arr[], size_t arr_size);
static bool is_special_char(char c);
static bool check_for_special_char(char str[]);
static char *string_to_one_line_formatted_string(char unformatted_str[]);
static char *target_reference_chars_comparison_to_string(char target[], char reference[], bool ignore_case, char equality_char, char difference_char, size_t std_char_width);





//Definitions of assert functions:
/*Single data types*/
/*STD assert functions for unsigned_integer type*/

void assert_unsigned_integer_equal(unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if they are equal.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_unsigned_integer_equal",                            //assert_name
                         "The target value SHOULD BE EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };


    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target == reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20llu != %-20llu\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}



void assert_unsigned_integer_notEqual(unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if they are different.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                           //was_successful
                         line_number,                                                    //line_number
                         "",                                                             //result_details[MAX_CHARS]
                         "assert_unsigned_integer_notEqual",                             //assert_name
                         "The target value SHOULD NOT BE EQUAL to the reference value.", //std_message
                         custom_message                                                  //custom_message
                                         };


    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target != reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20llu == %-20llu\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_unsigned_integer_greater(unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater than 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater than the latter.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                           //was_successful
                         line_number,                                                    //line_number
                         "",                                                             //result_details[MAX_CHARS]
                         "assert_unsigned_integer_greater",                              //assert_name
                         "The target value SHOULD BE GREATER than the reference value.", //std_message
                         custom_message                                                  //custom_message
                                         };


    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target > reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20llu <= %-20llu\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_unsigned_integer_greaterEqual (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater or equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater or equal to the latter.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                                  //was_successful
                         line_number,                                                           //line_number
                         "",                                                                    //result_details[MAX_CHARS]
                         "assert_unsigned_integer_greaterEqual",                                //assert_name
                         "The target value SHOULD BE GREATER OR EQUAL to the reference value.", //std_message
                         custom_message                                                         //custom_message
                                         };


    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target >= reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20llu <  %-20llu\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_unsigned_integer_less (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less than the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less than the latter.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                        //was_successful
                         line_number,                                                 //line_number
                         "",                                                          //result_details[MAX_CHARS]
                         "assert_unsigned_integer_less",                              //assert_name
                         "The target value SHOULD BE LESS than the reference value.", //std_message
                         custom_message                                               //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target < reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20llu >= %-20llu\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}

void assert_unsigned_integer_lessEqual (unsigned_integer target, unsigned_integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less or equal to the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less or equal to the latter.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                               //was_successful
                         line_number,                                                        //line_number
                         "",                                                                 //result_details[MAX_CHARS]
                         "assert_unsigned_integer_lessEqual",                                //assert_name
                         "The target value SHOULD BE LESS OR EQUAL to the reference value.", //std_message
                         custom_message                                                      //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target <= reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20llu >  %-20llu\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}

void assert_unsigned_integer_bitMaskEqual (unsigned_integer target, unsigned_integer reference, unsigned_integer mask, int line_number, char custom_message[])
/**
 * Description: This function checks if the bits selected by the bit mask 'mask' 
 * from the 'target' are respectively equal to the bits selected by the same mask 
 * from the 'reference'. If the 'mask' is 0, the result will be true. 
 *     The details of the high verbose result only shows the number of bits that
 * are necessary to show all sibnificant bits from 'mask'.
 *     The details are presented using binary representation of the numbers.
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less or equal to the latter.
 *        (unsigned_integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                                                                       //was_successful
                         line_number,                                                                                                //line_number
                         "",                                                                                                         //result_details[MAX_CHARS]
                         "assert_unsigned_integer_bitMaskEqual",                                                                     //assert_name
                         "The bits selected by the bit mask from the target and the reference values SHOULD BE RESPECTIVELY EQUAL.", //std_message
                         custom_message                                                                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (~(target ^ reference) & mask) == mask;

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        size_t num_of_digits = num_of_significant_bits(mask);
        char equal_symbol = '|', diff_symbol = ':';
        char *binary_target_str, *binary_reference_str, *binary_mask_str;
        char *target_reference_comparison_str;

        //Generate the binary form of each number:
        binary_target_str = decimal_to_binary_generate_str(target, num_of_digits);
        binary_reference_str = decimal_to_binary_generate_str(reference, num_of_digits);
        binary_mask_str = decimal_to_binary_generate_str(mask, num_of_digits);

        //Generate the string that compares target and reference:
        target_reference_comparison_str = mask_compare_generate_str(target, reference, mask, equal_symbol, diff_symbol);

        //Create the datailed message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    ">            <binary>  (<hexadecimal>)\n"\
                    "> target:    0b%s (0x%llX)\n"\
                    ">              %s\n"\
                    "> reference: 0b%s (0x%llX)\n"\
                    "> bit-mask:  0b%s (0x%llX)\n",
                    binary_target_str, 
                    target,
                    target_reference_comparison_str,
                    binary_reference_str,
                    reference,
                    binary_mask_str,
                    mask
                    );

        //Free the buffers:
        free(binary_target_str);
        free(binary_reference_str);
        free(binary_mask_str);
        free(target_reference_comparison_str);

               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}




//------------------------------------------------------------------------------
/*STD assert functions for integer type*/
void assert_integer_equal(integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if they are equal.
 *        (integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_integer_equal",                                     //assert_name
                         "The target value SHOULD BE EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target == reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %+20lld != %+-20lld\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}

void assert_integer_notEqual     (integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if they are different.
 *        (integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_integer_notEqual",                            //assert_name
                         "The target value SHOULD NOT BE EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target != reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %+20lld == %+-20lld\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_integer_greater(integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater than 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater than the latter.
 *        (integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_integer_greater",                            //assert_name
                         "The target value SHOULD BE GREATER than the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target > reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %+20lld <= %+-20lld\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}



void assert_integer_greaterEqual (integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater or equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater or equal to the latter.
 *        (integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_integer_greaterEqual",                            //assert_name
                         "The target value SHOULD BE GREATER OR EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target >= reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %+20lld <  %+-20lld\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}



void assert_integer_less (integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less than the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less than the latter.
 *        (integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_integer_less",                            //assert_name
                         "The target value SHOULD BE LESS than the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target < reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %+20lld >= %+-20lld\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}



void assert_integer_lessEqual (integer target, integer reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less or equal to the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (integer) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less or equal to the latter.
 *        (integer) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_integer_lessEqual",                            //assert_name
                         "The target value SHOULD BE LESS OR EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target <= reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %+20lld >  %+-20lld\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


/*STD assert functions for floating_point type*/

void assert_floating_point_almostEqual(floating_point target, floating_point reference, floating_point max_diff, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is almost equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     -If 'ignore' is true, this function will not test anything.
 *     -'target' is considered almost equal to 'reference' if:
 *     fabs(target - reference) < max_diff
 *     -max_diff >= 0.000000000001 (1e-12)
 *
 *     WARNING: This function uses absolute difference to check if two floating 
 * point numbers are almost equal. This technique may result in inaccurate results. 
 * This is caused by the intrinsic problems that exist while doing  floating point 
 * arithmetic. 
 *
 * Input: (floating_point) target    --> Value that will be compared to the reference in 
 *                         order to test if they are almost equal.
 *        (floating_point) reference --> The reference value.
 *        (floating_point) max_diff  --> The maximum difference between 'target' and 'reference' 
 *        allowed in order to consider both almost equal. 
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message   --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_floating_point_almostEqual",                            //assert_name
                         "The target value SHOULD BE ALMOST EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Check the input max_diff:
    if(max_diff < 1e-12) 
    {
        //Error with the input.
        error = true;
        snprintf(function_error_message, 
                max_error_msg_sz, 
                "\nError: max_diff must be greater than 1e-12 (at line %d).\n",
                line_number
                );
        goto finish;
    }
    
    //Execute the test:
    assert_result.was_successful = fabs(target - reference) < max_diff;

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {

        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %15s     %-15s\n"\
                    "> %+15lg !~= %+-15lg\n"\
                    ">\n"\
                    "> %20s    %-15s\n"\
                    "> %20lg >= %-15lg\n",
                        "target",
                               "reference",       
                    target, 
                    reference,
                    "|target - reference|",
                    "max_diff",
                    fabs(target - reference),
                    max_diff
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_floating_point_notAlmostEqual(floating_point target, floating_point reference, floating_point min_diff, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not almost equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     -If 'ignore' is true, this function will not test anything.
 *     -'target' is considered not almost equal to 'reference' if:
 *     fabs(target - reference) >= min_diff
 *     -min_diff >= 0.000000000001 (1e-12)
 *
 *     WARNING: This function uses absolute difference to check if two floating 
 * point numbers are almost equal. This technique may result in inaccurate results. 
 * This is caused by the intrinsic problems that exist while doing  floating point 
 * arithmetic. 
 *
 * Input: (floating_point) target    --> Value that will be compared to the reference in 
 *                         order to test if they are not almost equal.
 *        (floating_point) reference --> The reference value.
 *        (floating_point) min_diff  --> The minimum difference between 'target' and 'reference' 
 *        needed in order to consider both are not almost equal. 
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message   --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_floating_point_notAlmostEqual",                            //assert_name
                         "The target value SHOULD BE NOT ALMOST EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Check the input min_diff:
    if(min_diff < 1e-12) 
    {
        //Error with the input.
        error = true;
        snprintf(function_error_message, 
                max_error_msg_sz, 
                "\nError: min_diff must be greater than 1e-12 (at line %d).\n",
                line_number
                );
        goto finish;
    }
    
    //Execute the test:
    assert_result.was_successful = fabs(target - reference) >= min_diff;

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {

        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %15s    %-15s\n"\
                    "> %+15lg ~= %+-15lg\n"\
                    ">\n"\
                    "> %20s    %-15s\n"\
                    "> %20lg <  %-15lg\n",
                        "target",
                               "reference",       
                    target, 
                    reference,
                    "|target - reference|",
                    "min_diff",
                    fabs(target - reference),
                    min_diff
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_floating_point_greater(floating_point target, floating_point reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater than 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (floating_point) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater than the latter.
 *        (floating_point) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_floating_point_greater",                            //assert_name
                         "The target value SHOULD BE GREATER than the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target > reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20lg <= %-20lg\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_floating_point_greaterEqual (floating_point target, floating_point reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is greater or equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (floating_point) target --> Value that will be compared to the reference in 
 *                         order to test if the former is greater or equal to the latter.
 *        (floating_point) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_floating_point_greaterEqual",                            //assert_name
                         "The target value SHOULD BE GREATER OR EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target >= reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20lg <  %-20lg\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_floating_point_less (floating_point target, floating_point reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less than the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (floating_point) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less than the latter.
 *        (floating_point) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_floating_point_less",                            //assert_name
                         "The target value SHOULD BE LESS than the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target < reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20lg >= %-20lg\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_floating_point_lessEqual (floating_point target, floating_point reference, int line_number, char custom_message[])
/**
 * Description: This function checks if the 'target' is less or equal to the 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (floating_point) target --> Value that will be compared to the reference in 
 *                         order to test if the former is less or equal to the latter.
 *        (floating_point) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_floating_point_lessEqual",                            //assert_name
                         "The target value SHOULD BE LESS OR EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target <= reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %20s    %-20s\n"\
                    "> %20lg >  %-20lg\n",
                        "target",
                               "reference",       
                    target, 
                    reference
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}



/*STD assert functions for bool type*/

void assert_bool_equal(bool target, bool reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (bool) target --> Value that will be compared to the reference in 
 *                         order to test if they are equal.
 *        (bool) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_bool_equal",                            //assert_name
                         "The target value SHOULD BE EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target == reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %10s    %-10s\n"\
                    "> %10s != %-10s\n",
                        "target",
                               "reference",       
                    target ? "true":"false", 
                    reference ? "true":"false"
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_bool_notEqual(bool target, bool reference, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not equal to 'reference'. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (bool) target --> Value that will be compared to the reference in 
 *                         order to test if they are different.
 *        (bool) reference --> The reference value.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_bool_notEqual",                            //assert_name
                         "The target value SHOULD NOT BE EQUAL to the reference value.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target != reference);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %10s    %-10s\n"\
                    "> %10s == %-10s\n",
                        "target",
                               "reference",       
                    target ? "true":"false", 
                    reference ? "true":"false"
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_bool_true(bool target, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is true. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (bool) target --> Value that will be checked for true. 
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_bool_true",                            //assert_name
                         "The target value SHOULD BE true.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target == true);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %10s == %-10s\n",
                        "target",
                    target ? "true":"false" 
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_bool_false(bool target, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is false. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (bool) target --> Value that will be checked for false. 
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_bool_false",                            //assert_name
                         "The target value SHOULD BE false.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target == false);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %10s == %-10s\n",
                        "target",
                    target ? "true":"false" 
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_pointer_isNULL(void *target, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is NULL. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (void *) target --> Value that will be checked for NULL. 
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                       //was_successful
                         line_number,                            //line_number
                         "",                                     //result_details[MAX_CHARS]
                         "assert_pointer_isNULL",                //assert_name
                         "The pointer 'target' SHOULD BE NULL.", //std_message
                         custom_message                          //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target == NULL);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %s (%p) != NULL (%p)\n",
                    "target", 
                    target,
                    NULL
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}



void assert_pointer_notIsNULL(void *target, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not NULL. 
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (void *) target --> Value that will be checked for NULL. 
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(1)
 *
 * Space Complexity: O(1)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                       //was_successful
                         line_number,                            //line_number
                         "",                                     //result_details[MAX_CHARS]
                         "assert_pointer_notIsNULL",                //assert_name
                         "The pointer 'target' SHOULD NOT BE NULL.", //std_message
                         custom_message                          //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = (target != NULL);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> %s (%p) == NULL (%p)\n",
                    "target", 
                    target,
                    NULL
                    );
               
        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}

/*Array data type*/
/*STD assert functions for unsigned_integerArray type*/
void assert_unsigned_integerArray_equal (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if each element of the array 'target' is 
 * respectively equal to each element of the array 'reference'. The comparisons
 * will be done from the first element (index 0) until the element of number
 * min(target_size - 1, reference_size - 1).
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> Array with values that will be compared to the respective 
 *        values of the reference array in order to test if they are equal.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_unsigned_integerArray_equal",                            //assert_name
                         "Each element of the target array SHOULD BE EQUAL to each respective element of the reference array.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = true; //Start with the default value

    if(target_size != reference_size)
        assert_result.was_successful = false;
    else
    {
        //Check each element:
        size_t i;
        for(i = 0; i < target_size; i++)
        {
            if(target[i] != reference[i])
            {
                assert_result.was_successful = false;
                break;
            }
        }
    }

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char equal_symbol = '|', diff_symbol = ':';
        char *target_array_str, *reference_array_str;
        char *target_reference_comparison_str;
        char *target_reference_aligned_indexes_str;

        //Generate the string form of each array:
        target_array_str    = unsigned_integerArray_generate_aligned_str(target, target_size, reference, reference_size);
        reference_array_str = unsigned_integerArray_generate_aligned_str(reference, reference_size, target, target_size);

        //Generate the string that compares target and reference:
        target_reference_comparison_str = unsigned_integerArray_compared_equal_generate_str(target, target_size, reference, reference_size, equal_symbol, diff_symbol);

        //Generate the string for indexes:
        target_reference_aligned_indexes_str = unsigned_integerArray_indexes_generate_str(target, target_size, reference, reference_size);

        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    ">                  %s\n"\
                    "> reference_array: %s\n"\
                    "> (index)          %s\n",
                    target_array_str,
                    target_reference_comparison_str,
                    reference_array_str,
                    target_reference_aligned_indexes_str
                    );
               
        //Free the buffers:
        free(target_array_str);
        free(target_reference_comparison_str);
        free(reference_array_str);
        free(target_reference_aligned_indexes_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_unsigned_integerArray_notEqual (unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if each element of the array 'target' is 
 * respectively different from each element of the array 'reference'. The comparisons
 * will be done from the first element (index 0) until the element of number
 * min(target_size - 1, reference_size - 1).
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> Array with values that will be compared to the respective 
 *        values of the reference array in order to test if they are different.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_unsigned_integerArray_notEqual",                            //assert_name
                         "The target array SHOULD NOT BE EQUAL to the reference array.", //std_message
                         custom_message                                              //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = false; //Start with the default value false

    if(target_size != reference_size)
        assert_result.was_successful = true;
    else
    {
        //Check each element:
        size_t i;
        for(i = 0; i < target_size; i++)
        {
            if(target[i] != reference[i])
            {
                assert_result.was_successful = true;
                break;
            }
        }
    }

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char equal_symbol = '|', diff_symbol = ':';
        char *target_array_str, *reference_array_str;
        char *target_reference_comparison_str;
        char *target_reference_aligned_indexes_str;

        //Generate the string form of each array:
        target_array_str    = unsigned_integerArray_generate_aligned_str(target, target_size, reference, reference_size);
        reference_array_str = unsigned_integerArray_generate_aligned_str(reference, reference_size, target, target_size);

        //Generate the string that compares target and reference:
        target_reference_comparison_str = unsigned_integerArray_compared_equal_generate_str(target, target_size, reference, reference_size, equal_symbol, diff_symbol);

        //Generate the string for indexes:
        target_reference_aligned_indexes_str = unsigned_integerArray_indexes_generate_str(target, target_size, reference, reference_size);

        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    ">                  %s\n"\
                    "> reference_array: %s\n"\
                    "> (index)          %s\n",
                    target_array_str,
                    target_reference_comparison_str,
                    reference_array_str,
                    target_reference_aligned_indexes_str
                    );
               
        //Free the buffers:
        free(target_array_str);
        free(target_reference_comparison_str);
        free(reference_array_str);
        free(target_reference_aligned_indexes_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}

void assert_unsigned_integerArray_sorted(unsigned_integer target[], size_t target_size, bool ascending_order,  int line_number, char custom_message[])
/**
 * Description: This function checks if the array 'target' is sorted in ascending 
 * order if 'acsending_order' is true. Otherwise, it checks if 'target' is sorted
 * in descending order. The size of 'target' is 'target_size' and the elements
 * that will be checked are those with index from 0 to target_size - 1.
 *
 * Input: (unsigned_integer []) target --> Array that will be checked. 
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (bool) ascending_order --> true for checking ascending order sorting. Otherwise, 
 *        descending order.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(target_size)
 *
 * Space Complexity: O(target_size)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_unsigned_integerArray_sorted",                            //assert_name
                         "", //std_message
                         custom_message                                              //custom_message
                                         };
    char std_message_asc[] = "The target array SHOULD BE SORTED IN ASCENDING ORDER.";
    char std_message_dsc[] = "The target array SHOULD BE SORTED IN DESCENDING ORDER.";


    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = true; //Start with the default value true 

    //Check if the array is sorted only if it has more than 1 element:
    if(target_size > 1)
    {
        size_t i;
        for(i = 1; i < target_size; i++)
        {
            if(ascending_order)
            {
                if(target[i] < target[i - 1])
                {
                    assert_result.was_successful = false;
                    break;
                }
            }
            else
            {
                if(target[i] > target[i - 1])
                {
                    assert_result.was_successful = false;
                    break;
                }
            }
        }
    }

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char *target_array_str;
        char *target_sort_result_str;
        char *target_aligned_indexes_str;

        //Generate the string form of each array:
        target_array_str    = unsigned_integerArray_generate_aligned_str(target, target_size, NULL, 0);

        //Generate the string that compares target and reference:
        target_sort_result_str = unsigned_integerArray_notSorted_result_generate_str(target, target_size, ascending_order);

        //Generate the string for indexes:
        target_aligned_indexes_str = unsigned_integerArray_indexes_generate_str(target, target_size, target, target_size);

        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    ">                  %s\n"\
                    "> (index)          %s\n",
                    target_array_str,
                    target_sort_result_str,
                    target_aligned_indexes_str
                    );
               
        //Free the buffers:
        free(target_array_str);
        free(target_sort_result_str);
        free(target_aligned_indexes_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    if(ascending_order)
        assert_result.std_message = std_message_asc;
    else
        assert_result.std_message = std_message_dsc;

    print_assert_result(assert_result);

    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_unsigned_integerArray_notSorted(unsigned_integer target[], size_t target_size, bool ascending_order,  int line_number, char custom_message[])
/**
 * Description: This function checks if the array 'target' is NOT sorted in ascending 
 * order if 'acsending_order' is true. Otherwise, it checks if 'target' is NOT sorted
 * in descending order. The size of 'target' is 'target_size' and the elements
 * that will be checked are those with index from 0 to target_size - 1.
 *
 * Input: (unsigned_integer []) target --> Array that will be checked. 
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (bool) ascending_order --> true for checking ascending order sorting. Otherwise, 
 *        descending order.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(target_size)
 *
 * Space Complexity: O(target_size)
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    assert_result_struct assert_result = {
                                     true,                                                       //was_successful
                         line_number,                                                //line_number
                         "",                                                         //result_details[MAX_CHARS]
                         "assert_unsigned_integerArray_notSorted",                            //assert_name
                         "", //std_message
                         custom_message                                              //custom_message
                                         };
    char std_message_asc[] = "The target array SHOULD NOT BE SORTED IN ASCENDING ORDER.";
    char std_message_dsc[] = "The target array SHOULD NOT BE SORTED IN DESCENDING ORDER.";


    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    assert_result.was_successful = false; //Start with the default value false 

    //Check if the array is sorted only if it has more than 1 element:
    if(target_size > 1)
    {
        size_t i;
        for(i = 1; i < target_size; i++)
        {
            if(ascending_order)
            {
                if(target[i] < target[i - 1]) //Not sorted
                {
                    assert_result.was_successful = true;
                    break;
                }
            }
            else
            {
                if(target[i] > target[i - 1]) //Not sorted
                {
                    assert_result.was_successful = true;
                    break;
                }
            }
        }
    }

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char *target_array_str;
        char *target_sort_result_str;
        char *target_aligned_indexes_str;

        //Generate the string form of each array:
        target_array_str    = unsigned_integerArray_generate_aligned_str(target, target_size, NULL, 0);

        //Generate the string that compares target and reference:
        target_sort_result_str = unsigned_integerArray_sorted_result_generate_str(target, target_size, ascending_order);

        //Generate the string for indexes:
        target_aligned_indexes_str = unsigned_integerArray_indexes_generate_str(target, target_size, target, target_size);

        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    ">                  %s\n"\
                    "> (index)          %s\n",
                    target_array_str,
                    target_sort_result_str,
                    target_aligned_indexes_str
                    );
               
        //Free the buffers:
        free(target_array_str);
        free(target_sort_result_str);
        free(target_aligned_indexes_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    if(ascending_order)
        assert_result.std_message = std_message_asc;
    else
        assert_result.std_message = std_message_dsc;

    print_assert_result(assert_result);

    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}

void assert_unsigned_integerArray_permutation(unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is a permutation of 'reference'.
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> The target array.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    size_t i;
    T_array *ref_T_array;
    T_dict *ref_counter_dict;
    T_element tmp_element;
    size_t relative_index_array[target_size]; //Stores the index that relates 
                                              //each element from the target array 
                                              //with an element from the reference array. 
                                              //If there is no correspondence, we have 
                                              //relative_index_array[i] == reference_size (invalid value)
    size_t aux_relative_index_array[target_size]; //Stores the index that relates 
                                                  //each element from the target array 
                                                  //with an element from the reference array. 
                                                  //If there is no correspondence, we have 
                                                  //relative_index_array[i] == 0 (invalid value)
    size_t reference_index_array[reference_size];
    const size_t NUMBER_OF_LISTS = 4;
    size_t **list_of_lists_of_size[NUMBER_OF_LISTS];
    size_t *target_size_list[target_size + 1];
    size_t *relative_index_array_size_list[target_size + 1];
    size_t *reference_size_list[reference_size + 1];
    size_t *reference_index_size_list[reference_size + 1];
    size_t *result_list_with_final_sizes = NULL;
    assert_result_struct assert_result = {
                                     true,                                                               //was_successful
                                     line_number,                                                        //line_number
                                     "",                                                                 //result_details[MAX_CHARS]
                                     "assert_unsigned_integerArray_permutation",                         //assert_name
                                     "The target array SHOULD BE A PERMUTATION of the reference array.", //std_message
                                     custom_message                                                      //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test and create the relative index array:
    assert_result.was_successful = true; //Start with the default value
    ref_T_array = unsigned_integerArray_to_T_array(reference, reference_size);
    ref_counter_dict = CD_count_elements(ref_T_array);
    A_delete_array(&ref_T_array);

    for(i = 0; i < target_size; i++)
    {
        tmp_element = unsigned_integer_to_T_element(target[i]);
        if(CD_get_count(tmp_element, ref_counter_dict) == 0) //There is no match for the element target[i]
        {
            relative_index_array[i] = reference_size;
            aux_relative_index_array[i] = 0;
            if(assert_result.was_successful) assert_result.was_successful = false;
        }
        else aux_relative_index_array[i] = relative_index_array[i] = CD_pop_next_index(tmp_element, ref_counter_dict);

        T_free_element(&tmp_element);
    }

    if(ref_counter_dict->num_of_items != 0 && assert_result.was_successful) assert_result.was_successful = false;

    D_delete_dict(&ref_counter_dict);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char *target_array_str, *reference_array_str;
        char *target_reference_relative_index_str;
        char *reference_index_str;


        //Create the array with final sizes:
        list_of_lists_of_size[0] = target_size_list;
        list_of_lists_of_size[1] = relative_index_array_size_list;
        list_of_lists_of_size[2] = reference_size_list;
        list_of_lists_of_size[3] = reference_index_size_list;

        unsigned_integerArray_to_array_of_sizes(target, target_size, target_size_list, 0);
        size_tArray_to_array_of_sizes(aux_relative_index_array, target_size, relative_index_array_size_list, 1);
        unsigned_integerArray_to_array_of_sizes(reference, reference_size, reference_size_list, 0);

        for(i = 0; i < reference_size; i++) reference_index_array[i] = i;
        size_tArray_to_array_of_sizes(reference_index_array, reference_size, reference_index_size_list, 1);

        char *tmp_error_msg=NULL;
        if(!TF_generate_array_of_alligned_sizes(list_of_lists_of_size, &result_list_with_final_sizes, &tmp_error_msg, 0))
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    tmp_error_msg
                    );
            goto finish;
        }



        //Generate the strings to print:
        target_array_str    = unsigned_integerArray_to_str(target, target_size, result_list_with_final_sizes); 
        reference_array_str = unsigned_integerArray_to_str(reference, reference_size, result_list_with_final_sizes); 
        target_reference_relative_index_str = size_tArray_to_index_str(relative_index_array, target_size, result_list_with_final_sizes, reference_size); 
        reference_index_str = size_tArray_to_index_str(reference_index_array, reference_size, result_list_with_final_sizes, reference_size);



        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    "> (relative index) %s\n"\
                    "> reference_array: %s\n"\
                    "> (index)          %s\n", 
                    target_array_str,
                    target_reference_relative_index_str,
                    reference_array_str,
                    reference_index_str
                    );
               
        //Free the buffers:
        free_size_t_pointer_list(target_size_list);
        free_size_t_pointer_list(relative_index_array_size_list);
        free_size_t_pointer_list(reference_size_list);
        free_size_t_pointer_list(reference_index_size_list);
        free(result_list_with_final_sizes);
        free(target_array_str);
        free(target_reference_relative_index_str);
        free(reference_array_str);
        free(reference_index_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_unsigned_integerArray_notPermutation(unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not a permutation of 'reference'.
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> The target array.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    size_t i;
    T_array *ref_T_array;
    T_dict *ref_counter_dict;
    T_element tmp_element;
    size_t relative_index_array[target_size]; 
    size_t reference_index_array[reference_size];
    const size_t NUMBER_OF_LISTS = 4;
    size_t **list_of_lists_of_size[NUMBER_OF_LISTS];
    size_t *target_size_list[target_size + 1];
    size_t *relative_index_array_size_list[target_size + 1];
    size_t *reference_size_list[reference_size + 1];
    size_t *reference_index_size_list[reference_size + 1];
    size_t *result_list_with_final_sizes = NULL;
    assert_result_struct assert_result = {
                                     true,                                                                   //was_successful
                                     line_number,                                                            //line_number
                                     "",                                                                     //result_details[MAX_CHARS]
                                     "assert_unsigned_integerArray_notPermutation",                          //assert_name
                                     "The target array SHOULD NOT BE A PERMUTATION of the reference array.", //std_message
                                     custom_message                                                          //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test and create the relative index array:
    assert_result.was_successful = false; //Start with the default value
    ref_T_array = unsigned_integerArray_to_T_array(reference, reference_size);
    ref_counter_dict = CD_count_elements(ref_T_array);
    A_delete_array(&ref_T_array);

    for(i = 0; i < target_size; i++)
    {
        tmp_element = unsigned_integer_to_T_element(target[i]);
        if(CD_get_count(tmp_element, ref_counter_dict) == 0) //There is no match for the element target[i]
        {
            assert_result.was_successful = true;
            T_free_element(&tmp_element);
            break;
        }
        else relative_index_array[i] = CD_pop_next_index(tmp_element, ref_counter_dict);

        T_free_element(&tmp_element);
    }

    if(ref_counter_dict->num_of_items != 0 && !assert_result.was_successful) assert_result.was_successful = true;

    D_delete_dict(&ref_counter_dict);


    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char *target_array_str, *reference_array_str;
        char *target_reference_relative_index_str;
        char *reference_index_str;


        //Create the array with final sizes:
        list_of_lists_of_size[0] = target_size_list;
        list_of_lists_of_size[1] = relative_index_array_size_list;
        list_of_lists_of_size[2] = reference_size_list;
        list_of_lists_of_size[3] = reference_index_size_list;

        unsigned_integerArray_to_array_of_sizes(target, target_size, target_size_list, 0);
        size_tArray_to_array_of_sizes(relative_index_array, target_size, relative_index_array_size_list, 1);
        unsigned_integerArray_to_array_of_sizes(reference, reference_size, reference_size_list, 0);

        for(i = 0; i < reference_size; i++) reference_index_array[i] = i;
        size_tArray_to_array_of_sizes(reference_index_array, reference_size, reference_index_size_list, 1);

        char *tmp_error_msg=NULL;
        if(!TF_generate_array_of_alligned_sizes(list_of_lists_of_size, &result_list_with_final_sizes, &tmp_error_msg, 0))
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    tmp_error_msg
                    );
            goto finish;
        }



        //Generate the strings to print:
        target_array_str    = unsigned_integerArray_to_str(target, target_size, result_list_with_final_sizes); 
        reference_array_str = unsigned_integerArray_to_str(reference, reference_size, result_list_with_final_sizes); 
        target_reference_relative_index_str = size_tArray_to_index_str(relative_index_array, target_size, result_list_with_final_sizes, reference_size); 
        reference_index_str = size_tArray_to_index_str(reference_index_array, reference_size, result_list_with_final_sizes, reference_size);



        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    "> (relative index) %s\n"\
                    "> reference_array: %s\n"\
                    "> (index)          %s\n", 
                    target_array_str,
                    target_reference_relative_index_str,
                    reference_array_str,
                    reference_index_str
                    );
               
        //Free the buffers:
        free_size_t_pointer_list(target_size_list);
        free_size_t_pointer_list(relative_index_array_size_list);
        free_size_t_pointer_list(reference_size_list);
        free_size_t_pointer_list(reference_index_size_list);
        free(result_list_with_final_sizes);
        free(target_array_str);
        free(target_reference_relative_index_str);
        free(reference_array_str);
        free(reference_index_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_unsigned_integerArray_isPartialPermutation(unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is a partital permutation of 'reference'.
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> The target array.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    size_t i;
    T_array *ref_T_array;
    T_dict *ref_counter_dict;
    T_element tmp_element;
    size_t relative_index_array[target_size]; //Stores the index that relates 
                                              //each element from the target array 
                                              //with an element from the reference array. 
                                              //If there is no correspondence, we have 
                                              //relative_index_array[i] == reference_size (invalid value)
    size_t aux_relative_index_array[target_size]; //Stores the index that relates 
                                                  //each element from the target array 
                                                  //with an element from the reference array. 
                                                  //If there is no correspondence, we have 
                                                  //relative_index_array[i] == 0 (invalid value)
    size_t reference_index_array[reference_size];
    const size_t NUMBER_OF_LISTS = 4;
    size_t **list_of_lists_of_size[NUMBER_OF_LISTS];
    size_t *target_size_list[target_size + 1];
    size_t *relative_index_array_size_list[target_size + 1];
    size_t *reference_size_list[reference_size + 1];
    size_t *reference_index_size_list[reference_size + 1];
    size_t *result_list_with_final_sizes = NULL;
    assert_result_struct assert_result = {
                                     true,                                                               //was_successful
                                     line_number,                                                        //line_number
                                     "",                                                                 //result_details[MAX_CHARS]
                                     "assert_unsigned_integerArray_isPartialPermutation",                         //assert_name
                                     "The target array SHOULD BE A PARTIAL PERMUTATION of the reference array.", //std_message
                                     custom_message                                                      //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test and create the relative index array:
    assert_result.was_successful = true; //Start with the default value
    ref_T_array = unsigned_integerArray_to_T_array(reference, reference_size);
    ref_counter_dict = CD_count_elements(ref_T_array);
    A_delete_array(&ref_T_array);

    for(i = 0; i < target_size; i++)
    {
        tmp_element = unsigned_integer_to_T_element(target[i]);
        if(CD_get_count(tmp_element, ref_counter_dict) == 0) //There is no match for the element target[i]
        {
            relative_index_array[i] = reference_size;
            aux_relative_index_array[i] = 0;
            if(assert_result.was_successful) assert_result.was_successful = false;
        }
        else aux_relative_index_array[i] = relative_index_array[i] = CD_pop_next_index(tmp_element, ref_counter_dict);

        T_free_element(&tmp_element);
    }

    D_delete_dict(&ref_counter_dict);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char *target_array_str, *reference_array_str;
        char *target_reference_relative_index_str;
        char *reference_index_str;


        //Create the array with final sizes:
        list_of_lists_of_size[0] = target_size_list;
        list_of_lists_of_size[1] = relative_index_array_size_list;
        list_of_lists_of_size[2] = reference_size_list;
        list_of_lists_of_size[3] = reference_index_size_list;

        unsigned_integerArray_to_array_of_sizes(target, target_size, target_size_list, 0);
        size_tArray_to_array_of_sizes(aux_relative_index_array, target_size, relative_index_array_size_list, 1);
        unsigned_integerArray_to_array_of_sizes(reference, reference_size, reference_size_list, 0);

        for(i = 0; i < reference_size; i++) reference_index_array[i] = i;
        size_tArray_to_array_of_sizes(reference_index_array, reference_size, reference_index_size_list, 1);

        char *tmp_error_msg=NULL;
        if(!TF_generate_array_of_alligned_sizes(list_of_lists_of_size, &result_list_with_final_sizes, &tmp_error_msg, 0))
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    tmp_error_msg
                    );
            goto finish;
        }



        //Generate the strings to print:
        target_array_str    = unsigned_integerArray_to_str(target, target_size, result_list_with_final_sizes); 
        reference_array_str = unsigned_integerArray_to_str(reference, reference_size, result_list_with_final_sizes); 
        target_reference_relative_index_str = size_tArray_to_index_str(relative_index_array, target_size, result_list_with_final_sizes, reference_size); 
        reference_index_str = size_tArray_to_index_str(reference_index_array, reference_size, result_list_with_final_sizes, reference_size);



        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    "> (relative index) %s\n"\
                    "> reference_array: %s\n"\
                    "> (index)          %s\n", 
                    target_array_str,
                    target_reference_relative_index_str,
                    reference_array_str,
                    reference_index_str
                    );
               
        //Free the buffers:
        free_size_t_pointer_list(target_size_list);
        free_size_t_pointer_list(relative_index_array_size_list);
        free_size_t_pointer_list(reference_size_list);
        free_size_t_pointer_list(reference_index_size_list);
        free(result_list_with_final_sizes);
        free(target_array_str);
        free(target_reference_relative_index_str);
        free(reference_array_str);
        free(reference_index_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}



void assert_unsigned_integerArray_notIsPartialPermutation(unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if 'target' is not a partial permutation of 'reference'.
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> The target array.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    size_t i;
    T_array *ref_T_array;
    T_dict *ref_counter_dict;
    T_element tmp_element;
    size_t relative_index_array[target_size]; 
    size_t reference_index_array[reference_size];
    const size_t NUMBER_OF_LISTS = 4;
    size_t **list_of_lists_of_size[NUMBER_OF_LISTS];
    size_t *target_size_list[target_size + 1];
    size_t *relative_index_array_size_list[target_size + 1];
    size_t *reference_size_list[reference_size + 1];
    size_t *reference_index_size_list[reference_size + 1];
    size_t *result_list_with_final_sizes = NULL;
    assert_result_struct assert_result = {
                                     true,                                                                   //was_successful
                                     line_number,                                                            //line_number
                                     "",                                                                     //result_details[MAX_CHARS]
                                     "assert_unsigned_integerArray_notIsPartialPermutation",                          //assert_name
                                     "The target array SHOULD NOT BE A PARTIAL PERMUTATION of the reference array.", //std_message
                                     custom_message                                                          //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test and create the relative index array:
    assert_result.was_successful = false; //Start with the default value
    ref_T_array = unsigned_integerArray_to_T_array(reference, reference_size);
    ref_counter_dict = CD_count_elements(ref_T_array);
    A_delete_array(&ref_T_array);

    for(i = 0; i < target_size; i++)
    {
        tmp_element = unsigned_integer_to_T_element(target[i]);
        if(CD_get_count(tmp_element, ref_counter_dict) == 0) //There is no match for the element target[i]
        {
            assert_result.was_successful = true;
            T_free_element(&tmp_element);
            break;
        }
        else relative_index_array[i] = CD_pop_next_index(tmp_element, ref_counter_dict);

        T_free_element(&tmp_element);
    }

    D_delete_dict(&ref_counter_dict);


    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char *target_array_str, *reference_array_str;
        char *target_reference_relative_index_str;
        char *reference_index_str;


        //Create the array with final sizes:
        list_of_lists_of_size[0] = target_size_list;
        list_of_lists_of_size[1] = relative_index_array_size_list;
        list_of_lists_of_size[2] = reference_size_list;
        list_of_lists_of_size[3] = reference_index_size_list;

        unsigned_integerArray_to_array_of_sizes(target, target_size, target_size_list, 0);
        size_tArray_to_array_of_sizes(relative_index_array, target_size, relative_index_array_size_list, 1);
        unsigned_integerArray_to_array_of_sizes(reference, reference_size, reference_size_list, 0);

        for(i = 0; i < reference_size; i++) reference_index_array[i] = i;
        size_tArray_to_array_of_sizes(reference_index_array, reference_size, reference_index_size_list, 1);

        char *tmp_error_msg=NULL;
        if(!TF_generate_array_of_alligned_sizes(list_of_lists_of_size, &result_list_with_final_sizes, &tmp_error_msg, 0))
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    tmp_error_msg
                    );
            goto finish;
        }



        //Generate the strings to print:
        target_array_str    = unsigned_integerArray_to_str(target, target_size, result_list_with_final_sizes); 
        reference_array_str = unsigned_integerArray_to_str(reference, reference_size, result_list_with_final_sizes); 
        target_reference_relative_index_str = size_tArray_to_index_str(relative_index_array, target_size, result_list_with_final_sizes, reference_size); 
        reference_index_str = size_tArray_to_index_str(reference_index_array, reference_size, result_list_with_final_sizes, reference_size);



        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    "> (relative index) %s\n"\
                    "> reference_array: %s\n"\
                    "> (index)          %s\n", 
                    target_array_str,
                    target_reference_relative_index_str,
                    reference_array_str,
                    reference_index_str
                    );
               
        //Free the buffers:
        free_size_t_pointer_list(target_size_list);
        free_size_t_pointer_list(relative_index_array_size_list);
        free_size_t_pointer_list(reference_size_list);
        free_size_t_pointer_list(reference_index_size_list);
        free(result_list_with_final_sizes);
        free(target_array_str);
        free(target_reference_relative_index_str);
        free(reference_array_str);
        free(reference_index_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_unsigned_integerArray_hasPartialPermutation(unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if 'reference' is  a partital permutation of 'target'.
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> The target array.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    size_t i;
    T_array *target_T_array;
    T_dict *target_counter_dict;
    T_element tmp_element;
    size_t relative_index_array[reference_size]; //Stores the index that relates 
                                              //each element from the reference array 
                                              //with an element from the target array. 
                                              //If there is no correspondence, we have 
                                              //relative_index_array[i] == target_size (invalid value)
    size_t aux_relative_index_array[reference_size]; //Stores the index that relates 
                                                  //each element from the reference array 
                                                  //with an element from the target array. 
                                                  //If there is no correspondence, we have 
                                                  //relative_index_array[i] == 0 (invalid value)
    size_t target_index_array[target_size];
    const size_t NUMBER_OF_LISTS = 4;
    size_t **list_of_lists_of_size[NUMBER_OF_LISTS];
    size_t *target_size_list[target_size + 1];
    size_t *target_index_size_list[target_size + 1];
    size_t *reference_size_list[reference_size + 1];
    size_t *relative_index_array_size_list[reference_size + 1];
    size_t *result_list_with_final_sizes = NULL;
    assert_result_struct assert_result = {
                                     true,                                                               //was_successful
                                     line_number,                                                        //line_number
                                     "",                                                                 //result_details[MAX_CHARS]
                                     "assert_unsigned_integerArray_hasPartialPermutation",                         //assert_name
                                     "The target array SHOULD HAVE AS PARTIAL PERMUTATION the reference array.", //std_message
                                     custom_message                                                      //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test and create the relative index array:
    assert_result.was_successful = true; //Start with the default value
    target_T_array = unsigned_integerArray_to_T_array(target, target_size);
    target_counter_dict = CD_count_elements(target_T_array);
    A_delete_array(&target_T_array);

    for(i = 0; i < reference_size; i++)
    {
        tmp_element = unsigned_integer_to_T_element(reference[i]);
        if(CD_get_count(tmp_element, target_counter_dict) == 0) //There is no match for the element reference[i]
        {
            relative_index_array[i] = target_size;
            aux_relative_index_array[i] = 0;
            if(assert_result.was_successful) assert_result.was_successful = false;
        }
        else aux_relative_index_array[i] = relative_index_array[i] = CD_pop_next_index(tmp_element, target_counter_dict);

        T_free_element(&tmp_element);
    }

    D_delete_dict(&target_counter_dict);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char *target_array_str, *reference_array_str;
        char *reference_target_relative_index_str;
        char *target_index_str;


        //Create the array with final sizes:
        list_of_lists_of_size[0] = target_size_list;
        list_of_lists_of_size[1] = target_index_size_list;
        list_of_lists_of_size[2] = reference_size_list;
        list_of_lists_of_size[3] = relative_index_array_size_list;

        unsigned_integerArray_to_array_of_sizes(target, target_size, target_size_list, 0);

        for(i = 0; i < target_size; i++) target_index_array[i] = i;
        size_tArray_to_array_of_sizes(target_index_array, target_size, target_index_size_list, 1);
        unsigned_integerArray_to_array_of_sizes(reference, reference_size, reference_size_list, 0);
        size_tArray_to_array_of_sizes(aux_relative_index_array, reference_size, relative_index_array_size_list, 1);


        char *tmp_error_msg=NULL;
        if(!TF_generate_array_of_alligned_sizes(list_of_lists_of_size, &result_list_with_final_sizes, &tmp_error_msg, 0))
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    tmp_error_msg
                    );
            goto finish;
        }



        //Generate the strings to print:
        target_array_str    = unsigned_integerArray_to_str(target, target_size, result_list_with_final_sizes); 
        reference_array_str = unsigned_integerArray_to_str(reference, reference_size, result_list_with_final_sizes); 
        reference_target_relative_index_str = size_tArray_to_index_str(relative_index_array, reference_size, result_list_with_final_sizes, target_size); 
        target_index_str = size_tArray_to_index_str(target_index_array, target_size, result_list_with_final_sizes, target_size);



        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    "> (index)          %s\n"\
                    "> reference_array: %s\n"\
                    "> (relative index) %s\n",
                    target_array_str,
                    target_index_str,
                    reference_array_str,
                    reference_target_relative_index_str
                    );
               
        //Free the buffers:
        free_size_t_pointer_list(target_size_list);
        free_size_t_pointer_list(relative_index_array_size_list);
        free_size_t_pointer_list(reference_size_list);
        free_size_t_pointer_list(target_index_size_list);
        free(result_list_with_final_sizes);
        free(target_array_str);
        free(reference_target_relative_index_str);
        free(reference_array_str);
        free(target_index_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}


void assert_unsigned_integerArray_notHasPartialPermutation(unsigned_integer target[], size_t target_size, unsigned_integer reference[], size_t reference_size, int line_number, char custom_message[])
/**
 * Description: This function checks if 'reference' is not a partital permutation of 'target'.
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (unsigned_integer []) target --> The target array.
 *        (size_t) target_size --> The size of the array 'target'. May not be 0.
 *        (unsigned_integer []) reference --> The reference array.
 *        (size_t) reference_size --> The size of the array 'reference'. May not be 0.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(target_size, reference_size))
 *
 * Space Complexity: O(max(target_size, reference_size))
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    size_t i;
    T_array *target_T_array;
    T_dict *target_counter_dict;
    T_element tmp_element;
    size_t relative_index_array[reference_size]; 
    size_t target_index_array[target_size];
    const size_t NUMBER_OF_LISTS = 4;
    size_t **list_of_lists_of_size[NUMBER_OF_LISTS];
    size_t *target_size_list[target_size + 1];
    size_t *target_index_size_list[target_size + 1];
    size_t *reference_size_list[reference_size + 1];
    size_t *relative_index_array_size_list[reference_size + 1];
    size_t *result_list_with_final_sizes = NULL;
    assert_result_struct assert_result = {
                                     true,                                                               //was_successful
                                     line_number,                                                        //line_number
                                     "",                                                                 //result_details[MAX_CHARS]
                                     "assert_unsigned_integerArray_notHasPartialPermutation",                         //assert_name
                                     "The target array SHOULD NOT HAVE AS PARTIAL PERMUTATION the reference array.", //std_message
                                     custom_message                                                      //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test and create the relative index array:
    assert_result.was_successful = false; //Start with the default value
    target_T_array = unsigned_integerArray_to_T_array(target, target_size);
    target_counter_dict = CD_count_elements(target_T_array);
    A_delete_array(&target_T_array);

    for(i = 0; i < reference_size; i++)
    {
        tmp_element = unsigned_integer_to_T_element(reference[i]);
        if(CD_get_count(tmp_element, target_counter_dict) == 0) //There is no match for the element reference[i]
        {
            assert_result.was_successful = true;
            break;
        }
        else relative_index_array[i] = CD_pop_next_index(tmp_element, target_counter_dict);

        T_free_element(&tmp_element);
    }

    D_delete_dict(&target_counter_dict);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //------------------------------------------------------------------------------
        //Generate the details for a highly verbose fail message:
        char *target_array_str, *reference_array_str;
        char *reference_target_relative_index_str;
        char *target_index_str;


        //Create the array with final sizes:
        list_of_lists_of_size[0] = target_size_list;
        list_of_lists_of_size[1] = target_index_size_list;
        list_of_lists_of_size[2] = reference_size_list;
        list_of_lists_of_size[3] = relative_index_array_size_list;

        unsigned_integerArray_to_array_of_sizes(target, target_size, target_size_list, 0);

        for(i = 0; i < target_size; i++) target_index_array[i] = i;
        size_tArray_to_array_of_sizes(target_index_array, target_size, target_index_size_list, 1);
        unsigned_integerArray_to_array_of_sizes(reference, reference_size, reference_size_list, 0);
        size_tArray_to_array_of_sizes(relative_index_array, reference_size, relative_index_array_size_list, 1);


        char *tmp_error_msg=NULL;
        if(!TF_generate_array_of_alligned_sizes(list_of_lists_of_size, &result_list_with_final_sizes, &tmp_error_msg, 0))
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    tmp_error_msg
                    );
            goto finish;
        }



        //Generate the strings to print:
        target_array_str    = unsigned_integerArray_to_str(target, target_size, result_list_with_final_sizes); 
        reference_array_str = unsigned_integerArray_to_str(reference, reference_size, result_list_with_final_sizes); 
        reference_target_relative_index_str = size_tArray_to_index_str(relative_index_array, reference_size, result_list_with_final_sizes, target_size); 
        target_index_str = size_tArray_to_index_str(target_index_array, target_size, result_list_with_final_sizes, target_size);



        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> target_array:    %s\n"\
                    "> (index)          %s\n"\
                    "> reference_array: %s\n"\
                    "> (relative index) %s\n",
                    target_array_str,
                    target_index_str,
                    reference_array_str,
                    reference_target_relative_index_str
                    );
               
        //Free the buffers:
        free_size_t_pointer_list(target_size_list);
        free_size_t_pointer_list(relative_index_array_size_list);
        free_size_t_pointer_list(reference_size_list);
        free_size_t_pointer_list(target_index_size_list);
        free(result_list_with_final_sizes);
        free(target_array_str);
        free(reference_target_relative_index_str);
        free(reference_array_str);
        free(target_index_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}

/*STD assert functions for string type*/
void assert_string_equal (char target[], char reference[], bool ignore_case, int line_number, char custom_message[])
/**
 * Description: This function checks if the string 'target' is equal to the string
 * 'reference'. A string is a (char []) terminated by '\0' char.
 * Then, it returns the result of the test with details, if it fails. The level of
 * details is managed by the global variable 'verbose' --> LOW, MEDIUM, or HIGH.
 *     If 'ignore' is true, this function will not test anything.
 *
 * Input: (char []) target --> target string that will be compared with the 
 *                             reference string.
 *        (char []) reference --> The reference string.
 *        (int) line_number --> The number of the line on which this function was written in the
 *        source code.
 *        (char []) custom_message --> Personalized message that will be printed if the test fails.
 *
 * Output: (void)
 *
 * Time Complexity: O(max(strlen(target), strlen(reference)))
 *
 * Space Complexity: O(max(strlen(target), strlen(reference)))
 */
{
    //------------------------------------------------------------------------------
    //Define and initialize the variables:
    int counter;
    const int max_error_msg_sz = MAX_ERROR_MSG_SZ, max_string_size = 4096, number_of_lists = 3;
    size_t std_char_width;
    bool error = false;
    char function_error_message[max_error_msg_sz];
    char *target_reference_comparison_str;
    char *target_formatted_str;
    char *reference_formatted_str;
    assert_result_struct assert_result = {
                         true,                                                             //was_successful
                         line_number,                                                      //line_number
                         "",                                                               //result_details[MAX_CHARS]
                         "assert_string_equal",                                            //assert_name
                         "The string 'target' SHOULD BE EQUAL to the string 'reference'.", //std_message
                         custom_message                                                    //custom_message
                                         };

    //------------------------------------------------------------------------------
    //Check for ignore:
    if(ignore)
        goto print;

    //------------------------------------------------------------------------------
    //Execute the test:
    if(ignore_case) assert_result.was_successful = !strncasecmp(target, reference, max_string_size);
    else assert_result.was_successful = !strncmp(target, reference, max_string_size);

    //Check if it is necessary to generate highly verbose details in case of fail:
    if(!assert_result.was_successful && verbose == HIGH)
    {
        //Check for chars like '\n', '\t':
        if(check_for_special_char(target) || check_for_special_char(reference)) 
        {
            std_char_width = 2;
            target_formatted_str = string_to_one_line_formatted_string(target);
            reference_formatted_str = string_to_one_line_formatted_string(reference);
        }
        else 
        {
            std_char_width = 1;
            target_formatted_str = NULL;
            reference_formatted_str = NULL;
        }

        target_reference_comparison_str = target_reference_chars_comparison_to_string(target, reference, ignore_case, '|', '*', std_char_width);


        counter = snprintf(assert_result.result_details, 
                    MAX_CHARS,
                    "> ignore_case = %s\n"\
                    ">\n"\
                    "> target    (len %5zu): [%s]\n"\
                    ">                         %s\n"\
                    "> reference (len %5zu): [%s]\n",
                    ignore_case?"true":"false",
                    strlen(target),
                    target_formatted_str?target_formatted_str:target,
                    target_reference_comparison_str,
                    strlen(reference),
                    reference_formatted_str?reference_formatted_str:reference
                    );
               

        //Free allocated memory:
        free(target_reference_comparison_str);
        if(target_formatted_str) free(target_formatted_str);
        if(reference_formatted_str) free(reference_formatted_str);

        //------------------------------------------------------------------------------
        //Check for error:
        if (counter < 0) 
        {
            //Error creating the result message.
            error = true;
            snprintf(function_error_message, 
                    max_error_msg_sz, 
                    "\nError while generating the result message (at line %d).\n",
                    line_number
                    );
            goto finish;
        }
        //------------------------------------------------------------------------------
    }

    
    //------------------------------------------------------------------------------
    //Print the result:
print:
    print_assert_result(assert_result);
    
    //------------------------------------------------------------------------------
    //Finish:
finish:
    if(error)
    {
        fprintf(stderr, function_error_message);
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
}

//#################developing###################
//###################finish_developing##########


//------------------------------------------------------------------------------
//Definitions for the local auxiliary functions:
static char *decimal_to_binary_generate_str(unsigned_integer target, size_t num_of_digits)
/**
 * Description: This function transforms the decimal number 'target' into its 
 * binary form and returns the result as a string. 
 *     After using the string, the user must call free to liberate the memory 
 * allocated. 
 *     The string will have exactly 'num_of_digits' rightmost digits of 
 * the binary representation of 'target'.
 * 
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex1: if target == 0b01101 and num_of_digits == 3, the result is "101".
 * Ex2: if target == 0b01101 and num_of_digits == 6, the result is "001101".
 *
 * Input: (unsigned_integer) target --> Decimal number that will be transformed to 
 *       binary number.
 *       (int) num_of_digits --> The number of rightmost digits that 
 *       will be transformed to string and returned to the user of the function.
 * 
 * Output: (char *) --> The memory to the string allocated. This string contains
 *         the rightmost 'num_of_digits' of the binary representation of 'target'.
 */
{
    //------------------------------------------------------------------------------
    //Allocate memory for the binary digits:
    char *buffer;

    buffer = calloc(num_of_digits + 1, sizeof *buffer);
    if(!buffer)
    {
        fprintf(stderr, "\nERROR while allocating memory in function decimal_to_binary_generate_str.\n");
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
    //Fill the buffer with the binary characters:
    buffer[num_of_digits] = '\0';
    while(num_of_digits > 0)
    {
        buffer[--num_of_digits] = (target & 1)? '1':'0';
        target >>= 1;
    }

    //------------------------------------------------------------------------------
    //Return the result:
    return buffer;

    //------------------------------------------------------------------------------
}

static char *mask_compare_generate_str(unsigned_integer target, unsigned_integer reference, unsigned_integer mask, char equal_symbol, char diff_symbol)
/**
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 */
{
    //------------------------------------------------------------------------------
    //Allocate memory for the binary digits:
    char *buffer;
    size_t num_of_digits = num_of_significant_bits(mask);
    unsigned_integer digit_mask = 1;

    /*The bitwise operation "not (A xor B)" gives us the bits that are equal in A and B.*/
    unsigned_integer xnor_target_reference = ~ (target ^ reference);
    buffer = calloc(num_of_digits + 1, sizeof *buffer);

    //------------------------------------------------------------------------------
    //Check for error during the memory allocation:
    if(!buffer)
    {
        fprintf(stderr, "\nERROR while allocating memory in function mask_compare_generate_str.\n");
        exit(EXIT_FAILURE);
    }

    //------------------------------------------------------------------------------
    //Fill the buffer with the binary characters:
    buffer[num_of_digits] = '\0';
    while(num_of_digits)
    {
        if(mask & digit_mask) //Check if the digits of target and reference are equal.
        {
            buffer[--num_of_digits] = (digit_mask & xnor_target_reference)? equal_symbol:diff_symbol;
        }
        else //Ignore this digit
        {
            buffer[--num_of_digits] = ' ';
        }

        digit_mask <<= 1;
    }

    //------------------------------------------------------------------------------
    //Return the result:
    return buffer;

    //------------------------------------------------------------------------------
}


static int num_of_significant_bits(unsigned_integer number)
/**
 * Description: This function calculates the number of significant bits of 'number'.
 * Ex.: if 'number' is 0b00001101, the result will be 4, not 8.
 */
{
    int counter = 0;
    //Invariant relation: {counter = 0; number * 2 ^ counter}
    while(number)
    {
        number >>= 1;
        counter++;
    }

    //Return the result:
    return counter;
}




static char *unsigned_integerArray_generate_aligned_str(unsigned_integer target_array[], size_t target_array_size, unsigned_integer reference_array[], size_t reference_array_size) 
/**
 * Description: This function generates the string of the array 'target_array' 
 * of unsigned_integer's with size 'target_array_size'. The string is 
 * generated in such a way that each element will be aligned with each 
 * respective element of 'reference_array'. The alignment will take place 
 * only if there is a respective element in the reference array, otherwise, it 
 * will be used the minimum space necessary to accommodate each element plus one 
 * extra space. 
 *     The alignment is done in the following way: 
 *     (1) - If the respective element of the reference array has more digits, 
 *     aditional spaces are added to the target array element;
 *     (2) - Otherwise, no additional spaces are added.
 *
 *     The reference array may be NULL. In that situation, the reference_array_size
 * will be ignored.
 *     If the size of the array is different from the size passed as argument, the 
 * behavior is undefined.
 *
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex:
 * --> target_array:    [ 12, 34, 5, 123]
 * --> reference_array: [ 12334, 2343, 5, 4, 9]
 * --> result:          [    12,   34, 5, 123]
 * If this functions is called again but exchanging the reference array with the 
 * target array, the following result would be generated for the reference array:
 * -->                  [ 12334, 2343, 5,   4, 9]
 *  In conclusion, if this function is applied to both arrays (exchanging them 
 *  between target and reference), they will the generated strings would have 
 *  each respective element vertically aligned.
 *
 * Input: (unsigned_integer[]) target_array
 *        (size_t) target_array_size
 *        (unsigned_integer[]) reference_array
 *        (size_t) reference_array_size 
 *
 * Output: (char *) --> The formatted string.
 *
 * Time Complexity: O(n^2) --> This function uses strcat in 
 * a inefficient way.
 */
{
    //------------------------------------------------------------------------------
    //Declare local varibles:
    char *result;
    char number_buffer[50];
    size_t current_buffer_size = 100, buffer_chars_used = 0;


    //------------------------------------------------------------------------------
    //Allocate memory for the buffer:
    result = calloc(current_buffer_size, sizeof *result);
    if(!result)
    {
        fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
        exit(EXIT_FAILURE);
    }
    
    //------------------------------------------------------------------------------
    //Initialize the buffer:
    strcat(result, "[");
    buffer_chars_used += 2; //'[' + '\0'

    //------------------------------------------------------------------------------
    //Fill the buffer with the target_array elements:

    size_t i, n; 
    int number_of_digits;
    char intermediate_buffer[20] = "   %llu,";
    for(i = 0; i < target_array_size; i++)
    {
        //Create the string of the number that will be concatenated to the result:
        if (reference_array != NULL && i < reference_array_size)
            number_of_digits = num_of_digits(reference_array[i]);
        else 
            number_of_digits = 0;

        n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "   %%%dllu,",  number_of_digits);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        n = snprintf(number_buffer, sizeof number_buffer / sizeof number_buffer[0], intermediate_buffer,  target_array[i]);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        //Check if there is enough space:
        if(buffer_chars_used + n >= current_buffer_size)
        {
            //Allocate more memory:
            current_buffer_size = buffer_chars_used;
            current_buffer_size *= 2;
            result = realloc(result, sizeof *result * current_buffer_size);
            if(!result)
            {
                fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
                exit(EXIT_FAILURE);
            }
        }

        //Add the next number to the result:
        strcat(result, number_buffer);
        buffer_chars_used += n;
    }    

    //------------------------------------------------------------------------------
    //Add ']' in the end:
    result[buffer_chars_used - 2] = ']';

    //------------------------------------------------------------------------------
    //Return the result:
    return result;

    //------------------------------------------------------------------------------

}

static char *unsigned_integerArray_compared_equal_generate_str(unsigned_integer arr1[], size_t arr1_size, unsigned_integer arr2[], size_t arr2_size, char equal_symbol, char diff_symbol)
/**
 * Description: This function generates a string that compares each element of 
 * arr1 with each respertive element of arr2. If each respective pair of elements 
 * are equal, the 'equal_symbol' is used. Otherwise, the 'diff_symbol' is used. 
 * The symbol is aligned with the biggest element. If one of the arrays is greater
 * that the other, the 'diff_symbol' will be used for the rest of the elements.
 *
 *     If the size of the array is different from the size passed as argument, the 
 * behavior is undefined.
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex:
 * --> arr1:    [ 12, 34, 5, 123]
 * --> arr2     [ 12334, 2343, 5, 4, 9]
 * --> equal_symbol : '|'
 * --> diff_symbol: ':'
 * -->           [    12,   34, 5, 123]
 * --> result:         :     :  |    :  :      
 * -->           [ 12334, 2343, 5,   4, 9]
 *
 * Input: (unsigned_integer[]) arr1
 *        (size_t) arr1_size
 *        (unsigned_integer[]) arr2
 *        (size_t) arr2_size 
 *        (char)   equal_symbol
 *        (char)   diff_symbol
 *
 * Output: (char *) --> The formatted string.
 *
 * Time Complexity: O(n^2) --> This function uses strcat in 
 * a inefficient way.
 */
{
    //------------------------------------------------------------------------------
    //Declare local varibles:
    char *result;
    char symbol_buffer[50];
    size_t current_buffer_size = 100, buffer_chars_used = 0;


    //------------------------------------------------------------------------------
    //Allocate memory for the buffer:
    result = calloc(current_buffer_size, sizeof *result);
    if(!result)
    {
        fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
        exit(EXIT_FAILURE);
    }
    
    //------------------------------------------------------------------------------
    //Initialize the buffer:
    strcat(result, " ");
    buffer_chars_used += 2; //' ' + '\0'

    //------------------------------------------------------------------------------
    //Fill the buffer with the arr1 elements:

    size_t i, n; 
    size_t max_array_size = (arr1_size >= arr2_size)?arr1_size:arr2_size;
    int number_of_digits_element_arr1, number_of_digits_element_arr2, number_of_digits;
    char intermediate_buffer[20]; 
    for(i = 0; i < max_array_size; i++)
    {
        //Create the string of the char that will be concatenated to the result:
        number_of_digits_element_arr1 = (i < arr1_size)?num_of_digits(arr1[i]) : 0;
        number_of_digits_element_arr2 = (i < arr2_size)?num_of_digits(arr2[i]) : 0;

        number_of_digits = (number_of_digits_element_arr1 >= number_of_digits_element_arr2)? number_of_digits_element_arr1 : number_of_digits_element_arr2;


        n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "   %%%dc ",  number_of_digits);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        if(i < arr1_size && i < arr2_size)
            n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], intermediate_buffer,  (arr1[i] == arr2[i])?equal_symbol : diff_symbol);
        else
            n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], intermediate_buffer,  diff_symbol);

        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        //Check if there is enough space:
        if(buffer_chars_used + n >= current_buffer_size)
        {
            //Allocate more memory:
            current_buffer_size = buffer_chars_used;
            current_buffer_size *= 2;
            result = realloc(result, sizeof *result * current_buffer_size);
            if(!result)
            {
                fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
                exit(EXIT_FAILURE);
            }
        }

        //Add the next number to the result:
        strcat(result, symbol_buffer);
        buffer_chars_used += n;
    }    

    //------------------------------------------------------------------------------
    //Return the result:
    return result;

    //------------------------------------------------------------------------------
}


static char *unsigned_integerArray_indexes_generate_str(unsigned_integer arr1[], size_t arr1_size, unsigned_integer arr2[], size_t arr2_size)
/**
 * Description: This function generates a string with indexes for each element of 
 * arr1/arr2. The indexes are vertically aligned with the greatest of elements 
 * from arr1 or arr2. 
 *
 *     If the size of the array is different from the size passed as argument, the 
 * behavior is undefined.
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex:
 * --> arr1:    [ 12, 34, 5, 123]
 * --> arr2     [ 12334, 2343, 5, 4, 29]
 * -->           [      12,     34,   5, 123]
 * -->           [   12334,   2343,   5,   4,   29]
 * --> result:          (0)     (1)  (2)  (3)   (4) 
 *
 * Input: (unsigned_integer[]) arr1
 *        (size_t) arr1_size
 *        (unsigned_integer[]) arr2
 *        (size_t) arr2_size 
 *
 * Output: (char *) --> The formatted string with indexes.
 *
 * Time Complexity: O(n^2) --> This function uses strcat in 
 * a inefficient way.
 */
{
    //------------------------------------------------------------------------------
    //Declare local varibles:
    char *result;
    char formatted_index_buffer[50];
    size_t current_buffer_size = 100, buffer_chars_used = 0;


    //------------------------------------------------------------------------------
    //Allocate memory for the buffer:
    result = calloc(current_buffer_size, sizeof *result);
    if(!result)
    {
        fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
        exit(EXIT_FAILURE);
    }
    
    //------------------------------------------------------------------------------
    //Initialize the buffer:
    strcat(result, " ");
    buffer_chars_used += 2; //' ' + '\0'

    //------------------------------------------------------------------------------
    //Fill the buffer with the arr1 elements:

    size_t i, n; 
    size_t max_array_size = (arr1_size >= arr2_size)?arr1_size:arr2_size;
    int number_of_digits_element_arr1, number_of_digits_element_arr2, number_of_digits;
    char intermediate_buffer[20]; 
    char index_buffer[20];
    for(i = 0; i < max_array_size; i++)
    {
        //Create the string of the char that will be concatenated to the result:
        number_of_digits_element_arr1 = (i < arr1_size)?num_of_digits(arr1[i]) : 0;
        number_of_digits_element_arr2 = (i < arr2_size)?num_of_digits(arr2[i]) : 0;

        number_of_digits = (number_of_digits_element_arr1 >= number_of_digits_element_arr2)? number_of_digits_element_arr1 : number_of_digits_element_arr2;


        n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "%%%ds",  number_of_digits + 4);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        n = snprintf(index_buffer, sizeof index_buffer / sizeof index_buffer[0], "(%d)",  i);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        n = snprintf(formatted_index_buffer, sizeof formatted_index_buffer / sizeof formatted_index_buffer[0], intermediate_buffer,  index_buffer);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        //Check if there is enough space:
        if(buffer_chars_used + n >= current_buffer_size)
        {
            //Allocate more memory:
            current_buffer_size = buffer_chars_used;
            current_buffer_size *= 2;
            result = realloc(result, sizeof *result * current_buffer_size);
            if(!result)
            {
                fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
                exit(EXIT_FAILURE);
            }
        }

        //Add the next number to the result:
        strcat(result, formatted_index_buffer);
        buffer_chars_used += n;
    }    

    //------------------------------------------------------------------------------
    //Return the result:
    return result;

    //------------------------------------------------------------------------------
}


static char *unsigned_integerArray_notSorted_result_generate_str(unsigned_integer target[], size_t target_size, bool ascending_order)
/**
 * Description: This function generates a string that makes it easier to see that 
 * the 'target' array is NOT sorted in ascending_order if 'ascending_order' is 
 * true and in descending_order otherwise. It generates symbols that are aligned 
 * with the current element from target and indicates if this element is <=, <, 
 * >= or > than the next element. The first element that violates the sorting 
 * requirements is checked with a '*' symbol.
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex1: 
 * The array [ 12, 23, 34, 4, 23] is not sorted in ascending order. The string
 * that will be generated by this function in this case is:
 * target: [   12,   23,   34,   4,   23]
 *             <=    <=     >    *
 *
 * Ex2:
 * The array [ 0, 0, 0, 1] is not sorted in descending order. The string 
 * generated by this function is:
 * target: [   0,   0,   0,   1]
 *            >=   >=    <    *
 *
 * Inputs: (unsigned_integer[]) target --> The array that is not sorted. 
 *         (size_t) target_size --> The size of the array 'target'.
 *         (bool) ascending_order --> If true, means that the target array
 *         should be sorted in ascending order, but is not. Otherwise, it means
 *         that the array 'target' should be sorted in descending order but
 *         it is not.
 *
 * Output: (char *) --> The string generated in order to make it easier to 
 *         see that the array is not sorted.
 *
 *
 * Time Complexity: O(n^2) --> This function uses strcat in 
 * a inefficient way.
 */
{
    //------------------------------------------------------------------------------
    //Declare local varibles:
    char *result;
    char formatted_symbol_buffer[50];
    size_t current_buffer_size = 100, buffer_chars_used = 0;


    //------------------------------------------------------------------------------
    //Allocate memory for the buffer:
    result = calloc(current_buffer_size, sizeof *result);
    if(!result)
    {
        fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
        exit(EXIT_FAILURE);
    }
    
    //------------------------------------------------------------------------------
    //Initialize the buffer:
    strcat(result, " ");
    buffer_chars_used += 2; //' ' + '\0'

    //------------------------------------------------------------------------------
    //Fill the buffer with the arr1 elements:

    size_t i, n, remaining_loops = target_size; 
    int number_of_digits;
    char intermediate_buffer[20]; 
    char symbol_buffer[20];
    for(i = 0; i < target_size && remaining_loops > 0; i++, remaining_loops--)
    {
        //Create the string of the char that will be concatenated to the result:
        number_of_digits = num_of_digits(target[i]);


        n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "%%%ds",  number_of_digits + 4);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        if(remaining_loops == 1)
        {
            n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "%s",  "* ");
        }
        else if(ascending_order)
        {
            if(target[i] <= target[i + 1])
            {
                n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "<= ");
            }
            else
            {
                remaining_loops = 2;
                n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "> ");
            }
        }
        else /*Descending order*/
        {
            if(target[i] >= target[i + 1])
            {
                n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], ">= ");
            }
            else
            {
                remaining_loops = 2;
                n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "< ");
            }
        }

        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        n = snprintf(formatted_symbol_buffer, sizeof formatted_symbol_buffer / sizeof formatted_symbol_buffer[0], intermediate_buffer,  symbol_buffer);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        //Check if there is enough space:
        if(buffer_chars_used + n >= current_buffer_size)
        {
            //Allocate more memory:
            current_buffer_size = buffer_chars_used;
            current_buffer_size *= 2;
            result = realloc(result, sizeof *result * current_buffer_size);
            if(!result)
            {
                fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
                exit(EXIT_FAILURE);
            }
        }

        //Add the next number to the result:
        strcat(result, formatted_symbol_buffer);
        buffer_chars_used += n;
    }    

    //------------------------------------------------------------------------------
    //Return the result:
    return result;

    //------------------------------------------------------------------------------
}


static char *unsigned_integerArray_sorted_result_generate_str(unsigned_integer target[], size_t target_size, bool ascending_order)
/**
 * Description: This function generates a string that makes it easier to see that 
 * the 'target' array is sorted in ascending_order if 'ascending_order' is 
 * true and in descending_order otherwise. It generates symbols that are aligned 
 * with the current element from target and indicates if this element is <=, 
 * >= than the next element. The last element that is checked with a '*' symbol.
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex1: 
 * The array [ 1, 3, 4, 4, 5] is sorted in ascending order. The string
 * that will be generated by this function in this case is:
 * target: [   1,   3,   4,   4,   5]
 *            <=   <=   <=   <=    *
 *
 * Ex2:
 * The array [ 1, 0, 0, 0] is sorted in descending order. The string 
 * generated by this function is:
 * target: [   1,   0,   0,   0]
 *            >=   >=   >=    *
 *
 * Inputs: (unsigned_integer[]) target --> The array that is sorted. 
 *         (size_t) target_size --> The size of the array 'target'.
 *         (bool) ascending_order --> If true, means that the target array
 *         should be sorted in ascending order, but is not. Otherwise, it means
 *         that the array 'target' should be sorted in descending order but
 *         it is not.
 *
 * Output: (char *) --> The string generated in order to make it easier to 
 *         see that the array is sorted.
 *
 *
 * Time Complexity: O(n^2) --> This function uses strcat in 
 * a inefficient way.
 */
{
    //------------------------------------------------------------------------------
    //Declare local varibles:
    char *result;
    char formatted_symbol_buffer[50];
    size_t current_buffer_size = 100, buffer_chars_used = 0;


    //------------------------------------------------------------------------------
    //Allocate memory for the buffer:
    result = calloc(current_buffer_size, sizeof *result);
    if(!result)
    {
        fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
        exit(EXIT_FAILURE);
    }
    
    //------------------------------------------------------------------------------
    //Initialize the buffer:
    strcat(result, " ");
    buffer_chars_used += 2; //' ' + '\0'

    //------------------------------------------------------------------------------
    //Fill the buffer with the arr1 elements:

    size_t i, n, remaining_loops = target_size; 
    int number_of_digits;
    char intermediate_buffer[20]; 
    char symbol_buffer[20];
    for(i = 0; i < target_size && remaining_loops > 0; i++, remaining_loops--)
    {
        //Create the string of the char that will be concatenated to the result:
        number_of_digits = num_of_digits(target[i]);


        n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "%%%ds",  number_of_digits + 4);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array.\n");
            exit(EXIT_FAILURE);
        }

        if(remaining_loops == 1)
        {
            n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "%s",  "* ");
        }
        else if(ascending_order)
        {
            if(target[i] <= target[i + 1])
            {
                n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], "<= ");
            }
            else
            {
                fprintf(stderr, "\nERROR The target array is not sorted in ascending order.\n");
                exit(EXIT_FAILURE);
            }
        }
        else /*Descending order*/
        {
            if(target[i] >= target[i + 1])
            {
                n = snprintf(symbol_buffer, sizeof symbol_buffer / sizeof symbol_buffer[0], ">= ");
            }
            else
            {
                fprintf(stderr, "\nERROR The target array is not sorted in descending order.\n");
                exit(EXIT_FAILURE);
            }
        }

        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        n = snprintf(formatted_symbol_buffer, sizeof formatted_symbol_buffer / sizeof formatted_symbol_buffer[0], intermediate_buffer,  symbol_buffer);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        //Check if there is enough space:
        if(buffer_chars_used + n >= current_buffer_size)
        {
            //Allocate more memory:
            current_buffer_size = buffer_chars_used;
            current_buffer_size *= 2;
            result = realloc(result, sizeof *result * current_buffer_size);
            if(!result)
            {
                fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
                exit(EXIT_FAILURE);
            }
        }

        //Add the next number to the result:
        strcat(result, formatted_symbol_buffer);
        buffer_chars_used += n;
    }    

    //------------------------------------------------------------------------------
    //Return the result:
    return result;

    //------------------------------------------------------------------------------
}

static int num_of_digits(unsigned_integer number)
{
    int result = 1; //Already count the first digit.

    //While the number has at least 2 digits:
    while(number >= 10)
    {
        number = number/10;
        result++;
    }

    return result;
}

static void size_tArray_to_array_of_sizes(size_t arr[], size_t arr_size, size_t *array_of_sizes[], size_t offset)
/**
 * Description: This function allocates memory to and fills each element '*array_of_sizes[i]' with the 
 * number of digits of the number 'arr[i]' + offset, for i ranging from 0 to arr_size - 1.
 *
 * Input: The size of the array 'array_of_sizes' must be equal to 'arr_size' + 1 and the last element
 * will be filled with NULL value.
 */
{
    size_t i = 0;
    for(; i < arr_size; i++)
    {
        array_of_sizes[i] = malloc(sizeof *array_of_sizes[i]);
        if(array_of_sizes[i] == NULL) 
        {
            fprintf(stderr, "Error while allocating memory. Line: %d", __LINE__);
            exit(EXIT_FAILURE);
        }
        *array_of_sizes[i] = (size_t) num_of_digits(arr[i]) + offset;
    }
    array_of_sizes[i] = NULL;
}
 
static void unsigned_integerArray_to_array_of_sizes(unsigned_integer arr[], size_t arr_size, size_t *array_of_sizes[], size_t offset)
/**
 * Description: This function allocates memory to and fills each element '*array_of_sizes[i]' with the 
 * number of digits of the number 'arr[i]' + offset, for i ranging from 0 to arr_size - 1.
 *
 * Input: The size of the array 'array_of_sizes' must be equal to 'arr_size' + 1 and the last element
 * will be filled with NULL value.
 */
{
    size_t i = 0;
    for(; i < arr_size; i++)
    {
        array_of_sizes[i] = malloc(sizeof *array_of_sizes[i]);
        if(array_of_sizes[i] == NULL) 
        {
            fprintf(stderr, "Error while allocating memory. Line: %d", __LINE__);
            exit(EXIT_FAILURE);
        }
        *array_of_sizes[i] = (size_t) num_of_digits(arr[i]) + offset;
    }
    array_of_sizes[i] = NULL;
}

static void free_size_t_pointer_list(size_t *array_of_sizes[])
/**
 * Input: array_of_sizes is an array of previouslly allocated (size_t *) elements
 * with the last element equals to NULL.
 */
{
    size_t i = 0;
    while(array_of_sizes[i] != NULL) free(array_of_sizes[i++]);
}


static char *unsigned_integerArray_to_str(unsigned_integer target_array[], size_t target_array_size, size_t array_of_size_reference[]) 
/**
 * Description: This function generates the string of the array 'target_array' 
 * of unsigned_integers with size 'target_array_size'. The string is 
 * generated in such a way that each i-th element will have a total size given 
 * by array_of_size_reference[i].  
 *
 * Input: the size of array_of_size_reference must be greater or equal than 'target_array_size'.
 * Otherwise, behaviour is undefined.
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex:
 * --> target_array:            [ 12, 34, 5, 123]
 * --> array_of_size_reference: [ 3, 4, 5, 4, 3, 4, 1, 1]
 * --> result:                  [    12,     34,       5,   123]
 *                                  ***    ****    *****    ***
 *
 * Output: (char *) --> The formatted string.
 *
 * Time Complexity: O(n^2) --> This function uses strcat inefficiently.
 */
{
    //------------------------------------------------------------------------------
    //Declare local varibles:
    char *result;
    char number_buffer[50];
    size_t current_buffer_size = 100, buffer_chars_used = 0;


    //------------------------------------------------------------------------------
    //Allocate memory for the buffer:
    result = calloc(current_buffer_size, sizeof *result);
    if(!result)
    {
        fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
        exit(EXIT_FAILURE);
    }
    
    //------------------------------------------------------------------------------
    //Initialize the buffer:
    strcat(result, "[");
    buffer_chars_used += 2; //'[' + '\0'

    //------------------------------------------------------------------------------
    //Fill the buffer with the target_array elements:

    size_t i, n; 
    int number_of_digits;
    char intermediate_buffer[20];
    for(i = 0; i < target_array_size; i++)
    {
        //Create the string of the number that will be concatenated to the result:
        number_of_digits = (int) array_of_size_reference[i];

        n = snprintf(intermediate_buffer, sizeof intermediate_buffer / sizeof intermediate_buffer[0], "   %%%dllu,",  number_of_digits);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        n = snprintf(number_buffer, sizeof number_buffer / sizeof number_buffer[0], intermediate_buffer,  target_array[i]);
        if(n < 0)
        {
            fprintf(stderr, "\nERROR while generating the string of array in function unsigned_integerArray_generate_aligned_str.\n");
            exit(EXIT_FAILURE);
        }

        //Check if there is enough space:
        if(buffer_chars_used + n >= current_buffer_size)
        {
            //Allocate more memory:
            current_buffer_size = buffer_chars_used;
            current_buffer_size *= 2;
            result = realloc(result, sizeof *result * current_buffer_size);
            if(!result)
            {
                fprintf(stderr, "\nERROR while allocating memory in function unsigned_integerArray_generate_aligned_str.\n");
                exit(EXIT_FAILURE);
            }
        }

        //Add the next number to the result:
        strcat(result, number_buffer);
        buffer_chars_used += n;
    }    

    //------------------------------------------------------------------------------
    //Add ']' in the end:
    result[buffer_chars_used - 2] = ']';

    //------------------------------------------------------------------------------
    //Return the result:
    return result;

    //------------------------------------------------------------------------------

}

static char *size_tArray_to_index_str(size_t index_array[], size_t index_array_size, size_t array_of_size_reference[], size_t max_limit) 
/**
 * Description: This function generates the string of the array 'index_array' 
 * of size_ts with size 'index_array_size'. The string is 
 * generated in such a way that each i-th element will have a total size given 
 * by array_of_size_reference[i] - 1 (ignoring the '(' char). If index_array[i] >= max_limit,
 * "(*)" will be printed instead of the number index_array[i]. 
 *
 * Input: the size of array_of_size_reference must be greater or equal than 'index_array_size'.
 * Otherwise, behaviour is undefined.
 *
 * WARNING: The user must call free for the result returned by this function
 * after using it.
 *
 * Ex:
 * --> index_array:            [ 12, 34, 5, 123]
 * --> array_of_size_reference: [ 3, 4, 5, 4, 4, 4, 1, 1]
 * --> result:                      (12)    (34)      (5)   (123)
 *                                  ***    ****    *****    ****
 *
 * Output: (char *) --> The formatted string.
 *
 * Time Complexity: O(n^2) --> This function uses strcat inefficiently.
 */
{
    //------------------------------------------------------------------------------
    //Declare local varibles:
    char *result;
    char number_buffer[50];
    size_t current_buffer_size = 100, buffer_chars_used = 0;


    //------------------------------------------------------------------------------
    //Allocate memory for the buffer:
    result = calloc(current_buffer_size, sizeof *result);
    if(!result)
    {
        fprintf(stderr, "\nERROR while allocating memory in function size_tArray_to_index_str.\n");
        exit(EXIT_FAILURE);
    }
    
    //------------------------------------------------------------------------------
    //Initialize the buffer:
    strcat(result, " ");
    buffer_chars_used += 2; //' ' + '\0'

    //------------------------------------------------------------------------------
    //Fill the buffer with the index_array elements:

    size_t i, n; 
    int number_of_digits;
    char intermediate_buffer1[20];
    char intermediate_buffer2[20];
    for(i = 0; i < index_array_size; i++)
    {
        //Create the string of the number that will be concatenated to the result:
        number_of_digits = (int) array_of_size_reference[i];

        if(index_array[i] < max_limit)
        {
            n = snprintf(intermediate_buffer1, sizeof intermediate_buffer1 / sizeof intermediate_buffer1[0], "(%llu",  index_array[i]);
            if(n < 0)
            {
                fprintf(stderr, "\nERROR while generating the string of array in function size_tArray_to_index_str.\n");
                exit(EXIT_FAILURE);
            }

            n = snprintf(intermediate_buffer2, sizeof intermediate_buffer2 / sizeof intermediate_buffer2[0], "   %%%ds)",  number_of_digits);
            if(n < 0)
            {
                fprintf(stderr, "\nERROR while generating the string of array in function size_tArray_to_index_str.\n");
                exit(EXIT_FAILURE);
            }
            n = snprintf(number_buffer, sizeof number_buffer / sizeof number_buffer[0], intermediate_buffer2, intermediate_buffer1);
            if(n < 0)
            {
                fprintf(stderr, "\nERROR while generating the string of array in function size_tArray_to_index_str.\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            n = snprintf(intermediate_buffer2, sizeof intermediate_buffer2 / sizeof intermediate_buffer2[0], "   %%%ds)",  number_of_digits);
            if(n < 0)
            {
                fprintf(stderr, "\nERROR while generating the string of array in function size_tArray_to_index_str.\n");
                exit(EXIT_FAILURE);
            }
            n = snprintf(number_buffer, sizeof number_buffer / sizeof number_buffer[0], intermediate_buffer2, "(*");
            if(n < 0)
            {
                fprintf(stderr, "\nERROR while generating the string of array in function size_tArray_to_index_str.\n");
                exit(EXIT_FAILURE);
            }
        }

        //Check if there is enough space:
        if(buffer_chars_used + n >= current_buffer_size)
        {
            //Allocate more memory:
            current_buffer_size = buffer_chars_used;
            current_buffer_size *= 2;
            result = realloc(result, sizeof *result * current_buffer_size);
            if(!result)
            {
                fprintf(stderr, "\nERROR while allocating memory in function size_tArray_to_index_str.\n");
                exit(EXIT_FAILURE);
            }
        }

        //Add the next number to the result:
        strcat(result, number_buffer);
        buffer_chars_used += n;
    }    


    //------------------------------------------------------------------------------
    //Return the result:
    return result;

    //------------------------------------------------------------------------------

}

static T_element unsigned_integer_to_T_element(unsigned_integer n)
{
    return (T_element){{.u_i = n}, UNSIGNED_INTEGER};
}


static T_array *unsigned_integerArray_to_T_array(unsigned_integer arr[], size_t arr_size)
{
    size_t i = 0;
    T_array *result_array = NULL;
    T_element tmp;

    result_array = A_create_array();

    for (; i < arr_size; i++)
    {
        tmp = unsigned_integer_to_T_element(arr[i]);
        A_append_element(tmp, result_array);
    }

    return result_array;
}


static bool is_special_char(char c)
/**
 * A special character is any character in the set {'\t', '\n', '\b', '\v', '\r'}.
 */
{
    return c == '\t' || c == '\n' || c == '\b' || c == '\v' || c == '\r';
}

static bool check_for_special_char(char str[])
/**
 * Description: This function returns true if the string 'str' has any special
 * char and returns false otherwise. A string is a char array teminated with '\0' and a 
 * special character is any character that returns true if passed to the function
 * 'is_special_char'.
 *
 * Input: (char []) str --> It is a char array terminated with '\0', otherwise,
 * the behavior is undefined.
 */
{
    size_t i = 0;
    for(; i < strlen(str); i++)
    {
        if(is_special_char(str[i])) return true;
    }
    return false;
} 

static char *string_to_one_line_formatted_string(char unformatted_str[])
/**
 * Description: This function creates a new string with each char having a total 
 * width of 2 in order to support printing the string with special chars in only 
 * one line. 
 *
 * Memory issues: After using the returned string, it is necessary to free it.
 *
 * Error handling: If an error occurs, this function prints an error message and
 * exits a failure code.
 */
{
    size_t i, strlength = strlen(unformatted_str);
    char *resultant_string;
    resultant_string = calloc(2 * strlength + 1, sizeof *resultant_string);
    if(resultant_string == NULL)
    {
        fprintf(stderr, "Error (string_to_one_line_formatted_string at line %d): memory allocation was not possible.\n", __LINE__);
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < strlength; i++)
    {
        switch (unformatted_str[i])
        {
            case '\t':
                resultant_string[2 * i] = '\\';
                resultant_string[2 * i + 1] = 't';
                break;
            case '\n':
                resultant_string[2 * i] = '\\';
                resultant_string[2 * i + 1] = 'n';
                break;
            case '\b':
                resultant_string[2 * i] = '\\';
                resultant_string[2 * i + 1] = 'b';
                break;
            case '\v':
                resultant_string[2 * i] = '\\';
                resultant_string[2 * i + 1] = 'v';
                break;
            case '\r':
                resultant_string[2 * i] = '\\';
                resultant_string[2 * i + 1] = 'r';
                break;
            default:
                resultant_string[2 * i] = ' ';
                resultant_string[2 * i + 1] = unformatted_str[i];
                break;
            
        }
    }
    resultant_string[2 * strlength] = '\0';

    return resultant_string;
}


static char *target_reference_chars_comparison_to_string(char target[], char reference[], bool ignore_case, char equality_char, char difference_char, size_t std_char_width)
/**
 * Description: This function compares target string with reference string, 
 * creating and returning a formatted string with 'equality_char' for each
 * correspondence (target[i] == reference[i]) and 'difference_char' otherwise.
 * Each char of the comparinson string will have a total width of 'std_char_width'
 * and will be alligned to the right (>).
 *
 * Example: target = "abc\nd", reference = "abcdef", ignore_case = true, equality_char = ' ',
 * difference_char = ':', and std_char_width = 3.
 * The result is: 
 * formatted(target):    "  a  B  c \n  d"
 * comparison_string:    "           :  :  :"
 * formatted(reference): "  a  b  c  d  e  f"
 * Input: std_char_width must be greater than 0.
 *
 * Memory Issues: After using the returned pointer, the user must free it.
 *
 * Error handling: If an error occurs, this function prints an error message and
 * exits a failure code.
 *
 */
{
    size_t target_len = strlen(target);
    size_t reference_len = strlen(reference);
    size_t min_len = (target_len <= reference_len)?target_len:reference_len;
    size_t max_len = (target_len >= reference_len)?target_len:reference_len;
    size_t i, j;
    size_t init_index, final_index;
    char *comparison_string;
    char reference_char, target_char;

    if(std_char_width < 1) 
    {
        fprintf(stderr, "Error (target_reference_chars_comparison_to_string line %d): std_char_width must be greater than 0.\n", __LINE__);
        exit(EXIT_FAILURE);
    }

    comparison_string = calloc(max_len * std_char_width + 1, sizeof *comparison_string);
    if(comparison_string == NULL)
    {
        fprintf(stderr, "Error (target_reference_chars_comparison_to_string line %d): memory allocation was not possible.\n", __LINE__);
        exit(EXIT_FAILURE);
    }



    for(i = 0; i < min_len; i++)
    {
        init_index = i * std_char_width;
        final_index = init_index + std_char_width - 1; 
        for(j = init_index; j < final_index; j++) comparison_string[j] = ' ';

        if(ignore_case) 
        {
            reference_char = tolower(reference[i]);
            target_char = tolower(target[i]);
        }
        else
        {
            reference_char = reference[i];
            target_char = target[i];
        }
        
        if(target_char == reference_char) comparison_string[final_index] = equality_char;
        else comparison_string[final_index] = difference_char;
    }
    for(; i < max_len; i++)
    {
        init_index = i * std_char_width;
        final_index = init_index + std_char_width - 1; 
        for(j = init_index; j < final_index; j++) comparison_string[j] = ' ';

        comparison_string[final_index] = difference_char;
    }
    comparison_string[max_len * std_char_width] = '\0';

    return comparison_string;
}




//------------------------------------------------------------------------------
