/**
 * Author: Artur Assis Alves
 * Date: 31/05/2021
 * Title: TEXT FORMATTING
 */

/**
 * Description: This file contains functions used to format strings.
 */


//Includes:
#include "text_formatting.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Auxilliary functions:
int is_white_space(char s)
{
    return (s == ' ' || s == '\t' || s == '\n');
}

//Function definitions:
char *break_line(char text[], size_t max_text_length, char first_prefix[], char prefix[], char suffix[], size_t line_length)
/**
 * Description: This function receives a text as input and formats this text 
 * breaking each line in such a way that each line has exaclty the length equals 
 * to 'line_length'. If the length of any line is greater than the 'line_length', 
 * NULL is returned. After formatting the text, a new string with the formatted lines is 
 * returned. 
 *     It is possible to specify the suffix and prefix of each line. Other than 
 * that, the prefix of the first line can be specified separately and if this is 
 * NULL, it will be equals to 'prefix' by default. 
 * '    'Each line is not ended by '\n'. Behavior is not defined when '\n' is 
 * used in 'prefix' or 'suffix'. When '\n' is used in 'text', it will be ignored 
 * during the process of formatting. 
 *     The words will not be broken in syllables.
 *     After using the array of strings returned by this function, it is necessary
 * to call free for each element and for the array itself.
 *     If prefix/suffix is NULL, the default value (empty string) will be used. 
 *
 * Memory allocation: The user must free the (char *) output after using it.
 *
 * Input: (char []) text --> The text that will be formatted. If it does not 
 *        have any word, NULL is returned.
 *        (size_t) max_text_length --> The maximum length of the text that will be read 
 *        from the string 'text'. Any char is counted, even white space.
 *        (char []) first_prefix --> The prefix of the first line of the 
 *        formatted text. If NULL, prefix will be used instead.
 *        (char []) prefix --> The prefix of each formatted line.
 *        (char []) suffix --> The suffix of each formatted line.
 *        (size_t) line_length --> The length of each formatted line (including 
 *        the prefix and the suffix).
 *
 * Output: (char *) --> String with each line properly formatted.
 *
 * Time Complexity: O(text_length^2) 
 *     --> Squared complexity is not a problem considering the text_length is not too large.
 *     If it is necessary to makes this function faster, optimize the concatenation of the 
 *     final result.
 *
 * Space Complexity: O(text_length)
 */
{
    //Variables:
    word  *my_words;
    size_t current_line_length, word_index, white_spaces_to_add, num_of_words;
    char *formatted_lines;


    //Get the words from text:
    my_words = get_words(text, max_text_length, &num_of_words);

    //Check for empty text:
    if (my_words[0].string == NULL) return NULL;

    //Check for default values:
    if(prefix == NULL) prefix = "";

    if(suffix == NULL) suffix = "";

    if (first_prefix == NULL) first_prefix = prefix;

    //Check for impossible conditions:
    if (strlen(prefix) + strlen(suffix) >= line_length)
    {
        fprintf(stderr, "The sum of prefix and suffix' lengths is greater than the line lenght.");
        exit(EXIT_FAILURE);
    }    
    
    //Allocate memory for the result:
    formatted_lines = calloc(line_length * num_of_words, sizeof *formatted_lines); //Worst case: one word per line
    

    /*Format the first line*/
    word_index = 0;
    
    //Add the prefix:
    strcat(formatted_lines, first_prefix);
    current_line_length = strlen(first_prefix) + strlen(suffix); //Suffix will be added at the end
    while(current_line_length < line_length)
    {
        if(my_words[word_index].string == NULL || my_words[word_index].length + current_line_length > line_length) //Can not add a new word
        {
            //Add remaining white spaces:
            white_spaces_to_add = line_length - current_line_length; 
            

            while(white_spaces_to_add-- > 0)
                strcat(formatted_lines, " ");

            //Update the current line length:
            current_line_length = line_length;

        }else //It is possible to add a new word
        {
            //Add the new word:
            strcat(formatted_lines, my_words[word_index].string);

            //Update current line length:
            current_line_length += my_words[word_index++].length;

            //Add a whitespace:
            if (current_line_length < line_length) 
            {
                strcat(formatted_lines, " ");
                current_line_length++;
            }
        }
    }

    //Finish the first line:
    strcat(formatted_lines, suffix);
    strcat(formatted_lines, "\n");
    

    /*Format the remaining lines*/

    while(my_words[word_index].string != NULL)
    {
        //Add the prefix:
        strcat(formatted_lines, prefix);
        current_line_length = strlen(prefix) + strlen(suffix); //Suffix will be added at the end

        //Check if the next word is impossible to add:
        if ((my_words[word_index].length == line_length && strlen(prefix) + strlen(suffix) > 0) || my_words[word_index].length > line_length)
        {
            fprintf(stderr, "Too large word to be formatted.");
            exit(EXIT_FAILURE);
        }

        //Add the next line:
        while(current_line_length < line_length)
        {
            if(my_words[word_index].string == NULL || my_words[word_index].length + current_line_length > line_length) //Can not add a new word
            {
                //Add remaining white spaces:
                white_spaces_to_add = line_length - current_line_length; 
                

                while(white_spaces_to_add-- > 0)
                    strcat(formatted_lines, " ");

                //Update the current line length:
                current_line_length = line_length;

            }else //It is possible to add a new word
            {
                //Add the new word:
                strcat(formatted_lines, my_words[word_index].string);

                //Update current line length:
                current_line_length += my_words[word_index++].length;

                //Add a whitespace:
                if (current_line_length < line_length) 
                {
                    strcat(formatted_lines, " ");
                    current_line_length++;
                }
            }
        }

    //Finish the first line:
    strcat(formatted_lines, suffix);
    strcat(formatted_lines, "\n");

    }

    //Free my_words:
    word_index = 0;
    while (my_words[word_index].string != NULL)
        free(my_words[word_index++].string);
    free(my_words);
    
    

    return formatted_lines;
}


