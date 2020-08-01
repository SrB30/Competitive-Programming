#include <stdio.h>
#include <math.h>

int main()
{
    int t,i=0, n, j;
    double res;

    scanf("%d", &t);

    while (++i <= t)
    {
        scanf("%d", &n);

        res = ((((((n * 567) / 9) + 7492) * 235) / 47) - 498);

        j = (res/10);
        j = abs(j%10);
        printf("%d\n", j);
    }

    return 0;
}
