#ifndef ELEMENT_H
#define ELEMENT_H


#define NELEMSTRUCT 1
#define SEPARATORE '#'
#define DIM 10
#define TYPECOMP int


typedef struct {
	int id;
	char info[2048];

}Set;

typedef struct {//da modificare
	int prova;
	char stringa[DIM];
}TYPE;
typedef struct {
	char titolo[5];
	char nome[21];
	int anno;
	char saluto[101];
	char pass[20];
	char motto[201];

}Utente;

int compare(TYPECOMP a, TYPECOMP b);

#endif
