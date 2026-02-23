//Linear search using array
#include<stdio.h>
#include<stdlib.h>
#define size 5
int arr[size];

main()
{
	int data, n, i, item;
	printf("Enter the number of elements to be inserted : ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter %d element : ", (i+1));
		scanf("%d", &arr[i]);
	}
	
	printf("\nDisplaying the array :-\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
	
	printf("Enter the element to be search : ");
	scanf("%d", &item);
	
	for(i=0; i<n; i++)
	{
		if(item == arr[i])
		{
			printf("\nElement %d found at position : %d\n", item, (i+1));
			return;
		}	
	}
	printf("\nElement not in the array!!!!\n");
	return 0;
}
