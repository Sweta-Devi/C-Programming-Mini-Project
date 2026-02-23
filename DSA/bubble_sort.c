//Bubble sort
#include<stdio.h>
#include<stdlib.h>
#define size 20

int main()
{
	int arr[size], i, j, k, n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		printf("Enter %d element : ", i+1);
		scanf("%d", &arr[i]);
	}

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				arr[j] = arr[j]^arr[j+1];
				arr[j+1] = arr[j]^arr[j+1];
				arr[j] = arr[j]^arr[j+1];
			}
		}
		printf("After Pass %d elements are : ", i+1);
		for(k=0; k<n; k++)
			printf("\t%d\t", arr[k]);
		printf("\n\n");
	}
	printf("\nSorted List :-\n\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
	return 0;
}