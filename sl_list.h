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
};
pslist slist_new(list *LISTOK) {
    int elements;
    printf("How many alements of list you need\n");
    scanf("%d", &elements);
    LISTOK = (list*)malloc(elements * sizeof(list));
    for (int i = 0; i < elements; ++i)
    {
        int value = 0;
        printf("Write value\n");
        scanf("%d", value);
        LISTOK->value = value;
        LISTOK->next = NULL;
        list* temp_address = LISTOK;
    }
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
int slist_insert(pslist list, int value) {};

int slist_remove(pslist list, int value) {};

void slist_print(pslist list) {
};
