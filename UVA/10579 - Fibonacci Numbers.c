#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *c = (char*) malloc(1046);
    char *f[5001];
    int n, i, j, carry, d, len, l1=1;

    f[0] = (char*) malloc(2);
    strcpy(f[0], "0");
    f[1] = (char*) malloc(2);
    strcpy(f[1], "1");

    for(i=2; i<=5000; i++)
    {
        len = strlen(f[i-1]);
        f[i] = (char*) malloc(len+2);

        for (j=0, carry = 0; j<l1; j++)
        {
            d = carry + (f[i-1][j] - 48) + (f[i-2][j] - 48);
            carry = d/10;
            f[i][j] = (d%10)+48;
        }

        while (j<len)
        {
            d = carry + (f[i-1][j] - 48);
            carry = d/10;
            f[i][j] = (d%10)+48;
            j++;
        }

        if (carry == 1)
            f[i][j++] = '1';

        f[i][j] = '\0';
        l1 = len;
    }

    while (scanf("%d", &n) != EOF)
    {
        if(n!=0)
        {
            j= strlen(f[n]);
            for (i=j-1; i>=0; i--)
                printf("%c", f[n][i]);
        }
        printf("\n");
    }

    return 0;
}
