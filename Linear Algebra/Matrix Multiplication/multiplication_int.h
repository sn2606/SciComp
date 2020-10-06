# ifndef __MULTIPLICATION_INT__
# define __MULTIPLICATION_INT__

extern int ** matrix_multiplication_naive_int(int **a, int **b, int *dimA, int *dimB);
extern int ** transpose_int(int **b, int m, int n);
extern int ** matrix_multiplication_co_int(int **a, int **b, int *dimA, int *dimB);
extern void add_matrices(int **a, int **b, int size, int **c);
extern void subtract_matrices(int **a, int **b, int size, int **c);
extern void  strassen_multiply_int(int **c, int **d, int size, int size2, int **new);

# endif