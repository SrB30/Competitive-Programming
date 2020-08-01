#include <stdio.h>

int main()
{
    long long x, i, res[50005];

    res[0]=0;

    for(i=1; i<=50000; i++)
    {
        res[i] = res[i-1] + (i*i*i);
    }
    while(scanf("%d", &x) != EOF)
    {
        printf("%lld\n", res[x]);
    }

    return 0;
}
