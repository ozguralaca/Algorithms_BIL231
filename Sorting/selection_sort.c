// Selection Sort 

#include <stdio.h>

#define SIZE 10

int *selectionSort(int *a)
{
	int minIndex, i, j, temp;	
	
	for (i = 0; i < SIZE; i++)
	{
		minIndex = i;
		for (j = i + 1; j < SIZE; j++)
		{
			if ( a[minIndex] > a[j] ) 
				minIndex = j;
		}
		temp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = temp;
	}
	return a;	
}

void printArray(int *p)
{
	for(int i = 0; i < SIZE; i++)
		printf("%d ", p[i] );
	printf("\n");
}


void main(void)
{
	int A[SIZE] = {10, 2, 67, 1, 9, 1, 18, 86, 23, 3};

	printf("Unsorted Array:\n");
	printArray(A);

	selectionSort(A);

	printf("Sorted Array\n");
	printArray(A);
}