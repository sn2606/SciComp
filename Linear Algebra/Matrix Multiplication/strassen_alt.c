// C Program to implement Strassen's algorithm for matrix multiplication
// Divide and Conquer algorithm design paradigm

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "utility.h"
# define MAX 32

float **initial_matrix(float **a, int *dima);
float **add(float **a, float **b, int size, float **c);
float **sub(float **a, float **b, int size, float **c);
void multiply(float **c, float **d, int size, int size2, float **new);
void print_matrix(float **c, int *dimC);

// Main function
int main()
{
    float **a = NULL, **b = NULL, **c;
    int *dima = ivector(2);
    int *dimb = ivector(2);
    int *dimc = ivector(2);
    int n, status, p, k;

    printf("Enter size of the matrices (n) : ");
    status = scanf("%d", &n);
    fflush(stdin);

    p = log2(n);
    k = pow(2, p);

    while (status == 0 || n != k)
    {
        printf("Enter valid size : ");
        status = scanf("%d", &n);
        fflush(stdin);
        p = log2(n);
        k = pow(2, p);
    }

    dima[0] = n; dima[1] = n;
    dimb[0] = n; dimb[1] = n;
    dimc[0] = n; dimc[1] = n;  

    c = fmatrix(n, n);

    printf("\n------- MATRIX A (n x n) -------\n\n");
    a = initial_matrix(a, dima);

    printf("\n------- MATRIX B (n x n) -------\n\n");    
    b = initial_matrix(b, dimb);

    multiply(a, b, n, n, c);
    print_matrix(c, dimc);
    
    return 0;
}

// Function to initialize the matrices
float **initial_matrix(float **a, int *dima)
{
    int i, j, m1, n1, status, flag;

    m1 = dima[0];
    n1 = dima[1];

    a = fmatrix(m1, n1);

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

// Function to add two matrices
float **add(float **a, float **b, int size, float **c)
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    return c;
}

// Function to subtract two matrices
float **sub(float **a, float **b, int size, float **c)
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    return c;
}

