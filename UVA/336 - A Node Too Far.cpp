#include <bits/stdc++.h>
using namespace std;

int strt, ttl;
int s, vs;
map <int, vector<int> > m;

void vfs()
{
    queue <int> q;
    map <int, int> vstd;
    int i;

    q.push(strt);
    vstd[strt] = 0;
    vs = s-1;

    while(!q.empty())
    {
        int cur = q.front();
        if(vstd[cur] == ttl)
            return;

        q.pop();

        int cur_s = m[cur].size();
        for(i=0; i< cur_s; i++)
        {
            int node = m[cur][i];

            if(!vstd.count(node))
            {
                vstd[node] = vstd[cur]+1;
                q.push(node);
                vs--;
            }
        }
    }

    return;
}

int main()
{
    int nc, tc=0;
    int i;
    int x, y;

    while(scanf("%d", &nc) && nc)
    {
        for(i=0; i<nc;i++)
        {
            scanf("%d%d", &x, &y);
            m[x].push_back(y);
            m[y].push_back(x);
        }

        s = m.size();

        while(scanf("%d%d", &strt, &ttl) && (strt!=0 || ttl!=0))
        {
            vfs();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++tc, vs, strt, ttl);

        }
        m.clear();
    }

    return 0;
}
