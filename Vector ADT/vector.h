# ifndef _VECTOR_H_
# define _VECTOR_H_

extern void scierror(char *error_text);
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