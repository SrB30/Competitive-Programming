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
int nextN(int N) {return N + ( N & (-N));}
int parentN(int N) {return N - ( N & (-N));}

/*functions*/
template<typename T> T extGcd(T a, T b, T& x, T& y) { if(a==0) { x=0,y=1; return b; } T x1,y1,gcd = extGcd(b%a,a,&x1,&y1); x= y1-(b/a)*x1, y = x1; return gcd;}
template<typename T> T bigMod(T a, T p, T m) { if(p==1) return a; T x = bigMod(a,p/2,m)%m; x = (x*x)%m; return (p&1) ? (x*a)%m : x;}
template<typename T> T modMul(T a, T b, T m) { return ((a%m)*(b%m))%m; }
template<typename T> T modAdd(T a, T b, T m) { return ((a%m)+(b%m))%m; }
template<typename T> T modSub(T a, T b, T m) { return (a-b+m)%m; }
template<typename T> T modInverse(T a , T m) { return bigMod(a,m-2,m); }  ///m must be prime



const int maxn = 5*1e6;
ull phi[maxn+5];
void PHI()
{
    for (int i=0; i<= maxn; i++) phi[i] = i;

    for (int i=2; i<=maxn ; i++ ){
        if(phi[i]==(ull)i){
            for (int j=i; j<=maxn; j+=i){ phi[j] -= phi[j]/(ull)i; }
        }
    }
    forn(i,1,maxn) {phi[i] *= phi[i]; phi[i] += phi[i-1];}
}

/*****************************************************************************/


int main()
{
	
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    

    fastt;
    int t, a,b,i=0;
    PHI();
    cin>>t;
    while(t--){
    	cin>> a>>b;
    	kase(++i);
    	cout << phi[b]-phi[a-1] << endl;
    }
	return 0;
}