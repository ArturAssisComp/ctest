#ifndef TEXT_FORMATTING_H
#define TEXT_FORMATTING_H

//Include:
#include <stdlib.h>
#include <stdio.h>

//Structs:
typedef struct
{
	char *string;
	size_t length;
} word;


//Declaration of functions:
char **break_line(char text[], size_t text_length, char first_prefix[], char prefix[], char suffix[], size_t line_length);
word *get_words(char text[], size_t max_chars);
#endif
