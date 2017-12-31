// Buble Sort

#include <stdio.h>

#define SIZE 10

int* bubbleSort(int *a){
	
	int *p;
	p = a;
	int i, j, temp;
	
	for (i = 0; i < (SIZE-1); i++)
	{
		for (j = 0; j < (SIZE-1-i); j++)
		{
			if ( p[j] > p[j+1] )
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;			
			}	
		}
	}	
	return a;
}

void printArray(int *p)
{
	for(int i = 0; i < SIZE; i++)
		printf("%d ", p[i]);
	printf("\n");
}

void main(){

	int i = 0;
	
	int A[SIZE] = {5, 2, 6, 10, 1, 2, 1, 6, 12, 0};

	printf("Unsorted Array:\n");
	printArray(A);

	bubbleSort(A);

	printf("Sorted Array:\n");
	printArray(A);
}