#include<bits/stdc++.h>
using namespace std;

#define 	fin(i,ii,n)			for(int i=ii; i<n; ++i)
#define 	fni(i,n,ii)			for(int i=n; i>ii; --i)
#define		repit(i, c)			for( auto i = (c).begin(); i != (c).end();++i )
#define		dbg(args...)		do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
#define		pb					push_back
#define		sz(xx)				xx.size()
#define		mk					make_pair

template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vii;
typedef set<int> si;


const int  maxn = 1e7+1;
vector<int> primes;

void seive()
{
	bitset<maxn+1> spf;
    int sq = sqrt(maxn);

    spf[1]=1;
    for (int i=2; i<=maxn ; i+=2 ) spf[i]= 1;

    primes.pb(2);
    for (int i=3; i<maxn ; i+=2 )
    {
        if(!spf[i])
        {
            primes.pb(i);
            if(i<=sq){
                for (int j=i*i; j<maxn; j+=(2*i)) {spf[j]=1;}
            }
        }
    }
}


int primefactAns(ll n, int ps)
{
	//dbg("df");
	int i=0;
	vector<int>store;
	while((ll)(primes[i]*primes[i])<=n && i<ps && n>1){
		int d=0;
		while(n%primes[i]==0){
			n/=primes[i];
			d++;
		}
		if(d>0) store.pb(d);
		i++;
	}
	if(n>1) store.pb(1);
	//dbg("df");
	ll ans=1;
	int st = sz(store);
	fin(j, 0, st){
		ans*= (2*store[j]+1);
	}
	ans = (ans+1)/2;

	return ans;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);


	ll n;
	int t;
	cin>>t;
	int c=t;

	seive();
	int ps = sz(primes);
	while(t--){
		cin>>n;
		//int ans = primefactAns(n, ps);
		cout <<"Case " << c-t << ": " << primefactAns(n, ps) << endl;
	}

	return 0;
}
