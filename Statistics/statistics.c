# include <stdlib.h>
# include <math.h>
# include "utility.h"
# include "statistics.h"

// Function to carry out lagrange interpolation
double lagrange_interpolation(double *x, double *y, double xi, int n) 
{ 
	double yi = 0, sigma = 1, t; // Initialize yi 
    int i, j;

	for (i = 0; i < n; i++) 
	{
		sigma = y[i];

		for (j = 0; j < n; j++) 
		{ 
			if (j != i)
            {
				sigma = sigma * ((xi - x[j])/(x[i] - x[j]));
            }
		} 

		yi += sigma; 
	}

	return yi; 
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

// Function to find few moments
void moment_min(float data[], int n, float *ave, float *sdev)
{
	int j;
	float ep = 0.0, s;
    float *adev = (float *)malloc(sizeof(float));
    float *var = (float *)malloc(sizeof(float));

	if (n <= 1)
    {
        perror("n must be at least 2 in moment_min");
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

// Function to find karl-pearson correlation
float pearson_correlation(float *x, float *y, int n)
{
    float *xmean = (float *)malloc(sizeof(float));
    float *ymean = (float *)malloc(sizeof(float));
    float *xsdev = (float *)malloc(sizeof(float));
    float *ysdev = (float *)malloc(sizeof(float));

    int i;
    float num, denom, corr;

    moment_min(x, n, xmean, xsdev);
    moment_min(y, n, ymean, ysdev);

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

// Function to find correlation matrix
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

// Function to find moments of distribution
void moment(float data[], int n, float *ave, float *adev, float *sdev,	float *var, float *skew, float *Kurt)
{
	int j;
	float ep = 0.0, s, p;

	if (n <= 1) 
        scierror("n must be at least 2 in moment");
	
    s = 0.0;
	for (j = 0; j < n; j++)
        s += data[j];
	
    *ave = s / n;
	*adev = (*var) = (*skew) = (*Kurt) = 0.0;
	
	//printf("\n%f\n", ave);

    for (j = 0; j < n; j++)
    {
		*adev += fabs(s = data[j] - (*ave));
		ep += s;
		*var += (p = s*s);
		*skew += (p *= s);
		*Kurt += (p *= s);
	}

	*adev /= n;
	*var = (*var - ep*ep/n) / (n-1);
	*sdev = sqrt(*var);

	if (*var)
    {
		*skew /= (n * (*var) * (*sdev));
		*Kurt = (*Kurt) / (n * (*var) * (*var)) - 3.0;
	} 
    else 
	{
        scierror("No skew/kurtosis when variance = 0 (in moment)");
	}
}