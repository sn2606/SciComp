# include <stdio.h>

int main()
{
    double x1, x2, y1, y2, x, y;

    printf("\nx1 : ");
    scanf("%lf", &x1);

    printf("\ny1 : ");
    scanf("%lf", &y1);

    printf("\nx2 : ");
    scanf("%lf", &x2);

    printf("\ny2 : ");
    scanf("%lf", &y2);

    printf("\nPoint to be interpolated: ");
    scanf("%lf", &x);

    y = y1 + ((y2 - y1) / (x2 - x1))*x;

    printf("\nf(x) = %0.4lf\n", y);

    return 0;
}