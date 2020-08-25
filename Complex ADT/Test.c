#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

int main()
{
    complex_type A, B;
    A = complex(8, 6);
    B = sqrt_complex(A);
    print_complex(B);
}