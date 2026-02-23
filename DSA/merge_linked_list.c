/*Merging 2 linked list */
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*start1, *start2, *start3;

struct node *createNode(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insert_beg(struct node *start, int data)
{
	struct node *temp = createNode(data);
	if(start == 0)
		start = temp;
	else
	{
		temp->next = start;
		start = temp;
	}
	return;
}

void display(struct node *start)
{
	struct node *q = malloc(sizeof(struct node));
	q = start;
	while(q != 0)
	{
		printf("\t%d\t->\t", q->data);
		q = q->next;
	}
	printf("NULL\n\n");
}

struct node *merge_list(struct node *start1, struct node *start2)
{
	struct node *p1 = start1;
	
	while(p1->next != 0)
		p1 = p1->next;
	p1->next = start2;
}

int main()
{
	int data;
	char ch;
	printf("\nEnter the elements of linked list 1 :-\n ");
	do
	{
		printf("Enter the element : ");
		scanf("%d", &data);
		insert_beg(start1, data);
		
		printf("\n");
		
		display(start1);
		printf("\nDo u wanna continue inserting? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	
	printf("\nEnter the elements of linked list 2 :-\n");
	do
	{
		printf("Enter the element : ");
		scanf("%d", &data);
		insert_beg(start2, data);
		printf("\n");
		
		display(start2);
		
		printf("\nDo u wanna continue inserting? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	
	merge_list(start1, start2);
	printf("\n");
	display(start1);
	return 0;
}
