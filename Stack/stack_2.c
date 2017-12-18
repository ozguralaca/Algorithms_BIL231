/* 
* Özgür Alaca
* TLab
* 16.10.2016
* Operations of stack buffer.
*/
#include <stdio.h>
#include <stdlib.h>

struct stack{
	int data[50];
	int top;
	int size;
};

void display(struct stack *p);
void push(struct stack *p, int push_data);
int pop(struct stack *p);

void main(void){
	int sec = 0;
	int d;
	struct stack *s;
	s = (struct stack*) malloc( sizeof(struct stack) );
	s->top = -1;
	s->size = 10;
	while(1){
		printf("\nPlease, select the operation with numbers.\n");
		printf("1. Push in stack buffer.\n");
		printf("2. Pop in stack buffer.\n");
		printf("3. Display stack buffer.\n");
		printf("4. Exit\n");
		scanf("%d", &sec);
		switch(sec){
			case 1:
				printf("\nPlease, enter the data to push in stack buffer.\n");
				scanf("%d", &d);
				push(s, d);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				printf("\n---- Stack buffer is showed as is seen below. ----\n\n");
				display(s);	
				break;
			case 4:
				printf("\n");
				exit(1);
			default:
				printf("\nWarning !!!: Selection is not between 1 and 4.\n");
				printf("\nPlease, enter again.\n");
				break;
		}
	}
}

void push(struct stack *p, int push_data){
	if( p->top < (p->size-1) ){
		p->top++;	
		p->data[p->top] = push_data;
		printf("\nData %d is pushed.\n",push_data );
	}
	else{
		printf("\nWarning !!!: Stack buffer is full.\n");
		return;
	}
}

int pop(struct stack *p){
	int pop_data;
	if(p->top != -1){
		pop_data = p->data[p->top];
		p->top--;
		printf("\nData %d is poped.\n",pop_data);
		return pop_data;
	}
	else{
		printf("\nWarning !!!: Stack buffer is empty.\n");
	}
}

void display(struct stack *p){
	int t = p->top;
	if(t != -1){
		while(t != -1){
			printf("\t\t|  %d  |\n",p->data[t]);
			printf("\t\t  ---  \n");
			--t;
		}
	}
	else{
		printf("\nWarning !!!: Stack buffer is empty.\n");
		return;
	}
}

