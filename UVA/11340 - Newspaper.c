#include <stdio.h>
#include <ctype.h>

int main()
{
    int n, k, m, i, j=0, totalcent, alp[301], price;
    double money;
    char c, ig, str[10004];

    scanf("%d", &n);

    while(++j <= n)
    {
        for(i=0; i<=300; i++)
            alp[i] = 0;

        scanf("%d%c", &k, &ig);

        for(i=1; i<=k; i++)
        {
            scanf("%c%c", &c, &ig);
            scanf("%d%c", &price, &ig);
            alp[c]=price;
        }

        scanf("%d%c", &m, &ig);

        totalcent=0;
        j=1;
        while (j<=m)
        {
            gets(str);
            for(i=0; str[i]; i++)
            {
                totalcent = totalcent + alp[str[i]];
            }
            j++;
        }

        money = (double) totalcent/(100.0);

        printf("%.2lf$\n", money);
    }

    return 0;
}
