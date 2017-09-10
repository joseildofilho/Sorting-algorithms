#include <stdio.h>
#include <stdlib.h>
#include "ordAlg.h"
#include "Heap.h"

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

	int i, size = 7,* lista,* lista2 ,* lista3 ,* aux ,* lista4 ,* lista5, sizeList = sizeof(int)*size;

	lista = malloc(sizeList);
	lista2 = malloc(sizeList);
	lista3 = malloc(sizeList);
	lista4 = malloc(sizeList);
	lista5 = malloc(sizeList);
	aux = malloc(sizeList);

	for(i = size; i > 0; i--) {
        	lista[size-i] = rand() % 1000;
		//lista[5-1] = i;
	}
	for(i = 0; i < size; i++) {
		lista2[i] = lista[i];
	}
	for(i = 0; i < size; i++) {
		lista3[i] = lista[i];
	} 
	for(i = 0; i < size; i++) {
		lista4[i] = lista[i];	
	}
	for(i = 0; i < size; i++) {
		lista5[i] = lista[i];
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

	printf("quick\n");
	printList(lista4,size);
	quickSort(lista4,0,size-1);
	printList(lista4,size);

	printf("heap\n");
	printList(lista5,size);
	Heap * h = makeHeap(2,MAX);
	insertList(h,lista5,size);
	printList(h->heap,h->size);
	int * x = malloc(sizeof(int)*h->size);
	x = heapSort(h);
	printf("heap sort começa aqui\n");
	printList(x,h->size);


	return 0;
}
