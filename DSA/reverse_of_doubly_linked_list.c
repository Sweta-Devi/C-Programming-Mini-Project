/*WAP to print reverse of doubly linked list */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next, *prev;
};

struct node *createNode(int data)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->prev = 0;
	newNode->next = 0;
	return newNode;
}

void insert_beg(struct node **head, int data)
{

  struct node *newNode = createNode(data);

  //If the linked list already had atleast 1 node
  if(*head == 0)
		*head = newNode;
  // *head->prev = newNode; would not work it has (*head) must be used
	else
	{
		(*head)->prev = newNode;
		newNode->next = *head;
		*head = newNode;
	}
}

void count(struct node *head)
{
	int count = 0;
	struct node *temp = head;
	
	while(temp->next != 0)
	{
		temp = temp->next;
		count++;
	}
	count++;
	printf("\nNumber of nodes is : %d\n", count);
	
}
void reverse(struct node **head)
{
	struct node *prevNode, *temp;
	prevNode = 0;
	temp = *head;
	
	if(*head == 0)
	{
		printf("Empty list!!!!!\n");
		exit(1);
	}
	else
	{
		while(temp != 0)
		{
			// Swap the next and prev pointers
			prevNode = temp->prev;
			temp->prev = temp->next;
			temp->next = prevNode;
		
			// Move to the next node in the original list 
         	 // (which is now previous due to reversal)
			temp = temp->prev;
		}
		
		if(prevNode != 0)
			*head = prevNode->prev;
	}

}

void display(struct node *head)
{
	struct node *temp = head;
	while(temp != 0)
	{
		printf("%d\t->\t", temp->data);
		temp = temp->next;
	}
	printf("NULL\n\n"); 
}

int main()
{
	struct node *head = 0;
	int data;
	char ch = 'y';
	while(ch == 'Y' || ch == 'y')
	{
		printf("\nEnter a data : ");
		scanf("%d", &data);
		insert_beg(&head, data);
		printf("\n");
		display(head);
		printf("Do u wanna insert more nodes? (y/n) : ");
		getchar();
		scanf("%c", &ch);	
	}

	printf("\nGiven Doubly linked list is :-\n\n");
	display(head);
	reverse(&head);
	printf("\nReverse of the Doubly linked list :-\n\n");
	display(head);

	return 0;
}
		
