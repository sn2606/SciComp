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

void inverseGJ(float **A, int n)
/*
    A is the input coefficient matrix (n x n)
    On output, A is replaced with its matrix inverse,
*/
{
    int *indc, *indr, *piv;
    int i, col, row, j, k, l, p;
    float big, bt, pivinv;

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
		}


		indr[i] = row;
		indc[i] = col;

		if ( A[col][col] == 0.0) 
            scierror("gaussj: Singular Matrix");
        
		pivinv = 1.0 / A[col][col];
		A[col][col] = 1.0;

		for (l = 0; l < n; l++)
        {
            A[col][l] *= pivinv;
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
    int i, j, n = 3;
    float **A;

    A = fmatrix(n, n);


    *(*(A + 0) + 0) = 1.0;//10.0;
    *(*(A + 0) + 1) = 1.0;//-7.0;
    *(*(A + 0) + 2) = 1.0;//5.0;
    *(*(A + 1) + 0) = 4.0;//3.0;
    *(*(A + 1) + 1) = 3.0;//6.0;
    *(*(A + 1) + 2) = -1.0;//0.0;
    *(*(A + 2) + 0) = 3.0;//9.0;
    *(*(A + 2) + 1) = 5.0;//3.0;
    *(*(A + 2) + 2) = 3.0;//-2.0;

    // b[0] = 1.0;//9.0;
    // b[1] = 6.0;//-9.0;
    // b[2] = 4.0;//-1.0;

    inverseGJ(A, n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%f  ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    free_fmatrix(A, n, n);

    return 0;
}