/*
	This file sl_list.h
	single linked list header
	Authora Daniil leskevich and  Oledg Nicolaev
	Created by NAMELESS TEAM 
*/
//Matbe some names and function would be changing in future
#pragma once

typedef struct slist_entry* pslist_entry;
typedef struct slist* pslist;

struct slist_entry
{
	pslist_entry next;
	int value;
} list;

struct slist
{
	int list_size; // sugar
	pslist_entry head;
};

pslist slist_new(void);

void slist_delete(pslist list);

int slist_insert(pslist list, int value);

//int slist_remove(pslist list, int value);

void slist_print(pslist list);

