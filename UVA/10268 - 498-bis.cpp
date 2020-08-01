#include <bits/stdc++.h>
using namespace std;

int extractInt(string& s, vector<int>& a)
{
    stringstream ss(s);
    int x, cnt=0;
    while(ss >> x)
    {
        a.push_back(x);
        cnt++;
    }

    return cnt;
}

int horners(vector<int>& a, int n, int x)
{
    if(n==0) return 0;

    int m = n-1;
    vector<int> p(m+1);

    p[0] = a[0]*n;
    for (int i=1; i<=m ; ++i )
    {
        p[i] = (p[i-1]*x) + (a[i]*(n-i));
    }

    return p[m];
}

int main()
{
    ios::sync_with_stdio(false);

    int x;
    string s;

    while(cin >> x)
    {
        cin.ignore();

        vector<int> a;
        getline(cin, s);
        int n = extractInt(s, a) - 1;

            int result = horners(a, n, x);

            cout << result << endl;

    }

    return 0;
}

