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


vii elp;
map<pii, int> mp;

bool cmp(const pii& el1, const pii& el2)
{
	return (el1.first < el2.first) || ((el1.first == el2.first) && (el1.second > el2.second));
}

int len, ind;
void LIS(int n, vi& length, vi& index)
{
	length[n-1] = 1, index[n-1]=-1;
	fni(i,n-2, -1)
	{
		length[i]=1, index[i]=-1;
		fni(j,n-1,i)
		{
			if(elp[i].first< elp[j].first && elp[i].second > elp[j].second){
				if(length[i]<length[j]+1) {length[i] = length[j]+1; index[i]=j;}
				if(length[i]>len) len=length[i],ind=i;
			}
		}
	}
}

void printSequence(vi& index)
{
	cout << len << endl;
	int i=ind;
	while(i>-1){
		cout <<  mp[elp[i]]+1 << endl;
		i = index[i];
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n=0, a, b;

	while(cin>>a>>b) { elp.pb(pii(a,b)); mp[pii(a,b)]=n; n++;}
	vi length(n), index(n);

	sort(elp.begin(), elp.end(), cmp);

	LIS(n,length,index);
	printSequence(index);

	//fin(i, 0, n){dbg(elp[i].first, elp[i].second);}



	return 0;
}
