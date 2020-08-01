#include<bits/stdc++.h>
using namespace std;

#define 	fin(i,ii,n)			for(int i=ii; i<n; ++i)
#define 	fni(i,n,ii)			for(int i=n; i>ii; --i)
#define		repit(i, c)			for( auto i = (c).begin(); i != (c).end();++i )
#define		dbg(args...)		do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
#define		pb					push_back
#define		sz(xx)				xx.size()
#define		mk					make_pair
#define 	fastt 				ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vii;
typedef set<int> si;

#define d 	1		//discoverd
#define f  -1		//finished
#define u  0		//undiscoverd

const int maxn = 46341;

vi primes;
bitset<maxn+10> spf;

void seive()
{
    int sq = sqrt(maxn);

    //1=not prime, 0=prime;
    spf[1]=1;
    for(int i=4;i<maxn+1; i+=2) spf[i]=1;
    primes.pb(2);

    for (int i=3; i<=maxn ; i+=2 )
    {
        if(!spf[i])
        {
            primes.pb(i);
            if(i<=sq){
                for (int j=i*i; j<=maxn; j+=(2*i)){
                    if(!spf[j]) spf[j]=1;}
            }
        }
    }
}

int segmentedSieve(int a,int b)
{
	int cnt=0;
	if(b<=maxn){
		fin(i,a,b+1){ if(!spf[i]) cnt++; }
		return cnt;
	}
	if(a<=maxn){
		fin(i,a,maxn+1){ if(!spf[i]) cnt++; }
		a = maxn+1; 
	}

	ll lo=a,hi=b;
	int s = sz(primes), lim = sqrt(b);
	const int mx = 1e5+10;
	bitset<mx> sspf;

	for (int i=0; primes[i]<=lim && i<s; ++i)
	{
		ll lolim = (lo/primes[i])*primes[i];
		if(lolim<lo) lolim += primes[i];

		for (ll j=lolim; j<=hi; j+=primes[i]) {int l = j-lo; sspf[l] = 1;}
	}
	for(int i=a; i<b+1; i++){ if(!sspf[i-a]) cnt++; }

	return cnt;
}


int main()
{
	fastt;
	int tc=-1,t,a,b;
	cin>>t;
	while(++tc<t){
		cin>>a>>b;
		seive();
		int pr = segmentedSieve(a,b);
		cout << "Case " << tc+1 << ": " << pr << endl;
	}

	return 0;
}