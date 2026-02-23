//Stack implementation using linked list
#include<stdio.h>
#include<stdlib.h>
int top = -1;
struct node
{
	int data;
	struct node *next;
}*start;

struct node *createNode(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = 0;
	return temp;
}

void push(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	
	if(start == NULL)
	{
		start = temp;
		temp->next = NULL;
		top = start;
	}
	else
	{
		temp->next = start;
		start = temp;
		top = start;
	}
}

void pop()
{
	struct node *q = malloc(sizeof(struct node));
	q = start;
	
	if(start == NULL)
	{
		printf("Empty Stack!!!!");
		return;
	}
	else
	{
		start = start->next;
		top = start;
		free(q);
	}
}

void display()
{
	int i;
	struct node *q = start->next;
	if(top == -1)
	{
		printf("Stack Underflow!!!!");
		exit(1);	
	}
	printf("\t%d\t<-\n", start->data);
	while(q != 0)
	{
		printf("\t%d\n", q->data);
		q = q->next;
	}
	printf("\n");
}

int main()
{
	int n, data, i, res, choice;
	char ch='y';
	while(ch == 'y' || ch == 'Y')
	{
		printf("\n1. Push\n2. Pop\n3. Print the top element\n4. Print all the elements of the stack\n5. Exit\n\n");
		printf("Enter your choice : ");
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
				    pop();
				    printf("The Stack is now :-\n\n");
				    display();
				    break;
				    
			case 3 : printf("\n");
				    display();
				    printf("\nThe topmost element of the stack : %d\n", start->data);
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
