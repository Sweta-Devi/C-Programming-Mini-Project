//Shell sort
#include<stdio.h>
#define size 20

main()
{
	int arr[size], i, j, k, n, iner;
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
	
	printf("\nEnter maximum increment(odd value) : ");
	scanf("%d", &iner);
	
	while(iner >= 1)
	{
		for(j = iner; j<n; j++)
		{
			k = arr[j];
			for(i = j - iner; i >= 0 && k < arr[i]; i = i - iner)
				arr[i+iner] = arr[i];
			arr[i+iner] = k;
		}
		printf("\nIncrement = %d\n\n", iner);
		for(i=0; i<n; i++)
			printf("%d\t", arr[i]);
		printf("\n");
		iner = iner - 2;
	}
	printf("\nSorted list :-\n\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
}
