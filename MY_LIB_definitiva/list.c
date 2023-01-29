#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* OPERAZIONI PRIMITIVE */
list  emptylist(void)		/* costruttore lista vuota */
{
	return NULL;
}

boolean  empty(list l)	/* verifica se lista vuota */
{
	return (l == NULL);
}

list  cons(element e, list l)
{
	list t;       /* costruttore che aggiunge in testa alla lista */
	t = (list)malloc(sizeof(item));
	t->value = e;
	t->next = l;
	return(t);
}

element head(list l) { /* selettore testa lista */

	if (empty(l)) exit(1);
	else return l->value;
}

list  tail(list l)         /* selettore coda lista */
{
	if (empty(l)) exit(-1);
	else return (l->next);
}

void showList(list l) {
	// NON PRIMITIVE
	element a;
	printf("[");
	while (!empty(l)) {
		a = head(l);
		printf("%d ", a);
		l = tail(l);
		if (!empty(l)) printf(",\n");
	} printf("]\n\n");
}
int compare_member(element el, list l) { // da modificare in base al tipo
	int ritorno;
	ritorno = (el == head(l));
	return ritorno;
}


int member(element el, list l) {//controlla se l'elemento è presente nella lista
	int result = 0;
	while (!empty(l) && !result) {
		result = (compare_member(el,l));
		if (!result)
			l = tail(l);
	}
	return result;
}

void freelist(list l) {
	if (empty(l))
		return;
	else {
		freelist(tail(l));
		free(l);
	}
	return;
}
int compareinsord(element a, list b) { // da modificare in base al tipo
	int ritorno = a > head(b);
	return ritorno;
}
list insord(element el, list l) {
	if (empty(l)) return cons(el, l);
	else if (compareinsord(el,l)) return cons(el, l);
	else return cons(head(l), insord(el, tail(l)));
}
list filter(list a) {//restituisce una lista senza duplicati
		if (empty(a)) {
		return emptylist();
		}
		else {
		if (!member(head(a), tail(a))) {
			 return cons(head(a), filter(tail(a)));
		}
		else {
			return filter(tail(a));
		}
	}

}
// VERSIONE RICORSIVA
//int length(list l) {
//	if (empty(l)) return 0;
//	else return 1 + length(tail(l));
//}
//list append(list l1, list l2) {
//	if (empty(l1)) return l2;
//	else return cons(head(l1), append(tail(l1), l2));
//}
//
//list copy(list l) {
//	if (empty(l)) return l;
//	else return cons(head(l), copy(tail(l)));
//}
//list appendnostruct(list l1, list l2) {
//	if (empty(l1)) return copy(l2);
//	else return cons(head(l1), append(tail(l1), l2));
//
//}
//list delete(element el, list l) {
//	if (empty(l)) return emptylist();
//	else if (el == head(l)) return copy(tail(l));
//	else return cons(head(l), delete(el, tail(l)));
//}