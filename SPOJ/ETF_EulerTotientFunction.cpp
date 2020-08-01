#include<bits/stdc++.h>

using namespace std;

#define     forn(i,ii,n)         for(int i=ii; i<=n; ++i)
#define     ford(i,n,ii)         for(int i=n; i>=ii; --i)
 
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
 
typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;


const int maxn = 1e6;
vi phi(maxn+1);

void PHI()
{
    for (int i=1; i<= maxn; i++) phi[i] = i;

    for (int i=2; i<=maxn ; i++){
        if(phi[i]!=i) continue;
        for (int j=i; j<=maxn; j+=i) phi[j] -= phi[j]/i;
    }
}


int main()
{
	
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    fastt;

    PHI();
    int n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        cout << phi[n] << endl;
    }

	return 0;
}