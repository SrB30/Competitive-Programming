// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

using namespace std;
 
#define     infMx               LONG_LONG_MIN
#define     infMn               LONG_LONG_MAX

#define     forn(i,ii,n)         for(int i=ii; i<=n; ++i)
#define     ford(i,n,ii)         for(int i=n; i>=ii; --i)
#define     repit(i, c)         for( auto i = (c).begin(); i != (c).end();++i )
 
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
#define     kase(x)             cout << "Case " << x <<":\n"
#define     fastt               ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     dbg(args...)        do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
 
///Geometry
#define		distance(x1,y1,x2,y2) 		sqrt((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))
#define 	triangleArea(a,b,c,s) 		sqrt(s*(s-a)*(s-b)*(s-c))
#define 	triAngle(a,b,c) 			cosi((b*b+c*c-a*a)/(2*b*c))
 
///Trigonmetry
#define PI acos(-1.0)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI

#define gray    1		//discoverd
#define black  -1		//finished
#define white   0		//undiscoverd

template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
 
/*typedef*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ull> vul;
typedef pair<int,int> pii;
typedef pair<int,ull> piul;
typedef pair<int,double> pid;
typedef vector<pii> vii;
typedef vector<pid> vid;
typedef vector<piul> viul;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef set<int> si;
typedef priority_queue <pii, vector<pii>, greater<pii> > pq;	///for djkstra
/*typedef ends*/

const int mx = 1e5+50005;
int arr[mx];
int tree[mx*4];

int init(int node, int beg, int end)
{
    if(beg==end) { return (tree[node]=(int)(arr[beg]>0)); }

    int leftNode = node*2+1;
    int rightNode  = leftNode+1;

    int mid = (beg+end)/2;

    int lv = init(leftNode,beg,mid);
    int rv = init(rightNode,mid+1,end);

    return (tree[node] = lv+rv);
}

int ans;
int query(int node, int beg, int end, int pos)
{
    // dbg(beg,end,tree[node],pos,ans);
    if(end<beg) return 0;
    if(ans>-1 || tree[node]<pos) return tree[node];
    if(beg==end && pos==tree[node]){
        ans = arr[beg];
        // dbg("yes",ans);
        arr[beg]= 0;
        return (tree[node]=0);
    }
    if(beg==end) return tree[node];

    int leftNode = node*2+1;
    int rightNode  = leftNode+1;
    int mid = (beg+end)/2;

    int leftValue = query(leftNode,beg,mid,pos);
    int rightValue  = query(rightNode,mid+1,end,pos-leftValue);

    return (tree[node] = leftValue+rightValue);
}

int add (int node, int beg, int end, int pos, int val)
{
    if(end<beg) return 0;
    if(pos>end || pos<beg) return tree[node];
    
    if((beg==end) && (beg==pos)) {arr[beg]=val; return (tree[node]= (int)(arr[beg]>0));}
    else if(beg==end) return tree[node];

    int leftNode = node*2+1;
    int rightNode  = leftNode+1;
    int mid = (beg+end)/2;

    int lv = add(leftNode,beg,mid,pos,val);
    int rv = add(rightNode,mid+1,end,pos,val);

    return (tree[node] =lv+rv);
}


int main()
{
	
    // freopen("in.txt", "r", stdin);
    //   freopen("out.txt", "w", stdout);
    
    fastt;
    ll t,tc=0,n,q,p, pos;
    char c;
    cin>>t;

    while(t--){
        cin>>n>>q;
        forn(i,0,n-1) cin>>arr[i];
        forn(i,n,n+q+2) arr[i]=0;
        mem(tree,0);
        init(0,0,n+q);

        kase(++tc);

        pos = n-1;
        forn(i,1,q){
            cin.ignore();
            cin>>c>>p;
            if(c=='a') add(0,0,n+q,++pos,p);
            else {
                ans = -1;
                // dbg(p,tree[0]);
                if(p>tree[0]) ans = 0;
                else query(0,0,n+q,p);
                if(ans <1) cout << "none" << endl;
                else cout << ans << endl;
            }
            // forn(i,0,pos) cout << arr[i] << " ";
            // nl;
        }
    }

	return 0;
}