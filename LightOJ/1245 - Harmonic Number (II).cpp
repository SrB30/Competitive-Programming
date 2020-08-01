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
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vii;
typedef set<int> si;

/*long long Ho( int n ) {
    long long res = 0;
    for( int i = 1; i <= n; i++ )
        res = res + n / i;
    return res;
}*/

/*	idea:
	for each i till sqrt(n) ans += (n/i) + i +  {( n/(i-1) -  (n/i) - 1)*(i-1)}
	i.e if n=13, i=2,
	ans += (13/2=6) + 2 + multiply (2-1)=1 with {from ((13/2=6)+1)=7 to ((13/1=13)-1)=12 };
		+= 6+2+(13-6-1)*1;
		+= 6+2+(6*1);
		+= 14;
*/

ll H(int n)
{
	if(n==1) return 1;
	if(n==3) return 5;
	int d = sqrt(n);
	//dbg(d);
	ll res=1+(ll)n;
	int tmp=n, cnt=n-2;
	fin(i,2,d+1){
		int q = n/i;
		int div = i;
		ll ans = (ll)(tmp-q-1)*(i-1);

		if(div>q) ans=0;
		if(div>=q) {div=0; cnt++;}
		
		cnt -= (tmp-q-1);
		cnt -= 2;
		tmp = q;

		res += ans;
		res+= q;
		res+=div;
	}
	//dbg(res,cnt);
	if(cnt>0){
		int q = n/(d+1);
		int div = d+1;
		ll ans = (ll)(tmp-q-1)*d;

		if(div>q) ans=0;
		if(div>=q) {div=0; cnt++;}

		cnt -= (tmp-q-1);
		cnt-=2;
		tmp = q;

		res += ans;
		res += q;
		res +=div;
	}
	//dbg(res,cnt);

	return res;
}

int main()
{
	fastt

	int t,n,i=0;
	cin >> t;
	while(t--){
		cin>>n;
		//cout << Ho(n) <<" ";
		cout << "Case " << ++i << ": " << H(n) << endl;
	}
	

	return 0;
}
