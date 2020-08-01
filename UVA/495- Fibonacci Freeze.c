#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *c = (char*) malloc(1046);
    char *f[5001];
    int n, i, j, carry, d, len, ll=1, half;

    f[0] = (char*) malloc(2);
    strcpy(f[0], "0");
    f[1] = (char*) malloc(2);
    strcpy(f[1], "1");

    for(i=2; i<=5000; i++)
    {
        len = strlen(f[i-1]);
        f[i] = (char*) malloc(len+2);

        for (j=0, carry = 0; j<ll; j++)
        {
            d = carry + (f[i-1][j] - 48) + (f[i-2][j] - 48);
            carry = d/10;
            f[i][j] = (int)(d%10) + 48;
        }

        while (j<len)
        {
            d = carry + (f[i-1][j] - 48);
            carry = d/10;
            f[i][j] = (int)(d%10)+48;
            j++;
        }

        if (carry == 1)
            f[i][j++] = '1';

        f[i][j] = '\0';
        ll = len;
    }

    while (scanf("%d", &n) != EOF)
    {
        if ((j= strlen(f[n])) > 1)
        {
            half=j/2;
            for (i=0; i<=half; i++)
            {
                c[i] = f[n][j-i-1];
                c[j-i-1] = f[n][i];
            }
        }
        else
            c[0] = f[n][0];

        c[j] = '\0';
        printf("The Fibonacci number for %d is %s\n", n, c);
    }

    return 0;
}
