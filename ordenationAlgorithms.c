#include "swap.c"
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
void mergeSort(int *list, int start, int end) {
	int aux[final+1];
	mergeAlgo(&list,&aux, start,final);
}
void mergeAlgo(int *list,int *aux, int start, int end) {
	if(start >= final) {
		int q = (start + final) / 2;
		mergeAlgo(&list,&aux,start,q);
		mergeAlgo(&list,&aux,q+1,final);
		merge(&list,start,final,q);
	}
}
void merge(int *list,int *aux, int start,int final, int mid) {
	int q = mid - start,r = final - mid + 1, i, j = start, k = mid + 1;
	for(i = 0; i < final + 1; i++) {
		if((list[j] < list[k]) && q < j && r < k) {
			aux[i] = list[j];
			j++;
		} else {
			aux[i] = list[k];
			k++;
		}
	}
	for(i = 0; i < final + 1; i++) {
		list[start+i] = aux[i];
	}	
}
