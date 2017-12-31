#include <stdio.h>

#define SIZE 10

void conquer(int *p, int l, int m, int r);
void divide(int *p, int l, int r);
void print_array(int *p, int n);


void main(void)	
{

	int a[SIZE] = {10, 65, 21, 0, 9, 1, 56, 32, 99, 10};

	print_array(a, SIZE);

	divide(a, 0, SIZE-1);

	print_array(a, SIZE);
}

void conquer(int *p, int l, int m, int r)
{
	int i, j, k, n1, n2;

	n1 = m - l + 1;
	n2 = r - m;

	int L[n1];
	int R[n2];


	for(i = 0; i < n1; i++)
	{
		L[i] = p[l + i];
	}		
	for(j = 0; j < n2; j++)
	{
		R[j] = p[m + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			p[k] = L[i];
			i++;
		}
		else
		{
			p[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1)
	{
		p[k] = L[i];
		k++;
		i++;
	}

	while(j < n2)
	{
		p[k] = R[j];
		k++;
		j++;
	}
}

void divide(int *p, int l, int r)
{
	if(l < r)
	{
		int m = l+(r-l)/2;

		divide(p, l, m);
		divide(p, m+1, r);
		
		conquer(p, l, m, r);
	}
}


void print_array(int *p, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", p[i]);
	
	printf("\n\n");	
}





