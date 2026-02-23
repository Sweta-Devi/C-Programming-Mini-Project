/*WAP to find the transpose of a matrix */
#include<stdio.h>
int main()
{
	int mat[50][50], i, row, col, j, t_mat[50][50];
	printf("Enter the number of rows in matrix A : ");
	scanf("%d", &row);
	
	printf("Enter the number of column in matrix A : ");
	scanf("%d", &col);
	
	printf("\nEnter the elements of matrix A : ");
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			scanf("%d", &mat[i][j]);
	
	printf("\nMatrix A :-\n");
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
	
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			t_mat[j][i] = mat[i][j];
	
	printf("\nTranspose of the matrix A :-\n");		
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%d\t", t_mat[i][j]);
		printf("\n");
	}
	
	return 0;	
}
