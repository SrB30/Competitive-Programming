#include<bits/stdc++.h>

using namespace std;

#define     forn(i,ii,n)         for(int i=ii; i<=n; ++i)

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
typedef pair<int,int> pii;
/**************************************************************************************************/


const int maxn = 1e6+5;
pii phi[maxn];
int save[78500], ids[78500];
int a[10002],c;

void seive()
{
    int i,j;
    phi[0].ff=phi[1].ff=0;
    for(i=2; i<maxn; i+=2) phi[i].ff /= 2;

    for (i=3; i<maxn ; i+=2 ){
        if(phi[i].ff==i){
            for (j=i; j<maxn; j+=i) phi[j].ff= (phi[j].ff/i)*(i-1);
        }
    }

    save[c]= phi[0].ff; ids[c++]= phi[0].ss;
    int mx=0;
    forn(i,1,maxn-1) {
        if(phi[i].ff>mx) {save[c]=phi[i].ff;ids[c++]=phi[i].ss; mx= phi[i].ff;}
    }
}

ll solve(int n)
{
    ll ans=0;
    forn(i,0,n-1){
        int id = lower_bound(save,save+c,a[i])-save;
        ans += ids[id];
    }
    return ans;
}

int main()
{
	
      // freopen("in.txt", "r", stdin);
      //   freopen("out.txt", "w", stdout);
    

    fastt;
    forn(i,0,maxn-1) {phi[i]=pii({i,i});}
    seive();
    int t,k=0,n;
    cin>>t;
    while(t--){
        cin>>n;
        forn(i,0,n-1) cin>>a[i];
        kase(++k);
        cout << solve(n) << " Xukha" << endl;
    }

	return 0;
}