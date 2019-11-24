#pragma once
typedef struct slist_entry* pslist_entry;
typedef struct slist* pslist;


typedef struct slist_entry
{
	pslist_entry next;
	int value;
} list;


struct slist
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

    pslist our_list;
    our_list = &work_list;
    our_list->head = LISTOK;
    our_list->list_size = elements;
    return our_list;
};

/*
 * TODO
 */
int slist_insert(pslist listok, int value) {
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

//int slist_remove(pslist listok, int value) {};

void slist_print(pslist listok) {
    //printf("%p\n", listok);
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
    //free(listok->list_size);
    list* temp_address_1;
    list* temp_address_2;
    temp_address_1 = listok->head;
    for (int i = 0; i < weight; ++i) {
        temp_address_2 = temp_address_1->next;
        temp_address_1 = temp_address_2;
    }
    free(listok);

};
