#include <bits/stdc++.h>

using namespace std;
int n;
vector < vector <int> > adj;

bool vstd[102], vstn[102];


void dfs(int u, int lim)
{
    if(u == lim)
        return;
    vstn[u] = true;

    int last = adj[u].size();

    for(int i=0; i<last; i++)
    {
        if(!vstn[adj[u][i]])
            dfs(adj[u][i], lim);
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
    int  i, j, x;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        adj.resize(n);

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d", &x);
                if(x == 1)
                    adj[i].push_back(j);
            }
        }


        memset(vstn, false, n);

        dfs(0, -1);

        for(i=0; i<n; i++)
            vstd[i] = vstn[i];

        printf("Case %d:\n", ++tc);

        for(i=0; i<n; i++)
        {
            memset(vstn, 0, n);
            dfs(0, i);

            print();
            printf("|");

            for(j=0; j<n; j++)
            {
                if(vstd[j] && !vstn[j])
                    printf("Y|");
                else
                    printf("N|");
            }
            printf("\n");
        }
        print();

        adj.clear();
    }


    return 0;
}

