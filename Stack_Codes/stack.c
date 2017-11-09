#include <stdio.h>
#include <stdlib.h> 

#define SIZE 5

struct stack{
	int data[SIZE];
	int top;
	int counter;
};

void init(struct stack *p);
void push(struct stack *p, int data);
void pop(struct stack *p);
void display(struct stack *p);

void main(void)
{
	int data, sec;
	
	struct stack *s;
	s = (struct stack*) malloc(sizeof(struct stack));
	init(s);
	
	while(1)
	{
		printf("\n---------------------------------------------------------------\n");
		printf("\nPlease, choose the operation with numbers.\n");
		printf("1. Push data in stack buffer.\n");
		printf("2. Pop data in stack buffer.\n");
		printf("3. Display stack buffer.\n");
		printf("4. Exit\n");
		printf("\n---------------------------------------------------------------\n\n");
		
		scanf("%d", &sec);
		
		switch(sec)
		{
			case 1:
				printf("\nPlease, enter number for data.\n");
				scanf("%d", &data);
				push(s, data);
				break;
			case 2:
				printf("\n");
				pop(s);
				break;
			case 3:
				printf("\nStack buffer is displayed.\n");
				display(s);
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

void init(struct stack *p)
{
	p->top = -1;
	p->counter = 0;	
}

void push(struct stack *p, int data)
{
	if( p->counter == SIZE)
	{
		printf("\nWarning!!! Stack buffer is owerflow. \n");
		printf("Before push operation, pop data in stack.\n");	
	}
	else
	{
		p->top++;
		p->data[p->top] = data;
		p->counter++;
		printf("\nData %d is pushed.\n", p->data[p->top]);
	}
}

void pop(struct stack *p)
{
	if(p->counter == 0)
	{
		printf("\nWarning!!! Stack buffer is underflow. \n");
		printf("Before pop operation, push data in stack.\n");
	}
	else
	{
		printf("\nData %d is poped.\n", p->data[p->top]);
		p->data[p->top] = 0;
		p->top--;
		p->counter--;		
	}	
}

void display(struct stack *p)
{
	int i = SIZE-1;
	
	while(i != -1)
	{
		printf("\n\t| %d |\n",p->data[i]);
		printf("\t --- \n");
		i--;
	}
}