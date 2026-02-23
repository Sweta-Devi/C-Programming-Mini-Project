#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*start;

insert()
{
	int data;
	printf("Enter a data : ");
	scanf("%d", &data);
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	if(start == NULL)
	{
		start = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = start;
		start = temp;
	}
}

display()
{
	struct node *q = malloc(sizeof(struct node));
	q = start;
	if(start == NULL)
	{
		printf("Empty List!!!!\n");
		return;
	}
	else
	{
		while(q != NULL)
		{
			printf("%d\t", q->data);
			q = q->next;
		}
		printf("\n\n");
	}
}

reverse()
{
	struct node *q = malloc(sizeof(struct node));
	struct node *p = malloc(sizeof(struct node));
	struct node *n = malloc(sizeof(struct node));
	p = NULL;
	q = start;
	n = start;
	while(q != NULL)
	{
		n = q->next;
		q->next = p;
		q = n;
	}
	start = p;
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1.Insert\n2.Display\n3.Reverse\n4.Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :  insert();
					break;
			case 2 :  printf("\nDisplaying:-\n");
					display();
					break;
			case 3 :  printf("\nReverse:-\n");
					reverse();
					display();
					break;
			case 4 :  exit(1);
			default:  printf("INVALID!!!");
					break;
		}
	}
	return 0;
}
