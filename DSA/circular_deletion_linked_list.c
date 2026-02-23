#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*start, *tail;

struct node *createNode(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insert_beg(int data)
{
	struct node *temp = createNode(data);
	
	if(tail == 0)
	{
		tail = temp;
		start = temp;
		tail->next = temp;
	}
	else
	{
		temp->next = start;
		start = temp;
		tail->next = temp;
	}
}

void delete_beg()
{
	struct node *q = start, *nextNode;
	if(tail == 0)
	{
		printf("List is empty!!!!\n");
		return;
	}
	tail->next = start->next;
	start = start->next;
	free(q);
}

void delete_end()
{
	struct node *q = tail->next, *p = start;
	if(tail == 0)
	{
		printf("List is empty!!!!\n");
		return;
	}
	
	else if(tail == 1)
	{
		free(tail);
		printf("After removing the only node in the list, its an empty list now !!!\n");
		return;
	}
	else
	{
		while(q->next != tail)
			q = q->next;
			
		p = tail;			
		q->next = start;
		tail = q;
		free(p);
	}	
}

void delete_lo(int pos)
{
	struct node *q = tail->next, *p;
	
	if(tail == 0)
	{
		printf("\nList is empty!!!!!\n");
		return;
	}
	
	else if(pos == 1)
	{
		delete_beg();
		return;
	}
	
	else if(pos == tail)
	{
		delete_end();
		return;
	}
	else
	{
		while(pos - 1 > 1)
		{
			q = q->next;
			pos--;
		}
		
		p = q->next;
		q->next = p->next;
		free(p); 
	}
	return;
}

void display()
{
	struct node *q = tail->next;
	do
	{
		printf("\t%d\t->\t", q->data);
		q = q->next;
	}while(q != tail->next);		//q != start
	
	printf("NULL\n\n");
}


int main()
{
	int data, choice, pos;
	char ch;
	do
	{
	
		printf("\n\tMENU\n\n");
		printf("1. Insert at beginning\n2. Deletion from the beginning\n3. Deletion from the end\n4. Deletion from the specific location\n\n");
		printf("Enter ur choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1 :  printf("\nInserting element at the beginning:-\n");
					printf("\nEnter a data : ");
					scanf("%d", &data);
					insert_beg(data);
					printf("\n");
					display();
					break;
					
			case 2 :  printf("\nDeletion from the beginning:-\n");
					delete_beg();
					printf("\n");
					display();
					break;
					
			case 3 :  printf("\nDeletion from the end:-\n");
					delete_end();
					printf("\n");
					display();
					break;
					
			case 4 :  printf("\nDeletion from a particular location:-\n");
					printf("\nEnter the position : ");
					scanf("%d", &pos);
					
					delete_lo(pos);
					printf("\n");
					display();
					break;
					
			default: exit(1);
		}
		printf("\nDo you wanna continue? : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	return 0;
}
