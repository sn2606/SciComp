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

// Function to create a float matrix
float **fmatrix(long row, long col)
{
    float **m;
    int i;
    m = (float **)malloc(row * sizeof(float *));
    if(!m)
        scierror("Memory allocation failed.");

    for(i = 0; i < row; i++)
    {
        m[i] = (float *)malloc(col * sizeof(float));
        if(!(m[i]))
            scierror("Memory allocation failed.");
    }

    return m;
}

// Function to create an integer matrix
int **imatrix(long row, long col)
{
    int **m, i;
    m = (int **)malloc(row * sizeof(int *));
    if(!m)
        scierror("Memory allocation failed.");

    for(i = 0; i < row; i++)
    {
        m[i] = (int *)malloc(col * sizeof(int));
        if(!(m[i]))
            scierror("Memory allocation failed.");
    }

    return m;
}

// Function to create a character matrix
char **cmatrix(long row, long col)
{
    char **m;
    int i;
    m = (char **)malloc(row * sizeof(char *));
    if(!m)
        scierror("Memory allocation failed.");

    for(i = 0; i < row; i++)
    {
        m[i] = (char *)malloc(col * sizeof(char));
        if(!(m[i]))
            scierror("Memory allocation failed.");
    }

    return m;
}

// Function to create a double matrix
double **dmatrix(long row, long col)
{
    double **m;
    int i;
    m = (double **)malloc(row * sizeof(double *));
    if(!m)
        scierror("Memory allocation failed.");

    for(i = 0; i < row; i++)
    {
        m[i] = (double *)malloc(col * sizeof(double));
        if(!(m[i]))
            scierror("Memory allocation failed.");
    }

    return m;
}

// Function to create a unsigned long matrix
unsigned long **ulmatrix(long row, long col)
{
    unsigned long **m;
    int i;
    m = (unsigned long **)malloc(row * sizeof(unsigned long *));
    if(!m)
        scierror("Memory allocation failed.");

    for(i = 0; i < row; i++)
    {
        m[i] = (unsigned long *)malloc(col * sizeof(unsigned long));
        if(!(m[i]))
            scierror("Memory allocation failed.");
    }

    return m;
}

// Function to free a float matrix
void free_fmatrix(float **m, long row, long col)
{
    int i;

    for(i = 0; i < col; i++)
    {
        free(m[i]);
        if(!m[i])
            scierror("Free Memory Operation unsuccessful.");
    }

    free(m);
    if(!m)
        scierror("Free Memory Operation unsuccessful.");
}

// Function to free an integer matrix
void free_imatrix(int **m, long row, long col)
{
    int i;

    for(i = 0; i < col; i++)
    {
        free(m[i]);
        if(!m[i])
            scierror("Free Memory Operation unsuccessful.");
    }

    free(m);
    if(!m)
        scierror("Free Memory Operation unsuccessful.");
}

// Function to free a char matrix
void free_cmatrix(char **m, long row, long col)
{
    int i;

    for(i = 0; i < col; i++)
    {
        free(m[i]);
        if(!m[i])
            scierror("Free Memory Operation unsuccessful.");
    }

    free(m);
    if(!m)
        scierror("Free Memory Operation unsuccessful.");
}

// Function to free a double matrix
void free_dmatrix(double **m, long row, long col)
{
    int i;

    for(i = 0; i < col; i++)
    {
        free(m[i]);
        if(!m[i])
            scierror("Free Memory Operation unsuccessful.");
    }

    free(m);
    if(!m)
        scierror("Free Memory Operation unsuccessful.");
}

// Function to free an unsigned long matrix
void free_ulmatrix(unsigned long **m, long row, long col)
{
    int i;

    for(i = 0; i < col; i++)
    {
        free(m[i]);
        if(!m[i])
            scierror("Free Memory Operation unsuccessful.");
    }

    free(m);
    if(!m)
        scierror("Free Memory Operation unsuccessful.");
}
