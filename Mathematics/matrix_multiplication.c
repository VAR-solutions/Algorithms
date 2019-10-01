//matrix multiplication
#include<stdio.h>
#include<conio.h>
int matrix(int m1[100][100],int row,int col)
{
    //input and printing matrix
    int i,j;
    printf("enter list elements\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf("%d",&m1[i][j]);
    }
    printf("Matrix is\n\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d\t",m1[i][j]);
        printf("\n");
    }
}
void matmulti(int m1[100][100], int m2[100][100], int m3[100][100], int rowm1, int colm1, int colm2, int rowm2)
{
	if(colm1!=rowm2){
		printf("\n\nInvalid Dimensions. Multiplication not possible!\n");
		return;
	}
    int i,j,k;
    //matrix element initialisation
    for(i=0;i<rowm1;i++)
	{
		for(j=0;j<colm2;j++)
		{
			m3[i][j]=0;
		}
	}
	//matrix multiplication
    for(i=0;i<rowm1;i++)
    {
        for(j=0;j<colm2;j++)
        {
            for(k=0;k<rowm2;k++)
                m3[i][j]+=m1[i][k]*m2[k][j];
        }
    }
    printf("\n\nThe product of the two matrices is:\n\n");
    //matrix product display
    for(i=0;i<rowm1;i++)
    {
        for(j=0;j<colm2;j++)
            printf("%d\t",m3[i][j]);
        printf("\n");
    }
}
void main()
{
    int rowm1,rowm2,colm1,colm2;
    int m1[100][100],m2[100][100],m3[100][100];
    printf("enter no. of rows of 1st matrix: ");
    scanf("%d",&rowm1);
    printf("enter no. of columns of 1st matrix: ");
    scanf("%d",&colm1);
    matrix(m1,rowm1,colm1);
    printf("\nenter no. of rows of 2nd matrix: ");
    scanf("%d",&rowm2);
    printf("enter no. of columns of 2nd matrix: ");
    scanf("%d",&colm2);
    matrix(m2,rowm2,colm2);
    matmulti(m1,m2,m3,rowm1,colm1,colm2,rowm2);
    getch();
}
