#include <bits/stdc++.h>
#define white 1
#define black 2

using namespace std;

vector <vector <int> > adj;
int n, l, f, r;
int color[200];
int q[200];

int vfs()
{
    while(f <= r)
    {
        int u = q[f++];

        int size = adj[u].size();
       // printf("size = %d\n", size);
        for(int v = 0; v<size; v++)
        {
            if(color[adj[u][v]] == 0)
            {
                if(color[u]==white)
                    color[adj[u][v]] = black;
                else
                    color[adj[u][v]] = white;

                q[++r] = adj[u][v];
               // printf("%d = %d \t\t %d = %d\n", u, color[u], adj[u][v], color[adj[u][v]]);
            }
            else if (color[u] == color[adj[u][v]])
                return -1;
        }
    }

    return 1;
}

int main()
{
    int i, n1, n2;

    while(scanf("%d", &n))
    {
        if(n == 0)
            return 0;

        adj.resize(n);

        color[0] = black;

        for(i=1; i<n; i++)
            color[i] = 0;

        scanf("%d", &l);

        for(i=0; i<l; i++)
        {
            scanf("%d%d", &n1, &n2);
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        f=0; r=-1;
        int size = adj[0].size();
        //printf("size = %d\n", size);
        for(i=0; i<size; i++) {
            color[adj[0][i]] = white;
            //printf("%d = %d\n", adj[0][i], color[adj[0][i]]);
            q[++r] = adj[0][i];
        }

        int ret = vfs();
       // printf("%d\n", ret);

        if(ret == 1)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        adj.clear();
    }

    return 0;
}
