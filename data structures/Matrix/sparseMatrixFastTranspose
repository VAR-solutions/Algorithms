#include<stdio.h>
 typedef struct sparse
{
    int row;
    int col;
    int val;
}sparse;
void fasttranspose(struct sparse[],struct sparse[]);
int main()
{
    sparse spmatA[50],spmatB[50];
    int sparsemat[100][100],i,j,l,sprow,spcol;
    printf("enter the size of sparse matrix:\n");
    scanf("%d%d",&sprow,&spcol);
    printf("elements of sparse matrix:\n");
    for(i=0;i<sprow;i++)
    {
        for(j=0;j<spcol;j++)
        {
           scanf("%d",&sparsemat[i][j]);
        }
    }
    printf("sparse marrix:\n");
    for(i=0;i<sprow;i++)
    {
        for(j=0;j<spcol;j++)
        {
           printf("%d\t",sparsemat[i][j]);
        }
        printf("\n");
    }
    int k=0;
    for(i=0;i<sprow;i++)
    {
        for(j=0;j<spcol;j++)
        {
           if(sparsemat[i][j]!=0)
           {
               k++;
               spmatA[k].row=i;
               spmatA[k].col=j;
               spmatA[k].val=sparsemat[i][j];
           }
        }
    }
    spmatA[0].row=sprow;
    spmatA[0].col=spcol;
    spmatA[0].val=k;
    printf("rowsno.\t colno.\t values\n");       //printing non zero values of sparse matrix with location
    for(l=0;l<=k;l++)
    {
           printf("%d\t%d\t%d\n\n",spmatA[l].row,spmatA[l].col,spmatA[l].val);
    }
    fasttranspose(spmatA,spmatB);
}
//fast transpose
void fasttranspose(struct sparse spmatA[50],struct sparse spmatB[50])
{
    int rowterms[spmatA[0].col],startingpos[spmatA[0].col],i,j,k;
    for(i=0;i<spmatA[0].col;i++)
        rowterms[i]=0;
    for(i=0;i<=spmatA[0].val;i++)
    {
        k=spmatA[i].col;
        rowterms[k]++;
    }
    startingpos[0]=1;
    for(i=1;i<=spmatA[0].col;i++)
    {
        startingpos[i]=startingpos[i-1]+rowterms[i-1];
    }
    spmatB[0].row=spmatA[0].row;
    spmatB[0].col=spmatA[0].col;
    spmatB[0].val=spmatA[0].val;
    int index;
    for(i=1;i<=spmatA[0].val;i++)
    {
        index=0;
        index=startingpos[spmatA[i].col]++;
        spmatB[index].row=spmatA[i].col;
        spmatB[index].col=spmatA[i].row;
        spmatB[index].val=spmatA[i].val;
    }
    printf("rowsno.\t colno.\t values\n");       //printing non zero values of sparse matrix with location
    for(i=0;i<=spmatB[0].val;i++)
    {
           printf("%d\t%d\t%d\n\n",spmatB[i].row,spmatB[i].col,spmatB[i].val);
    }
}


