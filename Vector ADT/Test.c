#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    int *m;

    m = ivector(10);

    m[0] = 1;
    printf("%d", *m);

    free_ivector(m);

    return 0;

}