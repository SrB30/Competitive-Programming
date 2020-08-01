#include <stdio.h>
#include <math.h>
long long int m;

long long int bigmod(long long int b, long long int p)
{
    long long int c;
    if (p==0)
        return 1;
    else if ((p%2) == 0)
    {
        c = bigmod(b, p/2);
        return (c*c)%m;     ///(c%m) * (c*m)
    }
    else
        return (b* bigmod(b, p-1))%m;       ///(b%m) * (bigmod(b, p-1)%m)
}


int main()
{
    long long int b, p, r;

    while(scanf("%lld%lld%lld", &b, &p, &m) != EOF)
    {
        if (p==0 & m==1)
            printf("0\n");
        else
            printf("%lld\n", bigmod(b,p));
    }

    return 0;
}
