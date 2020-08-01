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
#define ud  0		//undiscoverd

#define INF -1

vector<vi>adjlist;
map<string,int>node_dis;
int source, des;
vi vis;

int bfs(){
	
	if(source == des) return 0;

	queue<pii>q;
	q.push(pii(source,0));
	vis[source] = d;
	
	while(!q.empty()){
		pii u = q.front(); q.pop();
		vis[u.first] = f;
		for(int v : adjlist[u.first]){
			//dbg(u.first,u.second,v);
			if(v==des){ return u.second+1;}
			if(vis[v]==ud){
				vis[v] = d;
				q.push(pii(v,u.second+1));
			}
		}
	}
	return -1;
}

int main()
{
	//fastt;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n ;

	cin>>n; cin.ignore();cin.ignore();


	while(n--){
	
		node_dis.clear();
		adjlist.clear();

		string str;
		vector<string>dic;

		int i=-1;
		while(getline(cin,str)){
			if(str=="*") break;
			dic.pb(str);
			node_dis[str] = ++i;
		}


		int size = dic.size();
		
		adjlist.resize(size);

		for(int i =0 ; i<size ; ++i){
			for(int j = i+1 ; j<size ; ++j){
				if(dic[i].size() != dic[j].size()) continue;

					int count=0, len = dic[i].size();

					for(int k =0 ; k<len ; ++k){
						if(dic[i][k]!=dic[j][k]) count++;
					}

					if(count==1){ adjlist[i].pb(j); adjlist[j].pb(i); }
			}
		}

		string query;
		while(getline(cin,query)){

			if(query=="") break;
			vis.clear();
			vis.resize(size,0);
			int i=-1;
			stringstream s(query);
			string val[2];
			while(s >> val[++i]);
			
			source = node_dis[val[0]];
			des = node_dis[val[1]];
			cout<<dic[source]<<" "<<dic[des]<<" "<<bfs()<<endl;

		}

		if(n>0) cout<<"\n";
	}

	return 0 ;
}