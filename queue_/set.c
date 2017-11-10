#include <stdio.h>
#include <stdlin.h>

struct set{
	int data;
	struct set *next;
	struct set *prev;
};

void insert(struct set *p, int d){
	

	while( d > p->next->data ){
		p = p->next;
	}
	if( p->data == d){
		printf(" There is same data in list.\n");
		return;
	}

}