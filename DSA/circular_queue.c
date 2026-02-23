/* Circular queue using array implementation */
#include<stdio.h>
#include<stdlib.h>
#define size 5

int equeue_arr[size];
int front = -1, rear = -1;

void insert()
{
	int data;
	
	printf("\nEnter a data : ");
	scanf("%d", &data);
	
	if(front == -1 && rear == -1)
	{
		front = 0; 	rear = 0;
		equeue_arr[front] = data;
	}
	else if(((rear+1)%size) == front)
	{
		printf("Queue Overflow!!!!");
		return;		
	}		
	else
	{
		rear = (rear+1) % size;
		equeue_arr[rear] = data;
	}
}

void del()
{

	if(front == -1 && rear == -1)
	{
		printf("Queue Underflow!!!");
		return;
	}
	else if(front == rear)
	{
		printf("\nElement deleted is : %d\n", equeue_arr[front]);
		front = -1;
		rear = -1;
	}
	else
	{
		printf("\nElement deleted is : %d\n", equeue_arr[front]);
		front = (front+1) % size;
	}
}

void display()
{	
	int i = front;
	
	if(front == -1 && rear == -1)
	{
		printf("Empty Queue!!!\n");
		return;
	}
	else
	{
		printf("\nQueue is :-\n\n");
		while(i != rear)
		{
			printf("%d\t", equeue_arr[i]);
			i = (i+1) % size;
		}
		printf("%d\t", equeue_arr[rear]);
		printf("\n\n");
	}
}

int main()
{
	int choice, i;
	char ch;
	while(1)
	{
		printf("\n\tMENU\n");
		for(i=0; i<25; i++)
			printf("-");
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1 :  printf("\nInsertion :-\n");
					insert();
					break;
			case 2 :  printf("\nDeletion :-\n");
					del();
					break;
			case 3 :  printf("\nCircular Queue is :-\n");
					display();
					break;
			case 4 :  exit(1);
			default:  printf("Enter valid no. ");
		}
	}
	
	return 0;
}


