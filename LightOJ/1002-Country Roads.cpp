#include<bits/stdc++.h>
using namespace std;

#define     fin(i,ii,n)         for(int i=ii; i<n; ++i)
#define     pb                  push_back

#define white 0 ///undiscovered
#define gray 1  ///discovered
#define black -1    ///finished


void MstPrim(vector<vector<pair<int,int> > >& adjList, vector<int>& key, int s, int n)
{
    int clr[n], cnt=0;
    for (int i = 0; i < n; ++i) { 
        key.pb(INT_MAX);
        clr[i] = 0;
    }

    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;

    q.push({0,s});
    clr[s] = gray;
    key[s] = 0;
    

    while(!q.empty())
    {
        pair<int,int> u = q.top();
        q.pop();
        int uu = u.second;

        if(clr[uu] == black) continue;
        clr[uu] = black;
        if(++cnt==n) return;

        for(auto v : adjList[uu])
        {
            int w = v.first;
            int vv = v.second;
            int maxWeight = max(key[uu], w);

            if(clr[vv] != black && maxWeight<key[vv])
            {
                key[vv] = maxWeight;
                q.push({key[vv],vv});
            }
        }
    }
    return;
}


int main()
{
    int t, n, m, u, v, w, city, i=0;
    cin>>t;
    while(++i<=t){
        cin>>n>>m;

        vector <vector<pair<int,int> > > adjList(n);
        vector<int> key;

        fin(i,0,m) {
            cin>>u>>v>>w;
            adjList[u].pb({w,v});
            adjList[v].pb({w,u});
        }
        cin>>city;

        MstPrim(adjList, key, city, n);

        cout <<  "Case " << i << ":\n";
        fin(i,0,n){
            if(key[i]<INT_MAX) cout << key[i] << endl;
            else cout << "Impossible" << endl;
        }
    }

    return 0;
}