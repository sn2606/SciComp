# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "utility.h"


// Function to swap two numbers
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
    FULL PIVOTING
*/
{
    int *indc, *indr, *piv;
    int i, col, row, j, k, l, p;
    float big, bt, pivinv;// temp;

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

        // printf("ayaygj\n");

		if (row != col) 
        {
			for (l = 0; l < n; l++)
            {
                swap( &(A[row][l]), &(A[col][l]));

                // temp = A[row][l];
                // A[row][l] = A[col][l];
                // A[col][l] = temp;
            }
		}

        //printf("ayaygj\n");

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

// LU Decomposition using Crout's algorithm
void crout(float **A, float **L, float **U, int n)
{
	int i, j, k;
	double sum = 0;

	for (i = 0; i < n; i++) 
    {
		U[i][i] = 1;
        L[i][0] = A[i][0];
	}

    for(i = 1; i < n; i++)
    {
        U[0][i] = A[0][i] / A[0][0];
    }

	for (j = 0; j < n; j++) 
    {
		for (i = j; i < n; i++) 
        {
			sum = 0;
			for (k = 0; k < j; k++) 
            {
				sum = sum + L[i][k] * U[k][j];	
			}
			L[i][j] = A[i][j] - sum;
		}

		for (i = j; i < n; i++)
        {
			sum = 0;
			for(k = 0; k < j; k++)
            {
				sum = sum + L[j][k] * U[k][i];
			}
			if (L[j][j] == 0)
            {
				scierror("det(L) close to 0!\n Can't divide by 0...\n");
				exit(EXIT_FAILURE);
			}
			U[j][i] = (A[j][i] - sum) / L[j][j];
		}
	}
}

// Function to solve equations
void solveCrout(int n, float *b, float **L, float **U)
{
	int i, j;
	float sum;

	for (i = 0; i < n; i++)
    {
        sum = b[i];
        
        for (j = 0; j < i; j++)
        { 
            sum -= L[i][j]*b[j];
        }
        b[i] = sum / L[i][i];     
	}

	for (i = n - 1; i >= 0; i--) 
    {
		sum = b[i];

		for(j = i + 1; j < n; j++)
        { 
            sum -= U[i][j]*b[j];
        }
		b[i] = sum;
	}
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

// Function to find inverse of the matrix
float **inverseLUDC(float **L, float **U, float **A, float **inv, int n)
{
    crout(A, L, U, n);

    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            inv[i][j] = 0;
        }

        inv[i][i] = 1.0;
    }

    for(i = 0; i < n; i++)
    {
        solveCrout(n, *(inv + i), L, U);
    }

    return transpose(inv, n, n);
}


// Optimal inversion method
void inverseMat(float **A, int size)
{
   float pivot; //det=1.0;
   int i, j, p;

   for(p = 0; p < size; p++)
   {
        pivot = A[p][p];
        //det = det * pivot;
        
        if (fabs(pivot) < 1e-5)
            return;

        
        // Elements of pivot comlumn
        for (i = 0; i < size; i++)
        {
            A[i][p] = -( A[i][p] / pivot );
        }

        for (i = 0; i < size; i++)
        {
            if (i != p)
            {
                for (j = 0; j < size; j++)
                {
                    if (j != p)
                    {
                        A[i][j] = A[i][j] + A[p][j] * A[i][p];
                    }
                }
            }
        }

        // Elements of pivot row
        for (j = 0; j < size; j++)
        {
            A[p][j] =  A[p][j]/ pivot;
        }

        A[p][p] = 1/ pivot;
    }
    //return det;
}


// void inverseGJ2(float **a, int SIZE)
// {
//         float x[SIZE], ratio;
// 		 int i,j,k,n;
// 		 clrscr();
// 		 /* Inputs */
// 		 /* 1. Reading order of matrix */
// 		 printf("Enter order of matrix: ");
// 		 scanf("%d", &n);
// 		 /* 2. Reading Matrix */
// 		 printf("Enter coefficients of Matrix:\n");
// 		 for(i=1;i<=n;i++)
// 		 {
// 			  for(j=1;j<=n;j++)
// 			  {
// 				   printf("a[%d][%d] = ",i,j);
// 				   scanf("%f", &a[i][j]);
// 			  }
// 		 }
// 		 /* Augmenting Identity Matrix of Order n */
// 		 for(i=1;i<=n;i++)
// 		 {
// 			  for(j=1;j<=n;j++)
// 			  {
// 				   if(i==j)
// 				   {
// 				    	a[i][j+n] = 1;
// 				   }
// 				   else
// 				   {
// 				    	a[i][j+n] = 0;
// 				   }
// 			  }
// 		 }
// 		 /* Applying Gauss Jordan Elimination */
// 		 for(i=1;i<=n;i++)
// 		 {
// 			  if(a[i][i] == 0.0)
// 			  {
// 				   printf("Mathematical Error!");
// 				   exit(0);
// 			  }
// 			  for(j=1;j<=n;j++)
// 			  {
// 				   if(i!=j)
// 				   {
// 					    ratio = a[j][i]/a[i][i];
// 					    for(k=1;k<=2*n;k++)
// 					    {
// 					     	a[j][k] = a[j][k] - ratio*a[i][k];
// 					    }
// 				   }
// 			  }
// 		 }
// 		 /* Row Operation to Make Principal Diagonal to 1 */
// 		 for(i=1;i<=n;i++)
// 		 {
// 			  for(j=n+1;j<=2*n;j++)
// 			  {
// 			   	a[i][j] = a[i][j]/a[i][i];
// 			  }
// 		 }
// 		//  /* Displaying Inverse Matrix */
// 		//  printf("\nInverse Matrix is:\n");
// 		//  for(i=1;i<=n;i++)
// 		//  {
// 		// 	  for(j=n+1;j<=2*n;j++)
// 		// 	  {
// 		// 	   	printf("%0.3f\t",a[i][j]);
// 		// 	  }
// 		// 	  printf("\n");
// 		//  }
// 		 getch();
// }