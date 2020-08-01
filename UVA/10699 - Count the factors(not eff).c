#include <stdio.h>
#include <math.h>

int main()
{
    long long int n, pr[45000] = {2,3,5,7,11,13,17,19,0}, i, j, k, sq, check, cnt;

    for(i=23, j=8; i<=500000; i+=2)
    {
        sq = sqrt(i);
        check=1;
        for(k=3; k<=sq; k+=2)
        {
            if(i%k == 0)
            {
                check=0;
                break;
            }
        }
        if (check==1)
            pr[j++]=i;
    }

    while(scanf("%lld", &n)==1)
    {
        if(n==0)
            return 0;

        cnt=0;
        for (i=0; pr[i]<=(n/2); i++)
        {
            if(n%pr[i] == 0)
                cnt++;
        }
        if (n%2 != 0)
        {
            check=1;
            sq = sqrt(n);
            for(k=3; k<=sq; k+=2)
            {
                if(n%k == 0)
                {
                    check=0;
                    break;
                }
            }

            if(check==1)
                cnt++;
        }

        if(n==1 || n==2)
            printf("%lld : 1\n", n);
        else
            printf("%lld : %lld\n", n, cnt);
    }
}
