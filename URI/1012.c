#include <stdio.h>

int main()
{
    double A, B, C, pi= 3.14159, tri, cir, trp, sq, rect;
    scanf("%lf%lf%lf", &A, &B, &C);

    tri = (1.0/2) * A*C;
    cir =  pi * (C*C);
    trp = (1.0/2) * (A+B) * C;
    sq = B*B;
    rect = A*B;

    printf("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", tri, cir, trp, sq, rect);

    return 0;
}
