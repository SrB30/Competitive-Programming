#include <stdio.h>

int main()
{
    long long int T,i,a,b,c;
    scanf("%lld", &T);
    for(i=1;i<=T;i++) {
        scanf("%lld%lld%lld", &a, &b, &c);

        if((a<b && a>c) || (a<c && a>b))
            printf("Case %lld: %lld\n", i, a);
        else if((b<a && b>c) || (b<c && b>a))
            printf("Case %lld: %lld\n", i, b);
        else if((c<a && c>b) || (c<b && c>a))
            printf("Case %lld: %lld\n", i, c);
        else
            printf("Case %lld: %lld\n", i, a);
    }
    return 0;
}
