# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "utility.h"
# define TINY 1.0e-20

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

void ludcmp(float **A, int n)
{
	int i, j, k;
	float sum = 0;

    for(i = 1; i < n; i++)
    {
        A[0][i] = A[0][i] / A[0][0];
    }

	for (j = 0; j < n; j++) 
    {
		for (i = j; i < n; i++) 
        {
			sum = 0;
			for (k = 0; k < j; k++) 
            {
				sum = sum + A[i][k] * A[k][j];	
			}
			A[i][j] = A[i][j] - sum;
		}

		for (i = j; i < n; i++)
        {
			sum = 0;
			for(k = 0; k < j; k++)
            {
				sum = sum + A[j][k] * A[k][i];
			}
			if (A[j][j] == 0)
            {
				scierror("det(L) close to 0!\n Can't divide by 0...\n");
				exit(EXIT_FAILURE);
			}
			A[j][i] = (A[j][i] - sum);// / A[j][j];
		}
	}



	// for (j = 0; j < n; j++)
    // {
		
    //     if(j >= 1)
    //         a[j][0] = a[j][0] / a[0][0];

    //     for (i = j + 1; i < n; i++)
    //     {
	// 		sum = a[j][i];

	// 		for (k = 0; k < j; k++)
	// 			sum -= a[j][k] * a[k][i];
            
	// 		a[j][i] = sum;
    //     }

    //     for (i = 0; i <= j; i++)
    //     {
	// 		sum = a[j][i];

	// 		for (k = 0; k < i; k++)
    //             sum -= a[j][k]*a[k][i];

    //         a[j][i] = sum;// / a[i][j];
    //     }
	// }
}

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

int main()
{
    float *d = fvector(1);
    int i, j, n = 3;
    int *index = ivector(n);
    float **A;

    for(i = 0; i < n; i++)
    {
        index[i] = i;
    }


    A = fmatrix(n, n);

    float *b = fvector(n);


    *(*(A + 0) + 0) = 1.0;//10.0;
    *(*(A + 0) + 1) = 1.0;//-7.0;
    *(*(A + 0) + 2) = 1.0;//5.0;
    *(*(A + 1) + 0) = 4.0;//3.0;
    *(*(A + 1) + 1) = 3.0;//6.0;
    *(*(A + 1) + 2) = -1.0;//0.0;
    *(*(A + 2) + 0) = 3.0;//9.0;
    *(*(A + 2) + 1) = 5.0;//3.0;
    *(*(A + 2) + 2) = 3.0;//-2.0;

    b[0] = 1.0;//9.0;
    b[1] = 6.0;//-9.0;
    b[2] = 4.0;//-1.0;

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

    // ludcmp(A, n);

    // for(i = 0; i < n; i++)
    // {
    //     for(j = 0; j < n; j++)
    //     {
    //         printf("%f  ", A[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    solveCrout(n, b, L, U);

    for(i = 0; i < n; i++)
        printf("%f  ", b[i]);

    printf("\n\n");   

}