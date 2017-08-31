#include "Heap.h"
#include <stdlib.h>
Heap construcHeap(int size,enum Type t) 
{
	Heap h;
	h.size = size;
	h.count = 0;
	h.heap = malloc(sizeof(int)*size);
	h.t = t;
	return h;
};
void insert(Heap h, int value) 
{
	int i = 1,j = 1;
	if(!h.count) {
		h.heap[1] = value;
	}
	while(h.heap[i] && h.heap[i+1]) {
		i = 2 * j;
		if (i < h.size) {
			int * x = malloc(2*sizeof(int)*h.size);
			int j;
			for(j = 0; j < h.size; j++) {
				x[j] = h.heap[j];
			}
			free(h.heap);
			h.heap = x;
			h.size *= 2;
		}
		j++;
	}
	if(!i) {
		h.heap[i] = value;
	} else {
		h.heap[i+1] = value;
	}
	h.count++;
}