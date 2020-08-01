#include<bits/stdc++.h>
using namespace std;

#define     pb                  push_back
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
typedef vector<ll> vl;
/*typedef ends*/


//const unsigned mod = (1LL<<32)-1;
const ll maxn = 1e8;
const int s = 5761456;
unsigned save[s+1], primes[s+1];

ll spf[maxn/64+1];

void seive()
{
    ll i,j;
    int c=1;

    primes[0]=1; save[0]=1;
    primes[1]=2; save[1]=2;

    for (i=3; i<maxn ; i+=2 ){
        if(((spf[i>>6]) & (1LL<<(i&63))) == 0){
            primes[++c]=i; save[c]= i*save[c-1];
            for (j=i*i; j<maxn; j+=(2*i)) spf[j>>6] |= (1LL<<(j&63));
        }
    }
    // dbg(c);
}

unsigned solve(unsigned n)
{
    unsigned x, ans= save[(upper_bound(primes,primes+s, n)-primes)-1];
    //dbg(ans);

    unsigned sq= sqrt(n);
    for(int i=1; primes[i]<=sq; i++){
        x = n/primes[i];
        while(x>=primes[i]){ans*=primes[i]; x/=primes[i];}
    }
    return ans;
}

int main()
{
    fastt;
    seive();
    int t, i=0, n;
    cin>>t;
    while(t--){
        cin>>n;
        unsigned ans = solve(n);
        kase(++i);
        cout << ans << endl;
    }

	return 0;
}