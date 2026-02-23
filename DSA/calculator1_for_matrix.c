//WAP to display pyramid using asterisk
#include<stdio.h>
int main()
{
	int n, i, j, k;
	printf("Enter the number of rows : ");
	scanf("%d", &n);
	
	for(i = 0; i< n; i++)
	{
		for(j = 0; j < (n-i-1); j++)
			printf(" ");
		
		for(j = 0; j < (i+1); j++)
			printf("* ");	
		
		printf("\n");
	}
	return 0;
}

