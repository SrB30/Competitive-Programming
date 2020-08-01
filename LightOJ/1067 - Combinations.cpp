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
 
/*typedef*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ull> vul;
typedef pair<int,int> pii;
typedef pair<int,ull> piul;
typedef pair<int,double> pid;
typedef vector<pii> vii;
typedef vector<pid> vid;
typedef vector<piul> viul;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef set<int> si;
typedef priority_queue <pii, vector<pii>, greater<pii> > pq;	///for djkstra
/*typedef ends*/
 

/*functions*/
template<typename T> T extGcd(T a, T b, T& x, T& y) { if(a==0) { x=0,y=1; return b; } T x1,y1,gcd = extGcd(b%a,a,&x1,&y1); x= y1-(b/a)*x1, y = x1; return gcd;}
template<typename T> T bigMod(T a, T p, T m) { if(p==1) return a; T x = bigMod(a,p/2,m)%m; x = (x*x)%m; return (p&1) ? (x*a)%m : x;}
template<typename T> T modMul(T a, T b, T m) { return ((a%m)*(b%m))%m; }
template<typename T> T modAdd(T a, T b, T m) { return ((a%m)+(b%m))%m; }
template<typename T> T modSub(T a, T b, T m) { return (a-b+m)%m; }
template<typename T> T modInverse(T a , T m) { return bigMod(a,m-2,m); }  ///m must be prime


const int maxn=1e6;
const ll mod = 1000003;
ll fact[maxn+1];

void factorial()
{
    fact[0]=1;
    forn(i,1,maxn) fact[i] = modMul(fact[i-1],(ll)i, mod);
}
ll ncr(int n, int r){
    return modMul(fact[n],modInverse(modMul(fact[r],fact[n-r],mod),mod),mod);
}
int main()
{
	
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    

    fastt;
    factorial();
    int t,i=0,n,r;
    cin>>t;
    while(t--){
        cin>>n>>r;
        ll ans = ncr(n,r);
        kase(++i); cout << ans << endl;
    }


	return 0;
}