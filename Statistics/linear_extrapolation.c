# include <stdio.h>
# include <stdlib.h>

int main()
{
    float x1, x2, y1, y2, x, y;

    printf("\nEnter x1: ");
    scanf("%f", &x1);

    printf("\nEnter y1: ");
    scanf("%f", &y2);

    printf("\nEnter x2: ");
    scanf("%f", &x2);

    printf("\nEnter y2: ");
    scanf("%f", &y2);

    printf("Enter x: ");
    scanf("%f", &x);

    y = y1 + ((x - x1)/(x2 - x1))*(y2 - y1);

    printf("\ny = %f\n", y);

    return 0;
}