#include "Heap.h"
#include <stdlib.h>
#include "swap.h"
Heap * makeHeap(int size,Type t) 
{
	Heap *h = (struct  Heap *) malloc(sizeof(Heap));
	h->size = size;
	h->count = 0;
	h->heap = malloc(sizeof(int)*size);
	h->t = t;
	return h;
};
void insert(Heap * h, int value) 
{
	int i = 1,j = 1;
	if(!h->count) {
		h->heap[1] = value;
		h->count++;
		return;
	}
	if (h->count == h->size-1) {
		int * x = malloc(2*sizeof(int)*h->size);
		int j;
		for(j = 0; j < h->size; j++) {
			x[j] = h->heap[j];
		}
		free(h->heap);
		h->heap = x;
		h->size *= 2;
	}
	h->count += 1;
	i = h->count;
	h->heap[i] = value;
	maxHeapify(h,i);
}
void insertList(Heap *h, int *list, int size) {
	int i = size;
	for (i = 0; i < size; i++) {
		insert(h,list[i]);
	}
}
void maxHeapify(Heap * h, int p)
{	int i = p/2;
	while(h->heap[p] > h->heap[i] && i > 0) {
		swap(&h->heap[p],&h->heap[i]);
		p /= 2;
		i /= 2;
	}
}
void printListh(Heap * h) {
	int i;
	for(i = 0; i < h->size; i++) {
	}
}
int getMax(Heap * h) {
	int r = h->heap[1],
	i = 1,j=2;
	h->heap[1] = 0;
	swap(&h->heap[1],&h->heap[h->count]);
	h->count--;
	while(j <= h->count){
		if(h->heap[j] < h->heap[j+1]) j++;
		else if(h->heap[j] < h->heap[i]) break;		
		swap(&h->heap[i],&h->heap[j]);
		printListh(h);
		i = j;
		j = 2 * j;
	}
	return r;
}
int * heapSort(Heap * h) {
	int * result = malloc(sizeof(int)*h->count), i;
	Heap * p = makeHeap(h->size,MAX);
	p->size = h->size;
	for(i = 0; i < h->size; i++) 
		p->heap[i] = h->heap[i];
	p->count = h->count;
	for(i = h->count -1; i >= 0; i--) { 
		result[i] = getMax(p);
	}
	return result;
}
