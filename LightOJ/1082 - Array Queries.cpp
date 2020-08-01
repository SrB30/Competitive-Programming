#include <bits/stdc++.h>

using namespace std;

int arr[100002];
int tree[300007];

void sgtree(int node, int beg, int end)
{
    if(beg == end)
    {
        tree[node] = arr[beg];
        return;
    }
    int left = 2*node + 1;
    int right = left + 1;
    int mid = (beg+end)/2;

    sgtree(left, beg, mid);
    sgtree(right, mid+1, end);
    tree[node] = min(tree[left], tree[right]);
    return;
}

int query(int node, int beg, int end, int i, int j)
{
    if(i>end || j<beg)
        return INT_MAX;
    if(beg>=i && end<=j)
        return tree[node];

    int left = 2*node + 1;
    int right = left + 1;
    int mid = (beg+end)/2;

    return min(query(left, beg, mid, i, j), query(right, mid+1, end, i, j));
}

int main()
{
    int t, tc=0;
    int n, q, qc;
    int i, j;

    scanf("%d", &t);
    while(++tc <= t)
    {
        scanf("%d%d", &n, &q);
        for(i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sgtree(0, 0, n-1);

        printf("Case %d:\n", tc);
        for(qc=0; qc<q; qc++)
        {
            scanf("%d%d", &i, &j);
            printf("%d\n", query(0, 0, n-1, i-1, j-1));
        }
    }

    return 0;
}
