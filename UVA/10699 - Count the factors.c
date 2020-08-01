#include <stdio.h>
#include <math.h>
int d, j, check;

void prime(int i)
{
    check=1;
    d= sqrt(i);

    for(j=2; j<=d; j++)
    {
        if (i%j == 0)
        {
            check=0;
            return;
        }
    }
    return;
}

int main()
{
    long long int n, k, cnt, i;

    while(scanf("%lld", &n)==1)
    {
        if(n==0)
            return 0;
        if(n==1)
        {
            printf("1 : 0\n");
            continue;
        }

        cnt=0;
        prime(n);
        if (check==1)
            cnt++;

        for(i=2; i<=sqrt(n); i++)
        {
            if (n%i == 0)
            {
                prime(i);
                if (check==1)
                    cnt++;

                if ((n/i) != i)
                {
                    prime(n/i);
                    if (check==1)
                        cnt++;
                }
            }
        }
        printf("%lld : %lld\n", n, cnt);
    }
}
