/*
Concept: Let, the given number is X = A - B. Here, B = A/10.
            So, A - A/10 = X
                A - (A-A%10)/10 = X
                10A - A + (A%10) = 10X
                9A = 10X - K , let K = A%10
                A = (10X - K)/9
                A = X + (X - K)/9
            For K equals to 0 to 9, if (X - K)%9 = 0, then A would be a solution.
            If we get a solution for K = 0, then we would also get a solution for
            K = 9 in this case. That means, if X%9 = 0, then there exists two
            solutions: A = X + X//9 - 1 and A = X + X//9.
            Otherwise the only solution would be A = X + X//9, where '//'
            indicates integer division.
*/

#include<bits/stdc++.h>
using namespace std;
 
#define     forn(i,ii,n)         for(int i=ii; i<=n; ++i)
#define     pb                  push_back
#define     sz(x)               (int)x.size()
#define     all(aa)             a.begin(),a.end()
#define		nl 					cout << endl
#define     kase(x)             cout << "Case " << x <<": "
#define     fastt               ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     dbg(args...)        do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;


template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
 
/*typedef*/
typedef long long ll;


/*****************************************************************************/

void solve(ll x){
    vector<ll> a;
    forn(i,0,9) {if((x+i)%9==0) a.pb(x+((x-i)/9));}
    sort(all(a));
    cout << a[0];
    forn(i,1,sz(a)-1) cout << " " << a[i];
    nl;
}
int main()
{
	
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    

    fastt;
    int t,i=0;
    ll n;
    cin>>t;
    while(t--) {
        cin>>n;
        kase(++i);
        solve(n);
    }


	return 0;
}