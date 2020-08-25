#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "complex.h"

// // Declaration of the complex data structure
// typedef struct COMPLEX
// {
//     float real;
//     float imaginary;
// }complex_type;

// Initializing complex numbers with values
complex_type complex(float r, float i)
{
    complex_type C;
    C.real      = r;
    C.imaginary = i;
    return C;
}

// Function to print a complex number
void print_complex(complex_type B)
{
    printf("%0.3f + %0.3fi", B.real, B.imaginary);
}

// Function to add two complex numbers A and B
complex_type add_complex(complex_type A, complex_type B)
{
    complex_type C;
    C.real      = A.real + B.real;
    C.imaginary = A.imaginary + B.imaginary;
    return C;
}

// Function to subtract two complex numbers A and B
// Order is important. Function will return A - B
complex_type sub_complex(complex_type A, complex_type B)
{
    complex_type C;
    C.real      = A.real - B.real;
    C.imaginary = A.imaginary - B.imaginary;
    return C;
}

// Function to multiply two complex numbers A and B
complex_type mul_complex(complex_type A, complex_type B)
{
    complex_type C;
    C.real      =  A.real*B.real      -  A.imaginary*B.imaginary;
    C.imaginary =  A.real*B.imaginary +  A.imaginary*B.real;
    return C;
}

// Function to get complex conjugate of a complex number A
complex_type complex_conjugate(complex_type A)
{
    complex_type C;
    C.real      =  A.real;
    C.imaginary = -A.imaginary;
    return C;
}

// Function to get absolute value of a complex number A
float absolute(complex_type A)
{
    float abs_value;
    abs_value   =   A.real*A.real + A.imaginary*A.imaginary;
    abs_value   =   sqrt(abs_value);
    return abs_value;
}

// Function to divide a complex number A by another complex number B
complex_type div_complex(complex_type A, complex_type B)
{
    complex_type C;
    float z     = absolute(B);
    z          *=  z;
    C           =  mul_complex(A, complex_conjugate(B));
    C.real      =  C.real / z;
    C.imaginary =  C.imaginary / z;
    return C;
}

// Function to get square root (positive) of a complex number A
complex_type sqrt_complex(complex_type A)
{
    complex_type C;
    float x, y;

    if(A.real == 0.0 && A.imaginary == 0)
    {
        C.real      = 0;
        C.imaginary = 0;
    }
    else
    {
        x           =  sqrt((A.real + absolute(A)) / 2.0);
        y           =  A.imaginary / (2.0 * x);
        C.real      =  x;
        C.imaginary =  y;
    }

    return C;
}