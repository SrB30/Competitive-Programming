#include<bits/stdc++.h>

using namespace std;
 
#define     forn(i,ii,n)         for(int i=ii; i<=n; ++i)
 
#define     pb                  push_back
#define     eb                  emplace_back
#define     sz(xx)              (int) xx.size()
#define     mk                  make_pair
#define     mem(x,val)          memset(x,val,sizeof x)
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
/*typedef ends*/
 
const int maxn = 1e4;
int spf[maxn+5];
void seive()
{
    int sq = sqrt(maxn); spf[1]=maxn;
    for (int i=3; i<= maxn; i+=2) spf[i] = i;
    for (int i=2; i<=maxn ; i+=2 ) spf[i]= 2;

    for (int i=3; i<=maxn ; i+=2 ){
        if(spf[i]==i){
            if(i<=sq){
                for (int j=i*i; j<=maxn; j+=(2*i)){ if(spf[j]==j) spf[j]=i; }
            }
        }
    }
}

int frq[maxn+5];
vector<int> primes;
void divs(int n)
{
    int prv=spf[n], mul=1;
    while(n>0){
        if(prv==spf[n]) {mul*=spf[n];}
        else {
            if(frq[prv]==0) primes.pb(prv);
            frq[prv] = max(mul,frq[prv]);
            prv=spf[n],mul=spf[n];
        }
        //dbg(n,spf[n],frq[prv]);
        n/=spf[n];
    }
}

int mul(char c, int x){ return (c-48)*x; }
int add(char c, int x){ return (c-48)+x; }

void mulStr(string& s, int n)
{
    int d,x,q,sc,mc,i, inc=0;
    string t=s;
    s="";
    while(n>0){
        d=n%10; n/=10;
        for(i=0,mc=0,sc=0; i<sz(t); i++){
            x = mul(t[i],d)+mc;
            mc = x/10; x = (x%10)+sc;

            if(i+inc < sz(s)) x = add(s[i+inc],x);
            q= x%10; sc = x/10;

            if(i+inc < sz(s)) s[i+inc]= q+48;
            else s+=q+48;
        }

        q=sc+mc, inc++;
        while(q>0) {s+= (q%10)+48; q/=10;}
    }
}


int main()
{
	
       //freopen("in.txt", "r", stdin);
         //freopen("out.txt", "w", stdout);
    

    fastt;
    int t,n,i=0, x;
    seive();

    cin>>t;
    while(t--){
        cin>>n;
        mem(frq,0);primes.clear();

        forn(i,1,n){
            cin>> x;
            divs(x);
        }
        //dbg(sz(primes));
        string s="1";
        forn(i,0,sz(primes)-1) { mulStr(s, frq[primes[i]]); /*dbg(primes[i], frq[primes[i]], s);*/ }
        reverse(all(s)); //dbg(sz(s));

        kase(++i); cout << s << endl;
    }


	return 0;
}