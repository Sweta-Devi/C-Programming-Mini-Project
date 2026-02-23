/* IMPLEMENT CIRCULAR LINKED LIST */
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

void insert_end(int data)
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
		temp->next = tail->next;	//start
		tail->next = temp;
		tail = tail->next;
	}
}

void insert_lo(int data, int pos)
{
	struct node *temp = createNode(data);
	struct node *q = tail->next;
	
	if(start == 0)
	{
		tail = temp;
		start = temp;
		tail->next = temp;
	}
	
	else if (pos == 1)
		insert_beg(data);
		
	else
	{
		while(pos - 1 > 1)
		{	
			q = q->next;
			pos--;
		}
		temp->next = q->next;
		q->next = temp;
	}
	return;
}

int count()
{
	struct node *q = tail->next;
	int cou;
	do
	{
		cou++;
		q = q->next;
	}while(q != tail->next);
	
	printf("\nTotal number of elements : %d\n", cou);
}
 
void display()
{
	struct node *temp = tail->next;
	do
	{
		printf("\t%d\t->\t", temp->data);
		temp = temp->next;
	}while(temp != tail->next);
	
	printf("NULL\n\n");
}

int getdata()
{
	int data;
	printf("\nEnter a data : ");
	scanf("%d", &data);
	return data;
}

int main()
{
	int choice, pos, i, ele;
	char ch;
	do
	{
		printf("\n\tMENU\n");
		for(i = 0; i<25; i++)
			printf("-");
			
		printf("\n1. Insertion at the beginning\n2. Insertion at the end\n3. Insertion at the specific location\n");
		printf("4. Print the last node\n5. Print the first node\n6. Count the number of nodes\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1 :  printf("Insertion at the beginning :-\n");
					ele = getdata();
					insert_beg(ele);
					printf("\n");
					display();
					break;
				    
			case 2 : printf("Insertion at the end :-\n");
					ele = getdata();
					insert_end(ele);
					printf("\n");
					display();
					break;
				    
			case 3 : printf("\nInsertion at specific location :-\n\n");
				    ele = getdata();
				    printf("Enter position : ");
				    scanf("%d", &pos);
				    insert_lo(ele, pos);
				    printf("\n");
				    display();
				    break;
				    
			case 4 : 	printf("\nThe last element of the list : %d\n\n", tail->data);
					break;
			case 5 : 	printf("\nThe first element of the list : %d\n\n", tail->next->data);
					break;
				    
		
			case 6 :	count();
					break;	
					
			default : exit(1);
		}
		
		printf("Do u wanna continue? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');

	return 0;
}


