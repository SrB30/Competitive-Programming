#include <stdio.h>

int main()
{
    int n,t, p, har[3651], i, j, d, day, cnt;


    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &p);

        for(i=1; i<=n; i++)
            har[i] = 0;

        for(i=0; i<p; i++)
        {
            scanf("%d", &day);

            for(j=1; n>=(d=day*j); j++)
                har[d] = 1;
        }
        for(i=1, cnt=0; i<=n; i++)
        {
            if(har[i] == 1)
            {
                if((i+1)%7 != 0 && i%7 != 0)
                    cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
