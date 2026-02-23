//WAP to insert in circular doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *createNode(int data)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->prev = newNode;
	newNode->next = newNode;
	return newNode;
}

struct node *insert_beg(struct node *tail, int data)
{
	struct node *newNode = createNode(data);
	if(tail == 0)
		return newNode;
	else
	{
		struct node *temp = tail->next;
		newNode->prev = tail;
		newNode->next = temp;
		temp->prev = newNode;
		tail->next = newNode;
		
		return tail;
	}
}

struct node *insert_end(struct node *tail, int data)
{
	struct node *newNode = createNode(data);
	if(tail == 0)
		tail = insert_beg(tail, data);
	else
	{
		struct node *temp = tail->next;
		
		newNode->prev = tail;
		newNode->next = tail->next;
		tail->next = newNode;
		newNode->next->prev = newNode;
		tail = newNode;
		return tail;
	}
}

struct node *insert_lo(struct node *tail, int data, int pos)
{
	struct node *newNode = createNode(data);
	struct node *temp = tail->next;
	
	if(tail == 0 || tail == 1)
		tail = insert_beg(tail, data);
	else 
	{
		while( pos-1 > 1)
		{
			temp = temp->next;
			pos--;
		}
		struct node *temp1 = temp->next;
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next = newNode;
		temp->next->prev = newNode;
		return tail;
		
		if(temp == tail)
			tail = insert_end(tail, data);
	}

}

void display(struct node *tail)
{
	struct node *temp = tail->next;
	if(tail == 0)
		printf("\nList is empty!!!!!!\n");
	else
	{
		do
		{
			printf("%d\t->\t", temp->data);
			temp = temp->next;
		}while(temp != tail->next);
		printf("NULL\n\n");
	}
}

int main()
{
	int data, choice, pos;
	struct node *tail = 0;
	char ch;
	do
	{
		printf("Enter a data : ");
		scanf("%d", &data);
		printf("\n1. Insertion at behinning\n2. Insertion at end\n3. Insertion at particular node\n");
		printf("\nEnter ur choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : printf("\nInsertion at beginning :-\n");
				    tail = insert_beg(tail, data);
				    printf("\n");
				    display(tail);
				    break;
			case 2 : printf("\nInsertion at end :-\n");
				    tail = insert_end(tail, data);
				    printf("\n");
				    display(tail);
				    break;
			case 3 : printf("\nInsertion at particular location :-\n");
				    printf("Enter the position : ");
				    scanf("%d", &pos);
				    tail = insert_lo(tail, data, pos);
				    printf("\n");
				    display(tail);
				    break;
			default : exit(1);
		}
		printf("\nDo u wanna continue inserting? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	return 0;
}
