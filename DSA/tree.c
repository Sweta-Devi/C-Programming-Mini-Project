/*Program to implement tree data structure */
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

void preorder(struct tree *curr)
{
	if(curr != NULL)
	{
		printf("%d\t", curr->data);
		preorder(curr->left);
		preorder(curr->right);
	}
}

void inorder(struct tree *curr)
{
	if(curr != NULL)
	{
		inorder(curr->left);
		printf("%d\t", curr->data);
		inorder(curr->right);
	}
}

void postorder(struct tree *curr)
{
	if(curr != NULL)
	{
		postorder(curr->left);
		postorder(curr->right);
		printf("%d\t", curr->data);
	}
}

void main()
{
	struct tree *node1, *node2, *node3, *node4, *node5, *node6, *node7, *start;
	node1 = (struct tree *)malloc(sizeof(struct tree));
	
	node1->data = 10;
	start = node1;
	node2 = (struct tree *)malloc(sizeof(struct tree));
	node3 = (struct tree *)malloc(sizeof(struct tree));
	node4 = (struct tree *)malloc(sizeof(struct tree));
	node5 = (struct tree *)malloc(sizeof(struct tree));
	node6 = (struct tree *)malloc(sizeof(struct tree));
	node7 = (struct tree *)malloc(sizeof(struct tree));
	
	node2->data = 5;
	node3->data = 30;
	
	node1->left = node2;
	node1->right = node3;
	
	node4->data = 40;
	node5->data = 50;
	
	node2->left = node4;
	node2->right = node5;
	
	node6->data = 60;
	node7->data = 70;
	
	node3->left = node6;
	node3->right = node7;
	
	node4->left = node4->right = NULL;
	node5->left = node5->right = NULL;
	node6->left = node6->right = NULL;
	node7->left = node7->right = NULL;
	
	int choice;	
	printf("\n\tMENU\n\n");
		
	printf("\n1. Preorder\n2.Inorder\n3. Postorder\n4. Exit\n\n");
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1 :  printf("Preorder is :-\n\n");
					preorder(start);
					break;
				
			case 2 :  printf("Inorder is :-\n\n");
					inorder(start);
					break;
				
			case 3 :  printf("Postorder is :-\n\n");
					postorder(start);
					break;
				
			case 4 : exit(1);
			default: printf("Invalid no.");
		}
	}
}
