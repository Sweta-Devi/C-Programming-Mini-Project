/* Queue implementation using linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*front = NULL, *rear = NULL;

void enqueue()
{
	int data;
	printf("Enter a data : ");
	scanf("%d", &data);
	
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = 0;
	
	if(rear == NULL)
	{
		front = temp;
		rear = temp;
	}
	rear->next = temp;
	rear = temp;
	printf("\nElement %d is added.\n", data); 
}

void	dequeue()
{
	struct node *q = malloc(sizeof(struct node));
	q = front;
	
	if(front == NULL)	
		printf("Empty Queue!!!!");
	
	front = front->next;
	printf("Element deleted from queue is : %d\n", q->data);
	free(q);
}

void menu()
{
	int i;
	printf("\tMENU\n\n");
	
	for(i = 0; i< 25; i++)
		printf("-");
	
	printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n\n");
	
}

void display()
{
	struct node *q = malloc(sizeof(struct node));
	q = front;
	if(front == NULL)
	{
		printf("Empty Queue!!!");
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

main()
{
	int choice;
	char ch;
	while(1)
	{
		menu();
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1 : 	enqueue();
					break;
					
			case 2 :  dequeue();
					break;
					
			case 3 :  display();
					break;
			
			default : exit(1);
		}
	}
	return 0;
}
