/* WAP TO PRINT REVERSE ON LINKED LIST */
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
	int data;
	struct node *next;
}*start;

struct node *createNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = 0;
	return temp;
}

void insert_end(int data)
{
	struct node *temp = createNode(data);

	if(start == NULL)
	{
		start = temp;
		return;
	}
	
	struct node *q = malloc(sizeof(struct node));
	q = start;
	while(q->next != 0)
		q = q->next;
	q->next = temp;
}

void reverse()
{
	struct node *q, *prevNode, *nextNode;
	prevNode = 0;
	q = start;
	nextNode = start;
	
	while(q != 0)
	{
		nextNode = q->next;
		q->next = prevNode;
		prevNode = q;
		q = nextNode;
	}
	start = prevNode;
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
	int data;
	char ch = 'y';
	while(ch == 'Y' || ch == 'y')
	{
		printf("\nEnter a data : ");
		scanf("%d", &data);
		
		insert_end(data);
		printf("\n");
		
		display(); 
		
		printf("Do u wanna insert more nodes? (y/n) : ");
		getchar();
		scanf("%c", &ch);	
	}

	printf("\nGiven linked list is :-\n\n");
	display();
	
	reverse();
	printf("\nReverse of the linked list :-\n\n");
	display();

	return 0;
}
