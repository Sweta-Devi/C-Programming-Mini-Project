// Insertion and Deletion on linked list
#include<stdio.h>
#include<stdlib.h>

struct node	//structure of node
{
	int data;
	struct node *next;		
}*start;

void insert_beg(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	if(start == NULL)
	{
		start = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = start;	// head = 0
		start = temp;	// head has the address of newNode
	}
	
}

void insert_end(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	
	if(start == NULL)
	{
		start = temp;	// head = 0
		temp->next = NULL;
	}
	else
	{
		struct node *q = malloc(sizeof(struct node));
		q = start;
		
		while(q->next != NULL)
			q = q->next;
			
		q->next = temp;
		temp->next = NULL;
	}
}

void insert_lo(int data)
{
	int pos;
	printf("Enter the position : ");
	scanf("%d", &pos);
	
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	
	if(start == 0)
	{
		start = temp;
		temp->next = NULL;
	}
	else if(pos == 1)
	{
		temp->next = start;	// head = 0
		start = temp;
	}
	
	else
	{
		struct node *q = malloc(sizeof(struct node));
		q = start;
		
		while( pos-1 > 1)
		{
			q = q->next;
			pos--;
		}
	
		if(q->next == NULL)		//if pos is > length of list, end it
			printf("\nPosition out of range\nAdding the element at the end\n");
		
		temp->next = q->next;
		q->next = temp;
	}
}

void delete_beg()
{
	struct node *q = malloc(sizeof(struct node));
	q = start;
	if(start == NULL)
		printf("List is empty!!!!\n");
	else
	{
		start = q->next;
		free(q);
	}
}

void delete_end()
{
	struct node *q = malloc(sizeof(struct node)), *p;
	q = start;
	if(start == NULL)
		printf("Empty list!!!!\n");
		
	while(q->next->next != 0)
		q = q->next;
	p = q->next;
	q->next = 0;
	free(p);
}

void delete_lo()
{
	struct node *q = malloc(sizeof(struct node)), *p;
	q = start;
	int pos;
	printf("Enter the position : ");
	scanf("%d", &pos);

	if(pos == 0)
	{
		printf("\nList is empty!!!!!!\n");
		exit(1);
	}
	else if(pos == 1)
	{
		start = 0;
		free(q);
	}
	else
	{
		while(pos-1 > 1)
		{
			q = q->next;
			pos--;
		}
		p = q->next;
		q->next = p->next;
		free(p);
	}
}

void display()
{
	struct node *q = start;
	while(q != 0)
	{
		printf("%d\t->\t", q->data);
		q = q->next;
	}
	printf("NULL\n\n");
}

int main()
{
	int data, choice, pos;
	char ch;
	do
	{
		printf("Enter a data : ");
		scanf("%d", &data);
		printf("\n");
		printf("1. Insert at beginning\n2. Insert at the end\n3. Insert at specified location\n4. Delete from beginning\n");
		printf("5. Delete from the end\n6. Delete from the specific location\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	printf("\nInsertion at beginning of the list :-\n");
					insert_beg(data);
					printf("\n");
					display();
					break;
					
			case 2:	printf("\nInsertion at the end of the list :-\n");
					insert_end(data);
					printf("\n");
					display();
					break;
					
			case 3:	printf("\nInsertion at particular location :-\n");
					insert_lo(data);
					printf("\n");
					display();
					break;
					
			case 4:	printf("\nDeletion from the beginning :-\n");
					delete_beg();
					printf("\n");
					display();
					break;
					
			case 5:	printf("\nDeletion from the end of the list :-\n");
					delete_end();
					printf("\n");
					display();
					break;
					
			case 6:	printf("\nDeletion from the particular location :-\n");
					delete_lo();
					printf("\n");
					display();
					break;
	
			default:	printf("INVALID!!!!!\n\n");	
		}
		printf("\nDo you wanna continue inserting? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	} while(ch == 'y' || ch == 'Y');
	
	return 0;
}
