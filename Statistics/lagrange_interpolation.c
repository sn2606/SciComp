// C Program for Lagrange Interpolation

# include <stdio.h>
# include <stdlib.h>
# include "utility.h" 

double lagrange_interpolation(double *x, double *y, double xi, int n);

int main()
{
    
    double xi = 1.334;
    double yi = 0;
    int n = 100, i, j;
    double *x = dvector(n);
    double *y = dvector(n);

    FILE *fp;

    fp = fopen("100x2.txt", "r");
    if(fp == NULL)
    {
        scierror("No file to be read");
        exit(1);
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            fscanf(fp, "%lf ", x + i);
            fscanf(fp, "%lf\n", y + i);
            //printf(" %d    %lf %lf\n", i + 1, x[i], y[i]);
        }
    }
    fclose(fp);

    yi = lagrange_interpolation(x, y, xi, n);

    printf("xi = %lf\nyi = %lf\n", xi, yi);

    return 0;
} 

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