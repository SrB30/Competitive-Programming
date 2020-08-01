#include<bits/stdc++.h>
using namespace std;
 
#define     fin(i,ii,n)         for(int i=ii; i<n; ++i)
#define     fini(i,ii,inc)      for(int i=ii; i<n; i+=inc)
#define     fni(i,n,ii)         for(int i=n; i>ii; --i)
#define     fnid(i,n,ii,dec)    for(int i=n; i>ii; i-=dec)
#define     repit(i, c)         for( auto i = (c).begin(); i != (c).end();++i )
 
#define     pb                  push_back
#define     sz(xx)              (int) xx.size()
#define     mk                  make_pair
#define     clr(xx)             xx.clear()
#define     ff                  first
#define     ss                  second
#define     all(x)              x.begin(),x.end()
#define     nl                  cout << endl

#define     fastt               ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     dbg(args...)        do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
 
///Geometry
#define     distance(x1,y1,x2,y2)       sqrt((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))
#define     triangleArea(a,b,c,s)       sqrt(s*(s-a)*(s-b)*(s-c))
#define     triAngle(a,b,c)             cosi((b*b+c*c-a*a)/(2*b*c))
 
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
 
#define gray    1       //discoverd
#define black  -1       //finished
#define white   0       //undiscoverd
 
template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
 
/*typedef*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
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
typedef priority_queue <pii, vector<pii>, greater<pii> > pq;    ///for djkstra
/*typedef ends*/
 
 
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
 
/*direction array*/
 
/***4 moves***/
/*
int dx[] = { 0,  0, -1, +1 } ;
int dy[] = {-1, +1,  0,  0 };
 */
/***8 moves***/
/*
int dx[] = { 0,  0, -1, -1, -1, +1, +1, +1 } ;
int dy[] = {-1, +1, -1,  0, +1, -1,  0, +1 } ;
*/
 
/*direction array ends*/
 
/**************************************************************************************************/
 

/*
///for dijkstra
class node{
public:
    int at,cost;
    node(int a,int b){at=a,cost=b;}
    bool operator <(const node& e)const{return cost<e.cost;}
};
*/


/*
int bsrc(int h,int l, int k)
{
    int ans = -1;
    int hi=h, lo=l, mid;

    while(hi>=lo){
        mid = (lo+hi)/2;
        int x = a[mid];
        if(k==x) { ans = mid; break; }
        if(k > x) { lo=mid+1; }
        else { hi= mid-1; }
    }

    return ans;
}
*/

class edge{public: int v,flow;};

int n,m,d,b;
vi cap, db;
vector<vector<edge> > adj;
vi vis;
int c;
int dfs(int u, int mCap, int mFlow)
{
    queue <int> q;

    
}

void input(vi& entry)
{
    cap.clear();
    adj.clear();
    db.clear();
    vis.clear();

    int node,x,y,c;
    cin>>n;
    cap.resize(n);
    adj.resize(n);
    db.resize(n,0); ///b=1,d=2
    vis.resize(n,0);

    fin(j,0,n) cin>>cap[j];

    cin>>m;
    fin(j,0,m){
        cin>>x>>y>>c;
        adj[x-1].pb({y-1,c});
    }

    cin>>b>>d;
    fin(j,0,b+d){
        cin>> node;
        if(j>=b) db[node-1]=2;
        else { entry.pb(node-1); db[node-1]=1; }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt", "r", stdin);
     //    freopen("out.txt", "w", stdout);
    #endif

    fastt;
    int t;
    cin>>t;
    fin(i,0,t){
        vi entry;
        int transfered=0;
        input(entry);

        fin(j,0,sz(entry)){
            nl;
            dbg(j,j);
            fin(k,0,n) cout << cap[k] << " ";
            nl;
            c=entry[j];
            if(cap[entry[j]]>0) transfered += dfs(entry[j], cap[entry[j]],cap[entry[j]]);
        }
        cout << "Case " << i+1 << ": " << transfered << endl;
    }
    

    return 0;
}
/*
2

4

10 20 30 40

6

1 2 5

1 3 10

1 4 13

2 3 5

2 4 7

3 4 20

3 1

1 2 3 4

2

50 100

1

1 2 100

1 1

1 2
*/