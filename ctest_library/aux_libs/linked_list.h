#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//Libs:
#include <stdbool.h>
#include "types.h"


//Declaration of functions:

linked_list *create_linked_list();
void delete_linked_list(linked_list **ptr_to_ptr_to_linked_list);
void insert_element(element *ptr_to_element, linked_list *ptr_to_linked_list);
element *get_and_delete_element(element *ptr_to_ref_element, linked_list *ptr_to_linked_list);
element *get_element(element *ptr_to_ref_element, linked_list *ptr_to_linked_list);



#endif
