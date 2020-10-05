#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DIMENSION 4     // Dimension for the matrix to be defined

float determinant(float **matrix, int dimension);
float getAt(float **m, int i, int j);
void putAt(float **m, int i, int j, float value);
float **randomMatrix(int dimension);
float **copyMatrix(float **matrix, int dimension);
void deleteMatrix(float **matrix, int dimension);
void swapRows(float **m, int a, int b);

int main(){
    float **matrix;     // matrix is a pointer to pointer
    float det;
    
   // Generate, and initialise random matrix
    matrix = randomMatrix(DIMENSION);
    det = determinant(matrix, DIMENSION);
    
    printf("%f \n", det);   
    return 0;
}

float determinant(float **matrix, int dimension){
    int i, j, k, p, swapCount=0, determinantFactor=1;
    float a, ajj, result, value;
	int swapee = 0;		// used to indicate row to swap
    float **m = NULL;

    // Let us copy the matrix first
    m = copyMatrix(matrix, dimension);

    // First step: perform LU Decomposition using Doolittle's Method
    // This algorithm will return, in the same matrix, a lower unit triangular matrix
    // (i.e. diagonals one)
    // and an upper trangular matrix
    // https://vismor.com/documents/network_analysis/matrix_algorithms/S4.SS2.php

    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < i; j++)
        {
            ajj = getAt(m,j,j);

            // a number we are dividing by is zero.
            // we thus have to do a partial pivot
            if (ajj == 0){
                if (swapCount == dimension)
                {
                    // Seems like we have exhaused all swaps
                    return NAN;
                }

                // Let's find a swap row to swap
                result = -INFINITY;
                for (k = 0; k < dimension; k++)
                {
                    value = getAt(m, k, j);
                    if (value > result)
                    {
                        result = value;
                        swapee = k;
                    }
                }
				// Swap rows
				swapRows(m, j, swapee);              
                swapCount++;
                determinantFactor *= -1;

                ajj = getAt(m,j,j);
            }

            a = getAt(m, i, j);
            for (p = 0; p < j; p++)
            {
                a -= getAt(m, i, p) * getAt(m, p, j);
            }
            putAt(m, i, j, a/ajj);
        }
        for (j = i; j < dimension; j++)
        {
            a = getAt(m, i, j);
            for (p = 0; p < i; p++)
            {
                a -= getAt(m, i, p) * getAt(m, p, j);
            }
            putAt(m, i, j, a);
        }
    }

    // Second step is to find the determinant.
    // Because the lower triangle is a unit triangular matrix
    // the determinant is simply a product of all the upper triangle diagonal
    // which in this case is exactly the diagonal of m
    result = determinantFactor;
    for (i = 0; i < dimension; i++)
        result *= getAt(m, i, i);

    deleteMatrix(m, dimension);
	
    return result;
}

// Based on i and j, and a float pointer, get the value at row i column j
float getAt(float **m, int i, int j)
{
    return *(*(m + i) + j);
}

// Based on i and j, and a float pointer, put the value at row i column j
void putAt(float **m, int i, int j, float value)
{
    *( (*(m+i)) + j ) = value;
} 

// Generate a n by n matrix consisting of numbers between -1 and 1.
// Outputs in a Matlab format, good for checking in Matlab
float **randomMatrix(int dimension)
{
    int i, j;
    float **matrix;
    float *row;
    float no;

    // let's first initialise the ragged array
    // initialise Ragged Array
    matrix = (float **) malloc(dimension*sizeof(float *));

    // Seed random number generator
    srand(time(NULL));

    printf("[");
    for (i = 0; i < dimension; i++){
        // Initialise this row
        row = (float *) malloc(dimension*sizeof(float));
        *(matrix + i) = row;

        // random no between -1 and 1
        for (j = 0; j < dimension; j++){
            no = ((float) (rand()%20))/10-1;
             *(row + j) = no;
            printf("%f ", no);
        }
        printf(";\n");
    }
    printf("]\n");

    return matrix;
}

// copy matrix (ragged array)
float **copyMatrix(float **matrix, int dimension)
{
    int i;
    float **copy = (float **) malloc(dimension*sizeof(float *));

    for (i = 0; i < dimension; i++)
    {
        // allocate memory for row
        *(copy + i) = (float *) malloc(dimension*sizeof(float));
        // copy row
        memcpy( *(copy +i), *(matrix + i), sizeof(float)*dimension );
    }

    return copy;
}

// delete matrix
void deleteMatrix(float **matrix, int dimension)
{
    int i;
    for (i = 0; i <dimension; i++)
    {
        free( *(matrix+i));
    }
	free(matrix);
}

// swap rows -- ragged array. swap rows a and b
void swapRows(float **matrix, int a, int b)
{
	 float *swapRowTemp = *( matrix + a );
	 *( matrix + a ) = *( matrix + b );
	 *( matrix + b ) = swapRowTemp;
}