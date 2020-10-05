# ifndef __INVERSION__
# define __INVERSION__

extern void swap(float *a, float *b);
extern void inverseGJ(float **A, int n);
extern void crout(float **A, float **L, float **U, int n);
extern void solveCrout(int n, float *b, float **L, float **U);
extern float ** transpose(float **b, int m, int n);
extern float **inverseLUDC(float **L, float **U, float **A, float **inv, int n);
extern void inverseMat(float **A, int size);

# endif