/*
    This file sl_list.h
    single linked list header
    Author Leskecvich Daniil and Oleg Nicolaev
    Created by NAMELESS TEAM
*/
#pragma once
/*typedef struct slist_entry* pslist_entry;
typedef struct slist* pslist;
int k = 0;  //indefecate k = 1 when we have active list in our programm, k = 0 we haven't active list


typedef struct slist_entry
{
	pslist_entry next;
	int value;
} list;


typedef struct slist
{
	int list_size; 
	pslist_entry head;
} work_list;
*/
/*function create new list and return pointer to it*/

pslist slist_new(void) {
    if (k)
    {
        printf("You must delete previos list, before create new\n");
        return NULL;
    }
    work_list* our_list  = NULL;
    our_list = (work_list*) malloc(1 * sizeof(work_list));
    if (NULL == our_list)
    {
        return NULL;
    }
    our_list->head = NULL;
    our_list->list_size = 0;
    k++;
    return our_list;
};

/*
 * add to the stsrt of list element with value frim console
 * return 0
 */
int slist_insert(pslist listok, int value) {
    if (NULL == listok || k == 0)
    {
        printf("You must firstly create list\n");
        return -2;
    }
    int k = 0;
    list* temp_list = NULL;
    temp_list = (list*)malloc(1 * sizeof(list));
    if (NULL == temp_list)
    {
        printf("Not enough memmory\n");
        return -1;
    }
    temp_list->value = value;
    temp_list->next = listok->head;
    listok->head = temp_list;
    listok->list_size ++;
    return 0;
};

/*
* write values values from list
* return none
*/

void slist_print(pslist listok) {
    if (NULL == listok || 0 == k)
    {
        printf("You must firstly create list\n");
       // return -2;
    }
    int weight = listok->list_size;
    printf("Programm start write %d values\n", weight);
    list* temp_address;
    temp_address = listok->head;
    for (int i = 0; i < weight; ++i) {
        printf("Value of elemeny number %d = %d\n", i+1, temp_address->value);
        temp_address = temp_address->next;
    }
};
/*
 * Deletes list and all the elements
 * Params: list - pointer to the list
 * Returns none
 */
void slist_delete(pslist listok) {
    int weight = listok->list_size;
    pslist_entry temp_address_1 = NULL;
    pslist_entry temp_address_2 = NULL;
    temp_address_1 = listok->head;
    for (int i = 0; i < weight; ++i) {
        temp_address_2 = temp_address_1->next;
        free(temp_address_1);
        temp_address_1 = temp_address_2;
    }
    free(listok);
    k--;
};
