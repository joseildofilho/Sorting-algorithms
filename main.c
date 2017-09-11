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

void mem(int * src, int *target,int size)
{
	int i;
	for(i = 0; i < size; i++) {
		target[i] = src[i];
	}
}

int main(void)
{

	int i, size = 7,* lista,* listaS ,* aux, sizeList = sizeof(int)*size;

	lista = malloc(sizeList);
	listaS = malloc(sizeList);
	aux = malloc(sizeList);

	for(i = size; i > 0; i--) {
        	listaS[size-i] = rand() % 10;
		//lista[5-1] = i;
	}

	mem(listaS,lista,size);

	printf("Insertion\n");
	printList(lista,size);
	insertion(lista,size);
	printList(lista,size);

	mem(listaS,lista,size);

	printf("selection\n");
	printList(lista,size);	
	selection(lista,size);
	printList(lista,size);

	mem(listaS,lista,size);

	printf("merge\n");
	printList(lista,size);
	mergeSort(lista,aux,0,size-1);
	printList(lista,size);

	mem(listaS,lista,size);

	printf("quick\n");
	printList(lista,size);
	quickSort(lista,0,size-1);
	printList(lista,size);

	mem(listaS,lista,size);

	printf("heap\n");
	printList(lista,size);
	Heap * h = makeHeap(2,MAX);
	insertList(h,lista,size);
	printList(h->heap,h->size);
	int * x = malloc(sizeof(int)*h->size);
	x = heapSort(h);
	printf("heap sort começa aqui\n");
	printList(x,h->size);

	
	mem(listaS,lista,size);
	
	printf("count\n");
	printList(lista,size);
	count(&lista,size);
	printList(lista,size);
	printf("end");
	free(lista);
	free(listaS);
	free(aux);	
	return 0;
}
