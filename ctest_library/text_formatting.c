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

//Auxilliary functions:
int is_white_space(char s)
{
	return (s == ' ' || s == '\t' || s == '\n');
}

//Function definitions:
char **break_line(char text[], size_t max_text_length, char first_prefix[], char prefix[], char suffix[], size_t line_length)
/**
 * Description: This function receives a text as input and formats this text 
 * breaking each line in such a way that each line has exaclty the length equals 
 * to 'line_length'. If the length of any line is greater than the 'line_length', 
 * NULL is returned. After formatting the text, a new array of strings is 
 * returned. Each element of this array is a line formatted. The last element of 
 * the array of strings that will be returned will be NULL.
 * 	It is possible to specify the suffix and prefix of each line. Other than 
 * that, the prefix of the first line can be specified separately and if this is 
 * NULL, it will be equals to 'prefix' by default. 
 * 	Each line is not ended by '\n'. Behavior is not defined when '\n' is 
 * used in 'prefix' or 'suffix'. When '\n' is used in 'text', it will be ignored 
 * during the process of formatting. 
 * 	The words will not be broken in syllables.
 * 	After using the array of strings returned by this function, it is necessary
 * to call free for each element and for the array itself.
 * 	If prefix/suffix is NULL, the default value (empty string) will be used. 
 *
 * Input: (char []) text --> The text that will be formatted.
 *        (size_t) max_text_length --> The maximum length of the text that will be read 
 *        from the string 'text'. Any char is counted, even white space.
 *        (char []) first_prefix --> The prefix of the first line of the 
 *        formatted text. If NULL, prefix will be used instead.
 *        (char []) prefix --> The prefix of each formatted line.
 *        (char []) suffix --> The suffix of each formatted line.
 *        (size_t) line_length --> The length of each formatted line (including 
 *        the prefix and the suffix).
 *
 * Output: (char **) --> Array of strings. Each element of that array is a 
 *         formatted line.
 *
 * Time Complexity: O(text_length)
 *
 * Space Complexity: O(text_length)
 */
{
	//Variables:
	word  *my_words;
	my_words = get_words(text, max_text_length);

	//Debug:
	int i = 0;
	for (; my_words[i].string != NULL; i++)
		printf("Word: %s (sz: %d)\n", my_words[i].string, my_words[i].length);
}


word *get_words(char text[], size_t max_chars)
/**
 * Description: This function reads each word from text and returns an array with 
 * each word as an element. After using the result, it is necessary to call free 
 * for each string of each element of the array and for the array itself. The last
 * element is the NULL string. Its length is 0.
 *
 * Input: (char []) text --> text with the words that will be read.
 *        (size_t) max_chars --> The maximum number of chars that will be read.
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


