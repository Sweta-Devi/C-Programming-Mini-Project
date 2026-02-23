/*Bubble sort in array */
#include<stdio.h>
#define size 10

int main()
{
	int arr[size], i, j, k, temp, n, xchanges = 0;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	
	
	for(i=0; i<n; i++)
	{
		printf("\nEnter %d elemens : ", i+1);
		scanf("%d", &arr[i]);
	}
	
		
	printf("\nUnsorted array :-\n\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
	
	for(i=0; i<n-1; i++)	//bubble sort function
	{
		for(j=0; j<(n-1) - i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				xchanges++;
			}
		}
		
		if(xchanges == 0)
			break;
			
		printf("\nAfter Pass %d elements are : ", i+1);
		for(k=0; k<n; k++)
			printf("\t%d\t", arr[k]);
		printf("\n");
	}
	
	printf("\nSorted list is :\n\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
	return 0;
}
