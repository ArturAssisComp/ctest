#ifndef TYPES_H
#define TYPES_H

//Include libs:
#include "..\globals\globals.h"
#include <stdbool.h>
#include <stdlib.h>

//Macro constants:

//Declaration of types:

/*Element*/
typedef enum 
{
	//Individual elements:
	UNSIGNED_INTEGER,
       	INTEGER,
        FLOATING_POINT,
        BOOL,
        CHAR,
        STRING,
	//Group elements:
	ARRAY, //Array of generic elements
	DICT,   //Dict of generic elements
        _NULL
} data_type;


struct element;
struct linked_list;
typedef size_t hash_type;

typedef struct element *array;
typedef struct 
{
        struct linked_list **table;
        hash_type table_size;
}dict;

typedef struct 
{
	union {
		unsigned_integer u_i;
		integer i;
		floating_point f_p;
		bool b;
		char c;
		char *str; //A string is considered an individual element. 
		array *arr;
		dict *dct;
	} value;
	data_type type;
} element;


/*Dict element*/
typedef struct 
{
	element key;
	element value;
	hash_type hash;
} dict_item; //Pair of a key associated with a value.

/*Linked list of dict elements*/
struct linked_list_element 
{
	dict_item item;
	struct linked_list_element *next_element;
};
typedef struct linked_list_element linked_list_element;

struct linked_list
{
	linked_list_element *head;
	size_t num_of_elements;

};
typedef struct linked_list linked_list;


//Function declarations:
bool is_equal(element e1, element e2);
void free_element(element e);


#endif
