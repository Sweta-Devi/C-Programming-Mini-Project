/*Insertion sort in array */
#include<stdio.h>
#define size 20

main()
{
	int arr[size], i, j, k, n;
	printf("Enter the number of element : ");
	scanf("%d", &n);	
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("\nUnsorted list :-\n\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
		
	for(j=1; j<n; j++)
	{
		k = arr[j];
		for(i = j-1; i >= 0 && k < arr[i]; i--)
			arr[i+1] = arr[i];	
		arr[i+1] = k;
		printf("Pass %d, Element inserted in proper place : %d\n\n", j, k);
		
		for(i=0; i<n; i++)
			printf("%d\t", arr[i]);	
		printf("\n\n");
	}
	
	printf("\nSorted list :-\n");
	for(i = 0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
}
