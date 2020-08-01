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


int total;
class node
{
public:
	bool isend;
	int num;
	map<char, node*> next;
	node(){ isend = false, num=0; }
} * root;


void insert(string s)
{
	node* curr = root;

	fin(i,0, sz(s)){
		if(curr->next.find(s[i]) == curr->next.end()) curr->next[s[i]]= new node();
		curr = curr->next[s[i]];
	}
	curr->isend =  true;
	curr->num++;
}

void del(node* cur)
{
	repit(nod,cur->next){
		del(nod->second);
	}

	delete(cur);
}

void display(node* cur, string s)
{
	if(cur->isend) cout << s <<fixed << setprecision(4) << " " << (cur->num*1.0 / total)*100 << endl;
	repit(nod,cur->next){
		display(nod->second, s+ nod->first);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	fastt;

	int t;
	cin>>t;

	string s;
	getline(cin,s);
	getline(cin,s);

	while(t--){
		root = new node();
		total=0;

		while(getline(cin,s)) {/*dbg(s);*/ if(s[0]=='\0') break; insert(s); total++;}
		display(root, "");
		if(t>0) cout << endl;

		del(root);
	}

	return 0;
}
/*
1

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow
*/