#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n, m;

    while(cin>>n>>m && (m!=0 || n!=0))
    {
        if(n>m) { cout << 0.000000 << endl; continue; }

        double ans = ((m-n+1)*1.0) / (m+1);     ///reference: Bertland's Ballot Theorem
        cout << fixed << setprecision(6) << ans << endl;
    }



    return 0;
}
