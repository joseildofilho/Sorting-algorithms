#include <stdio.h>
#include <stdlib.h>
#include "swap.h"
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
/*Linear ordenation*/
int max(int *list, int size) 
{
	int m = list[0], i;
	for(i = 1; i < size;i ++) {
		if(list[i] > m)
			m = list[i];
	}
	return m;
}
//doens't work for negative number's
void count(int ** listP, int size) 
{	//select de value max of array

	int i,k, * list = *listP,
	maxValue = max(list,size);
	maxValue += 1;
	//array's sport
	int * aux = malloc(maxValue*sizeof(int)),
		* auxOrd = malloc(size*sizeof(int));
			
	for(i = 0; i < size; i++) {
		aux[list[i]] += 1;
	}
	for(i = 0; i < maxValue - 1; i++) {
		aux[i+1] = aux[i] + aux[i+1];
	} 

	for(i = size-1; i > -1; i--) {
		k = list[i];
		aux[k]-=1;
		auxOrd[aux[k]] = k;
	}
	free(*listP);
	free(*list);
	*listP = auxOrd;

//	free(auxOrd);
	free(aux);
}
void bucket(int ** list, int size) 
{
	printf("Not Implemented");
}
void radix(int ** listP, int size) 
{
	int * aux, *list = *listP, *out, m, i, j, k;
	aux = malloc(sizeof(int)*10);
	
	out = malloc(sizeof(int)*size);
	m = max(list,size);
	for(i = 1; i < m; i*= 10) {
		memset(aux,0,sizeof(int)*10);
		for(j = 0; j < size; j++)
			aux[((list[j] % (i*10))/ i)] += 1;
		for(j = 1; j < 10; j++)
			aux[j] += aux[j-1];
		for(j = size-1; j > -1; j--) {
			k = ((list[j] % (i*10))/ i);
			aux[k]--;
			out[aux[k]] = list[j];
		}
		for(j = 0; j < size; j++)
			list[j] = out[j];
	}
	*listP = list;
}
