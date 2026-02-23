//Selection Sort
#include<stdio.h>
#define size 20
main()
{
	int arr[size], i, j, k, n, temp, small;
	printf("Enter the numberof elements : ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		printf("\nEnter %d element : ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("\nUnsorted list :-\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
	
	for(i=0; i<n-1; i++)	//Selection sort function
	{
		small = i;
		
		for(k = i+1; k < n; k++)
		{
			if(arr[small] > arr[k])	//find the smallest element throught the list
				small = k;
		}
		if(i != small)
		{
			temp = arr[i];
			arr[i] = arr[small];
			arr[small] = temp;
		}
		printf("\nAfter Pass %d elements are :\t", i+1);
		for(j=0; j<n; j++)
			printf("%d\t", arr[j]);
		printf("\n\n");
	}
	
	printf("Sorted List :-\n\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");

}
