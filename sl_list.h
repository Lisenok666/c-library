#pragma once
typedef struct slist_entry* pslist_entry;
typedef struct slist* pslist;


typedef struct slist_entry
{
	pslist_entry next;
	int value;
} list;


typedef struct slist
{
	int list_size; // sugar
	pslist_entry head;
} work_list;
pslist slist_new(void) {
    list* LISTOK;
    int elements = 0;
    printf("How many alements of list you need\n");
    scanf_s("%d", &elements);
    LISTOK = (list*)malloc(elements * sizeof(list));
    if (NULL == LISTOK)
    {
        printf("Not enough memmory\n");
        return -1;
    }
    int last_element = elements - 1;
    for (int i = 0; i < elements; ++i)
    {
        int value_list = 0;
        printf("Write value\n");
        scanf_s("%d", &value_list);
        (LISTOK[i]).value = value_list;
        if (i != last_element)
        {
            (LISTOK[i]).next = (LISTOK + i + 1);
        }
        else
        {
            (LISTOK[i]).next = NULL;
        }
    }
    work_list our_list;
    (&our_list)->head = LISTOK;
    (&our_list)->list_size = elements;
    return (&our_list);
};

/*
 * Deletes list and all the elements
 * Params: list - pointer to the list
 * Returns none
 */
void slist_delete(pslist list) {};

/*
 * TODO
 */
//int slist_insert(pslist list, int value) { };

//int slist_remove(pslist list, int value) {};

void slist_print(pslist work_list) {
};
