#include <stdio.h>

int main()
{
    int t, n, i;
    double mul, sum, farm, ani, frn;


    while(scanf("%d", &t) != EOF)
    {
        while(t--)
        {
            scanf("%d", &n);
            for(i=0, sum=0; i<n; i++)
            {
                scanf("%lf%lf%lf", &farm, &ani, &frn);
                mul = (farm/ani) * frn * ani;
                sum = sum + mul;
            }
            n = sum;
            printf("%d\n", n);
        }
    }

    return 0;
}
