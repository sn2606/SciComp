# ifndef _MATRIX_H_
# define _MATRIX_H_

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

# endif