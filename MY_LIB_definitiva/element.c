#define _CRT_SECURE_NO_WARNINGS
#include "ordinamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(TYPECOMP a, TYPECOMP b) {
	int ritorno = -1;
	if (a < b) {
		ritorno = 1;
	}
	else if (a == b) {
		ritorno = 0;
	}
	return ritorno;
}

void leggiconspazi(FILE* fp, TYPE* res) {
	int i = 0;
	char temp;
	do {
		temp = fgetc(fp);
		if (temp != SEPARATORE && i < DIM - 1 && temp != EOF && temp != '\n') {
			(*res).stringa[i] = temp;
			i++;
		}
	} while (temp != SEPARATORE && i < DIM - 1 && temp != EOF && temp != '\n');//cambiare la dim nel caso
	(*res).stringa[i] = '\0';
}
TYPE leggiuno(FILE* fp) {
	TYPE res;
	char strtemp[DIM];
	int result;
	if (fscanf(fp, "%d", &res.prova) == 1) {
		do {//leggere un arr fino al termiantore
			result = fscanf(fp, "%s", strtemp);
			if ((strcmp(strtemp, "@@") != 0) && result==1) {// qui si puo cambiare con qualsiasi carattere
				strcpy(res.stringa, strtemp);
			}
		} while (strcmp(strtemp, "@@") != 0 && result == 1 );
	}
	else {
		res.prova = -1;
	}
	return res;
}
TYPE leggi_un_type(FILE* fp) {
	TYPE res;
	if (fscanf(fp, "%d ", &res.prova) == NELEMSTRUCT)
	{
		leggiconspazi(fp, &res);//o nel caso altre scanf

	}
	else
		res.prova = -1;//effettuare un controllo se serve
	return res;
}


list file_e_list(FILE* fp) {
	list res;
	TYPE temp;
	res = emptylist();//se va tutto male returna una lista vuota
	temp = leggi_un_type(fp);
	while (temp.prova != -1) {//qui faccio il controllo che puo cambiare
		res = cons(temp.prova, res);//ATTENZIONE QUI DOVREBBE ESSERE PASSATA TUTTA LA STRUTTURA
		temp = leggi_un_type(fp);

	}
	return res;
}

list file_e_list2(char fileName[]) {
	list res;
	TYPE temp;
	FILE* fp = fopen(fileName, "r");
	res = emptylist();
	if (fp == NULL) {
		printf("errore");
	}
	else {
		temp = leggi_un_type(fp);
		while (temp.prova != -1) {//qui faccio il controllo che puo cambiare
			res = cons(temp.prova, res);//ATTENZIONE QUI DOVREBBE ESSERE PASSATA TUTTA LA STRUTTURA
			temp = leggi_un_type(fp);
			
		}
		fclose(fp);
	}
	return res;
}



TYPE* file_e_struct_allocdinamic1(char fileName[], int* dim) {
	FILE* fp;
	TYPE* res;			//modificare
	TYPE temp;				//modificare
	int counter;
	(*dim) = 0;
	res = NULL;
	fp = fopen(fileName, "rt");
	if (fp != NULL) {
		counter = 0;
		do {
			temp = leggi_un_type(fp);
			if (temp.prova != -1) {//da modificare nel caso in cui vuole un altro controllo
				counter++;
			}
			//o sfruttare la funzione conta uno
		} while (temp.prova != -1);
		//modificare num di numelementi
		if (counter > 0) {
			rewind(fp);
			res = (TYPE*)malloc(sizeof(TYPE) * counter);//ATTENZIONE MODIFICARE il type
			do {
				temp = leggi_un_type(fp);
				if ((*dim) < counter && temp.prova != -1) {
					res[*dim] = temp;
					(*dim)++;
				}

			} while ((*dim) < counter && temp.prova != -1);
		}
		fclose(fp);
	}
	return res;
}


void stampastruct(TYPE* res, int dim) {
	int i;
	for (i = 0;i < dim;i++) {
		printf("%d", res[i].prova);//modificare con valori
	}


}
void stamparic(TYPE* res, int dim) {
	if (dim == 0) {
		return;
	}
	else {
		stamparic(res, dim - 1);
		printf("%d", res[dim - 1].prova);
		//nel caso in cui sta una struct in una struct fare un ciclo for qui

	}
}