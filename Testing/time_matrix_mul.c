// Timing the matrix multiplications

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "utility.h"
# include "multiplication.h"


int main()
{
    int i, j, inp = 0, size;
    double **time_mat = dmatrix(1, 2);//dmatrix(8, 3);
    time_t start_naive, end_naive, start_cache, end_cache;
    double  time_naive, time_cache;
    int dimA[2], dimB[2];
    
    /*******************************
     * TIMING 1000 x 1000 matrices *
     * ****************************/

    FILE *fp1, *fp2;

    size = 1000;
    float **A = fmatrix(size, size);
    float **B = fmatrix(size, size);
    float **C;

    dimA[0] = dimA[1] = dimB[0] = dimB[1] = size;

    fp1 = fopen("1000x1000.txt", "r");
    if(fp1 == NULL)
    {
        printf("ERROR: No file to be read");
        exit(1);
    }
    else
    {
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                if (!fscanf(fp1, "%f", *(A + i) + j)) 
                    break;
            }
        }
    }
    fclose(fp1);

    fp2 = fopen("1000x1000_2.txt", "r");
    if(fp2 == NULL)
    {
        printf("ERROR: No file to be read");
        exit(1);
    }
    else
    {
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                if (!fscanf(fp2, "%f", *(B + i) + j)) 
                    break;
            }
        }
    }
    fclose(fp2);

    start_naive = clock();
    C = matrix_multiplication_naive(A, B, dimA, dimB);
    end_naive   = clock();

    time_naive  = ((double) (end_naive - start_naive))/CLOCKS_PER_SEC;

    time_mat[inp][0] = time_naive;    

    start_cache = clock();
    C = matrix_multiplication_co(A, B, dimA, dimB);
    end_cache   = clock();

    time_cache  = ((double) (end_cache - start_cache))/CLOCKS_PER_SEC;

    time_mat[inp][1] = time_cache;

    free_fmatrix(A, size, size);
    free_fmatrix(B, size, size);
    free_fmatrix(C, size, size);


    printf("%lf %lf", time_mat[0][0], time_mat[0][1]);

    FILE *fptr;

    fptr = fopen("mul_op_nc.csv", "a+");

    //fprintf(fptr, "Naive,CacheOpt\n");

    fprintf(fptr, "%lf,%lf\n", time_mat[0][0], time_mat[0][1]);

    fclose(fptr);
    
    return 0;
}