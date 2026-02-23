//Write a program in C to find the maximum number between three numbers using a pointer.
#include<stdio.h>
int max(int, int, int);
int main()
{
	int n, n1, n2, maximum;
	printf("Enter 3 numbers : ");
	scanf("%d%d%d", &n, &n1, &n2);
	max(n, n1, n2);
	
	return 0;
}
int max(int n, int n1, int n2)
{
	int *ptr;
	if(n > n1 && n > n2)
		ptr = &n;
	else if(n1 > n && n1 > n2)
		ptr = &n1;
	else
		ptr = &n2;
	printf("Maximum number is : %d\n", *ptr);
}
