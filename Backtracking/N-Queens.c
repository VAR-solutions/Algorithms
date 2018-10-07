#include<stdio.h>
#define max 8

int n;
int board[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};

void printSolution()
{
  int i, j;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
      printf("%d ", board[i][j]);
    printf("\n");
  }
}

int isSafe(int row, int col)
{
  int i, j;

  for(i = 0; i < col; i++)
  {
    if(board[row][i])
      return 0;
  }

  for(i=row, j=col; i>=0 && j>=0; i--, j--)
  {
    if(board[i][j])
      return 0;
  }

  for(i=row, j=col; i<n && j>=0; i++, j--)
  {
    if(board[i][j])
      return 0;
  }
}

int solveNQueens(int col)
{
  int i,j;
  if(col>=n)
    return 1;

  for(i = 0; i < n; i++)
  {
    if(isSafe(i, col))
    {
      board[i][col] = 1;

      if(solveNQueens(col +1))
        return 1;

      board[i][col] = 0;
    }
  }
  return 0;
}

void main()
{
  printf("Enter the value of n: ");
  scanf("%d", &n);
  if(solveNQueens(0)==0)
    printf("Solution does not exist.\n");
  else
    printSolution();
}
