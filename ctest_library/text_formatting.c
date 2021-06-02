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
 * 	--> Squared complexity is not a problem considering the text_length is not too large.
 * 	If it is necessary to makes this function faster, optimize the concatenation of the 
 * 	final result.
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
 * 	This function changes the value of the pointer 'num_of_words_read' to the
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


