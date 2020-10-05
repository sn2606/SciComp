// Gauss Jordan Elimination with full pivoting

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "utility.h"

void swap(float *a, float *b)
{
    float temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}

void gauss_jordan(float **A, int n, float **b, int m)
/*
    A is the input coefficient matrix (n x n)
    b is the matrix of m right hand vectors (n x m)
    On output, A is replaced with its matrix inverse,
    b is replaced with corresponding set of solution vectors
*/
{
    int *indc, *indr, *piv;
    int i, col, row, j, k, l, p;
    float big, bt, pivinv, temp;

    indc = ivector(n);
    indr = ivector(n);
    piv  = ivector(n);

    for(i = 0; i < n; i++)
    {
        *(piv + i) = 0;
    }

    for(i = 0; i < n; i++)
    {
        big = 0.0;
        for(j = 0; j < n; j++)
        {
            if (piv[j] != 1)
				for (k = 0; k <= n; k++) 
                {
					if (piv[k] == 0) 
                    {
						if (fabs(A[j][k]) >= big) 
                        {
							big = fabs(A[j][k]);
							row = j;
							col = k;
						}
					}
				}
        }

		piv[col]++;


		if (row != col) 
        {
			for (l = 0; l < n; l++)
            {
                swap( &A[row][l], &A[col][l]);
            }

			for (l = 0; l < m; l++)
            { 
                swap( &b[row][l], &b[col][l]);
            }
		}


		indr[i] = row;
		indc[i] = col;

		if ( A[col][col] == 0.0) 
            printf("gaussj: Singular Matrix");
        
		pivinv = 1.0 / A[col][col];
		A[col][col] = 1.0;

		for (l = 0; l < n; l++)
        {
            A[col][l] *= pivinv;
        }

		for (l = 0; l < n; l++) 
        {
            b[col][l] *= pivinv;
        }

		for (p = 0; p < n; p++)
        {
			if (p != col)
            {
				bt = A[p][col];
				A[p][col] = 0.0;
				for (l = 0; l < n; l++) 
                {
                    A[p][l] -= A[col][l] * bt;
                }
				for (l = 0; l < m; l++) 
                {
                    b[p][l] -= b[col][l] * bt;
                }
			}
        }
	}

	for (l = n - 1; l >= 0; l--)
    {
		if (indr[l] != indc[l])
        {
			for (k = 0; k < n; k++)
            {
				swap( &A[k][indr[l]], &A[k][indc[l]]);
            }
        }
	}
	
    free_ivector(piv);
	free_ivector(indr);
	free_ivector(indc);
}

int main()
{
    int i; 
    float **A; 
    float **b;

    // A = (float **)malloc(3 * sizeof(float *));

    // for(i = 0; i < 3; i++)
    //     *(A + i) = (float *)malloc(3 * sizeof(float));

    // b = (float **)malloc(3 * sizeof(float *));

    // for(i = 0; i < 3; i++)
    //     *(b + i) = (float *)malloc(sizeof(float));

    A = fmatrix(3, 3);
    b = fmatrix(3, 1);


    *(*(A + 0) + 0) = 10.0;
    *(*(A + 0) + 1) = -7.0;
    *(*(A + 0) + 2) = 5.0;
    *(*(A + 1) + 0) = 3.0;
    *(*(A + 1) + 1) = 6.0;
    *(*(A + 1) + 2) = 0.0;
    *(*(A + 2) + 0) = 9.0;
    *(*(A + 2) + 1) = 3.0;
    *(*(A + 2) + 2) = -2.0;

    // for(i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 3; j++)
    //         scanf("%f", *(A + i) + j);

    //     // printf("\n");
    // }

    b[0][0] = 9.0;
    b[1][0] = -9.0;
    b[2][0] = -1.0;
    
    // for(i = 0; i < 3; i++)
    // {
    //     scanf("%f", &b[i][0]);
    // }

    // for(i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 3; j++)
    //         printf("%f  ", *(*(A + i) + j));

    //     printf("\n");
    // }

    // for(i = 0; i < 3; i++)
    // {
    //     printf("%f  ", b[i][0]);
    // }

    gauss_jordan(A, 3, b, 1);

    for(i = 0; i < 3; i++)
    {
        printf("%f  ", b[i][0]);
    }
}