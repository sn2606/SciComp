# include <stdio.h>
# include <stdlib.h>
# include "utility.h"


void doolittle(float **A, float **L, float **U, int n)
{
	int i, j, k;
	double sum = 0;

	for (i = 0; i < n; i++) 
    {
		L[i][i] = 1;
        U[0][i] = A[0][i];
	}

    for(i = 1; i < n; i++)
    {
        L[i][0] = A[i][0] / A[0][0];
    }

	for (i = 0; i < n; i++) 
    {
		
        for(j = i; j < n; j++)
        {
            sum = 0;
            for(k = 0; k < i; k++)
            {
                sum = sum + L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }                                   
        
        for (j = i; j < n; j++) 
        {
			sum = 0;
			for (k = 0; k < i; k++) 
            {
				sum = sum + L[j][k] * U[k][i];	
			}
            if (U[i][i] == 0)
            {
				scierror("det(L) close to 0!\n Can't divide by 0...\n");
				exit(EXIT_FAILURE);
			}
			L[j][i] = (A[j][i] - sum) / U[i][i];
		}
	}
}

void solveDoolittle(int n, float *b, float **L, float **U)
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
        b[i] = sum;// / L[i][i];     
	}
    

	for (i = n - 1; i >= 0; i--) 
    {
		sum = b[i];

		for(j = i + 1; j < n; j++)
        { 
            sum -= U[i][j]*b[j];
        }
		b[i] = sum / U[i][i];
	}
}

int main()
{
    int i, j, n = 3;
    float **A;

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

    doolittle(A, L, U, n);

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

    solveDoolittle(n, b, L, U);

    for(i = 0; i < n; i++)
        printf("%f  ", b[i]);

    printf("\n\n");   

}

// // Doolittle uses unit diagonals for the lower triangle
// void Doolittle(int d,double*S,double*D){
//    for(int k=0;k<d;++k)
//    {
//       for(int j=k;j<d;++j){
//          double sum=0.;
//          for(int p=0;p<k;++p)sum+=D[k*d+p]*D[p*d+j];
//          D[k*d+j]=(S[k*d+j]-sum); // not dividing by diagonals
//       }
//       for(int i=k+1;i<d;++i){
//          double sum=0.;
//          for(int p=0;p<k;++p)sum+=D[i*d+p]*D[p*d+k];
//          D[i*d+k]=(S[i*d+k]-sum)/D[k*d+k];
//       }
//    }
// }
// void solveDoolittle(int d,double*LU,double*b,double*x){
//    double y[d];
//    for(int i=0;i<d;++i){
//       double sum=0.;
//       for(int k=0;k<i;++k)sum+=LU[i*d+k]*y[k];
//       y[i]=(b[i]-sum); // not dividing by diagonals
//    }
//    for(int i=d-1;i>=0;--i){
//       double sum=0.;
//       for(int k=i+1;k<d;++k)sum+=LU[i*d+k]*x[k];
//       x[i]=(y[i]-sum)/LU[i*d+i];
//    }
// }