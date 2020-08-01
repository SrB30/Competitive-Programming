#include <stdio.h>

int main()
{
    int X, Y;
    double t;
    scanf("%d%d", &X, &Y);

    if (X==1) {
        t = 4.00 * Y;
        printf("Total: R$ %.2lf\n", t);
    }
    if (X==2) {
        t = 4.50 * Y;
        printf("Total: R$ %.2lf\n", t);
    }
    if (X==3) {
        t = 5.00 * Y;
        printf("Total: R$ %.2lf\n", t);
    }
    if (X==4) {
        t = 2.00 * Y;
        printf("Total: R$ %.2lf\n", t);
    }
    if (X==5) {
        t = 1.50 * Y;
        printf("Total: R$ %.2lf\n", t);
    }

    return 0;
}
