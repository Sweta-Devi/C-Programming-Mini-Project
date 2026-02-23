//Binary search using array in ascending order
#include<stdio.h>
#include<stdlib.h>
#define size 50
int arr[size];

int bsearch(int n, int item)
{
	int beg = 0, last = n-1, mid;
	while(beg <= last)
	{
		mid = (beg + last) / 2;
		if(item == arr[mid])
			return mid;
		else if(item > arr[mid])
			beg = mid+1;
		else
			last = mid;
	}
	return -1;
}

int main()
{
	int data, i, n, item, pos;
	printf("Enter the number of elements to be inserted in array : ");
	scanf("%d", &n);
	
	if(n > 50)
	{
		printf("\nArray Overflow!!! must be below 50\n");
		exit(1);
	}
	
	for(i=0; i<n; i++)
	{
		printf("Enter %d element : ", (i+1));
		scanf("%d", &arr[i]);
	}
	printf("The array is as shown below:-\n\n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n\n");
	
	printf("Enter the element to be search : ");
	scanf("%d", &item);
		
	pos = bsearch(n, item);

	if(pos == -1)
		printf("\nElement %d is not found in the array.\n", item);
	else
		printf("\nElement %d found at position : %d\t, Index : %d\n", item, pos+1, pos);

	return 0;
}


