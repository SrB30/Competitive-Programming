#include<bits/stdc++.h>
using namespace std;

#define		fastt				ios_base::sync_with_stdio(false);cin.tie(NULL),cout.tie(NULL);
#define 	fin(i,ii,n)			for(unsigned int i=ii; i<n; ++i)
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


class node
{
public:
	bool isend;
	map<char, node*> next;
	node(){ isend = false; }
} * root;

bool insert(string s)
{
	bool isprefix=false;
	node* curr = root;

	fin(i,0, sz(s)){
		if(curr->isend) return true;
		if(curr->next.find(s[i]) == curr->next.end()) curr->next[s[i]]= new node();
		curr = curr->next[s[i]];
	}
	if(curr->next.begin() != curr->next.end()) return true;
	curr->isend =  true;

	return isprefix;
}

void del(node* cur)
{
	repit(nod,cur->next){
		del(nod->second);
	}

	delete(cur);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	fastt;
	int n, t;
	cin>>t;
	while(t--){
		cin>>n;
		string phn[n];
		int i=-1, tn=-1;
		bool isprefix;
		while(++tn<n) cin>>phn[tn];
		root =  new node();

		while(++i<n){
			isprefix = insert(phn[i]);
			if(isprefix) {cout << "NO" << endl; break; }
		}
		if(!isprefix)
			cout  << "YES" << endl;
		del(root);
	}

	return 0;
}
/*
2
3
91125426
97625999
911
5
113
12340
123440
12345
98346
*/