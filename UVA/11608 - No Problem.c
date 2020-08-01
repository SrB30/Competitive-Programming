#include <stdio.h>

int main()
{
    int T=0, a[15], b[15], S, i, sum;

    while (++T)
    {
        scanf("%d", &S);

        if (S < 0)
        {
            return 0;
        }

        for (i=1; i<=12; i++)
        {
            scanf("%d", &a[i]);
        }
        for (i=1; i<=12; i++)
        {
            scanf("%d", &b[i]);
        }

        printf("Case %d:\n", T);

        sum = S;
        for(i=1; i<=12; i++)
        {
            if (sum >= b[i]) {
                printf("No problem! :D\n");
                sum = sum - b[i];
            }
            else
                printf("No problem. :(\n");

            sum = sum + a[i];
        }

    }

    return 0;
}
