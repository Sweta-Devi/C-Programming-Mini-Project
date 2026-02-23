/*Length of linked List */
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
	
	if(start == 0)
		start = temp;
		
	temp->next = start;
	start = temp;	// head has the address of newNode
}

void display()
{
	struct node *q = malloc(sizeof(struct node));
	q = start;
	while(q != 0)
	{
		printf("%d\t->\t", q->data);
		q = q->next;
	}
	printf("NULL\n\n");
}

void getlength()
{
	int count = 0;
	struct node *q = malloc(sizeof(struct node));
	q = start;
	while(q != 0)
	{
		count++;
		q = q->next;
	}
	printf("Length of the list is : %d\n", count);
}

int main()
{
	int data;
	char ch;
	do
	{
		printf("Enter a data : ");
		scanf("%d", &data);
		
		insert_beg(data);
		
		display();
		
		printf("Do u wanna continue inserting? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'Y' || ch == 'y');
	
	getlength();
	
	return 0;
}
