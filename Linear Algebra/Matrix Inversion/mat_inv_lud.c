# include <stdio.h>
# include <stdlib.h>
# include "utility.h"


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

    float **L = fmatrix(n, n);
    float **U = fmatrix(n, n);

    crout(A, L, U, n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%f  ", L[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%f  ", U[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    float **inv = fmatrix(n, n);

    inv = inverseLUDC(L, U, A, inv, n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%f  ", inv[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    free_fmatrix(A, n, n);
    free_fmatrix(L, n, n);
    free_fmatrix(U, n, n);
    free_fmatrix(inv, n, n);

    return 0;
}