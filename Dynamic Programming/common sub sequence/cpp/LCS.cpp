#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


void strrev(char c[])
{
    int i = 0, j = strlen(c);

    while(i < j/2)
    {
        char t = c[i];
        c[i] = c[j - i - 1];
        c[j - i - 1] = t;
        i++;
    }

}

void PrintPath(int **Diag, char a[], char c[], int i, int j)
{

    static int k = 0;
    if(i == 0 || j == 0)
        return;

    if(Diag[i][j] == 1)
        PrintPath(Diag, a, c, i, j-1);

    else if(Diag[i][j] == 2)
        PrintPath(Diag, a, c, i-1, j);

    else if(Diag[i][j] == 0)
    {       
        c[k++] = a[i];
        c[k] = '\0';
        
        PrintPath(Diag, a, c, i-1, j-1);
    }

    else
        return;
}


void LongestCommonSubsequence(char a[], char b[], int alen, int blen)
{
    int **LCS, **Diag;

    LCS = new int*[alen + 1];
    Diag = new int*[alen];

    for (int i = 0; i < alen; ++i)
        LCS[i] = new int [blen + 1];

    for (int i = 0; i < alen; ++i)
        Diag[i] = new int [blen];

//--------giving value -1 to diag -----------------
    for (int i = 0; i < alen; ++i)
        for (int j = 0; j < blen; ++j)
            Diag[i][j] = -1;
        
//--------------------Giving value 0 to LCS for i = 0 and j = 0----------------
    for (int i = 0; i < alen; ++i)
        LCS[i][0] = 0;

    for (int i = 0; i < blen; ++i)
        LCS[0][i] = 0;


//------------------Computing LCS matrix-----------------------
    for (int i = 1; i < alen; ++i)
    {
        for (int j = 1; j < blen; ++j)
        {
            if(a[i] == b[j])
            {
                LCS[i][j] = 1 + LCS[i-1][j-1];
                Diag[i][j] = 0;                     //Move diagonally backwards
            }

            else
            {
                //---FINDING MAX -------------

                if( LCS[i][j-1] > LCS[i-1][j] )
                {
                    LCS[i][j] = LCS[i][j-1] ;
                    Diag[i][j] = 1;                 //Move horizantally backwards
                }

                else
                {
                    LCS[i][j] = LCS[i-1][j];        //Move vertically backwards
                    Diag[i][j] = 2; 
                }
            }
        }
    }


// cout<<endl;
// //---------PRINTING THE LCS MATRIX------------------
//  for (int i = 0; i < alen; ++i)
//  {
//      for (int j = 0; j < blen; ++j)
//      {
//          cout<<LCS[i][j]<<" ";
//      }
//      cout<<endl;
//  }

//  for (int i = 0; i < alen; ++i)
//  {
//      for (int j = 0; j < blen; ++j)
//      {
// //           Diag[i][j] = -1;
//          cout<<Diag[i][j]<<" ";
//      }
//      cout<<endl;
//  }

    char c[15];
    c[0] = '\0';
    PrintPath(Diag, a, c, alen - 1, blen - 1);
    strrev(c);
    cout<<endl<<c;

}

int main()
{
    char a[15], b[15], c[15], d[15];
    cin>>c>>d;

    a[0] = b[0] = '0';
    a[1] = b[1] = '\0';

    strcat(a,c);
    strcat(b,d);

    int alen = strlen(a), blen = strlen(b);

    LongestCommonSubsequence(a, b, alen, blen);



}