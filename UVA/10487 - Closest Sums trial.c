#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int A[1001];
    int ans, cur, mid, i, j, d1, d2, N, q, cs=1;

    while(scanf("%d", &N) == 1 && N)
    {
        printf("Case %d:\n", cs++);

        for( i = 0; i < N; i++ )
            scanf("%d", &A[i]);

        scanf("%d", &q);

        while(q--)
        {
            scanf("%d", &mid);
            ans = A[0] + A[1];
            d1= abs(ans-mid);
            for(i = 0; i < N-1; i++ )
            {
                for( j = i+1; j < N; j++ )
                {
                    cur = A[i] + A[j];
                    if( d1 > (d2=abs(cur - mid)))
                    {
                        ans = cur;
                        d1 = d2;
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", mid, ans);
        }
    }
    return 0;
}
