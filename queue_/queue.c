#include <stdio.h>
#include <stdlib.h>

bool state = false;

struct Queue{
	int data[50];
	int front;
	int rear;
	int size;
};

void main(void){
	struct Queue *q;
	q->front = -1;
	q->rear = -1;
	q->size = 5;


}

void insert(struct Queue *p, int data){
	
	if( p->rear < (p->size-1) ){
		if(state == false)	
			p->front = 0;
		else 
			++p->front;
		p->data[++p->rear] = data;
		printf("\nData %d is inserted on %d. place.\n",data, p->rear);
	}
	else{
		state = true;
		p->rear = -1;
		insert(p, data);
	}
	if(p->front == 5)
		p->front = 0;
	
}

void delete(struct Queue *p){
	if( (p->front) == -1 ){
		printf("Buffer is emty\n");
	}
	else{
		p->data[p->front++] = 0;		
	}
}