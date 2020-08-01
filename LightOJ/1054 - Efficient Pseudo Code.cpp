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
typedef pair<int,ll> pii;
typedef vector<pii> vii;

/*functions*/
template<typename T> T extGcd(T a, T b, T& x, T& y) { if(a==0) { x=0,y=1; return b; } T x1,y1,gcd = extGcd(b%a,a,&x1,&y1); x= y1-(b/a)*x1, y = x1; return gcd;}
template<typename T> T bigMod(T a, T p, T m) { if(p==1) return a; T x = bigMod(a,p/2,m)%m; x = (x*x)%m; return (p&1) ? (x*a)%m : x;}
template<typename T> T modMul(T a, T b, T m) { return ((a%m)*(b%m))%m; }
template<typename T> T modAdd(T a, T b, T m) { return ((a%m)+(b%m))%m; }
template<typename T> T modSub(T a, T b, T m) { return (a-b+m)%m; }
template<typename T> T modInverse(T a , T m) { return bigMod(a,m-2,m); }  ///m must be prime

 
/**************************************************************************************************/


const int maxn = 5e4;
const ll mod = 1e9+7;
bitset<maxn> isprime;        //prime=0,not_prime=1
vector<int> primes;
vii factors;

void seive()
{
    int sq = sqrt(maxn);
    for(int i=4; i<=maxn; i+=2) isprime[i]=1;

    primes.pb(2);
    for (int i=3; i<=maxn ; i+=2 ){
        if(!isprime[i]){
            primes.pb(i);
            if(i<=sq){
                for (int j=i*i; j<=maxn; j+=(2*i)) isprime[j]=1;
            }
        }
    }
    //dbg(sz(primes));
}

void primeFactorize(int n, int m)
{
    int x=sqrt(n);
    //dbg(n,m);
    for(int i=0,d=0; i<sz(primes) && primes[i]<=x && n>1; i++,d=0){
        //dbg(primes[i],d,m,n);
        if(n<maxn){ if(!isprime[n]) break;}

        while(n>1 && n%primes[i]==0) d++, n/=primes[i];
        if(d>0) factors.pb({primes[i],(ll)d*m});
    }
    //dbg(n);
    if(n>1) factors.pb({n,m});

    //for(auto x : factors)dbg(x.ff,x.ss);
}


int main()
{
	
       //freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    

    fastt;
    seive();
    int t,i=0, n,m;

    cin>>t;
    while(t--){
        cin>>n>>m;
        factors.clear();
        primeFactorize(n, m);
        ll ans=1;
        for(auto p : factors){
            ans = modMul(ans, modMul(modSub(bigMod((ll)p.ff,(ll)p.ss+1,mod),1LL,mod),modInverse((ll)p.ff-1,mod),mod),mod);
        }

        kase(++i); cout << ans << endl;
    }


	return 0;
}