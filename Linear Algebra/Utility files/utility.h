# ifndef _UTILITY_H_
# define _UTILITY_H_

extern void scierror(char *error_text);
extern float **fmatrix(long row, long col);
extern int **imatrix(long row, long col);
extern char **cmatrix(long row, long col);
extern double **dmatrix(long row, long col);
extern unsigned long **ulmatrix(long row, long col);
extern void free_fmatrix(float **m, long row, long col);
extern void free_imatrix(int **m, long row, long col);
extern void free_cmatrix(char **m, long row, long col);
extern void free_dmatrix(double **m, long row, long col);
extern void free_ulmatrix(unsigned long **m, long row, long col);
extern float *fvector(long n);
extern int *ivector(long n);
extern char *cvector(long n);
extern double *dvector(long n);
extern unsigned long *ulvector(long n);
extern void free_fvector(float *f);
extern void free_ivector(int *f);
extern void free_cvector(char *f);
extern void free_dvector(double *f);
extern void free_ulvector(unsigned long *f);

# endif