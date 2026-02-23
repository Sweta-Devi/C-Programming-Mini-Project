/* WAP to implement bubble sort on doubly linked list */
#include<stdio.h>
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

// Function to sort the linked list using bubble sort
struct node* bubbleSort(struct node* head) {
    if (head == NULL) 
		return head;

    int swapped;
    struct node* tail = 0;

    // Keep going until no swaps occur in a pass
    do 
    {
     swapped = 0;
	struct node* temp = head;

        // Traverse through the list and swap adjacent
        // nodes if they are in the wrong order
        while (temp->next != tail) {
            if (temp->data > temp->next->data) {
              
                // Nodes to be swapped
                struct node* nextNode = temp->next;

                // Perform the swap
                if (temp->prev == 0) {
                  
                    // Swapping the head node with next node
                    head = nextNode;
                } 
                else {
                  
                    // Linking previous node to next node
                    temp->prev->next = nextNode;
                }

                if (nextNode->next != 0) {
                    nextNode->next->prev = temp;
                }

                // Re-linking nodes to complete swap
                temp->next = nextNode->next;
                nextNode->prev = temp->prev;
                nextNode->next = temp;
                temp->prev = nextNode;

                // Update swapped
                swapped = 1;
            } 
            else {
              
                // Move to the next pair of nodes
               temp = temp->next;
            }
        }
      
        // Update the last sorted element
        tail = temp;
    } while (swapped);

    return head;
}

void printList(struct Node* node) {
    struct Node* curr = node;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
