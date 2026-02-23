/* WAP to find the max and min element in an array using pointer */
#include<stdio.h>
#include<stdlib.h>
int max(int [], int);
int min(int [], int);
int main()
{
	int arr[40], n, i, maximum;
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter the %d elements : ", (i+1));
		scanf("%d", &arr[i]);
	}
	
	printf("\nArray is as shown below :-\n\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	min(arr, n);
	max(arr, n);
	
	return 0;
}
int max(int arr[40], int size)
{
	int *large, i;
	large = arr;
	for(i=0; i<size; i++)
		if(arr[i] > *large)
			*large = arr[i];
			
	printf("\nMaximum number of the array is : %d\n", *large);
}
int min(int arr[40], int size)
{
	int *small, i;
	small = arr;
	for(i=0; i<size; i++)
		if(arr[i] < *small)
			*small = arr[i];
			
	printf("\nSmallest element of the array is : %d\n", *small);
}
