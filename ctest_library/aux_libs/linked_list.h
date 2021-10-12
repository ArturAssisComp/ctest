#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//Libs:
#include <stdbool.h>
#include "types.h"


//Declaration of functions:

linked_list *create_linked_list(void);
void delete_linked_list(linked_list **ptr_to_target_linked_list);
linked_list_element *insert_item(dict_item item, linked_list *target_linked_list);
linked_list_element *get_and_delete_linked_list_element(element key, linked_list *target_linked_list);
linked_list_element *get_linked_list_element(element key, linked_list *target_linked_list);



#endif
