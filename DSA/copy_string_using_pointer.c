/*WAP using pointers to copy a string to another string varianle without using library function */
#include<stdio.h>
void copy_string(char *, char *);
int main()
{
	char *str[50], *str1[50];
	
	printf("Enter a string : ");
	scanf("%[^\n]", str);
	
	copy_string(str, str1);
	
	printf("\nThe String is : %s\n", str);
	printf("\nThe copied String is : %s\n", str1);
	
	return 0;
}
void copy_string(char *str, char *str1)
{
	int i;
	for(i=0; str[i] != '\0'; i++)
	{
		str1[i] = str[i];
	}
	str1[i] = '\0';
}
