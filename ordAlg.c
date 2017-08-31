﻿#include <stdio.h>
#include <stdlib.h>
#include "swap.c"
#include "ordAlg.h"

void printLis(int * list,int size)
{
	int i;
	for(i = 0; i < size; i++) {
		printf("%i %i\n",i,list[i]);
	}
	printf("\n");
}

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

void merge(int *list,int *aux ,int start,int final, int mid) {
    
    int i = start, j = mid + 1, k = 0;
  
    while (i <= mid && j <= final) {
        if (list[i] <= list[j])
            aux[k++] = list[i++];
        else
            aux[k++] = list[j++];
    }
    while (i <= mid)
        aux[k++] = list[i++];
  
    while (j <= final)
        aux[k++] = list[j++];
  
    k--;
    while (k >= 0) {
        list[start + k] = aux[k];
        k--;
    }
}

void mergeSort(int *list,int *aux, int start, int end) 
{
	if(start < end) {
		int q = (start + end) / 2;
		mergeSort(list,aux,start,q);
		mergeSort(list,aux,q+1,end);
		merge(list,aux,start,end,q);
	}
}

int partition(int *list, int start, int end) 
{			
	int i,
	pivot = list[end],
	j = start - 1;	
	for(i = start;i < end;i ++) {
		if(list[i] < pivot) {
			j++;
			swap(&list[i],&list[j]);
		}	
	}
	swap(&list[end],&list[j+1]);
	return j+1;
}

void quickSort(int *list, int start, int end) 
{
	if(start < end) {
		int q = partition(list,start,end);
		quickSort(list,start,q-1);
		quickSort(list,q+1,end);

	}
}

