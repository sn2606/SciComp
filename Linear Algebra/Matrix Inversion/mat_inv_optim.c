// Ahmad, Farooq & Khan, Hamid. (2010). An Efficient and Simple Algorithm for Matrix Inversion. IJTD. 1. 20-27. 10.4018/jtd.2010010102. 
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "utility.h"


float inverseMat(float **MatB, int size)
{
   float pivot, det=1.0;
   int i, j, p;
   for(p = 0; p < size; p++)
   {
        pivot = MatB[p][p];
        det = det * pivot;
        
        if (fabs(pivot) < 1e-5)
            return 0;

        
        // Elements of pivot comlumn
        for (i = 0; i < size; i++)
        {
            MatB[i][p] = -( MatB[i][p] / pivot );
        }

        for (i = 0; i < size; i++)
        {
            if (i != p)
            {
                for (j = 0; j < size; j++)
                {
                    if (j != p)
                    {
                        MatB[i][j] = MatB[i][j] + MatB[p][j] * MatB[i][p];
                    }
                }
            }
        }

        // Elements of pivot row
        for (j = 0; j < size; j++)
        {
            MatB[p][j] =  MatB[p][j]/ pivot;
        }

        MatB[p][p] = 1/ pivot;
    }
    return det;
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

    float det = inverseMat(A, n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%f  ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("det = %f\n", det);

    free_fmatrix(A, n, n);

    return 0;
}