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
typedef pair<ll,ll> pii;
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


/*****************************************************************************/
const int maxn = 1e6;
vector<pii> facts(maxn+1);
void preprocess()
{
    facts[0].ff=0,facts[0].ss=0;
    forn(i,1,maxn){
        int n=i;
        facts[i]=facts[i-1];

        int d=0;
        while(n%2==0) d++, n/=2;
        facts[i].ff += d;

        d=0;
        while(n%5==0) d++, n/=5;
        facts[i].ss += d;
    }
}


ll solve(int n, int r, int p, int q){
    pii up = facts[n];
    pii down=facts[r];
    down.ff += facts[n-r].ff;
    down.ss += facts[n-r].ss;

    pii pw = pii({(facts[p].ff-facts[p-1].ff)*q, (facts[p].ss-facts[p-1].ss)*q});

    up = pii({up.ff+pw.ff-down.ff, up.ss+pw.ss-down.ss});

    return min(up.ff,up.ss);
}

int main()
{
	
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    

    fastt;
    preprocess();
    int t,i=0,n,r,p,q;
    cin>>t;
    while(t--){
        kase(++i);
        cin>>n>>r>>p>>q;
        ll ans =solve(n,r,p,q);
        cout << ans << endl;
    }


	return 0;
}