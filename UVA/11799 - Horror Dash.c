#include <stdio.h>

int main()
{
    int t, i=0, j, n, a, max;
    scanf("%d", &t);

    while(++i <= t)
    {
        scanf("%d%d", &n, &a);

        for(j=2, max=a; j<=n; j++)
        {
            scanf("%d", &a);

            if (a>max)
                max = a;
        }
        printf("Case %d: %d\n", i, max);
    }
    return 0;
}
