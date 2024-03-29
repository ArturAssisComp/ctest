#ifndef _CTEST_TEXT_FORMATTING_H
#define _CTEST_TEXT_FORMATTING_H

//Include:
#include <stdlib.h>
#include <stdbool.h>



//Structs:
typedef struct
{
    char *string;
    size_t length;
} word;


//Declaration of functions:
char *break_line(char text[], size_t max_text_length, char first_prefix[], char prefix[], char suffix[], size_t line_length);
word *get_words(char text[], size_t max_chars, size_t *num_of_words_read);
char *merge_str(char *str_arr[], char sep[], char end[]);
bool TF_generate_array_of_alligned_sizes(size_t ** input_list_of_lists_of_sizes[], size_t **result_list_of_alligned_sizes_address, char **error_msg, size_t min_width);
#endif



