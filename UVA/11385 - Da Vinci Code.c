#include <stdio.h>
#include <math.h>

int main()
{
    long long int fib[47]= {1,2, 0}, i, j, Beg, End, Mid, t, f[46], max, n;
    char out[46], c[101];

    for(i=2; i<=46; i++)
        fib[i] = fib[i-1] + fib[i-2];

    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);

        for(i=0; i<n; i++)
            scanf("%lld", &f[i]);

        gets(c);

        for(i=0; i<45; i++)
            out[i] = 32;

        scanf("%c", &c[0]);

        for(i=0, j=0, max=0; c[i]!='\n'; )
        {
            if((c[i]>='A' && c[i]<='Z') && j<n)
            {
                Beg=0, End=44;
                Mid = (Beg+End)/2;
                while((Beg <= End) && (fib[Mid] != f[j]))
                {
                    if(f[j] < fib[Mid]) {End= Mid-1;}

                    else {Beg= Mid+1;}

                    Mid = (Beg+End)/2;
                }
                out[Mid] = c[i];

                if(max < Mid) {max=Mid;}
                j++;
            }

            scanf("%c", &c[++i]);
        }

        out[++max] = '\0';

        printf("%s\n", out);
    }

    return 0;
}
