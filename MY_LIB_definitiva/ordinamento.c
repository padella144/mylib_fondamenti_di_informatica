#include "ordinamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//algoritmi di ordinamento
void scambia(TYPECOMP* a, TYPECOMP* b)
{//modificare nel caso di stringhe
	TYPECOMP tmp = *a;
	*a = *b;
	*b = tmp;
}

int trovaPosMax(TYPECOMP v[], int n) {
	int i, posMax = 0;
	for (i = 1; i < n; i++)
		if (compare(v[posMax], v[i])<0) {//funzione compare
			posMax = i;
		}
	return posMax;
}

void naiveSort(TYPECOMP v[], int n) {
	int p;
	while (n > 1) {
		p = trovaPosMax(v, n);
		if (p < n - 1) scambia(&v[p], &v[n - 1]);
		n--;
	}
}

void bubbleSort(TYPECOMP v[], int n) {
	int i, ordinato = 0;
	while (n > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < n - 1; i++)
			if (compare(v[i], v[i + 1])>0) {
				scambia(&v[i], &v[i + 1]);
				ordinato = 0;
			}
		n--;
	}
}
void insOrd(TYPECOMP v[], int pos) {
	int i = pos - 1;
	TYPECOMP x = v[pos];
	while (i >= 0 && compare(x, v[i]) < 0) { //se l'elemento è minore scambia
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}
	v[i + 1] = x; /* inserisce l’elemento */ //nel caso di stringhe modificare
}
void insertSort(TYPECOMP v[], int n) {
	int k;
	for (k = 1; k < n; k++)
		insOrd(v, k);
}


void merge(TYPECOMP v[], int i1, int i2,
	int fine, TYPECOMP vout[]) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compare(v[i], v[j])<0) {//modificare qui
			vout[k] = v[i++];
		}
		else {
			vout[k] = v[j++];
		}
		k++;
	}
	while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
	while (j <= fine) { vout[k] = v[j++]; k++; }
	for (i = i1; i <= fine; i++) v[i] = vout[i];
}

void mergeSort1(TYPECOMP v[], int first, int last,
	TYPECOMP vout[]) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort1(v, first, mid, vout);
		mergeSort1(v, mid + 1, last, vout);
		merge(v, first, mid + 1, last, vout);
	}
}
void mergeSort(TYPECOMP v[], int dim) {
	TYPECOMP* vout;
	vout = (TYPECOMP*)malloc(sizeof(TYPECOMP) * dim);
	if (vout != NULL) {
		mergeSort1(v, 0, dim - 1, vout);
		free(vout);
	}
	else {
		printf("errore nell'allocare memoria");
	}


}
void quickSortR(TYPECOMP v[], int first, int last) {
    int i, j, indexPivot;
    TYPECOMP pivot;

    if (first < last) {
        i = first;
        j = last;
        indexPivot = last;
        pivot =  v[indexPivot];

        do {
            while (i < j && compare(pivot, v[i]) >= 0)
                i++;

            while (j > i && compare(v[j], pivot) >= 0)
                j--;

            if (i < j)
                scambia(&v[i], &v[j]);
        } while (i < j);

        if (i != indexPivot && compare(v[i], v[indexPivot]) != 0) {
            scambia(&v[i], &v[indexPivot]);

            indexPivot = i;
        }

        if (first < indexPivot - 1)
            quickSortR(v, first, indexPivot - 1);

        if (indexPivot + 1 < last)
            quickSortR(v, indexPivot + 1, last);
    }
}

void quickSort(TYPECOMP v[], int dim) {
    quickSortR(v, 0, dim - 1);
}