word *get_words(char text[], size_t max_chars, size_t *num_of_words_read)
/**
 * Description: This function reads each word from text and returns an array with 
 * each word as an element. After using the result, it is necessary to call free 
 * for each string of each element of the array and for the array itself. The last
 * element is the NULL string. Its length is 0.
 *     This function changes the value of the pointer 'num_of_words_read' to the
 * number of words that have been read.
 *
 * Memory allocation: The user must free the (word *) output after using it. Each
 * string of each element must be freed.
 *
 * Input: (char []) text --> text with the words that will be read.
 *        (size_t) max_chars --> The maximum number of chars that will be read.
 *        (site_t *) num_of_words_read --> The number of words that was read.
 *
 * Output: (word *) --> Array of words.
 */
{
    word *result_words;
    size_t i, num_of_words, init, end, word_index, word_length; //Each word starts at 'init' and ends at 'end' - 1
    char state;

    //Count the number of words:
    i = 0;
    num_of_words = 0;
    state = 0;
    /* Finite state machine:
     *  Recognize each word. Each word is a set of adjacents non-whitespace 
     *  chars.
     * States 0, 1, and 2.
     */
    while(state != 2)
    {
        switch(state)
        {
            case 0: //Reading white spaces
                if(is_white_space(text[i])) i++;
                else if (text[i] == '\0') state = 2;
                //Start reading a new word:
                else
                {
                    init = i++;
                    state = 1;
                }

                //Check for i >= max_chars:
                if (i >= max_chars) state = 2;
                break;
            case 1: //Reading a word
                if(!is_white_space(text[i]) && text[i] != '\0') 
                {
                    i++;
                    //Check for i >= max_chars:
                    if(i >= max_chars) 
                    {
                        num_of_words++; //Truncate the last word
                        state = 2;
                    }
                }
                //Finish reading the word:
                else if (text[i] == '\0') 
                {
                    end = i;
                    num_of_words++;
                    state = 2;
                }
                else
                {
                    end = i++;
                    num_of_words++;
                    state = 0;
                    //Check for i >= max_chars:
                    if (i >= max_chars) state = 2;
                }


                break;
            case 2:
                break;
        }
    }
    //Allocate the array of words and set the last element:
    result_words = calloc(num_of_words + 1, sizeof *result_words);
    if(result_words == NULL)
    {
        fprintf(stderr, "Error during memory allocation.");
        exit(EXIT_FAILURE);
    }
    result_words[num_of_words].string = NULL;
    result_words[num_of_words].length = 0;

    //Update the number of words read:
    *num_of_words_read = num_of_words;
    
    //Copy each word to the result array:
    i = 0;
    word_index = 0;
    word_length = 0;
    state = 0;
    /* Finite state machine:
     *  Recognize each word. Each word is a set of adjacents non-whitespace 
     *  chars.
     * States 0, 1, and 2.
     */
    while(state != 2)
    {
        switch(state)
        {
            case 0: //Reading white spaces
                if(is_white_space(text[i])) i++;
                else if (text[i] == '\0') state = 2;
                //Start reading a new word:
                else
                {
                    init = i++;
                    state = 1;
                }

                //Check for i >= max_chars:
                if (i >= max_chars) state = 2;
                break;
            case 1: //Reading a word
                if(!is_white_space(text[i]) && text[i] != '\0') 
                {
                    i++;
                    //Check for i >= max_chars:
                    if(i >= max_chars) 
                    {
                        state = 2;
                        end = i;
                        
                        //Allocate the space for the string:
                        word_length = end - init;
                        result_words[word_index].string = calloc(word_length + 1, sizeof (char));
                        if(result_words[word_index].string == NULL)
                        {
                            fprintf(stderr, "Error during memory allocation.");
                            exit(EXIT_FAILURE);
                        }
                        result_words[word_index].string[word_length] = '\0';
                        result_words[word_index].length = word_length;

                        //Copy the word to the result_words:
                        while(word_length > 0)
                            result_words[word_index].string[--word_length] = text[--end];

                        //Update word_index:
                        word_index++;
                    }
                }
                //Finish reading the word:
                else 
                {
                    if (text[i] == '\0') 
                    {
                        end = i;
                        state = 2;
                    }
                    else
                    {
                        end = i++;
                        state = 0;
                        //Check for i >= max_chars:
                        if (i >= max_chars) state = 2;
                    }

                    //Allocate the space for the string:
                    word_length = end - init;
                    result_words[word_index].string = calloc(word_length + 1, sizeof (char));
                    if(result_words[word_index].string == NULL)
                    {
                        fprintf(stderr, "Error during memory allocation.");
                        exit(EXIT_FAILURE);
                    }
                    result_words[word_index].string[word_length] = '\0';
                    result_words[word_index].length = word_length;

                    //Copy the word to the result_words:
                    while(word_length > 0)
                        result_words[word_index].string[--word_length] = text[--end];

                    //Update word_index:
                    word_index++;
                }
                    

                break;
            case 2:
                break;
        }
    }

    //Return the result:
    return result_words;
}


