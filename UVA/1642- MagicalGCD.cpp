
#include<bits/stdc++.h>
using namespace std;
 
#define     infMx               LONG_LONG_MIN
#define     infMn               LONG_LONG_MAX

#define     fin(i,ii,n)         for(int i=ii; i<n; ++i)
#define     fini(i,ii,inc)      for(int i=ii; i<n; i+=inc)
#define     fni(i,n,ii)         for(int i=n; i>ii; --i)
#define     fnid(i,n,ii,dec)    for(int i=n; i>ii; i-=dec)
#define     repit(i, c)         for( auto i = (c).begin(); i != (c).end();++i )
 
#define     pb                  push_back
#define     sz(xx)              (int) xx.size()
#define     mk                  make_pair
#define     mem(x,v)            memset(x,v,sizeof x)
#define		clr(xx)				xx.clear()
#define		ff 					first
#define		ss 					second
#define		all(x)				x.begin(),x.end()
#define		nl 					cout << endl
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
 
 
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int nextN(int N) {return N + ( N & (-N));}
int parentN(int N) {return N - ( N & (-N));}
/*direction array*/
 
/***4 moves***/
/*
int dx[] = { 0,  0, -1, +1 } ;
int dy[] = {-1, +1,  0,  0 };
 */
/***8 moves***/
/*
int dx[] = { 0,  0, -1, -1, -1, +1, +1, +1 } ;
int dy[] = {-1, +1, -1,  0, +1, -1,  0, +1 } ;
*/
 
/*direction array ends*/
 
/**************************************************************************************************/

/*functions*/
template<typename T> T extGcd(T a, T b, T& x, T& y)
{
    if(a==0) { x=0,y=1; return b; }
    T x1,y1,gcd = extGcd(b%a,a,&x1,&y1);
    x= y1-(b/a)*x1, y = x1;
    return gcd;
}
template<typename T> T bigMod(T a, T p, T m)
{
    if(p==1) return a;
    T x = bigMod(a,p/2,m)%m;
    x = (x*x)%m;
    return (p&1) ? (x*a)%m : x;
}
template<typename T> T modMul(T a, T b, T m) { return ((a%m)*(b%m))%m; }
template<typename T> T modAdd(T a, T b, T m) { return ((a%m)+(b%m))%m; }
template<typename T> T modSub(T a, T b, T m) { return (a-b+m)%m; }
template<typename T> T modInverse(T a , T m) { return bigMod(a,m-2,m); }  ///m must be prime

/*
const int maxn = 3572;
int spf[maxn+1];
vector<int> primes;
void seive()
{
    int sq = sqrt(maxn);
    for (int i=1; i<= maxn; i+=2) spf[i] = i;
    for (int i=2; i<=maxn ; i+=2 ) spf[i]= 2;

    primes.pb(2);
    for (int i=3; i<=maxn ; i+=2 ){
        if(spf[i]==i){
            primes.pb(i);
            if(i<=sq){
                for (int j=i*i; j<=maxn; j+=(2*i)){ if(spf[j]==j) spf[j]=i; }
            }
        }
    }
    dbg(sz(primes));
}
*/

/*
///for dijkstra
class node{
public:
	int at,cost;
	node(int a,int b){at=a,cost=b;}
	bool operator <(const node& e)const{return cost<e.cost;}
};
class edge{public: int v,w;};
*/
/*
int bsrc(int h,int l, int k)
{
    int ans = -1;
    int hi=h, lo=l, mid;

    while(hi>=lo){
        mid = (lo+hi)/2;
        int x = a[mid];
        if(k==x) { ans = mid; break; }
        if(k > x) { lo=mid+1; }
        else { hi= mid-1; }
    }

    return ans;
}
*/
/*****************************************************************************/

bool cmp(pair<ll,int> a, pair<ll,int> b)
{
	return (a.ff != b.ff) ? a.ff<b.ff : a.ss < b.ss;
}
int main()
{
	#ifndef ONLINE_JUDGE
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    #endif

    fastt;
    int t;
    cin>>t;
    while(t--){
    	ll n, ans=0;
    	cin>>n;
    	vl a(n);
    	vector<pair<ll,int> > v;
    	fin(i,0,n) {cin>>a[i]; ans =max(ans,a[i]);}
    	v.pb({a[0],0});

    	fin(i,1,n){
    		vector<pair<ll,int> > tmp;
    		fin(j,0,sz(v)){
    			ll g = __gcd(v[j].ff, a[i]);
    			tmp.pb({g,v[j].ss});
    		}
    		tmp.pb({a[i],i});
    		sort(all(tmp), cmp);

    		v.clear();
    		for(int j=0; j<sz(tmp); j++){
    			if(j==0) v.pb(tmp[j]);
    			else if(tmp[j].ff == v[sz(v)-1].ff) continue;
    			v.pb(tmp[j]);

    			ll cur = v[sz(v)-1].ff * (i-v[sz(v)-1].ss + 1LL);
    			ans =  max(ans, cur);
    		}
    	}

    	cout << ans << endl;
    }

	return 0;
}