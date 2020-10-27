/*
    Author: Utkarsh
    Institute: IIIT Guwahati, India
    e-mail: utk.akt@gmail.com
*/

#include <bits/stdc++.h>

#define STRASSEN //NAIVE for naive, DIV_CON for divide and conquer, STRASSEN for Strassen's

using namespace std;

int **alloc_2D(int ord)
{
    int **mat = (int **)calloc(ord, sizeof(int *));
    for (int i = 0; i < ord; i++)
    {
        mat[i] = (int *)calloc(ord, sizeof(int));
    }

    return mat;
}

void free_2D(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

//Naive Algorithm
int **naive(int **mat1, int **mat2, int ord)
{
    int **res_mat = alloc_2D(ord);

    for (int i = 0; i < ord; i++)
    {
        for (int j = 0; j < ord; j++)
        {
            for (int k = 0; k < ord; k++)
            {
                res_mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return res_mat;
}

int **add_mat(int **mat1, int **mat2, int ord)
{
    int **res_mat = alloc_2D(ord);
    for (int i = 0; i < ord; i++)
    {
        for (int j = 0; j < ord; j++)
        {
            res_mat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return res_mat;
}

int **sub_mat(int **mat1, int **mat2, int ord)
{
    int **res_mat = alloc_2D(ord);
    for (int i = 0; i < ord; i++)
    {
        for (int j = 0; j < ord; j++)
        {
            res_mat[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return res_mat;
}

//Recursion using Divide-and-Conquer
int **divcon(int **mat1, int **mat2, int ord)
{
    int **matC = alloc_2D(ord);

    if (ord == 1)
    {
        matC[0][0] = mat1[0][0] * mat2[0][0];
    }
    else
    {
        int new_ord = ord / 2;

        //>>>>>>>>>
        //Forming Partitions

        int **a11 = alloc_2D(new_ord);
        int **a12 = alloc_2D(new_ord);
        int **a21 = alloc_2D(new_ord);
        int **a22 = alloc_2D(new_ord);

        int **b11 = alloc_2D(new_ord);
        int **b12 = alloc_2D(new_ord);
        int **b21 = alloc_2D(new_ord);
        int **b22 = alloc_2D(new_ord);

        for (int i = 0; i < new_ord; i++)
        {
            for (int j = 0; j < new_ord; j++)
            {
                a11[i][j] = mat1[i][j];
                a12[i][j] = mat1[i][j + new_ord];
                a21[i][j] = mat1[i + new_ord][j];
                a22[i][j] = mat1[i + new_ord][j + new_ord];

                b11[i][j] = mat2[i][j];
                b12[i][j] = mat2[i][j + new_ord];
                b21[i][j] = mat2[i + new_ord][j];
                b22[i][j] = mat2[i + new_ord][j + new_ord];
            }
        }

        //<<<<<<<<<<

        //Performing recursive calls for matC [<Resultant Matrix>]
        int **c11 = add_mat(divcon(a11, b11, new_ord), divcon(a12, b21, new_ord), new_ord);
        int **c12 = add_mat(divcon(a11, b12, new_ord), divcon(a12, b22, new_ord), new_ord);
        int **c21 = add_mat(divcon(a21, b11, new_ord), divcon(a22, b21, new_ord), new_ord);
        int **c22 = add_mat(divcon(a21, b12, new_ord), divcon(a22, b22, new_ord), new_ord);

        for (int i = 0; i < new_ord; i++)
        {
            for (int j = 0; j < new_ord; j++)
            {
                matC[i][j] = c11[i][j];
                matC[i][j + new_ord] = c12[i][j];
                matC[i + new_ord][j] = c21[i][j];
                matC[i + new_ord][j + new_ord] = c22[i][j];
            }
        }
    }

    return matC;
}

//Strassen's Method
int **stras(int **mat1, int **mat2, int ord)
{
    int **matC = alloc_2D(ord);

    if (ord == 1)
    {
        matC[0][0] = mat1[0][0] * mat2[0][0];
    }
    else
    {
        int new_ord = ord / 2;

        //>>>>>>>>>
        //Forming Partitions

        int **a = alloc_2D(new_ord);
        int **b = alloc_2D(new_ord);
        int **c = alloc_2D(new_ord);
        int **d = alloc_2D(new_ord);

        int **e = alloc_2D(new_ord);
        int **f = alloc_2D(new_ord);
        int **g = alloc_2D(new_ord);
        int **h = alloc_2D(new_ord);

        for (int i = 0; i < new_ord; i++)
        {
            for (int j = 0; j < new_ord; j++)
            {
                a[i][j] = mat1[i][j];
                b[i][j] = mat1[i][j + new_ord];
                c[i][j] = mat1[i + new_ord][j];
                d[i][j] = mat1[i + new_ord][j + new_ord];

                e[i][j] = mat2[i][j];
                f[i][j] = mat2[i][j + new_ord];
                g[i][j] = mat2[i + new_ord][j];
                h[i][j] = mat2[i + new_ord][j + new_ord];
            }
        }

        //<<<<<<<<<<
        // X _> Row+        Y_> Column-
        int **p1 = stras(a, sub_mat(f, h, new_ord), new_ord);                      //a(f-h)
        int **p2 = stras(add_mat(a, b, new_ord), h, new_ord);                      //(a+b)h
        int **p3 = stras(add_mat(c, d, new_ord), e, new_ord);                      //(c+d)e
        int **p4 = stras(d, sub_mat(g, e, new_ord), new_ord);                      //d(g-e) *
        int **p5 = stras(add_mat(a, d, new_ord), add_mat(e, h, new_ord), new_ord); //diag (a+d)(e+h)
        int **p6 = stras(sub_mat(b, d, new_ord), add_mat(g, h, new_ord), new_ord); //last CR (b-d)(g+h)
        int **p7 = stras(sub_mat(a, c, new_ord), add_mat(e, f, new_ord), new_ord); //first CR (a-c)(e+f)

        int **c11 = sub_mat(add_mat(add_mat(p4, p5, new_ord), p6, new_ord), p2, new_ord); //p4+p5+p6-p2
        int **c12 = add_mat(p1, p2, new_ord);                                             //p1 + p2
        int **c21 = add_mat(p3, p4, new_ord);                                             //p3+p4
        int **c22 = sub_mat(add_mat(p1, p5, new_ord), add_mat(p3, p7, new_ord), new_ord); //p1-p3+p5-p7

        for (int i = 0; i < new_ord; i++)
        {
            for (int j = 0; j < new_ord; j++)
            {
                matC[i][j] = c11[i][j];
                matC[i][j + new_ord] = c12[i][j];
                matC[i + new_ord][j] = c21[i][j];
                matC[i + new_ord][j + new_ord] = c22[i][j];
            }
        }
    }

    return matC;
}

int main()
{
    unsigned ord;
    cout << "Enter the order of the matrix(Must be a power of 2): " << endl;
    cin >> ord;

    int **mat1 = alloc_2D(ord), **mat2 = alloc_2D(ord), **res_mat = alloc_2D(ord);

    cout << "Enter the first matrix: " << endl;
    for (int i = 0; i < ord * ord; i++)
    {
        cin >> mat1[i % ord][i / ord];
    }

    cout << "Enter the second matrix: " << endl;
    for (int i = 0; i < ord * ord; i++)
    {
        cin >> mat2[i % ord][i / ord];
    }

#ifdef NAIVE
    cout << "Naive Algorithm" << endl;
    res_mat = naive(mat1, mat2, ord);
#endif

#elif DIV_CON
    cout << "Divide and Conquer" << endl;
    res_mat = divcon(mat1, mat2, ord);
#endif

#ifdef STRASSEN
    cout << "Strassen's Method" << endl;
    res_mat = stras(mat1, mat2, ord);
#endif

    cout << "The Product is: " << endl;
    for (int i = 0; i < ord; i++)
    {
        for (int j = 0; j < ord; j++)
        {
            cout << res_mat[i][j] << " ";
        }
        cout << endl;
    }

    free_2D(mat1, ord);
    free_2D(mat2, ord);
    free_2D(res_mat, ord);

    return 0;
}