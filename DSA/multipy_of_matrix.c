/*WAP to multiply 2 matrices */
#include<stdio.h>
#include<stdlib.h>
int multi(int [100][100], int [100][100], int, int, int);
int main()
{
	int mat[100][100], mat1[100][100], row, col, row1, col1, i, j;
	printf("Enter the number of rows in matrix A : ");
	scanf("%d", &row);
	
	printf("\nEnter the number of columns in matrix A : ");
	scanf("%d", &col);
	
	printf("\nEnter the number of rows in the matrix B : ");
	scanf("%d", &row1);
	
	printf("\nEnter the number of coumns in the matrix B : ");
	scanf("%d", &col1);
	
	if(col != row1)
	{
		printf("\nERROR!!! No. of column of matrix A must be equal to the number of rows in matrix B. \n");
		exit(1);
	}
	
	printf("\nEnter the elements of matrix A : ");
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			scanf("%d", &mat[i][j]);
			
	printf("\nEnter the elements of matrix B : ");
	for(i=0; i<row1; i++)
		for(j=0; j<col1; j++)
			scanf("%d", &mat1[i][j]);
	
	printf("\nMatrix A :- \n");		
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
	
	printf("\nMatrix B :- \n");
	for(i=0; i<row1; i++)
	{
		for(j=0; j<col1; j++)
			printf("%d\t", mat1[i][j]);
		printf("\n");
	}
	
	multi(mat, mat1, row, col, col1);
	
	return 0;	
}

int multi(int a[100][100], int b[100][100], int row, int col, int col1)
{
	int i, j, k, mul[100][100];
	
	for(i=0; i<row; i++)
		for(j=0; j < col1; j++)
			for(k=0; k < col; k++)
				mul[i][j] += a[i][k] * b[k][j];
				
	printf("\nThe result matrix :- \n");
	for(i=0; i<row; i++)
	{
		for(j=0; j < col1; j++)
			printf("%d\t", mul[i][j]);
		printf("\n");
		
	}
}
