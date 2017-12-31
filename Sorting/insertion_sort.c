#include <stdio.h>

#define SIZE 10

int insertionSort(int *a)
{
	int key, i, j;

	for(i=1; i<SIZE; i++)
	{

		key = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = key;
	}
}

void printArray(int *p)
{
	for(int i = 0; i < SIZE; i++)
		printf("%d ", p[i] );
	printf("\n");
}


void main(void)
{
	int A[SIZE] = {100, 2, 81, 3, 9, 1, 44, 36, 3, 31};

	printf("Unsorted Array:\n");
	printArray(A);

	insertionSort(A);

	printf("Sorted Array\n");
	printArray(A);
}