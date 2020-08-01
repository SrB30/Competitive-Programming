#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, p[1000], pr, d, j, check;

    while(scanf("%d", &n)==1)
    {
        if(n==0)
            return 0;

        printf("%d = ", n);

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


        pr= 0;
        if (n%2 == 0)
        {
            do
            {
                p[pr++] = 2;
                n = n/2;
            }
            while(n%2 == 0);


            if (n != 1)
            {
                check=1;
                d= sqrt(n);

                for(j=3; j<=d; j+=2)
                {
                    if (n%j == 0)
                    {
                        check=0;
                        break;
                    }
                }

                if (check==1)
                {
                    i=n;
                    do
                    {
                        p[pr++] = i;
                        n = n/i;
                    }
                    while(n%i == 0);
                }
            }
        }


        for(i=3; i<=sqrt(n) && n!=1; i+=2)
        {
            if (n%i == 0)
            {
                check=1;
                d= sqrt(i);

                for(j=3; j<=d; j+=2)
                {
                    if (i%j == 0)
                    {
                        check=0;
                        break;
                    }
                }
                if (check==1)
                {
                    do
                    {
                        p[pr++] = i;
                        n = n/i;
                    }
                    while(n%i == 0);
                }
            }
        }

        if (n != 1)
            p[pr++] = n;

        printf("%d", p[0]);

        for(i=1; i<pr; i++)
        {
            printf(" x %d", p[i]);
        }

        printf("\n");
    }

    return 0;
}
