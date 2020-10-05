// Timing the matrix multiplications

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "utility.h"
# include "multiplication_int.h"


int main()
{
    int i, j, inp = 0, size;
    double **time_mat = dmatrix(1, 3);//dmatrix(8, 3);
    time_t start_naive, end_naive, start_cache, end_cache, start_strassen, end_strassen;
    double  time_naive, time_cache, time_strassen;
    int dimA[2], dimB[2];
    
    /*******************************
     * TIMING 2048 x 2048 matrices *
     * ****************************/

    FILE *fp1, *fp2;

    size = 2048;
    int **A = imatrix(size, size);
    int **B = imatrix(size, size);
    int **C = imatrix(size, size);

    dimA[0] = dimA[1] = dimB[0] = dimB[1] = size;

    fp1 = fopen("2048x2048_1.txt", "r");
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
                if (!fscanf(fp1, "%d", *(A + i) + j)) 
                    break;
            }
        }
    }
    fclose(fp1);

    fp2 = fopen("2048x2048_2.txt", "r");
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
                if (!fscanf(fp2, "%d", *(B + i) + j)) 
                    break;
            }
        }
    }
    fclose(fp2);

    start_naive = clock();
    C = matrix_multiplication_naive_int(A, B, dimA, dimB);
    end_naive   = clock();

    time_naive  = ((double) (end_naive - start_naive))/CLOCKS_PER_SEC;

    time_mat[inp][0] = time_naive;    

    start_cache = clock();
    C = matrix_multiplication_co_int(A, B, dimA, dimB);
    end_cache   = clock();

    time_cache  = ((double) (end_cache - start_cache))/CLOCKS_PER_SEC;

    time_mat[inp][1] = time_cache;

    start_strassen = clock();
    strassen_multiply_int(A, B, size, size, C);
    end_strassen   = clock();

    time_strassen  = ((double)(end_strassen - start_strassen)) / CLOCKS_PER_SEC;

    time_mat[inp][2] = time_strassen;

    free_imatrix(A, size, size);
    free_imatrix(B, size, size);
    free_imatrix(C, size, size);


    printf("%lf %lf %lf", time_mat[0][0], time_mat[0][1], time_mat[0][2]);

    FILE *fptr;

    fptr = fopen("mul_op_ncs.csv", "a+");

    //fprintf(fptr, "Naive,CacheOpt\n");

    fprintf(fptr, "%lf,%lf,%lf\n", time_mat[0][0], time_mat[0][1], time_mat[0][2]);

    fclose(fptr);
    
    return 0;
}