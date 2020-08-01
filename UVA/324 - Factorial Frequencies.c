#include <stdio.h>
#include <string.h>
#define jk 782
char facts[367][jk];
char fact[4][jk];

int main()
{
    char t[5], temp;
    int l, l1, l2, i, j, mc, sum, sc, k, len, m, n;

    strcpy(facts[0], "1");
    strcpy(facts[1], "1");

    for(i=0; i<4; i++)
        for(j=0; j<jk; j++)
            fact[i][j] = '0';

    for(i=2; i<=366; i++)
    {
        j=i, l2=0;
        while(j != 0)
        {
            t[l2++] = (j%10)+48;
            j = j/10;
        }

        for(l=0; l<l2; l++)
        {
            mc = 0;
            for(k=0; facts[i-1][k]!= '\0'; k++)
            {
                m= ((facts[i-1][k]-48) * (t[l]-48)) + mc;
                fact[l][k+l] = (m%10)+48;
                mc = m/10;
            }
            if (mc>0) {
                fact[l][(k+l)] = mc+48;
                k++;
            }
        }
        len = k-1+l-1;
        for(k=0, sc = 0; k<=len; k++)
        {
            sum=0;
            for(j=0; j<l2; j++)
            {
                sum = sum + (fact[j][k]-48);
            }
            sum = sum+sc;
            sc = sum/10;
            facts[i][k] = (sum%10)+48;
        }
        if(sc > 0)
            facts[i][k++] = sc+48;
        facts[i][k] = '\0';
    }

    while(scanf("%d", &n))
    {
        if (n==0)
            return 0;

        int frq[11] = {0};

        printf("%d! --\n", n);

        for(i=0; facts[n][i] != '\0'; i++)
        {
            frq[facts[n][i]-48]++;
        }
        for(i=0; i<10; i++)
        {
            if(i==5)
                printf("\n");

            printf("   (%d)   %d", i, frq[i]);
        }
        printf("\n");
    }


    return 0;

}
