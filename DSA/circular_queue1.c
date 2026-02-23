/* Circular queue using array implementation */
#include<stdio.h>
#include<stdlib.h>
#define size 5

int equeue_arr[size];
int front = -1, rear = -1;

insert()
{
	int data;
	
	printf("\nEnter a data : ");
	scanf("%d", &data);
	
	if((front == 0 && rear == size-1) || (front == rear + 1))
	{
		printf("Queue Overflow!!!!");
		return;		
	}	
	
	if(front == -1)
	{
		front = 0;
		rear = 0;
		equeue_arr[front] = data;
	}
		
	else
	{
		if(rear == size-1)
		{
			rear = 0;
			equeue_arr[rear] = data;
		}
		
		rear++;
		equeue_arr[rear] = data;
	}
}

del()
{
	int ret;
	if(front == -1)
	{
		printf("Queue Underflow!!!");
		return;
	}
	else
	{
		ret = equeue_arr[front];
		
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			if(front == size - 1)
				front = 0;
			front++;
		}
			
	}
	printf("\nElement deleted is : %d\n", ret);
}

display()
{	
	int i;
	
	if(front == -1)
	{
		printf("Empty Queue!!!\n");
		return;
	}
		
	if(rear > front)
	{
		printf("\nFRONT\t->\t%d\t", equeue_arr[front]);
		
		for(i = front + 1; i < rear; i++)
			printf("%d\t", equeue_arr[i]);
		
		printf("%d\t<-\tREAR\n", equeue_arr[rear]);
	}
	
	if(rear == front)
		printf("\nFRONT\t->\t%d\t<-\tREAR\n", equeue_arr[rear]);
}

main()
{
	int choice, i;
	char ch;
	do
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
		printf("\nDo you wanna continue? : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	
	return 0;
}


