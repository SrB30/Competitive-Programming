#include <bits/stdc++.h>
using namespace std;

vector <vector<int> > adj;
bool vis[10002];
int cnt;

void dfs(int u)
{
    int size = adj[u].size();

    for(int i=0; i<size; i++)
    {
        int v = adj[u][i];
        if(!vis[v])
        {
            cnt++;
            vis[v] = true;
            dfs(v);
        }
    }

    return;
}


int main()
{
    int t, n, m, l;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        adj.resize(n+1);
        fill(vis, vis+n+1, false);
        scanf("%d", &m);
        scanf("%d", &l);

        while(m--)
        {
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);
            adj[x].push_back(y);
        }

        int z;
        cnt = 0;
        while(l--)
        {
            scanf("%d", &z);
            if(!vis[z])
            {
                vis[z] = true;
                cnt++;
                dfs(z);
            }
        }
        printf("%d\n", cnt);
        adj.clear();
    }

    return 0;
}
