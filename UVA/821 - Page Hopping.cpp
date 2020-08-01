#include <bits/stdc++.h>
#define INF 100000
using namespace std;
vector<vector<int> > mat(101, vector<int> (101));
int sum, mx;                                        ///mx = Counts total number of nodes
int mapp[101];

void warshall(int mx)
{
    for(int k=1; k<=mx; k++)
    {
        for(int i=1; i<=mx; i++)
        {
            for(int j=1; j<=mx; j++)
            {
                if(mat[i][k]+mat[k][j] < mat[i][j])             //mat[i][j] = min(mat[i][k]+mat[k][j], mat[i][j]);
                {
                    mat[i][j] = mat[i][k]+mat[k][j];
                }
            }
        }
    }
    return;
}


void init()
{
    for(int i=1; i<101; i++)
    {
        for(int j = 1; j<101; j++)
            mat[i][j] = INF;
    }
    //mat.resize(101, vector<int> (101, INF));

    for(int i=1; i<101; i++) {
      mat[i][i] = 0;
      mapp[i] = 0;
    }

    return;
}

void mapp_fun(int a, int b)
{
    if(mapp[a]== 0)
        mapp[a] = ++mx;
    if(mapp[b]== 0)
        mapp[b] = ++mx;

    mat[mapp[a]][mapp[b]] = 1;
    return;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int a, b;
    int t=0;

    while(scanf("%d%d", &a, &b)==2 && (a!=0 || b!=0))
    {
        init();

        mx = 0;             /// Initially, Number of nodes = 0
        mapp_fun(a, b);

        while(scanf("%d%d", &a, &b)==2 && (a!=0 || b!=0))
        {
            mapp_fun(a, b);
        }

        warshall(mx);

        int sum = 0;
        for(int i=1; i<=mx; i++)
        {
            for(int j=1; j<=mx; j++)
            {
                sum += mat[i][j];       /// Sum of all possible pairs
            }
        }

        double avg = double(sum) / (mx * (mx-1));                                     ///total possible pairs = (mx * (mx-1)
        printf("Case %d: average length between pages = %.3lf clicks\n", ++t, avg);
    }
    return 0;
}


/*
1 2 2 4 1 3 3 1 4 3 0 0
1 2 1 4 4 2 2 7 7 1 0 0
0 0
*/
