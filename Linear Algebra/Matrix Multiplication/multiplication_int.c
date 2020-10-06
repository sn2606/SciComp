# include <stdio.h>
# include <stdlib.h>
# include "utility.h"


// Function to strassen_multiply_int the matrices
int ** matrix_multiplication_naive_int(int **a, int **b, int *dimA, int *dimB)
{
    int arow = dimA[0], acol = dimA[1];
    int brow = dimB[0], bcol = dimB[1];
    int **c  = imatrix(arow, bcol);
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
            c[i][j] = 0;
        }
    }

    // strassen_multiply_inting the matrices
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
int ** transpose_int(int **b, int m, int n)
{
    int **t = imatrix(n, m);
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


// Function to strassen_multiply_int the matrices
int ** matrix_multiplication_co_int(int **a, int **b, int *dimA, int *dimB)
{
    int arow = dimA[0], acol = dimA[1];
    int brow = dimB[0], bcol = dimB[1];
    int **c  = imatrix(arow, bcol);
    int i, j, k;
    int **t = imatrix(bcol, brow);

    if(acol != brow)
    {
        scierror("Invalid Input! Matrices cannot be multiplied\n");
        exit(0);
    }

    t = transpose_int(b, brow, bcol);

    // Initializing product matrix C
    for(i = 0; i < arow; i++)
    {
        for(j = 0; j < bcol; j++)
        {
            c[i][j] = 0;
        }
    }

    // strassen_multiply_inting the matrices
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

// Function to add two matrices
void add_matrices(int **a, int **b, int size, int **c)
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            c[i][j] = a[i][j] + b[i][j];   
        }
    }
}


// Function to subtract two matrices
void subtract_matrices(int **a, int **b, int size, int **c)
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}


