#ifndef HEAP_H
#define HEAP_H
typedef enum Type {MAX, MIN} Type;
typedef struct Heap {
	int size,* heap, count;
	Type t;
} Heap;
Heap * makeHeap(int size,Type t);
void insert(Heap * h, int value);
void insertList(Heap *h,int * list, int size);
int getMax(Heap * h);
int * heapSort(Heap * h);
#endif
