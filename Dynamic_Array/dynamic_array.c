#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *start(int *a);
int *allocate_array_memory(int *a, int size);
int *resize_array_memory(int *a, int size);
void display_array(int *a);

int counter = 0;

void main(void)
{
	int m, i, space, k; 
	int sec; 	
	int *a; 
	a = start(a);
	
	while(1)
	{
		printf("\n---------------------------------------------------------------\n");
		printf("\nPlease, choose array operations.\n");
		printf("1. Add data in dynamic array.\n");
		printf("2. Delete added memory.\n");
		printf("3. Display array.\n");
		printf("4. Exit\n");
		scanf("%d", &sec);
		printf("\n---------------------------------------------------------------\n");
		
		switch(sec)
		{
			case 1: 
				printf("Enter the length of data.\n ");
				scanf("%d",&m);
				// Bir önceki array bloklarındaki boşluklar belirlenir.
				space = ( SIZE - (counter % SIZE) ) % SIZE;
				// Datanın yazılması için gereken array uzunluğu belirlenir.	
				k = ( (m-space) / SIZE );
				if( ( (m-space) % SIZE ) != 0 )
					k++;
				// Bir önceki array in uzunluğuda eklenir.
				k = k + (counter/SIZE);
				if( (counter%SIZE) != 0)
					k++;
				
				a = resize_array_memory(a, SIZE*k);
				
				while(m != 0)
				{
					a[counter] = counter + 1;
					counter++;
					m--;
				}
				break;
			case 2:
				printf("Added array is delated.\n");
				a = resize_array_memory(a, SIZE);
				counter = SIZE;
				break;
			case 3: 
				display_array(a);
				break;
			case 4: 
				exit(1);
			default:
				printf("\nWarning! Selection is not between 1 and 3 \n");
				printf("Please, enter again.\n");
				break;
		}		
	}	
}

int *start(int *a)
{
	int i;
	
	a = allocate_array_memory(a, SIZE);
	
	for(i = 0; i < SIZE; i++)
	{
		a[i] = i + 1;		
		counter++;
	}
	
    return a;
}

int *allocate_array_memory(int *a, int size)
{
	a = (int *) malloc(size * sizeof(int));
	
	return a ;	
}

int *resize_array_memory(int *a, int size)
{
	a = (int *) realloc(a, size * sizeof(int));
	
	return a;	
}

void display_array(int *a)
{
	int i = 0;
	
	while(i < counter)
	{
		printf("|%d| - ", a[i]);
		i++;
	}
}



