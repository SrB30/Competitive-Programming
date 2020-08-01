#include <stdio.h>

int main()
{
    int T, i, C, d;
    double F, Cel;
    scanf("%d", &T);
    for(i=1;i<=T;i++) {
        scanf("%d%d", &C, &d);
        F = ((9.0/5)*C) + d;
        Cel= ((5.0/9)*F);
        printf("Case %d: %.2lf\n", i, Cel);
    }
    return 0;
}
