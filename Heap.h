#ifndef HEAP_H
#define HEAP_H
typedef enum Type {MAX, MIN} Type;
typedef struct Heap {
	int size,* heap, count;
	Type t;
} Heap;
extern Heap makeHeap(int size,Type t);
extern void insert(Heap h, int value);
#endif
