# ifndef __STATISTICS__
# define __STATISTICS__

extern double lagrange_interpolation(double *x, double *y, double xi, int n);
extern float ** transpose(float **b, int m, int n);
extern void moment_min(float data[], int n, float *ave, float *sdev);
extern float pearson_correlation(float *x, float *y, int n);
extern float **pearson_correlation_matrix(float **A, int row, int col);
extern void moment(float data[], int n, float *ave, float *adev, float *sdev,	float *var, float *skew, float *Kurt);

# endif
