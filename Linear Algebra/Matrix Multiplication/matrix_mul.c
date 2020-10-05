# include <stdio.h>
# include <stdlib.h>
# include "utility.h"
# define N 50

// C program to multiply two matrices
// Naive algorithm - O(n^3)

float **initial_matrix(float **a, int *dima);
float ** matrix_multiplication(float **a, float **b, int *dimA, int *dimB);
void print_matrix(float **c, int *dimC);

// Main function
int main()
{
    float **a = NULL, **b = NULL, **c;
    int *dima = ivector(2);
    int *dimb = ivector(2);
    int *dimc = ivector(2);

    printf("\n------- MATRIX A (m x n) -------\n\n");
    a = initial_matrix(a, dima);

    printf("\n------- MATRIX B (m x n) -------\n\n");    
    b = initial_matrix(b, dimb);

    if(dima[1] != dimb[0])
    {
        scierror("Invalid Input! Matrices are not compatible for multiplication.\n");
        exit(0);
    }
    else
    {
        dimc[0] = dima[0];
        dimc[1] = dimb[1];
    }

    c   = matrix_multiplication(a, b, dima, dimb);
    print_matrix(c, dimc);
    
    return 0;
}

// Function to initialize the matrices
float **initial_matrix(float **a, int *dima)
{
    int i, j, m1, n1, status, flag;

    printf("Enter number of rows in the matrix: ");
    scanf("%d", &m1);
    fflush(stdin);

    printf("Enter number of columns in the matrix: ");
    scanf("%d", &n1);
    fflush(stdin);

    dima[0] = m1;
    dima[1] = n1;

    a = fmatrix(m1, n1);

    // *a = (float **)malloc(m1 * sizeof(float *));
    // for(i = 0; i < m1; i++)
    //     **(a + i) = (float *)malloc(n1 * sizeof(float));

    // Taking input for matrix A + validation
    do {

    for(i = 0; i < m1; i++)
    {
        printf("Enter row %d: ", i+1);
        flag = 1;

        for(j = 0; j < n1; j++)
        {
            status = scanf("%f", (*(a + i)) + j);
            if(status == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
        {
            printf("Invalid entry!\n");
            fflush(stdin);
            break;
        }
    }

    }while(flag == 0);

    return a;
}

// Function to multiply the matrices
float ** matrix_multiplication(float **a, float **b, int *dimA, int *dimB)
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

// Function to print the output
void print_matrix(float **c, int *dimC)
{
    int i, j;
    int crow = dimC[0], ccol = dimC[1];
    
    // Printing the matrix C
    printf("\n\n------- MATRIX A * MATRIX B -------\n\n");
    for(i = 0; i < crow; i++)
    {
        for(j = 0; j < ccol; j++)
        {
            printf("%0.2f\t", c[i][j]);
        }
        printf("\n");
    }
}