// Function to multiply two matrices using
// Strassen's algorithm
void multiply(float **c, float **d, int size, int size2, float **new)
{
    int i, j;
    int nsize = size / 2;
    
    if(size == 1)
    {
        new[0][0] = c[0][0] * d[0][0];
    }
    else
    {
        // Divisions of C matrix
        float **c11 = fmatrix(nsize, nsize);
        float **c12 = fmatrix(nsize, nsize);
        float **c21 = fmatrix(nsize, nsize);
        float **c22 = fmatrix(nsize, nsize);

        // Divisions of D matrix
        float **d11 = fmatrix(nsize, nsize);
        float **d12 = fmatrix(nsize, nsize);
        float **d21 = fmatrix(nsize, nsize);
        float **d22 = fmatrix(nsize, nsize);

        // Seven Product matrices
        float **p1 = fmatrix(nsize, nsize);
        float **p2 = fmatrix(nsize, nsize);
        float **p3 = fmatrix(nsize, nsize);
        float **p4 = fmatrix(nsize, nsize);
        float **p5 = fmatrix(nsize, nsize);
        float **p6 = fmatrix(nsize, nsize);
        float **p7 = fmatrix(nsize, nsize);

        // Partitioning input matrices
        for(i = 0; i < nsize; i++)
        {
            for(j = 0; j < nsize; j++)
            {
                // Partitioning matrix C
                c11[i][j] = c[i][j];
                c12[i][j] = c[i][j + nsize];
                c21[i][j] = c[i + nsize][j];
                c22[i][j] = c[i + nsize][j + nsize];

                // Partitioning matrix D
                d11[i][j] = d[i][j];
                d12[i][j] = d[i][j + nsize];
                d21[i][j] = d[i + nsize][j];
                d22[i][j] = d[i + nsize][j + nsize];
            }            
        }

        // printf("\n");

        // for(i = 0; i < nsize; i++)
        // {
        //     for(j = 0; j < nsize; j++)
        //     {
        //         printf("%f  ", d22[i][j]);
        //     }
        //     printf("\n");
        // }

        // Smaller multiplications
        float **s1 = fmatrix(nsize, nsize);
        s1 = sub(d12, d22, nsize, s1);
        printf("nsize = %d\n", nsize);
        for(i = 0; i < nsize; i++)
        {
            for(j = 0; j < nsize; j++)
            {
                printf("%f  ", s1[i][j]);
            }
            printf("\n");
        }
        multiply(c11, s1, nsize, size, p1);
        free_fmatrix(s1, nsize, nsize);


        float **s2 = fmatrix(nsize, nsize);
        s2 = add(c11, c12, nsize, s2);
        multiply(s2, d22, nsize, size, p2);
        free_fmatrix(s2, nsize, nsize);

        float **s3 = fmatrix(nsize, nsize);
        s3 = add(c21, c22, nsize, s3);
        multiply(s3, d11, nsize, size, p3);
        free_fmatrix(s3, nsize, nsize);

        float **s4 = fmatrix(nsize, nsize);
        s4 = sub(d21, d11, nsize, s4);
        multiply(c22, s4, nsize, size, p4);
        free_fmatrix(s4, nsize, nsize);

        float **s5 = fmatrix(nsize, nsize);
        float **s6 = fmatrix(nsize, nsize);
        s5 = add(c11, c22, nsize, s5);
        s6 = add(d11, d22, nsize, s6);
        multiply(s5, s5, nsize, size, p5);
        free_fmatrix(s5, nsize, nsize);
        free_fmatrix(s5, nsize, nsize);

        printf("yay");

        float **s7 = fmatrix(nsize, nsize);
        float **s8 = fmatrix(nsize, nsize);
        s7 = sub(c12, c22, nsize, s7);
        s8 = add(d21, d22, nsize, s8);
        multiply(s7, s8, nsize, size, p6);
        free_fmatrix(s7, nsize, nsize);
        free_fmatrix(s8, nsize, nsize);

        float **s9 = fmatrix(nsize, nsize);
        float **s10 = fmatrix(nsize, nsize);
        s9 = sub(c11, c21, nsize, s9);
        s10 = add(d11, d12, nsize, s10);
        multiply(s9, s10, nsize, size, p7);
        free_fmatrix(s9, nsize, nsize);
        free_fmatrix(s10, nsize, nsize);

        printf("yay1\n");

        // Few temporary matrices
        float **t1 = fmatrix(nsize, nsize);
        printf("yay2\n");
        float **t2 = fmatrix(nsize, nsize);
        printf("yay3\n");
        float **t3 = fmatrix(nsize, nsize);
        printf("yay4\n");
        float **t4 = fmatrix(nsize, nsize);
        printf("yay5\n");
        float **t5 = fmatrix(nsize, nsize);
        printf("yay6\n");
        float **t6 = fmatrix(nsize, nsize);

        printf("yay7\n");

        // Calculating final divisions of result matrices
        t1 = add(p5, p4, nsize, t1);
        t2 = sub(p2, p6, nsize, t2);
        t3 = sub(t1, t2, nsize, t3); // New11

        t4 = add(p1, p2, nsize, t4); // New12

        t5 = add(p3, p4, nsize, t5); // New21

        t1 = add(p5, p1, nsize, t1);
        t2 = add(p3, p7, nsize, t2);
        t6 = sub(t4, t5, nsize, t6); // New22

        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                if(i >= 0 && i < nsize && j >= 0 && j < nsize)
                {
                    new[i][j] = t3[i][j];
                }
                else if(i >= 0 && i < nsize && j >= nsize && j < size)
                {
                    new[i][j] = t4[i][j];
                }
                else if(i >= nsize && i < size && j >= 0 && j < nsize)
                {
                    new[i][j] = t5[i][j];
                }
                else if(i >= nsize && i < size && j >= nsize && j < size)
                {
                    new[i][j] = t6[i][j];
                }
                printf("%d %d %f\n", i, j, new[i][j]);
            }
        }

        free_fmatrix(p1, nsize, nsize);
        free_fmatrix(p2, nsize, nsize);
        free_fmatrix(p3, nsize, nsize);
        free_fmatrix(p4, nsize, nsize);
        free_fmatrix(p5, nsize, nsize);
        free_fmatrix(p6, nsize, nsize);
        free_fmatrix(p7, nsize, nsize);
        free_fmatrix(t1, nsize, nsize);
        free_fmatrix(t2, nsize, nsize);
        free_fmatrix(t3, nsize, nsize);
        free_fmatrix(t4, nsize, nsize);
        free_fmatrix(t5, nsize, nsize);
        free_fmatrix(t6, nsize, nsize);
        free_fmatrix(c11, nsize, nsize);
        free_fmatrix(c12, nsize, nsize);
        free_fmatrix(c21, nsize, nsize);
        free_fmatrix(c22, nsize, nsize);
        free_fmatrix(d11, nsize, nsize);
        free_fmatrix(d12, nsize, nsize);
        free_fmatrix(d21, nsize, nsize);
        free_fmatrix(d22, nsize, nsize);
        printf("yay");

    }
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