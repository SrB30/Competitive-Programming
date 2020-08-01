#include<bits/stdc++.h>

using namespace std;

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

/**************************************************************************************************/


const ll maxn = 1.5e7;
bitset<maxn+2> isprime;
vector<ll> primes;

void seive()
{
    ll sq = sqrt(maxn);
    isprime[2]=1;
    for (ll i=1; i<= maxn; i+=2) isprime[i] = 1;

    primes.pb(2LL);
    for (ll i=3; i<=maxn ; i+=2 ){
        if(isprime[i]){
            primes.pb(i);
            if(i<=sq){
                for (ll j=i*i; j<=maxn; j+=i*2) isprime[j]=0;
            }
        }
    }
    //dbg(sz(primes));
}


ll solve(ll n)
{
    vector<ll> prm;
    for(int i=0; i<sz(primes) && primes[i]<=sqrt(n); i++){
        if(n<maxn){if(isprime[n]) break;}
        ll d=0;
        while(n%primes[i]==0){d++; n/=primes[i];}
        if(d>0 && primes[i]>2) prm.pb(d);
    }
    if(n>2LL) prm.pb(1);
    if(sz(prm)==0) return 0;
    if(sz(prm)==1) return prm[0];
    
    ll cnt=1;
    for(auto x: prm) cnt*=(x+1);
    return cnt-1;
    
}

int main()
{
	
     //  freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    

    fastt;
    seive();
    int t,i=0;
    ll n;
    cin>>t;
    while(t--){
        cin>>n;
        kase(++i);
        cout << solve(2LL*n) << endl;
    }

	return 0;
}