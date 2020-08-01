#include <bits/stdc++.h>

using namespace std;
int n;
bool mat[102][102];
bool out[102][102];
bool vstd[102], vstn[102];


void dfs(int u, int lim)
{
    if(u == lim)
        return;
    vstn[u] = true;

    for(int i=0; i<n; i++)
    {
        if(mat[u][i] && !vstn[i])
            dfs(i, lim);
    }
    return;
}


void print()
{
    printf("+");
    for(int i=0; i<(2*n - 1); i++)
        printf("-");
    printf("+\n");

    return;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, tc=0;
    int  i, j;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                scanf("%d", &mat[i][j]);
        }
        memset(vstn, false, n);

        dfs(0, -1);

        for(i=0; i<n; i++)
            vstd[i] = vstn[i];

        for(i=0; i<n; i++)
        {
            memset(vstn, 0, n);
            dfs(0, i);

            for(j=0; j<n; j++)
            {
                if(vstd[j] && !vstn[j])
                    out[i][j] = true;
                else
                    out[i][j] = false;
            }
        }

        printf("Case %d:\n", ++tc);

        for(i=0; i<n; i++)
        {
            print();
            printf("|");
            for(j=0; j<n; j++) {
                if(out[i][j])
                    printf("Y|");
                else
                    printf("N|");
            }
            printf("\n");
        }
        print();
    }

    return 0;
}
