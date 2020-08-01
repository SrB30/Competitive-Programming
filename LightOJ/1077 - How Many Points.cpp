#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

using namespace std;
 
#define     infMx               LONG_LONG_MIN
#define     infMn               LONG_LONG_MAX

#define     forn(i,ii,n)         for(int i=ii; i<=n; ++i)
#define     ford(i,n,ii)         for(int i=n; i>=ii; --i)
#define     repit(i, c)         for( auto i = (c).begin(); i != (c).end();++i )
 
#define     pb                  push_back
#define     eb                  emplace_back
#define     sz(xx)              (int) xx.size()
#define     mk                  make_pair
#define     mem(x,v)            memset(x,v,sizeof x)
#define		clr(xx)				xx.clear()
#define		ff 					first
#define		ss 					second
#define		all(x)				x.begin(),x.end()
#define		nl 					cout << endl
#define     kase(x)             cout << "Case " << x <<": "
#define     fastt               ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     dbg(args...)        do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;

template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}

typedef long long ll;

/*****************************************************************************/


int main()
{
	
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    

    fastt;
    int t,i=0;
    ll x1,x2,y1,y2;
    cin>>t;
    while(t--){
        kase(++i);
        cin>>x1>>y1>>x2>>y2;
        x1 = abs(x1-x2);
        y1 = abs(y1-y2);
        //dbg(x1,y1);
        ll ans = __gcd(x1,y1)+1;
        cout << ans << endl;
    }


	return 0;
}