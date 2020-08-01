#include <stdio.h>
#include <math.h>
int d, j, check;

int prime(int i)
{
    if (i==1)
    {
        check = 0;
        return;
    }
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
    long long int n, k, i, p[1000], pr, org;

    while(scanf("%lld", &n)==1)
    {
        if(n==0)
            return 0;

        printf("%lld = ", n);
        if (n==1)
        {
            printf("\n");
            continue;
        }

        if(n<0)
        {
            printf("-1 x ");
            if (n== -1)
            {
                printf("\n");
                continue;
            }
            n= abs(n);
        }
        org = n;


        pr= 0;
        if (n%2 == 0)
        {
            do
            {
                p[pr++] = 2;
                n = n/2;
            }
            while(n%2 == 0);



            prime(n);
            if (check==1)
            {
                k=n;
                do
                {
                    p[pr++] = k;
                    n = n/k;
                }
                while(n%k == 0);
            }
        }


        for(i=3; i<=sqrt(n); i+=2)
        {
            if (n%i == 0)
            {
                prime(i);
                if (check==1)
                {
                    do
                    {
                        p[pr++] = i;
                        n = n/i;
                    }
                    while(n%i == 0);
                }


                prime(n);

                if (check==1)
                {
                    k=n;
                    do
                    {
                        p[pr++] = k;
                        n = n/k;
                    }
                    while(n%k == 0);
                }
            }
        }

        if (org != 2)
        {
            prime(org);
            if (check==1)
                p[pr++] = org;
        }

        printf("%lld", p[0]);

        for(i=1; i<pr; i++)
        {
            printf(" x %lld", p[i]);
        }

        printf("\n");
    }

    return 0;
}

