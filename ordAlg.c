#include "swap.c"
#include "ordAlg.h"
void selection(int *list,int size)
{
    if(size == 1)
        return;
    int i,j,pivot;
    for(i = 0; i < size; i++) {
        pivot = i;
        for(j = i; j < size; j++) {
            if(list[j] < list[pivot]) {
                        pivot = j;
            }
        }
        swap(&list[i],&list[pivot]);
    }
}
void insertion(int *list, int size)
{
        if(size == 1)
                return;
        int i,j,pivot;
        for(i = 1; i < size; i++) {
                pivot = list[i];
                for(j = i; j > 0; j--)
                        if(pivot < list[j-1])
                                swap(&list[j],&list[j-1]);
                        else
                                break;
        }
}

