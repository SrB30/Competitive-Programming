#include <stdio.h>

int main()
{
    int T=0, R, N, q, r;

    while (++T)
    {
        scanf("%d%d", &R, &N);

        if (R == 0 && N == 0)
            return 0;

        q = R/N;
        r = R%N;
        if (r == 0 && q ==27)
            printf("Case %d: %d\n", T, (q-1));

        else if (q > 26)
            printf("Case %d: impossible\n", T);

        else if (R%N == 0)
            printf("Case %d: %d\n", T, (q-1));

        else
            printf("Case %d: %d\n", T, q);
    }
}
