#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b)
{
    if(b==0)
        return a;

    return gcd(b, a%b);
}

int main()
{
    long long int n, m, num[101], i, j, k, max, A, B, r, tc=0;
    char numstr[101][11];

    scanf("%lld", &n);

    gets(numstr[0]);

    while(n--)
    {
        i=0;
        do
        {
            j=0;
            do
            {
                scanf("%c", &numstr[i][j]);

                if(numstr[i][j]=='\n' || numstr[i][j]== 32)
                    break;

            }
            while(++j);

            if(numstr[i][j] == '\n')
            {
                numstr[i][j] = '\0';
                num[i] = atol(numstr[i]);
                printf("%lld\n", num[i]);
                break;
            }

            numstr[i][j] = '\0';
            num[i] = atol(numstr[i]);
            printf("%lld\n", num[i]);
        }
        while(++i);

        for(j=0, max=0; j<=i-1; j++)
        {
            for(k=j+1; k<=i; k++)
            {
                if (num[j] <= num[k])
                    A = gcd(num[k], num[j]);

                else
                    A = gcd(num[k], num[j]);


                if(max< A)
                    max = A;
            }
        }
        printf("%lld\n", max);
    }

    return 0;
}

/*i=0;
        while (1)
        {
            scanf("%d", &num[i++]);

            if (getchar() == '\n')
                break;
        }*/
