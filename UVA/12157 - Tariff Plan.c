#include <stdio.h>

int main()
{
    int N, T, i=1, j, l, dr, mile, juice, du[25];

    scanf("%d", &T);
    while (i<=T)
    {
        scanf("%d", &N);
        for (j=1; j<=N; j++)
        {
            scanf("%d", &du[j]);
        }

        mile = 0;
        for (l=1; l<=N; l++)
        {
            dr = du[l];
            while (dr >= 0)
            {
                mile = mile +10;
                dr = dr-30;
            }
        }

        juice = 0;
        for (l=1; l<=N; l++)
        {
            dr = du[l];
            while (dr >= 0)
            {
                juice = juice +15;
                dr = dr-60;
            }
        }

        if (mile < juice)
            printf("Case %d: Mile %d\n", i, mile);
        else if (mile > juice)
            printf("Case %d: Juice %d\n", i, juice);
        else if (mile == juice)
            printf("Case %d: Mile Juice %d\n", i, mile);
        i++;
    }

    return 0;
}
