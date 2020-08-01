// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
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
 
///Geometry
#define		distance(x1,y1,x2,y2) 		sqrt((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))
#define 	triangleArea(a,b,c,s) 		sqrt(s*(s-a)*(s-b)*(s-c))
#define 	triAngle(a,b,c) 			cosi((b*b+c*c-a*a)/(2*b*c))
 
///Trigonmetry
#define PI acos(-1.0)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI

#define gray    1		//discoverd
#define black  -1		//finished
#define white   0		//undiscoverd

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
 
 
int setbit(int N,int pos){return N=N | (1<<pos);}
int resetbit(int N,int pos){return N= N & ~(1<<pos);}
bool checkbit(int N,int pos){return (bool)(N & (1<<pos));}

 
/**************************************************************************************************/


const int maxn = 1e6, s=78498;
int spf[maxn+1], primes[s+2];
void seive()
{
    int sq = sqrt(maxn), c=0;
    for(int i=4; i<maxn; i+=2) spf[i]=1;    ///1=not prime;

    primes[c++]=2;
    for (int i=3; i<maxn ; i+=2 ){
        if(!spf[i]){
            primes[c++]=i;
            if(i<=sq){
                for (int j=i*i; j<maxn; j+=(2*i)) spf[j]=1;
            }
        }
    }
    // dbg(c);
}

ll primeFactorize(ll n)
{
    ll tot=1;
    for(int i=0,d=0; i<s && n>1 && primes[i]<=sqrt(n); i++,d=0){
        if(n<(ll)maxn){if(!spf[n])break;}
        while(n%primes[i]==0) d++, n/=primes[i];
        if(d>0) tot*=(d+1);
    }
    if(n>1) tot*=2;
    return (tot>>1);
}

ll solve(ll a, ll b)
{
    ll ret=0;
    forn(i,1,b-1){
        if(a%(ll)i==0) ret++;
    }
    return ret;
}

int main()
{
	
       freopen("in.txt", "r", stdin);
         freopen("out.txt", "w", stdout);
    
    clock_t  s = clock();
    fastt;
    seive();
    int t,kas=0;
    ll a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        kase(++kas);
        if(b*b>=a) {cout << "0" << endl; continue;}

        ll ans = primeFactorize(a) - solve(a,b);
        cout << ans << endl;
    }
    double sec = ((double)(clock() - s))/CLOCKS_PER_SEC;
    dbg(sec);

	return 0;
}