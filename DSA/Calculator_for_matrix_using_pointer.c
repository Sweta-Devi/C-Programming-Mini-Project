/* WAP TO ADD TWO MATRIX USING POINTER*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int 
	print:	printf("\n\n----------MENU------------\n");
	printf("\n1. Addition \n2. Subtraction \n3. Multiplication \n4. Exit\n\n");
	printf("Enter your choice : ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1: 	printf("\nAddition of matrix A and matrix B :-\n\n");
				matrixAdd(row, col, mat, mat1, res);
				break;
		case 2:	printf("\nSubtraction of the matrix A and matrix B :-\n\n");
				matrixSubtract(row, col, mat, mat1, res);
				break;
		case 3 :	printf("\nMultiplication of the matrix A and matrix B :-\n\n");
				matrixMultiply(row, col, mat, mat1, res);
				break;
		case 4 : exit(1);
		default : printf("INVALID !!!!!!\n");
				exit(1);
	}
	goto print;
	
	return 0;
}
void matrixInput(int row, int col, int mat[row][col])
{
	int i, j;
	printf("Enter the elements : ");
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			scanf("%d", (*(mat + i) + j));		//since *(mat + i) + j = mat[i][j]
	}
	printf("\nThe matrix is as shown below :- \n\n");
	for(i = 0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%d\t", *(*(mat + i) + j));
		printf("\n");
	}
}
int matrixAdd(int row, int col, int mat[row][col], int mat1[row][col], int res[row][col])
{
	int i, j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			*(*(res + i) + j) = *(*(mat + i) + j) + *(*(mat1 + i) + j);	//res[i][j] = mat[i][j] + mat1[i][j];
	}
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%d\t", *(*(res + i) + j));
		printf("\n");
	}
}

int matrixSubtract(int row, int col, int mat[row][col], int mat1[row][col], int sub[row][col])
{
	int i, j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			*(*(sub + i) + j) = *(*(mat + i) + j) - *(*(mat1 + i) + j);
	}
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%d\t", *(*(sub + i) + j));
		printf("\n");
	}
}

int matrixMultiply(int row, int col, int mat[row][col], int mat1[row][col], int res[row][col])
{
	int i, j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			*(*(res + i) + j) += *(*(mat + i) + j) + *(*(mat1 + i) + j);
	}
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%d\t", *(*(res + i) + j));
		printf("\n");	
	}
}
