#include <stdio.h>
#include <stdlib.h>
#include "ordAlg.c"
int main(void)
{

	int i, size = 10;
    	int lista [size],lista2[size];
	for(i = size; i > 0; i--) {
        	lista[size-i] = rand() % 10000;
		//lista[5-1] = i;
	}
	for(i = 0; i < size; i++) {
		lista2[i] = lista[i];
	}
	printList(lista,size);
	insertion(lista,size);
	printList(lista,size);
	
	printList(lista2,size);	
	selection(lista2,size);
	printList(lista2,size);

	return 0;
}

void printList(int * list,int size)
{
	int i;
	for(i = 0; i < size; i++) {
		printf("%i %i\n",i,list[i]);
	}
	printf("\n");
}

