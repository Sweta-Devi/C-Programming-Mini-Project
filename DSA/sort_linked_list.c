/* Bubble Sorting of linked list */
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};

struct node *createNode(int data)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = 0;
	return newNode;
}

void swap(struct node *a, struct node *b)  
{  
    int temp = a->data;  
    a->data = b->data;  
    b->data = temp;  
}  

struct node *insert_beg(struct node *head, int data)
{
	struct node *newNode = createNode(data);
	newNode->next = head;	// head = 0
	head = newNode;	// head has the address of newNode
	return head;
}

void bubbleSort(struct node *start)  
{  
    int swapped, i;  
    struct node *ptr1;  
    struct node *lptr = 0;  
  
    /* Checking for empty list */
    if (start == 0)  
        return;  
  
    do
    {  
        swapped = 0;  
        ptr1 = start;  
  
        while (ptr1->next != 0)  
        {  
            if (ptr1->data > ptr1->next->data)  
            {  
                swap(ptr1, ptr1->next);  
                swapped = 1;  
            }  
            ptr1 = ptr1->next;  
        }  
        lptr = ptr1;  
    }  
    while (swapped);  
}  

void display(struct node *head)
{
	struct node *temp = head;
	while(temp != 0)
	{
		printf("%d\t->\t", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main()
{
	int data, choice;
	struct node *head = 0;
	char ch;
	do
	{
		printf("Enter a data : ");
		scanf("%d", &data);
		head = insert_beg(head, data);
		printf("\n");
		display(head);
		printf("\nDo you wanna continue deleting / inserting? (y/n) : ");
		getchar();
		scanf("%c", &ch);
	} while(ch == 'y' || ch == 'Y');
	
	printf("\nList before sorting :-\n\n");
	
	display(head);
	
	bubbleSort(head);
	
	printf("\nList after sorting :-\n\n");
	display(head);	
	
	return 0;
}