char *merge_str(char *str_arr[], char sep[], char end[])
/**
 * Description: This function returns all the strings from the array 'str_arr' 
 * merged. They are separated by the string 'sep' and finished by the string 
 * 'end'. 'str_arr' must be NULL terminated, otherwise the behavior is undefined. 
 *     The 'sep' and 'end' have default values equal to the empty string when they 
 * are NULL.
 *
 * Memory Allocation (!): After using this function, the caller must free the (char *)
 * returned.
 *
 * Input: (char *[]) str_arr --> Array of strings that will be merged.
 *        (char []) sep --> The separator string. 
 *        (char []) end --> The terminator string.
 *
 * Output: (char *) --> The resultant merged string.
 *
 * Time Complexity: O(total_chars_of(str_arr)^2)
 *     --> This function is not critical to the performance of the program, so it 
 *     will not be optimized.
 *
 * Space Complexity: O(total_chars_of(str_arr))
 */
{
    size_t total_chars, i, sep_size;
    char *merged_str;

    //Check for default values:
    if(sep == NULL) sep = "";
    if(end == NULL) end = "";
    
    

    //Count the number of chars of str_arr:
    i           = 0;
    total_chars = 0;
    sep_size = strlen(sep);
    while(str_arr[i] != NULL)
        total_chars += strlen(str_arr[i++]) + sep_size;
    total_chars += strlen(end) - sep_size;
    //Allocate memory for the result:
    merged_str = calloc(total_chars + 1, sizeof *merged_str);
    if(merged_str == NULL)
    {
        fprintf(stdout, "Problems during memory allocation.");
        exit(EXIT_FAILURE);
    }
    merged_str[0] = '\0';

    //Merge:
    i = 0;
    while(str_arr[i] != NULL)
    {
        strcat(merged_str, str_arr[i]);
        if(str_arr[++i] != NULL) //if true, sep is necessary
            strcat(merged_str, sep);
    }
    strcat(merged_str, end);
    
    //Return the result:
    return merged_str;
}

