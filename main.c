#include <stdio.h>
#include <stdlib.h>
#include "ordAlg.c"

void printList(int * list,int size)
{
	int i;
	for(i = 0; i < size; i++) {
		printf("%i %i\n",i,list[i]);
	}
	printf("\n");
}

int main(void)
{

	int i, size = 5;
    	int lista [size],lista2[size],lista3[size],aux[size];
	for(i = size; i > 0; i--) {
        	lista[size-i] = rand() % 10000;
		//lista[5-1] = i;
	}
	for(i = 0; i < size; i++) {
		lista2[i] = lista[i];
	}
	for(i = 0; i < size; i++) {
		lista3[i] = lista[i];
	} 

	printf("Insertion\n");
	printList(lista,size);
	insertion(lista,size);
	printList(lista,size);

	printf("selection\n");
	printList(lista2,size);	
	selection(lista2,size);
	printList(lista2,size);

	printf("merge\n");
	printList(lista3,size);
	mergeSort(lista3,aux,0,size-1);
	printList(lista3,size);

	return 0;
}