/*Queue implementation using array */

#include<stdio.h>
#include<stdlib.h>
#define size 50

int queue_arr[size], front = -1, rear = -1;

void insert_rear()		//enqueue meas insertion in queue
{
	int data;
	printf("Enter a data : ");
	scanf("%d", &data);
	
	if(rear == size-1)
	{	
		printf("Overflow!!!!");
		return;
	}
		
	else if(rear == -1)
	{
		front = 0;
		rear = 0;
		queue_arr[rear] = data;
		printf("Enqueued %d in queue\n", data);
	}
		
	else
	{
		queue_arr[rear + 1] = data;
		printf("Enqueued %d in queue\n", data);
		rear += 1;
	}
}

void delete_front()		//dequeue means deletion in queue
{
	if(front == -1 || front > rear)
	{
		printf("Underflow!!!");	//if the no. of item is less tham deletion than its error
		return;
	}
	
	printf("Element deleted from queue is : %d\n", queue_arr[front]);
	front += 1;
}

void display()
{
	int i;
	if(front == -1)
	{
		printf("Queue is Empty!!!");
		return;
	}
	else
	{
		printf("\nQueue is :- \n\n");
		for(i = front; i<=rear; i++)
			printf("%d\t", queue_arr[i]);
		printf("\n\n");
	}
}

void menu()
{
	int i;
	printf("\n\tMENU\n\n");
	
	for(i = 0; i< 25; i++)
		printf("-");
	
	printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n\n");
	
}

int main()
{
	int choice;
	while(1)
	{
		menu();
		printf("Enter your choice : ");
		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1 :  printf("\n");
					insert_rear();
					break;
					
			case 2 :  printf("\n");
					delete_front();
					break;
					
			case 3 :  printf("\n");
					display();
					break;
					
			case 4 : exit(1);
			default: printf("Enter a valid number\n");	
		}
	}
	return 0;
}


