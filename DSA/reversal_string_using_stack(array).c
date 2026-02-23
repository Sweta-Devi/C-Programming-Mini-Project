/*Program to reverse a string using stack */
#include<stdio.h>
#include<string.h>
#define size 20
int top = -1;
char stack[size];

char pop()
{
	if(top == -1)
	{
		printf("Stack Underflow!!!\n");
		return;
	}
	return stack[top--];
}

push(char item)	//contain void data type
{
	if(top == size-1)
	{
		printf("Stack Overflow!!!!\n");
		return;
	}
	stack[++top] = item;
}

main()
{
	char str[20];
	int i;
	
	printf("Enter a string : ");
	scanf(" %[^\n]", &str);		//gets(str);
	
	printf("\nThe string is :-\n\n");
	for(i = 0; i < strlen(str); i++)	//push characters of the string 'str' on the stack
		push(str[i]);
	printf(str);
		
	for(i = 0; i < strlen(str); i++)
		str[i] = pop();
	
	printf("\nReversed string :-\n\n");
	puts(str);
	
	return 0;
}




