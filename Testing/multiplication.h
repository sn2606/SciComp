# ifndef __MULTIPLICATION__
# define __MULTIPLICATION__

extern float ** matrix_multiplication_naive(float **a, float **b, int *dimA, int *dimB);
extern float ** transpose(float **b, int m, int n);
extern float ** matrix_multiplication_co(float **a, float **b, int *dimA, int *dimB);

# endif