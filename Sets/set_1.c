/*
 * Set implemented with array.
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct set{
	int data[SIZE];
	int data_count;	
};

struct set *init_set(struct set *p);
void display_set(struct set *p, int s);
int set_insert(struct set *p, int data);
int set_delete(struct set *p, int data);
int set_union(struct set *p1, struct set *p2);
int set_intersect(struct set *p1, struct set *p2);
int set_except(struct set *p1, struct set *p2);


void main(void)
{
	int sec, data;
	
	struct set *s1;
	struct set *s2;
	
	init_set(s1);
	init_set(s2);
	
	while(1)
	{
		printf("\n---------------------------------------------------------------\n");
		printf("Which sets are used.\n");
		printf("Please, choose with numbers.\n");
		printf("1. Set 1\n");
		printf("2. Set 2\n");
		printf("3. Both of them\n");
		printf("4. Display sets\n");
		printf("5. Exit\n");
		printf("\n---------------------------------------------------------------\n");
		
		scanf("%d", &sec);
		
		switch(sec)
		{
			case 1:
				printf("\n--------------------------------------\n");
				printf("Please, choose operations for first set.\n");
				printf("1. Insert\n");
				printf("2. Delete\n");
				printf("3. Exit\n");
				printf("\n--------------------------------------\n");
				
				scanf("%d", &sec);
				
				switch(sec)
				{
					case 1:
						printf("\nEnter data to add.\n");
						scanf("%d", &data);
						set_insert(s1,data);
						break;
					case 2: 
						printf("\nEnter data to sub.\n");
						scanf("%d", &data);
						set_delete(s1,data);
						break;
					case 3:
						break;
					default:
						printf("\nWarning !!!: Selection is not between 1 and 3.\n");
						break;					
				}
				break;
			case 2: 
				printf("\n--------------------------------------\n");
				printf("Please, choose operations for second set.\n");
				printf("1. Insert\n");
				printf("2. Delete\n");
				printf("3. Exit\n");
				printf("\n--------------------------------------\n");
				
				scanf("%d", &sec);
				
				switch(sec)
				{
					case 1:
						printf("\nEnter data to add.\n");
						scanf("%d", &data);
						set_insert(s2,data);
						break;
					case 2: 
						printf("\nEnter data to sub.\n");
						scanf("%d", &data);
						set_delete(s2,data);
						break;
					case 3:
						break;
					default:
						printf("\nWarning !!!: Selection is not between 1 and 3.\n");
						break;					
				}
				break;
			case 3:
				printf("\n--------------------------------------\n");
				printf("Please, choose operations for sets.\n");
				printf("1. Union.\n");
				printf("2. Intersect.\n");
				printf("3. Except.\n");
				printf("4. Exit\n");
				printf("\n--------------------------------------\n");
				
				scanf("%d", &sec);
				
				switch(sec)
				{
					case 1:
						set_union(s1, s2);
						break;
					case 2:
						set_intersect(s1, s2);
						break;						
					case 3:
						set_except(s1, s2);
						break;
					case 4:
						break;
					default:
						printf("\nWarning !!!: Selection is not between 1 and 4.\n");
						break;
				}
				break;
			case 4: 
				printf("\n--------------------------------------\n");
				printf("Which set.\n");
				printf("1. Set\n");
				printf("2. Set\n");
				printf("3. All of them.\n");
				printf("4. Exit.\n");
				printf("\n--------------------------------------\n");
				
				scanf("%d", &sec);
				
				switch(sec){
					case 1:
						display_set(s1, 1);
						break;
					case 2:
						display_set(s2, 2);
						break;
					case 3:
						display_set(s1, 1);
						display_set(s2, 2);
						break;
					case 4:
						break;	
					default:
						printf("\nWarning !!!: Selection is not between 1 and 4.\n");
						break;
				}			
				break;
			case 5:
				exit(1);
			default:
				printf("\nWarning !!!: Selection is not between 1 and 5.\n");
				break;
		}		
	}
		
}

struct set *init_set(struct set *p)
{
	p = (struct set*) malloc(sizeof(struct set));
	p->data_count = 0;
	return p;
}

void display_set(struct set *p, int s)
{
	int i = 0;
	
	printf("\nSet%d : {",s);
	while( i < (p->data_count-1) )
	{
		printf("%d, ", p->data[i]);
		i++;
	}
	printf("%d}\n", p->data[i]);
}

int set_insert(struct set *p, int data)
{
 
	if(p->data_count == SIZE)
	{
		printf("\nWarning!!! Set is overflow.\n");
		return 0;
	}
	
	if(p->data_count == 0)
	{
		p->data[p->data_count] = data;
		p->data_count++;
		return 1;
	}
		
	int i = 0;
	while(i < p->data_count)
	{
		if(p->data[i] == data)
			return 0;		
		if(p->data[i] > data)
			break;		
		i++;
	}
	
	/* Array is shifted. */
	int j = 0;	
	while( j < (p->data_count-i) )
	{
		p->data[p->data_count-j] = p->data[p->data_count-1-j];
		j++;
	}
	
	/* Data is inserted. */
	p->data[i] = data;
	p->data_count++;
	
	return 1;	
}

int set_delete(struct set *p, int data)
{
	if(p->data_count == 0)
	{
		printf("\nWarning!!! Set is underflow.\n");
		return 0;
	}
	
	int i = 0;
	while(i < p->data_count)
	{
		if(p->data[i] == data)
			break;		
		i++;
	}
	
	if(i == p->data_count)
	{
		printf("\nData is not exist.\n");
		return 0;
	}
	
	while( i < (p->data_count - 1) )
	{
		p->data[i] = p->data[i + 1];
		i++;
	}
	
	p->data_count--;
	
	return 1;
}

int set_union(struct set *p1, struct set *p2)
{
	struct set *p3;
	init_set(p3);		
	
	int i = 0;
	while(i < p1->data_count)
	{
		set_insert(p3, p1->data[i]);
		i++;		
	}
	
	i = 0;
	while(i < p2->data_count)
	{
		set_insert(p3, p2->data[i]);
		i++;
	}
	
	printf("\nUnion of both sets : ");
	display_set(p3, 3);
	
	return 1;	
}

int set_intersect(struct set *p1, struct set *p2)
{
	struct set *p3;
	init_set(p3);
	
	int i = 0;
	int j = 0;
	
	while( (i != p1->data_count) && (j != p2->data_count) )
	{
		if(p1->data[i] < p2->data[j])
			i++;			
		else if (p1->data[i] > p2->data[j])
			j++;
		else 
		{
			set_insert(p3, p2->data[i]);
			i++;
			j++;
		}
	}
	printf("\nIntersect of both sets : ");
	display_set(p3, 3);
	return 1;	
}

int set_except(struct set *p1, struct set *p2)
{
	struct set *p3;
	init_set(p3);
	
	p3 = p1;
	
	int i = 0;
	
	while(i < p2->data_count)
	{
		set_delete(p3, p2->data[i]);			
	}

	printf("\nFirst set expect second set : ");
	display_set(p3, 3);
	return 1;
}











