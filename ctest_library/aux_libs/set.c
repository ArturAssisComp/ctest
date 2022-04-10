#include "types.h"
#include "set.h"
#include "array.h"
#include "dict.h"
#include <stdio.h>

T_set *S_create_set(T_hash_type table_size)
/**
 * Description: This function creates a T_set with a hash table of size 'table_size'.
 * It returns a pointer to the created set and must be deleted after using it. 
 * Call S_delete_set to delete the set.
 */
{
    T_set *created_set = NULL;
    char *error_msg = NULL;

    created_set = malloc(sizeof *created_set);
    if(!created_set) 
    {
        error_msg = "Problems while allocating memory for for T_set.\n";
        goto error;
    }
    created_set->dict = D_create_dict(table_size);

    return created_set;

error:
	fprintf(stderr, error_msg);
	exit(EXIT_FAILURE);
}

bool S_has_element(T_element element, T_set *target_set)
/**
 * Description: This function returns true if the set 'target_set' has the element
 * 'element'. Otherwise, it returns false.
 */
{
    if(D_get_value(element, target_set->dict)) return true;
    
    return false;
}

bool S_remove_element(T_element element, T_set *target_set)
/**
 * Description: This function tries to delete the T_element 'element' of 'target_set' 
 * if this T_element exists. If the elment exists and is deleted, it 
 * returns true. If the T_element does not exist, it returns false.
 */
{
    return D_delete_element(element, target_set->dict);
}

void S_add_element(T_element element, T_set *target_set)
/**
 * Description: This function adds the T_element 'element' into the 'target_set'.
 * If the element already exists, nothing happens.
 */
{
    D_assign_value_to_key(element, (T_element){.type=NULL_TYPE}, target_set->dict);
}

bool S_is_subset(T_set *set1, T_set *set2)
/**
 * Description: This function returns true if set1 is a subset of set2, and 
 * false otherwise.
 */
{
    T_array *arr1, *arr2;
    size_t i;
    T_element *tmp_element;

    arr1 = S_set_to_array(set1);
    for(i = 0; i < arr1->num_of_elements; i++)
    {
        tmp_element = A_get_element(i, arr1);
        if(!S_has_element(*tmp_element, set2)) return false;
    }
    return true;
}

bool S_is_equal(T_set *set1, T_set *set2)
/**
 * Description: This function returns true if set1 is equal to set2, and 
 * false otherwise.
 */
{
    if(S_is_subset(set1, set2) && S_is_subset(set2, set1)) return true;

    return false;
}

T_array *S_set_to_array(T_set *current_set)
/**
 * Description: This function returns an array with the elements of 'current_set'.
 * There is no specific order in which the elements will be organized in the array.
 * The user must delete the array after using by calling A_delete_array.
 */
{
    return D_dict_to_array(current_set->dict);
}

T_set *S_array_to_set(T_array *current_array)
/**
 * Description: This function creates a T_set using the elements from 'current_array' and returns the pointer to the set.
 */
{
    const int table_size_factor = 5;
    int i;
    T_element *tmp_element = NULL; 
    T_set *new_set = S_create_set(current_array->num_of_elements / table_size_factor + 1);

    for(i = 0; i < current_array->num_of_elements; i++)
    {
        tmp_element = A_get_element(i, current_array);
        S_add_element(*tmp_element, new_set);
    }

    return new_set;
}

void S_delete_set(T_set **ptr_to_set)
/**
 * Description: This function deletes a set pointed by 'ptr_to_set'. After that, 
 * it makes ptr_to_set points to NULL.
 */
{
    D_delete_dict(&((*ptr_to_set)->dict));
    free(*ptr_to_set);
    ptr_to_set = NULL;
}

