/* IMPLEMENT Doubly Linked List */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*start;

/*struct node *createNode(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->prev = 0;
	temp->next = 0;
	return temp;
};*/

// Function to insert a new node at the front of doubly linked list
void insert_beg(int data)
{

	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;

  //If the linked list already had atleast 1 node
	if(start == 0)
	{
		start = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
		
  // start->prev = temp; would not work it has (start) must be used
	else
	{
		start->prev = temp;
		temp->next = start;
		start = temp;
	}
}


// Function to insert a new node at the end of the doubly linked list
void insert_end(int data) 
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;

    // If the linked list is empty, set the new node as the head
	if(start == 0)
	{
		start = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
    else 
    {
        struct node *q = start;
        while (q->next != 0)
     	q = q->next;

        // Set the next of last node to new node
        q->next = temp;
        temp->prev = q;
        temp->next = NULL;
    }
}

void insert_lo(int data, int pos)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	struct node *q = start, *n = start;
	
	if(start == 0)
	{
		start = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
		
	else if(pos == 1)
	{
		start->prev = temp;
		temp->next = start;
		start = temp;
	}
	
	else
	{
		while(pos-1 > 1) 
		{
			q = q->next;
			pos--;
		}
		
		if(q->next != NULL)		//if pos is > length of list, end it
		{
			n = q->next;
			temp->prev = q;
			temp->next = n;
			q->next = temp;
			n->prev = temp;
		}	
		else
		{
			printf("\nPosition out of range\nAdding the element at the end\n");
			q->next = temp;
        		temp->prev = q;
        		temp->next = NULL;	
		}	
	}
}

void delete_beg()
{
	struct node *q = start;
	
	if(start == NULL)
	{
		printf("\nList is empty!!!!");
		exit(1);
	}
		
		start = q->next;
		start->prev = 0;
		q->next = 0;
		free(q);
}

void delete_end()
{
	struct node *q = start, *prevNode = start;

		while(q->next != 0)
		{
			q = q->next;
		}
		
		prevNode = q->prev;
		prevNode->next = 0;
		free(q);
}

void delete_lo(int pos)
{
	int i = 1;
	struct node *q = start, *prevNode = start, *nextNode = start;
	
	if(start == 0)
		printf("List is empty!!!!\n");
		
	else if(pos == 1)
	{
		delete_beg();
	}
	else
	{
		while( i < pos)
		{
			q = q->next;
			i++;
		}
			
			nextNode = q->next;
			prevNode = q->prev;
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			q->next = 0;
			q->prev = 0;
			free(q);
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

void getlength()
{
	struct node *q = start;
	int count = 0;
	while(q != 0)
	{
		count++;
		q = q->next;
	}
	printf("\nLength of the doubly linked list : %d\n", count);
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
	
		printf("1. Insert at beginning\n2. Insert at the end\n3. Insert at specified location\n");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	printf("\nInsertion at beginning of the list :-\n");
					insert_beg(data);
					display();
					break;
			case 2:	printf("\nInsertion at the end of the list :-\n");
					insert_end(data);
					display();
					break;
			case 3:	printf("\nInsertion at particular location :-\n");
					printf("Enter the position : ");
					scanf("%d", &pos);
					insert_lo(data, pos);
					display();
					break;
		
			default:	printf("INVALID!!!!!\n\n");
				break;
		}
		printf("\nDo you wanna continue inserting? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	} while(ch == 'y' || ch == 'Y');
	
	do
	{
		printf("\n\n4. Delete from beginning\n5.Delete from end\n6. Delete at a specified location\n7. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
				case 4:	printf("Deleteing at beggining :-\n");
						delete_beg();
						display();
						break;
				case 5:	printf("Deleteing at ending :-\n");
						delete_end();
						display();
						break;
				case 6:	printf("Deleting at a specific location :-\n");
						printf("\nEnter a position : ");
						scanf("%d", &pos);
						delete_lo(pos);
						display();
						break;
				case 7 : break;
		}
		printf("\nDo you wanna continue deleting? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');	
	
	printf("\n");	
	getlength();
	
	return 0;
}
