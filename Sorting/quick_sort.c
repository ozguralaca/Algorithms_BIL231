// Quick Sort 
#include <stdio.h>

#define SIZE 10

void print_array(int *p, int size);
int quick_sort(int *p, int low, int high);
int partition(int *p, int low, int high);
int swap(int *p, int i, int j);

void main(void)
{
	int a[SIZE] = {3, 19, 1, 9, 11, 32, 0, 10, 1, 5};
	
	print_array(a, SIZE);
	
	quick_sort(a, 0, (SIZE-1));
	
	print_array(a, SIZE);
}

void print_array(int *p, int size)
{
	int i = 0;
	while(i < size)
	{
		printf("%d, ",p[i]);
		i++;
	}
	printf("\n\n");
}

int quick_sort(int *p, int low, int high)
{
	int pivot = 0;
	
	if(low < high)
	{
		pivot = partition(p, low, high);
		quick_sort(p, low, (pivot-1));
		quick_sort(p, (pivot+1), high);
	}
	
	return 1;
		
}

int partition(int *p, int low, int high)
{
	int i, j, pivot;
	
	pivot = p[high];
	j = low;
	
	for(i = low; i < high; i++)
	{		
		if(p[i] <= pivot)
		{
			swap(p, i, j);
			j++;
		}		
	}	

	swap(p, high, j);
	return j;	
}

int swap(int *p, int i, int j)
{
	int temp = p[j];
	p[j] = p[i];
	p[i] = temp;
	
	return 1;	
}