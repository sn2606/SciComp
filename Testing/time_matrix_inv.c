# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "utility.h"
# include "inversion.h"

int main()
{
    int i, j, inp = 0, size;
    double **time_mat = dmatrix(1, 3);//dmatrix(8, 3);
    time_t start_gj, end_gj, start_lud, end_lud, start_m, end_m;
    float  time_gj, time_lud;
    double time_m;
    
    /******************************
     *  TIMING 1000 x 1000 matrix *
     * ***************************/

    FILE *fp8;

    size = 1000;
    float **A1000 = fmatrix(size, size);
    float **inv1000 = fmatrix(size, size);
    float **L1000 = fmatrix(size, size);
    float **U1000 = fmatrix(size, size);

    fp8 = fopen("1000x1000.txt", "r");
    if(fp8 == NULL)
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
                if (!fscanf(fp8, "%f", *(A1000 + i) + j)) 
                    break;
            }
        }
    }
    fclose(fp8);

    //inp = 8;

    start_gj = clock();
    inverseGJ(A1000, size);
    end_gj   = clock();

    time_gj  = ((double) (end_gj - start_gj))/CLOCKS_PER_SEC;

    time_mat[inp][0] = time_gj;    

    start_lud = clock();
    inv1000 = inverseLUDC(L1000, U1000, A1000, inv1000, size);
    end_lud   = clock();

    time_lud  = ((double) (end_lud - start_lud))/CLOCKS_PER_SEC;

    time_mat[inp][1] = time_lud;    

    start_m = clock();
    inverseMat(A1000, size);
    end_m   = clock();

    time_m  = ((double) (end_m - start_m))/CLOCKS_PER_SEC;

    time_mat[inp][2] = time_m;

    free_fmatrix(A1000, size, size);
    free_fmatrix(inv1000, size, size);
    free_fmatrix(L1000, size, size);
    free_fmatrix(U1000, size, size);


    printf("%lf %lf %lf", time_mat[0][0], time_mat[0][1], time_mat[0][2]);

    FILE *fptr;

    fptr = fopen("inv_op.csv", "a+");

    //fprintf(fptr, "GJ, LUD, M\n");

    fprintf(fptr, "%lf, %lf, %lf\n", time_mat[0][0], time_mat[0][1], time_mat[0][2]);
    
    
    return 0;
}
