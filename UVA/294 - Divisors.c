#include <stdio.h>
#include <math.h>

int main()
{
    int t, l, u, d, i, j, p, cnt, pow, k;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d%d", &l, &u);
        if(u==1)
            d=p=1;

        else
        {
            for(i=l, d=0, p=0; i<=u; i++)
            {
                cnt=1, k=i, pow=0;
                while(k%2 == 0)
                {
                    pow++;
                    k /= 2;
                }
                if(pow != 0)
                    cnt *= (pow+1);


                for(j=3; j<=sqrt(k) && k!=1; j+=2)
                {
                    pow = 0;
                    while (k % j == 0)
                    {
                        pow++;
                        k /= j;
                    }

                    if (pow != 0)
                        cnt *= pow + 1;
                }
                if(k != 1)
                    cnt *= 2;

                if(cnt > d)
                {
                    d = cnt;
                    p = i;
                }
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, p, d);
    }

    return 0;
}
