#include <stdio.h>
#include <stdlib.h>
//#include "linked_list.h"

struct list{
	int a;
	struct list *next;
};

void section(void);
void add_list(struct list *p, int location, int num);
void sub_list(struct list *p, int location, int num);
struct list *reverse_list(struct list *p);
void display_list(struct list *p);

int listlen = 0;
int s_location;
int s_num;

int main(void)
{
	int sec;
	struct list *linked_list;
	linked_list = (struct list*) malloc( sizeof(struct list));
	++listlen;
	linked_list->a = listlen;
	linked_list->next = NULL;
	
	display_list(linked_list);
	
	while(1)
	{
		printf("\n---------------------------------------------------------------\n");
		printf("\nPlease, choose list operations with numbers. \n\n");
		printf("1. Add Lists\n");
		printf("2. Sub Lists\n");
		printf("3. Reverse Lists\n");
		printf("4. Display List\n");
		printf("5. Exit\n");
		printf("\n---------------------------------------------------------------\n\n");
		
		scanf("%d", &sec);
		
		switch(sec)
		{
			case 1:
				printf("\nPlease, enter lacotion and number of lists to make addition process.\n");
				section();
				add_list(linked_list, s_location, s_num);
				break;
			case 2:
				printf("\nPlease, enter the location and number of lists to make subtraction process.\n");
				section();
				sub_list(linked_list, s_location, s_num);	
				break;
			case 3:
				linked_list = reverse_list(linked_list);
				printf("\nLinked list is reversed.\n");
				break;
			case 4:
				printf("\n---- List is displayed as is showed below. ----\n\n");
				display_list(linked_list);
				break;
			case 5:
				exit(1);
			default:
				printf("\nWarning !!!: Selection is not between 1 and 5.\n");
				printf("\nPlease, enter again.\n");
				break;
		}		
	}	
}

void section(void)
{
	// ------ Define Location ------
	printf("Location of List:\n");
	while(1)
	{
		scanf("%d", &s_location);
		
		if(s_location > listlen)
		{
			printf("\nWarning !!!: Selected location is bigger than length of list.\n");
			printf("\nPlease, again enter new location ");
			
			if(listlen == 1)
			{
				printf("with 1. list.\n");
			}
			else
			{
				printf("between 1. and %d. list.\n",listlen);
			}
		}
		else 
			break;
	}
	
	// ------ Define Number of Lists ------
	printf("\nNumber of Lists:\n");
	scanf("%d", &s_num);
}

void add_list(struct list *p, int location, int num)
{
	int i = location;
	listlen = listlen + num;
	
	// Go on with "location" value to add list wanted order.
	while(--i)
	{
		p = p->next;
	}
	
	// If location is last order.
	if(p->next == NULL)
	{
		while(num)
		{
			struct list *new;
			new = (struct list*) malloc(sizeof(struct list));
			++location;
			new->a = location;
			new->next = NULL;
			p->next = new;
			p = p->next;
			--num;
		}		
	}
	// If location is not last order.
	else
	{
		// Create list pointer not to lose order.
		struct list *temp; 
		temp = p->next;
		while(num)
		{
			struct list *new;
			new = (struct list*) malloc(sizeof(struct list));
			++location;
			new->a = location;
			new->next = NULL;
			p->next = new;
			p = p->next;
			--num;
		}
		
		p->next = temp;
		
		// Data in lists is orginezed.
		while(p->next != NULL)
		{
			p = p->next;
			++location;
			p->a = location;
		}
		
	}
}

void sub_list(struct list *p, int location, int num)
{
	int i = location;
	
	// Go on with "location" value to add list wanted order.
	while(--i)
	{
		p = p->next;
	}
	
	// If there is not any list wanted location.
	if(p->next == NULL) 
	{
		printf("\nWarning !!!: After %d. list location, there is not any list. \n", location);
	}
	else 
	{
		struct list *temp1;
		struct list *temp2;
		temp1 = p->next;
		p->next = NULL;
		
		// Subtruction process
		while(num--)
		{
			if(temp1->next != NULL)
			{
				temp2 = temp1->next;
				free(temp1);
				listlen--;
				temp1 = temp2;
			}
			else 
			{
				free(temp1);
				listlen--;
				temp1 = NULL;
				temp2 = NULL;
				break;
			}			
		}
		// To connect first part of list and remaining of list.
		if(temp1)
		{
			p->next  = temp1;	
			// Data in lists is orginezed.
			while(p->next != NULL)
			{
				location++;
				p = p->next;
				p->a = location;
			}
		}	
	}	
}

struct list *reverse_list(struct list *p)
{
	struct list *prev;
	struct list *current;
	struct list *next;
	
	current = p;
	next = p->next;
	current->next = NULL;
	
	while(next->next != NULL)
	{
		prev = current;
		current = next;
		next = current->next;
		current->next = prev;		
	}	
	next->next = current;
	return next;
}

void display_list(struct list *p)
{
	while(p->next != NULL)
	{
		printf("|| %d. List || ---> ",p->a);
		p = p->next;
	}
	printf("|| %d. List || \n", p->a);
	printf("\n Length of list is %d\n", listlen);	
}
