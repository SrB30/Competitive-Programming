#include <stdio.h>

int main()
{
    char m1[9], m2[9];
    int j=0, i, p1, w[102], p2, l[102], n, k;
    double win;

    while (scanf("%d", &n) == 1)
    {
        if (n == 0)
            return 0;

        scanf("%d", &k);

        if(j++ != 0)
            printf("\n");


        for(i=1; i<=n; i++)
        {
            w[i] = l[i] = 0;
        }

        for(i=1; i<=(k*n*(n-1))/2; i++)
        {
            scanf("%d %s %d %s", &p1, m1, &p2, m2);

            if (m1[0] != m2[0])
            {
                if (m1[0]=='r' && m2[0]=='p')
                {
                    w[p2]++;
                    l[p1]++;
                }
                else if (m1[0]=='p' && m2[0]=='r')
                {
                    w[p1]++;
                    l[p2]++;
                }
                else if (m1[0]=='s' && m2[0]=='p')
                {
                    w[p1]++;
                    l[p2]++;
                }
                else if (m1[0]=='p' && m2[0]=='s')
                {
                    w[p2]++;
                    l[p1]++;
                }
                else if (m1[0]=='r' && m2[0]=='s')
                {
                    w[p1]++;
                    l[p2]++;
                }
                else if (m1[0]=='s' && m2[0]=='r')
                {
                    w[p2]++;
                    l[p1]++;
                }
            }
        }

        for (i=1; i<=n; i++)
        {
            if (w[i]!=0 || l[i]!=0)
            {
                win = (w[i]*1.0) / (w[i] + l[i]);
                printf("%.3lf\n", win);
            }
            else
                printf("-\n");
        }
    }
}
