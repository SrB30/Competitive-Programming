#include <stdio.h>

int main()
{
    int n, i, j, c, r, row, col, m[101][101], rs[101];

    while(scanf("%d", &n) == 1)
    {
        if(n==0)
            return 0;

        int r=0, cs[101] = {0}, rs[101]={0};

        for(i=1, row=0; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d", &m[i][j]);
                rs[i]= rs[i] + m[i][j];
                cs[j]= cs[j] + m[i][j];
            }

            if((rs[i] %2) != 0)
            {
                r++, row = i;
            }
        }

        for(i=1, c=0, col=0; i<=j; i++)
        {
            if((cs[i] % 2) != 0)
            {
                c++, col = i;
            }
        }

        if(r>1 || c>1)
            printf("Corrupt\n");

        else if (r==0 && c==0)
            printf("OK\n");

        else
            printf("Change bit (%d,%d)\n", row, col);
    }
}
