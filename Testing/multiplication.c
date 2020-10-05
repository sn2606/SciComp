# include <stdio.h>
# include <stdlib.h>
# include "utility.h"


// Function to multiply the matrices
float ** matrix_multiplication_naive(float **a, float **b, int *dimA, int *dimB)
{
    int arow = dimA[0], acol = dimA[1];
    int brow = dimB[0], bcol = dimB[1];
    float **c  = fmatrix(arow, bcol);
    int i, j, k;

    if(acol != brow)
    {
        scierror("Invalid Input! Matrices cannot be multiplied\n");
        exit(0);
    }

    // Initializing produxt matrix C
    for(i = 0; i < arow; i++)
    {
        for(j = 0; j < bcol; j++)
        {
            c[i][j] = 0.0;
        }
    }

    // Multiplying the matrices
    for(i = 0; i < arow; i++)
    {
        for(j = 0; j < bcol; j++)
        {
            for(k = 0; k < acol; k++)
            {
                // printf("%f %f\n", a[i][k], b[k][j]);
                c[i][j] += a[i][k]* b[k][j];
            }
        }
    }

    return c;
}


// Function to transpose a matrix
float ** transpose(float **b, int m, int n)
{
    float **t = fmatrix(n, m);
    int i, j;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            t[j][i] = b[i][j];
        }
    }

    return t;
}


// Function to multiply the matrices
float ** matrix_multiplication_co(float **a, float **b, int *dimA, int *dimB)
{
    int arow = dimA[0], acol = dimA[1];
    int brow = dimB[0], bcol = dimB[1];
    float **c  = fmatrix(arow, bcol);
    int i, j, k;
    float **t = fmatrix(bcol, brow);

    if(acol != brow)
    {
        scierror("Invalid Input! Matrices cannot be multiplied\n");
        exit(0);
    }

    t = transpose(b, brow, bcol);

    // Initializing produxt matrix C
    for(i = 0; i < arow; i++)
    {
        for(j = 0; j < bcol; j++)
        {
            c[i][j] = 0;
        }
    }

    // Multiplying the matrices
    for(i = 0; i < arow; i++)
    {
        for(j = 0; j < bcol; j++)
        {
            for(k = 0; k < acol; k++)
            {
                // printf("%f %f\n", a[i][k], b[k][j]);
                c[i][j] += a[i][k]* t[j][k];
            }
        }
    }
    return c;
}