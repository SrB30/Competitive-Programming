#include <stdio.h>

int main()
{
    int t, n, i=0, j, card, max;

    scanf("%d", &t);
    while (++i <= t)
    {
        scanf("%d", &n);
        for(j=1, max=0; j<=n; j++)
        {
            scanf("%d", &card);
            if(card > max)
                max = card;
        }
        printf("Case %d: %d\n", i, max);
    }

    return 0;
}
