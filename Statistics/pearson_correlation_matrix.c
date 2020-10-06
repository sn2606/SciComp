# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "utility.h"
# include "multiplication.h"

void moment(float data[], int n, float *ave, float *sdev)
{
	int j;
	float ep = 0.0, s;
    float *adev = (float *)malloc(sizeof(float));
    float *var = (float *)malloc(sizeof(float));

	if (n <= 1)
    {
        perror("n must be at least 2 in moment");
        exit(1);
    }
	
    s = 0.0;
	for (j = 0; j < n; j++)
        s += data[j];
	
    *ave = s / n;
	*adev = 0.0;
    *var  = 0.0;
	
    for (j = 0; j < n; j++)
    {
		s = data[j] - (*ave);
        *adev += fabs(s);
		ep += s;
		*var += s*s;
	}

	*adev /= n;
	*var = (*var - ep*ep/n) / (n-1);
	*sdev = sqrt(*var);
}


float pearson_correlation(float *x, float *y, int n)
{
    float *xmean = (float *)malloc(sizeof(float));
    float *ymean = (float *)malloc(sizeof(float));
    float *xsdev = (float *)malloc(sizeof(float));
    float *ysdev = (float *)malloc(sizeof(float));

    int i;
    float num, denom, corr;

    moment(x, n, xmean, xsdev);
    moment(y, n, ymean, ysdev);

    denom = (n - 1) *(*xsdev) * (*ysdev);

    float sigma = 0.0;

    for(i = 0; i < n; i++)
    {
        sigma += (x[i]) * (y[i]);
    }

    num = sigma - (n * (*xmean) * (*ymean));

    corr = num / denom;

    free(xmean);
    free(ymean);
    free(xsdev);
    free(ysdev);

    return corr;
}

float **pearson_correlation_matrix(float **A, int row, int col)
{
    int i, j;

    float **Corr_mat = fmatrix(col, col);
    float **B = fmatrix(col, row);

    B = transpose(A, row, col);

    for(i = 0; i < col; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(i == j)
            {
                Corr_mat[i][j] = 1.0;
            }
            else
            {
                Corr_mat[i][j] = pearson_correlation(B[i], B[j], row);
            }
            
        }
    }

    return Corr_mat;
}

int main()
{
    float x[] = {65.0, 66.0, 67.0, 67.0, 68.0, 69.0, 70.0, 72.0};
    float y[] = {67.0, 68.0, 65.0, 68.0, 72.0, 72.0, 69.0, 71.0};
    int n = 8;
    float corr = 100;

    corr = pearson_correlation(x, y, n);

    printf("%f\n", corr);

    int row = 100;
    int col = 5;
    int i, j;

    float **A        = fmatrix(row, col);
    float **corr_mat = fmatrix(col, col);

    FILE *fp;

    fp = fopen("100x5.txt", "r");

    if(fp == NULL)
    {
        scierror("No file to be read");
        exit(1);
    }
    else
    {
        for(i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                fscanf(fp, "%f", &A[i][j]);
            }
        }
    }
    fclose(fp);

    corr_mat = pearson_correlation_matrix(A, row, col);

    FILE *fp2;

    fp2 = fopen("100x5_corr_mat.txt", "w+");

    if(fp2 == NULL)
    {
        scierror("No file to be read");
        exit(1);
    }
    else
    {
        for(i = 0; i < col; i++)
        {
            for(j = 0; j < col; j++)
            {
                fprintf(fp2, "%f ", corr_mat[i][j]);
            }
            fprintf(fp2, "%c", '\n');
        }
        
    }
    fclose(fp2);

    for(i = 0; i < col; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%-2f\t", corr_mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}