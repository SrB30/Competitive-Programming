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
#define     mem(x ,y)           memset(x , y , sizeof x )
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
template<typename T> T modInverse(T a, T m) ///m must be prime
{
    if(__gcd(a,m)>1) return infMn;
    return bigMod(a,m-2,m);
}

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


int dp[3][2000][2000];
int solve(int h, int a, int p, int cnt)
{
    if(h<1 || a<1) return 0;
    if(dp[p][h][a]>-1) return 1+dp[p][h][a];

    if(p==0){
        dp[p][h][a] = max(solve(h+3, a+2, 1,cnt+1), solve(h-5, a-10, 2,cnt+1));

    }
    if(p==1){
        dp[p][h][a] = max(solve(h-20, a+5, 0,cnt+1), solve(h-5, a-10, 2,cnt+1));
    }
    else{
        dp[p][h][a] = max(solve(h-20, a+5, 0,cnt+1), solve(h+3, a+2, 1,cnt+1));
    }
    return dp[p][h][a]+1;
}
int main()
{
	#ifndef ONLINE_JUDGE
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    #endif

    fastt;
    int t,h,a;
    cin>>t;
    while(t--){
        cin>>h>>a;
        int ans =0;
        for(int i=0; i<3; i++) {
            mem(dp, -1);
            ans = max(ans, solve(h,a,i,0));
        };
        cout << ans-1 << endl;
    }
    

	return 0;
}