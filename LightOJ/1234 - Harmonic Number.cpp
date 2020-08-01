#include<bits/stdc++.h>

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
 

/*****************************************************************************/
const int M = 1e6;
double c = 0.5772156649015328606065120900824024310421;
double h[M+1];
void pre(){
    forn(i,1,M) h[i]= (1.0/i) + h[i-1];
}
int main()
{
	
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    

    fastt;
    pre();
    int n,t,i=0;
    double ans;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=M) ans = h[n];
        else ans = (double)log(n) + ((double)1.0/(2*n)) + c;
        kase(++i);
        cout << setprecision(10) << fixed << ans << endl;
    }



	return 0;
}