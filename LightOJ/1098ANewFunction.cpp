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

ll countDivisiblesInRange(ll a,ll b,ll m)
{
	return (b/m) - (a/m) + 1;
}
ll csod(ll n)
{
	ll sum=0;
	int d = sqrt(n);
	fin(i,2,d+1){
		ll a = (ll)i*i;
		ll cnt = countDivisiblesInRange(a,n,i);
		ll lineSum = (cnt-1)*i;
		ll edgeSum = (cnt*(2*i + (cnt-1)*1))/2; 
		sum += (lineSum+edgeSum);
	}
	return sum;
}

int main()
{
	#ifndef ONLINE_JUDGE
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    #endif

    fastt;
    int t,n,i=0;
    cin>>t;
    while(t--){
    	cin>>n;
    	cout <<"Case " << ++i << ": " << csod(n) << endl;
    }
    
    

	return 0;
}