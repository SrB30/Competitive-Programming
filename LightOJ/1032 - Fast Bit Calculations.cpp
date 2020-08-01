#include<bits/stdc++.h>
using namespace std;
 
#define     infMx               LONG_LONG_MIN
#define     infMn               LONG_LONG_MAX

#define     forn(i,ii,n)        for(int i=ii; i<=n; ++i)
#define     ford(i,n,ii)        for(int i=n; i>=ii; --i)

#define     fini(i,ii,inc)      for(int i=ii; i<n; i+=inc)
#define     fnid(i,n,ii,dec)    for(int i=n; i>ii; i-=dec)
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
 
 
int setbit(int N,int pos){return N=N | (1<<pos);}
int resetbit(int N,int pos){return N= N & ~(1<<pos);}
bool checkbit(int N,int pos){return (bool)(N & (1<<pos));}

/*******************************************************************************************/

string s="0000000000000000000000000000000";
int mx;

ll dp[32][32][2];
ll digitDp(int idx, int sum, int digitTaken, bool tight)
{
    if(idx>=mx) return sum;
    ll &ret = dp[idx][sum][digitTaken];
    if(!tight && ret!=-1) return ret;

    int mxDigit = tight ? s[idx]-48 : 1;

    ret=0;
    for(int i=0; i<=mxDigit; i++){
        ret += digitDp(idx+1, sum+(digitTaken && i), i, (tight && i==mxDigit) ? 1 : 0 );
    }

    return ret;
}
int main()
{
	#ifndef ONLINE_JUDGE
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    #endif

    fastt;

    /*#ifndef timeComplexity
    clock_t st = clock();
    #endif*/
    int t,n, i=0;
    cin>>t;
    while(t--){
        cin>>n;
        forn(i,0,30) s[30-i] = checkbit(n,i)+48;
        mx=sz(s);
        mem(dp,-1);
        ll ans = digitDp(0,0,0,true);


        kase(++i); cout << ans << endl;
    }
    

    /*#ifndef timeComplexity
    st = clock() - st;
    dbg((double)st/CLOCKS_PER_SEC);
    #endif*/

	return 0;
}