#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct queue{
	int data[SIZE];
	int front; 
	int rear;
	int counter;
};

void init(struct queue *p);
void enqueue(struct queue *p, int data);
void dequeue(struct queue *p);
void display_queue(struct queue *p) ;

void main(void)
{
	int sec, data;
	
	struct queue *q;
	q = (struct queue*) malloc( sizeof(struct queue));
	
	init(q);
	
	while(1)
	{
		printf("\n---------------------------------------------------------------\n");
		printf("\nPlease, choose queue operation with numbers. \n\n");
		printf("1. Insert data in queue list.\n");
		printf("2. Get data in queue list.\n");
		printf("3. Display queue list.\n");
		printf("4. Exit\n");
		printf("\n---------------------------------------------------------------\n\n");
		
		scanf("%d", &sec);
		
		switch(sec)
		{
			case 1: 
				printf("\nPlease, enter number for data.\n");
				scanf("%d", &data);
				enqueue(q, data);
				break;
			case 2:
				dequeue(q);
				break;
			case 3:
				printf("\nQueue lists are displayed. \n");
				display_queue(q);
				break;
			case 4: 
				exit(1);
			default:
				printf("\nWarning !!!: Selection is not between 1 and 4.\n");
				printf("\nPlease, enter again.\n");
				break;			
		}
	}	
}

void init(struct queue *p)
{
	p->front = 0;
	p->rear = 0;
	p->counter = 0;
}

void enqueue(struct queue *p, int data)
{
	if( p->counter == SIZE )
	{
		printf("\nWarning!!! Queue is overflow.\n");
		printf("Before insert operation, get data in queue to empty queue.\n");			
	}
	else
	{
		p->data[p->rear] = data;
		p->rear++;		
		p->counter++;
		printf("\nData %d is inserted on %d. place in queue array.\n", data, p->rear );	
		if( p->rear == SIZE)
			p->rear = 0;				
	}	
}

void dequeue(struct queue *p)
{
	if( p->counter == 0 )
	{
		printf("\nWarning!!! Queue is underflow.\n");
		printf("Before get operation, insert data in queue array.\n");
	}
	else 
	{
		printf("\nData %d is gotten in queue array.\n", p->data[p->front]);
		
		p->data[p->front] = 0;
		
		p->front++;
		
		p->counter--;
		
		if(p->front == SIZE)
				p->front = 0;
	}
}

void display_queue(struct queue *p) 
{
	int i = 0;
	
	while(i < SIZE)
	{
		printf("| %d |-", p->data[i]);
		i++;
	}
}