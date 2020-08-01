#include <stdio.h>

int main()
{
    int X;
    double Y, avg;
    scanf("%d%lf", &X, &Y);

    avg = X/Y;
    printf("%.3lf km/l\n", avg);

    return 0;
}
