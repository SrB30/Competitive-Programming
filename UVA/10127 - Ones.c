#include <stdio.h>
#include <string.h>
#define l 10001
char a[l];

int main()
{
    long long i, mod, div;
    for(i=0; i<l; i++) {
        a[i] = '1';
    }

    while (scanf("%lld", &div) != EOF)
    {
        mod=0;
        for (i=0; i<l; i++)
        {
            if ((mod = ((10*mod) + (a[i]-48))%div)== 0)
            {
                printf("%lld\n", i+1);
                break;
            }
        }
    }
    return 0;
}