bool TF_generate_array_of_alligned_sizes(size_t ** input_list_of_lists_of_sizes[], size_t *result_list_of_alligned_sizes, char *error_msg, size_t min_width)
/**
 * Description: This function receives a list of lists of sizes. It creates a 
 * single array with the size of the greatest list of sizes from the input list 
 * of lists and with the size necessary for each element (each element is related 
 * to each index) to be alligned with the respective element with the same index 
 * from other lists. It returns true if the operation was successful and false 
 * otherwise. If false is returned, the error_msg is defined.
 * 
 * Input: (size_t ** []) input_list_of_lists_of_sizes -> NULL terminated list of 
 *                                                     lists of sizes. Each list 
 *                                                     of sizes is NULL terminated.
 *        (size_t *) result_list_of_alligned_sizes -> A pointer to size_t with value
 *                                                    equals NULL. The result will
 *                                                    be allocated using that pointer
 *                                                    and consists of an array with
 *                                                    the greatest sizes from the 
 *                                                    input lists or the 'min_width'.
 *                                                    It has the size of the greatest
 *                                                    list of sizes from the input.
 *        (char *) error_msg -> Pointer to char. Its value must be NULL.
 *        (size_t) min_width -> The minimun size for each element that will be returned
 *                              as the result.
 *
 * Error Handling: This function returns false if an error happens and true otherwise.
 * If an error happens, the error message is stored into the variable 'error_msg',
 * and 'result_list_of_alligned_sizes' is not changed.
 *
 * Memory Allocation issues: If the function returns true, the result will be stored
 * into 'result_list_of_alligned_sizes'. It is necessary to call the function free 
 * for the result_list_of_alligned_sizes pointer.
 */
{
    bool result = false;
    size_t result_size, current_size;
    size_t i, j;

    //Check the inputs:
    if(input_list_of_lists_of_sizes == NULL) 
    {
        error_msg = "First input (list of lists of sizes) may not be NULL.";
        goto return_result;
    }

    if(result_list_of_alligned_sizes != NULL)
    {
        error_msg = "The pointer to store the result must have initially the value NULL.";
        goto return_result;
    }

    if(error_msg != NULL)
    {
        error_msg = "The pointer to store the error message must have initially the value NULL.";
        goto return_result;
    }

    //Get the size of the result:
    result_size = 0;
    i = 0;
    while(input_list_of_lists_of_sizes[i] != NULL)
    {
        j = 0;
        current_size = 0;
        while(input_list_of_lists_of_sizes[i][j] != NULL) j++;
        current_size = j;
        if (current_size > result_size) result_size = current_size;
        i++;
    }

    //Allocate memory for the result and initialize it:
    
    result_list_of_alligned_sizes = calloc(result_size, sizeof *result_list_of_alligned_sizes);
    if(result_size == 0) //avoid returning false if calloc returned NULL in the case result_size is 0.
    {
        result = true;
        goto return_result;
    }

    if(result_list_of_alligned_sizes == NULL)
    {
        error_msg = "Error while allocating memory for the result.";
        goto return_result;
    }

    for(i = 0; i < result_size; i++) result_list_of_alligned_sizes[i] = min_width;

    //Get the maximum size for each index:
    i = 0;
    while(input_list_of_lists_of_sizes[i] != NULL)
    {
        j = 0;
        while(input_list_of_lists_of_sizes[i][j] != NULL) 
        {
            //Check the index j:
            if(*input_list_of_lists_of_sizes[i][j] > result_list_of_alligned_sizes[j]) 
                result_list_of_alligned_sizes[j] = *input_list_of_lists_of_sizes[i][j];
            j++;
        }
        i++;
    }
    result = true;

return_result:
    return result;

}
