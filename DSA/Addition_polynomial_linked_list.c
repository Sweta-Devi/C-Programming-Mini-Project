/* ADDITION OF 2 POLYNOMIALS */
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	float co;
	int ex;
	struct node *next;
};

struct node *insert(struct node *head, float coeff, int expo)
{
	struct node *temp = head;
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->co = coeff;
	newNode->ex = expo;
	newNode->next = 0;
	
	if(head == 0 || expo > head->ex)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		while(temp->next != 0 && temp->next->ex >= expo)
			temp = temp->next;
		newNode->next = temp->next;
		temp->next = newNode;
	}
	return head;
}

struct node *create(struct node *head)
{
	int n, i, expo;
	float coeff;
	printf("Enter the number of terms : ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		printf("Enter the coefficient for term %d : ", i+1);
		scanf("%f", &coeff);
		printf("\n");
		printf("Enter the exponent for term %d : ", i+1);
		scanf("%d", &expo);
		printf("\n");
		head = insert(head, coeff, expo);
	}
	return head;
}

void print(struct node *head)
{
	if(head == 0)
		printf("\nNo Polynomial\n");
	else
	{
		struct node *temp = head;
		while(temp != 0)
		{
			printf("(%.1fx^%d)", temp->co, temp->ex);
			temp = temp->next;
			if(temp != 0)
				printf(" + ");
			else
				printf("\n");
		}
	}
}

void polyAdd(struct node *head1, struct node *head2)
{
	struct node *head3 = 0;
	struct node *ptr1 = head1, *ptr2 = head2;
	
	while(ptr1 != 0 && ptr2 != 0)
	{
		if(ptr1->ex == ptr2->ex)
		{
			head3 = insert(head3, ptr1->co + ptr2->co, ptr1->ex);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if(ptr1->ex > ptr2->ex)
		{
			head3 = insert(head3, ptr1->co, ptr1->ex);
			ptr1 = ptr1->next;
		}
		else 
		{
			head3 = insert(head3, ptr2->co, ptr2->ex);
			ptr2 = ptr2->next;
		}
	}
	while(ptr1 != 0)
	{
		head3 = insert(head3, ptr1->co, ptr1->ex);
		ptr1 = ptr1->next;
	}
	while(ptr2 != 0)
	{
		head3 = insert(head3, ptr2->co, ptr2->ex);
		ptr2 = ptr2->next;
	}
	printf("\nAdded Polynomial is : ");
	print(head3);
}

int main()
{
	struct node *head1 = 0, *head2 = 0;
	printf("\nEnter the first polynomial :-\n\n");
	head1 = create(head1);
	printf("\nEnter the second polynomial :-\n\n");
	head2 = create(head2);
	
	polyAdd(head1, head2);
	
	return 0;
}