// Function to multiply two matrices c and d by strassen algorithm
void strassen_multiply_int(int **c, int **d, int size, int size2, int **new)
{
    // if(size == 1)
    // {   
    //     new[0][0] = c[0][0] *d[0][0];   
    // }
    // Added cutoff point
    if(size == 512)
    {
        int dimA[] = {512, 512};
        int dimB[] = {512, 512};

        matrix_multiplication_co_int(c, d, dimA, dimB);
    }

    else 
    {
        int i,j;
        int nsize =size/2;

        int **c11 = malloc(nsize * sizeof(int *));
        int **c12 = malloc(nsize * sizeof(int *));
        int **c21 = malloc(nsize * sizeof(int *));
        int **c22 = malloc(nsize * sizeof(int *));
        int **d11 = malloc(nsize * sizeof(int *));
        int **d12 = malloc(nsize * sizeof(int *));
        int **d21 = malloc(nsize * sizeof(int *));
        int **d22 = malloc(nsize * sizeof(int *));
        int **m1 = malloc(nsize * sizeof(int *));
        int **m2 = malloc(nsize * sizeof(int *));
        int **m3 = malloc(nsize * sizeof(int *));
        int **m4 = malloc(nsize * sizeof(int *));
        int **m5 = malloc(nsize * sizeof(int *));
        int **m6 = malloc(nsize * sizeof(int *));
        int **m7 = malloc(nsize * sizeof(int *));
        int **temp1 = malloc(nsize * sizeof(int *));
        int **temp2 = malloc(nsize * sizeof(int *));
        int **temp3 = malloc(nsize * sizeof(int *));
        int **temp4 = malloc(nsize * sizeof(int *));
        int **temp5 = malloc(nsize * sizeof(int *));
        int **temp6 = malloc(nsize * sizeof(int *));
        int **temp7 = malloc(nsize * sizeof(int *));
        int **temp8 = malloc(nsize * sizeof(int *));
        int **temp9 = malloc(nsize * sizeof(int *));
        int **temp10 = malloc(nsize * sizeof(int *));
        int **t1 = malloc(nsize * sizeof(int *));
        int **t2 = malloc(nsize * sizeof(int *));
        int **t3 = malloc(nsize * sizeof(int *));
        int **t4 = malloc(nsize * sizeof(int *));
        int **t5 = malloc(nsize * sizeof(int *));
        int **t6 = malloc(nsize * sizeof(int *));
        int **t7 = malloc(nsize * sizeof(int *));
        int **t8 = malloc(nsize * sizeof(int *));

        for(i = 0; i < nsize; i++)
        {
            c11[i] = malloc(nsize * sizeof(int));
            c12[i] = malloc(nsize * sizeof(int));
            c21[i] = malloc(nsize * sizeof(int));
            c22[i] = malloc(nsize * sizeof(int));
            d11[i] = malloc(nsize * sizeof(int));
            d12[i] = malloc(nsize * sizeof(int));
            d21[i] = malloc(nsize * sizeof(int));
            d22[i] = malloc(nsize * sizeof(int));
            m1[i]  = malloc(nsize * sizeof(int));
            m2[i]  = malloc(nsize * sizeof(int));
            m3[i]  = malloc(nsize * sizeof(int));
            m4[i]  = malloc(nsize * sizeof(int));
            m5[i]  = malloc(nsize * sizeof(int));
            m6[i]  = malloc(nsize * sizeof(int));
            m7[i]  = malloc(nsize * sizeof(int));
            temp1[i] = malloc(nsize * sizeof(int));
            temp2[i] = malloc(nsize * sizeof(int));
            temp3[i] = malloc(nsize * sizeof(int));
            temp4[i] = malloc(nsize * sizeof(int));
            temp5[i] = malloc(nsize * sizeof(int));
            temp6[i] = malloc(nsize * sizeof(int));
            temp7[i] = malloc(nsize * sizeof(int));
            temp8[i] = malloc(nsize * sizeof(int));
            temp9[i] = malloc(nsize * sizeof(int));
            temp10[i] = malloc(nsize * sizeof(int));
            t1[i] = malloc(nsize * sizeof(int));
            t2[i] = malloc(nsize * sizeof(int));
            t3[i] = malloc(nsize * sizeof(int));
            t4[i] = malloc(nsize * sizeof(int));
            t5[i] = malloc(nsize * sizeof(int));
            t6[i] = malloc(nsize * sizeof(int));
            t7[i] = malloc(nsize * sizeof(int));
            t8[i] = malloc(nsize * sizeof(int));
           
        }

        for(i = 0; i < nsize; i++)
        {
            for(j = 0; j < nsize; j++) 
            {
                c11[i][j]=c[i][j];
                c12[i][j]=c[i][j+nsize];
                c21[i][j]=c[i+nsize][j];
                c22[i][j]=c[i+nsize][j+nsize]; 
                                  
                d11[i][j]=d[i][j];
                d12[i][j]=d[i][j+nsize];
                d21[i][j]=d[i+nsize][j];
                d22[i][j]=d[i+nsize][j+nsize];
            }
        }

       
        add_matrices(c11,c22,nsize,temp1);
        add_matrices(d11,d22,nsize,temp2);
        strassen_multiply_int(temp1,temp2,nsize,size,m1);

        add_matrices(c21, c22, nsize, temp3);
        strassen_multiply_int(temp3, d11, nsize, size, m2);

        subtract_matrices(d12,d22,nsize,temp4);
        strassen_multiply_int(c11,temp4,nsize,size,m3);

        subtract_matrices(d21,d11,nsize,temp5);
        strassen_multiply_int(c22,temp5,nsize,size,m4);

        add_matrices(c11,c12,nsize,temp6);
        strassen_multiply_int(temp6,d22,nsize,size,m5);

        subtract_matrices(c21,c11,nsize,temp7);
        add_matrices(d11,d12,nsize,temp8);
        strassen_multiply_int(temp7,temp8,nsize,size,m6);

        subtract_matrices(c12,c22,nsize,temp9);
        add_matrices(d21,d22,nsize,temp10);
        strassen_multiply_int(temp9,temp10,nsize,size,m7);

        add_matrices(m1,m7,nsize,t1);
        subtract_matrices(m4,m5,nsize,t2);
        add_matrices(t1,t2,nsize,t3);    //c11
           
        add_matrices(m3,m5,nsize,t4);//c12   
        add_matrices(m2,m4,nsize,t5);//c21
       
        add_matrices(m3,m6,nsize,t6);
        subtract_matrices(m1,m2,nsize,t7);
       
        add_matrices(t6,t7,nsize,t8);//c22
       
        int a = 0, b = 0, c = 0, d = 0, e = 0;

        int nsize2 = 2*nsize;

        for(i = 0; i < nsize2; i++)
        {
            for(j = 0; j < nsize2; j++)
            {
                if(j>=0 && j<nsize && i>=0 && i<nsize)
                {
                    new[i][j] = t3[i][j];
                }
                if(j>=nsize && j<nsize2 && i>=0 && i<nsize)
                {
                    a=j-nsize;
                    new[i][j] = t4[i][a];
                }
                if(j>=0 && j<nsize && i>= nsize && i < nsize2)
                {
                    c=i-nsize;
                    new[i][j] = t5[c][j];
                }
                if(j>=nsize && j< nsize2 && i>= nsize && i< nsize2 )
                {
                    d=i-nsize;
                    e=j-nsize;
                    new[i][j] =t8[d][e];
                }
            }   
        }


    for(i = 0; i < nsize; i++)
    {
        free(temp1[i]);
        free(temp2[i]);
        free(temp3[i]);
        free(temp4[i]);
        free(temp5[i]);
        free(temp6[i]);
        free(temp7[i]);
        free(temp8[i]);
        free(temp9[i]);
        free(temp10[i]);        
        free(m1[i]);
        free(m2[i]);
        free(m3[i]);
        free(m4[i]);
        free(m5[i]);
        free(m6[i]);
        free(m7[i]);
        free(t1[i]);
        free(t2[i]);
        free(t3[i]);
        free(t4[i]);
        free(t5[i]);
        free(t6[i]);
        free(t7[i]);
        free(t8[i]);
        free(c11[i]);
        free(c12[i]);   
        free(c21[i]);   
        free(c22[i]);   
        free(d11[i]);
        free(d12[i]);   
        free(d21[i]);   
        free(d22[i]);
    }

    free(temp1);
    free(temp2);
    free(temp3);
    free(temp4);
    free(temp5);
    free(temp6);
    free(temp7);
    free(temp8);
    free(temp9);
    free(temp10);
    free(m1);
    free(m2);   
    free(m3);   
    free(m4);   
    free(m5);   
    free(m6);   
    free(m7);   
    free(t1);
    free(t2);   
    free(t3);   
    free(t4);   
    free(t6);   
    free(t8);   
    free(c11);
    free(c12);   
    free(c21);   
    free(c22);   
    free(d11);
    free(d12);   
    free(d21);   
    free(d22);

    }   
}