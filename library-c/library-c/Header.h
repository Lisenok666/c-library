/*
    This file header.h
    single linked list header
    Authora Daniil leskevich and  Oledg Nicolaev
    Created by NAMELESS TEAM
*/
#pragma once
#include"sl_list_library.c"

/*
 * Creates an empty list
 * Params: none
 * Returns pointer to the list
 */
pslist slist_new(void);

/*
 * Deletes list and all the elements
 * Params: list - pointer to the list
 * Returns none
 */
void slist_delete(pslist list);

/*
 * add to the stsrt of list element with value frim console
 * return 0
 */
int slist_insert(pslist list, int value);

/*
* write values values from list
* return none
*/

void slist_print(pslist list);
//

