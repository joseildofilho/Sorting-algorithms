CC  = gcc
all: main

#Junção principal
main: main.c swap.o ordAlg.o Heap.o
	$(CC) -o main main.c Heap.o ordAlg.o swap.o
	
#Compilação do cabeçalho sozinho, sem link
Heap.o: Heap.c Heap.h swap.h
	$(CC) -c Heap.c -o Heap.o
	
ordAlg.o: ordAlg.c ordAlg.h swap.h
	$(CC) -c ordAlg.c -o ordAlg.o
	
swap.o: swap.c swap.h
	$(CC) -c swap.c -o swap.o
	
clean:
	rm main
	rm *.o