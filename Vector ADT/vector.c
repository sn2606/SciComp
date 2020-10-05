# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <stddef.h>

// Function to show desired errors
void scierror(char *error_text)
{
    fprintf(stderr, "SciComp utility error : %s\n", error_text);
    exit(-1);
}

// Function to create a float vector
float *fvector(long n)
{
    float *v;
    v = (float *)malloc(n * sizeof(float));

    if(!v)
    {
       scierror("Memory allocation failure.");
    }
    return v;
}

// Function to create an int vector
int *ivector(long n)
{
    int *v;
    v = (int *)malloc(n * sizeof(int));

    if(!v)
    {
       scierror("Memory allocation failure.");
    }
    return v;
}

// Function to create a char vector
char *cvector(long n)
{
    char *v;
    v = (char *)malloc(n * sizeof(char));

    if(!v)
    {
       scierror("Memory allocation failure.");
    }
    return v;
}

// Function to create a double vector
double *dvector(long n)
{
    double *v;
    v = (double *)malloc(n * sizeof(double));

    if(!v)
    {
       scierror("Memory allocation failure.");
    }
    return v;
}

// Function to create a unsigned long vector
unsigned long *ulvector(long n)
{
    unsigned long *v;
    v = (unsigned long *)malloc(n * sizeof(unsigned long));

    if(!v)
    {
       scierror("Memory allocation failure.");
    }
    return v;
}

// Function to free float vector
void free_fvector(float *f)
{
    free(f);
    if(!f)
    {
        scierror("Free memory operation failed.");
    }
}

// Function to free int vector
void free_ivector(int *f)
{
    free(f);
    if(!f)
    {
        scierror("Free memory operation failed.");
    }
}

// Function to free char vector
void free_cvector(char *f)
{
    free(f);
    if(!f)
    {
        scierror("Free memory operation failed.");
    }
}

// Function to free double vector
void free_dvector(double *f)
{
    free(f);
    if(!f)
    {
        scierror("Free memory operation failed.");
    }
}

// Function to free unsigned long vector
void free_ulvector(unsigned long *f)
{
    free(f);
    if(!f)
    {
        scierror("Free memory operation failed.");
    }
}