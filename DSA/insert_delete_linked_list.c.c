// C Program to insert a node at the beginning of doubly
// linked list
#include<stdio.h>
#include<malloc.h>


struct node	//structure of node
{
	int data;
	struct node *next;		
}*start;

struct node *createNode(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = 0;
}

void insert_beg()
{
	int data;
	printf("Enter a data : ");
	scanf("%d", &data);
	
	struct node *temp = createNode(data);
	temp->next = start;	// head = 0
	start = temp;	// head has the address of newNode
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
		q->next = q->next->next;
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
	int choice;
	char ch;
	do
	{
		printf("\n\tMENU\n");
		printf("1. Insertion at beginning\n2. Deletion from beginning\n3. Deletion from the end\n");
		printf("4. Deletion from the specific location\n5. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1 : insert_beg();
					printf("\n");
					display();
					printf("\n");
					break;
					
			case 2 :  delete_beg();
					printf("\n");
					display();
					printf("\n");
					break;
					
			case 3 :  delete_end();
					printf("\n");
					display();
					printf("\n");
					break;
			
			case 4 :  delete_lo();
					printf("\n");
					display();
					printf("\n");
					break;
			
			case 5 :  exit(1);
			default: break;
		}
		
		printf("Do you wanna continue? : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	
	return 0;
}
