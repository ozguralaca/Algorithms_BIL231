#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

char *section(char *fp, char *sp, int sec);
int strings_compare(char *fp, char *sp);
char *string_concatenate(char *fp, char *sp);
char *string_copy(char *fp, char *sp);
int string_length(char *p);
char *string_uppercase(char *p);
char *string_lowercase(char *p);

void main(void)
{
	char first_string[SIZE];
	char second_string[SIZE];
	int selection;

	while(1)
	{
		printf("\n---------------------------------------------------------------\n");
		printf("\nPlease, select string operation.\n");
		printf("1. Compare of two strings.\n");
		printf("2. Concatenate of two strings.\n");
		printf("3. Copy second string to first string.\n");
		printf("4. Length of strings.\n");
		printf("5. Uppercase of string.\n");
		printf("6. Lowercase of string.\n");
		printf("7. Exit \n");
		printf("\n---------------------------------------------------------------\n");
		
		scanf("%d", &selection);
		printf("\a");
		
		section(first_string, second_string, selection);
		
		switch(selection)
		{
			case 1:
				printf("\nCompare two strings.\n");
				int comp = strings_compare(first_string, second_string);
				switch(comp)
				{
					case -1:
						printf("\nSecond string is bigger than first.\n");
						break;
					case 0:
						printf("\nStrings are equal each other.\n");
						break;
					case 1:
	                	printf("\nFirst string is bigger than second.\n");
	                	break;
				}
				break;
			case 2:
				printf("\nConcatenate two strings.\n");	
				string_concatenate(first_string, second_string);
				printf("\nNew concatenate string is %s\n", first_string);
				break;
			case 3:
				printf("\nSecond string is copied to first string.\n");
				string_copy(first_string, second_string);
				printf("\nFirst new string is %s\n", first_string);
				break;
			case 4:
				printf("\n");
				int str_length = string_length(first_string);
				printf("\nLengt of string is %d \n", str_length);
				break;
			case 5: 
				printf("\nString %s is changed with uppercase",first_string);
				string_uppercase(first_string);
				printf(" string %s. \n", first_string);
				break;
			case 6: 
				printf("\nString %s is changed with lowercase",first_string);
				string_lowercase(first_string);
				printf(" string %s. \n", first_string);
				break;
			case 7:
				exit(1);
			default:
				printf("\nWarning !!!: Selection is not between 1 and 7.\n");
				printf("Please, try again.\n");
				break;
		}	
		
	}	
}

/*
* 	Get string according to selections.
*/
char *section(char *fp, char *sp, int sec)
{
	if(sec < 4 && sec > 0)
	{
		printf("\nPlease, enter two strings one by one.\n\n");
		printf("First string : ");
		scanf("%s",fp);
		printf("\n");
		printf("Second string : ");
	    scanf("%s",sp);
		printf("\n");
	}
	else if(sec < 7 && sec > 3)
	{
		printf("\nPlease, enter string.\n\n");
		printf("String : ");
		scanf("%s",fp);
		printf("\n");
	}
	return fp, sp;
}

/*
* 	Compare two  strings according to ASCII values
*/
int strings_compare(char *fp, char *sp)
{
	int compareRes;
	
	while( (*fp != '\0') || (*sp != '\0'))
	{
		compareRes = (*fp) - (*sp);
		
		if(compareRes > 0)
			return 1;
		else if(compareRes < 0)
			return -1;
		fp++;
		sp++;		
	}
	return 0;
}

/*
*  Concatenate two strings on first input string.
*/
char *string_concatenate(char *fp, char *sp)
{
	int counter = 0;
	
	while(*fp != '\0')
	{
		fp++;
		counter++;
	}
	while(*sp != '\0')
	{
		*fp = *sp;
		sp++;
		fp++;
		counter++;
	}
	*fp = *sp;
	while(counter != 0)
	{
		fp--;
		counter--;
	}
	return fp;
}

/*
*  Copy second input string on first input string .
*/
char *string_copy(char *fp, char *sp)
{
	int counter = 0;
	
	while(*sp != '\0')
	{
		*fp = *sp;
		fp++;
		sp++;
		counter++;
	}
	*fp = *sp;
	
	while(counter != 0)
	{
		fp--;
		counter--;
	}
	return fp;
}

/*
* 	Length of string 	
*/
int string_length(char *p)
{
	int counter = 0;
	
	while(*p != '\0')
	{
		counter++;
		p++;
	}
	
	return counter;	
}

/*
*  Uppercase of input string.
*/
char *string_uppercase(char *p)
{
	char *t;
	t = p;
	
	while(*t != '\0')
	{
		if( (*t) >  96 && (*t) < 123)
		{
			*t = (*t) - 32;
		}
		t++;
	}
	
	return p;
}

/*
*  Lowercase of input string.
*/
char *string_lowercase(char *p)
{
	char *t;
	t = p;
	
	while(*t != '\0')
	{
		if((*t) > 64 && (*t) < 91)
		{
			*t = (*t) + 32;
		}
		t++;
	}
	
	return p;
}








