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
    if(size == 1)
    {   
        new[0][0] = c[0][0] *d[0][0];   
    }

    else 
    {
        int i,j;
        int nsize =size/2;

        int **c11 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            c11[i]= malloc(nsize*sizeof(int));
        }

        int **c12 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            c12[i]= malloc(nsize * sizeof(int));
        }

        int **c21 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            c21[i]= malloc(nsize * sizeof(int));
        }

        int **c22 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++){
            c22[i]= malloc(nsize*sizeof(int));
        }

        int **d11 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            d11[i]= malloc(nsize*sizeof(int));
        }

        int **d12 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++){
            d12[i]= malloc(nsize*sizeof(int));
        }

        int **d21 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            d21[i]= malloc(nsize*sizeof(int));
        }

        int **d22 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            d22[i]= malloc(nsize*sizeof(int));
        }

        int **m1 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            m1[i]= malloc(nsize*sizeof(int));
        }

        int **m2 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            m2[i]= malloc(nsize*sizeof(int));
        }

        int **m3 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            m3[i]= malloc(nsize*sizeof(int));
        }

        int **m4 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            m4[i] = malloc(nsize*sizeof(int));
        }

        int **m5 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            m5[i]= malloc(nsize*sizeof(int));
        }

        int **m6 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++){
            m6[i]= malloc(nsize*sizeof(int));
        }

        int **m7 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++){
            m7[i]= malloc(nsize * sizeof(int));
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

        int **temp1 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            temp1[i]= malloc(nsize*sizeof(int));
        }

        int **temp2 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            temp2[i] = malloc(nsize*sizeof(int));
        }
       
        add_matrices(c11,c22,nsize,temp1);
        add_matrices(d11,d22,nsize,temp2);
        strassen_multiply_int(temp1,temp2,nsize,size,m1);

        free_imatrix(temp1, nsize, nsize);
        free_imatrix(temp2, nsize, nsize);
       
        int **temp3 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            temp3[i]= malloc(nsize*sizeof(int));
        }       
        add_matrices(c21, c22, nsize, temp3);
        strassen_multiply_int(temp3, d11, nsize, size, m2);
        //free(temp3);
        free_imatrix(temp3, nsize, nsize);


        int **temp4 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            temp4[i]= malloc(nsize*sizeof(int));
        }
        subtract_matrices(d12,d22,nsize,temp4);
        strassen_multiply_int(c11,temp4,nsize,size,m3);
        // free(temp4);
        free_imatrix(temp4, nsize, nsize);

        int **temp5 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            temp5[i]= malloc(nsize*sizeof(int));
        }
        subtract_matrices(d21,d11,nsize,temp5);
        strassen_multiply_int(c22,temp5,nsize,size,m4);
        // free(temp5);
        free_imatrix(temp5, nsize, nsize);

        int **temp6 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            temp6[i]= malloc(nsize*sizeof(int));
        }
        add_matrices(c11,c12,nsize,temp6);
        strassen_multiply_int(temp6,d22,nsize,size,m5);
        // free(temp6);
        free_imatrix(temp6, nsize, nsize);

        int **temp7 = malloc(nsize * sizeof(int *));
        for(i=0;i<nsize;i++)
        {
            temp7[i]= malloc(nsize*sizeof(int));
        }

        int **temp8 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            temp8[i]= malloc(nsize*sizeof(int));
        }
        subtract_matrices(c21,c11,nsize,temp7);
        add_matrices(d11,d12,nsize,temp8);
        strassen_multiply_int(temp7,temp8,nsize,size,m6);
        // free(temp7);   
        // free(temp8);

        free_imatrix(temp7, nsize, nsize);
        free_imatrix(temp8, nsize, nsize);

        int **temp9 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            temp9[i]= malloc(nsize*sizeof(int));
        }

        int **temp10 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            temp10[i]= malloc(nsize*sizeof(int));
        }       
        subtract_matrices(c12,c22,nsize,temp9);
        add_matrices(d21,d22,nsize,temp10);
        strassen_multiply_int(temp9,temp10,nsize,size,m7);
        // free(temp9);
        // free(temp10);
        free_imatrix(temp9, nsize, nsize);
        free_imatrix(temp10, nsize, nsize);
       

        int **t1 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            t1[i]= malloc(nsize * sizeof(int));
        }

        int **t2 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            t2[i] = malloc(nsize*sizeof(int));
        }

        int **t3 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            t3[i] = malloc(nsize * sizeof(int));
        }

        int **t4 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            t4[i] = malloc(nsize * sizeof(int));
        }

        int **t5 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            t5[i] = malloc(nsize * sizeof(int));
        }

        int **t6 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            t6[i]= malloc(nsize * sizeof(int));
        }

        int **t7 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            t7[i] = malloc(nsize * sizeof(int));
        }

        int **t8 = malloc(nsize * sizeof(int *));
        for(i = 0; i < nsize; i++)
        {
            t8[i] = malloc(nsize * sizeof(int));
        }

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

    free_imatrix(m1, nsize, nsize);
    free_imatrix(m2, nsize, nsize);   
    free_imatrix(m3, nsize, nsize);   
    free_imatrix(m4, nsize, nsize);   
    free_imatrix(m5, nsize, nsize);   
    free_imatrix(m6, nsize, nsize);   
    free_imatrix(m7, nsize, nsize);   
    free_imatrix(t1, nsize, nsize);
    free_imatrix(t2, nsize, nsize);   
    free_imatrix(t3, nsize, nsize);   
    free_imatrix(t4, nsize, nsize);   
    free_imatrix(t5, nsize, nsize);   
    free_imatrix(t6, nsize, nsize);   
    free_imatrix(t7, nsize, nsize);   
    free_imatrix(t8, nsize, nsize);   
    free_imatrix(c11, nsize, nsize);
    free_imatrix(c12, nsize, nsize);   
    free_imatrix(c21, nsize, nsize);   
    free_imatrix(c22, nsize, nsize);   
    free_imatrix(d11, nsize, nsize);
    free_imatrix(d12, nsize, nsize);   
    free_imatrix(d21, nsize, nsize);   
    free_imatrix(d22, nsize, nsize);

    }   
}