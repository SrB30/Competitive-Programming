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
    int pre, p;

    p = a[0];
    for (int i=1; i<=n ; ++i )
    {
        pre = p;
        p = (pre*x) + a[i];
    }

    return p;
}

int main()
{
    ios::sync_with_stdio(false);
    string s1, s2;

    while(getline(cin, s1))
    {
        vector<int> a,b;
        int n = extractInt(s1, a) - 1;  ///degree is n-1;

        getline(cin, s2);
        int xn = extractInt(s2, b);

        for (int i=0; i<xn ; ++i )
        {
            int result = horners(a, n, b[i]);

            cout << result;
            if(i < xn-1)
                cout << " ";
        }

        cout << endl;

    }

    return 0;
}
