#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef LIST_H
#define LIST_H
#include "element.h"
#define element int// da modificare nel caso


typedef struct list_element {
	element value;
	struct list_element* next;
} item;

typedef  item* list;

typedef  int boolean;

/* PRIMITIVE  */
list emptylist(void);
boolean empty(list);
list cons(element, list);
element head(list);
list tail(list);
int member(element el, list l);
void showList(list l);
void freelist(list l);
list insord(element el, list l);
list filter(list a);

#endif