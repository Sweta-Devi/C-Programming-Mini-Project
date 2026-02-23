/* Implemenent Polynomial arithmetic */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	float coeff;
	int expo;
	struct node *next;
};

struct node *insert(struct node *head, float co, int ex)
{
	struct node *temp = head;
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->coeff = co;
	newNode->expo = ex;
	newNode->next = 0;
	
	if(head == 0 || ex > head->expo)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		temp = head;
		while(temp->next != 0 && temp->next->expo >= ex)	//check if the exponent of the newNode is smaller than the temp->ex
			temp = temp->next;	// if the newNode is bigger then in temp place, newNode will be place, or else traverse
		newNode->next = temp->next;
		temp->next = newNode;
	}
	return head;
}

struct node *create(struct node *head)
{
	int n, i;
	float coeff;
	int expo;
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
	struct node *temp = head;
	if(head == 0)
		printf("\nNo Polynomial!!!!");
	else
	{
		while(temp != 0)
		{
			printf("(%.1fx^%d)", temp->coeff, temp->expo);
			temp = temp->next;
			if(temp != 0)
				printf(" + ");
			else
				printf("\n");
		}
	}
}

int main()
{
	struct node *head = 0;
	printf("Enter the polynomials :-\n\n");
	head = create(head);
	print(head);
	return 0;
}
