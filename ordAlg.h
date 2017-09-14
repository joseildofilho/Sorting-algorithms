#ifndef ORDALG_H
#define ORDALG_H
void selection(int *list,int size);
void insertion(int *list,int size);
void mergeSort(int *list,int * aux, int start, int end);
void quickSort(int *list,int start, int end);
void count(int **list, int size);
void bucket(int **list, int size);
void radix(int **list, int size);
#endif
