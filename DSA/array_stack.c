/* Array Implementation of stacks */
#include<stdio.h>
#include<stdlib.h>
#define size 50
int array[size];
int top = -1;

int push(int data)
{
	if(top == size-1)
	{
		printf("Stack OVERFLOW!!!!!");
		return;
	}
	else
	{
		top++;
		array[top] = data;
	}
}

int pop()
{
	int ret;
	if(top == -1)
	{
		printf("Stack Underflow!!!!");
		exit(1);
	}
	else
	{
		ret = array[top];
		top--;
	}
	return ret;
}

void display()
{
	int i;
	if(top == -1)
	{
		printf("Stack Underflow!!!!");
		exit(1);	
	}
	printf("\t%d\t<-\n", array[top]);
	for(i = top - 1; i >= 0; i--)
		printf("\t%d\n", array[i]);
	printf("\n");
}

int main()
{
	int n, data, i, res, choice;
	char ch='y';
	while(ch == 'y' || ch == 'Y')
	{
		printf("\tMENU\n\n");
		printf("\n1. Push\n2. Pop\n3. Print the top element\n4. Print all the elements of the stack\n5. Exit\n\n");
		printf("Enter ypur choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1 : printf("\nEnter a data : ");
				    scanf("%d", &data);
				    push(data);
				    printf("\n");
				    display();
				    break;
				    
			case 2 : printf("\nNow deletion of elements begins... \n");
				    res = pop();
				    printf("\nElement deleted : %d\n", res);
				    printf("The Stack is now :-\n");
				    display();
				    break;
				    
			case 3 : printf("\n");
				    display();
				    printf("\nThe topmost element of the stack : %d\n", array[top]);
				    break;
				    
			case 4 : printf("\nStack is :- \n\n");
				    display();
				    break;
				    
			case 5 : exit(1);
		}
		printf("\nWanna continue? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	}
	return 0;
}
