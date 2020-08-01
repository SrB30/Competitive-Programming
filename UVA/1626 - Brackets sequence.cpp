#include<bits/stdc++.h>
using namespace std;
 
#define     minInf                 INT_MIN
#define     maxInf                 INT_MAX

#define     fin(i,ii,n)         for(int i=ii; i<n; ++i)
#define     fini(i,ii,inc)      for(int i=ii; i<n; i+=inc)
#define     fni(i,n,ii)         for(int i=n; i>ii; --i)
#define     fnid(i,n,ii,dec)    for(int i=n; i>ii; i-=dec)
#define     repit(i, c)         for( auto i = (c).begin(); i != (c).end();++i )
 
#define     pb                  push_back
#define     sz(xx)              (int) xx.size()
#define     mk                  make_pair
#define		clr(xx)				xx.clear()
#define		ff 					first
#define		ss 					second
#define		all(x)				x.begin(),x.end()
#define		nl 					cout << endl
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

/*functions*/
template<typename T> T extGcd(T a, T b, T& x, T& y)
{
    if(a==0) { x=0,y=1; return b; }
    T x1,y1,gcd = extGcd(b%a,a,&x1,&y1);
    x= y1-(b/a)*x1, y = x1;
    return gcd;
}
template<typename T> T bigMod(T a, T p, T m)
{
    if(p==1) return a;
    T x = bigMod(a,p/2,m)%m;
    x = (x*x)%m;
    return (p&1) ? (x*a)%m : x;
}
template<typename T> T modInverse(T a, T m) ///m must be prime
{
    if(__gcd(a,m)>1) return minInf;
    return bigMod(a,m-2,m);
}

/*
///for dijkstra
class node{
public:
	int at,cost;
	node(int a,int b){at=a,cost=b;}
	bool operator <(const node& e)const{return cost<e.cost;}
};
class edge{public: int v,w;};
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
int n;
string s;

bool match(char a, char b)
{
    return (a=='(' && b==')') || (a=='[' && b==']');
}

void printSolution(vvi& dp, int i, int j)
{
    //dbg(s[i],s[j]);
    if(i>j) return; ///all matched
    if(i==j){   ///single character, add a bracket to make it valid sequence of 2
        if(s[i]=='(' || s[i]==')') cout << "()";
        else cout << "[]";
        return;
    }

    if(match(s[i],s[j]) && dp[i][j]==dp[i+1][j-1]) {

        cout << s[i];
        printSolution(dp,i+1,j-1);
        cout << s[j];
        return;
    }

    for(int k=i; k<j; k++){
        if(dp[i][j]==dp[i][k]+dp[k+1][j]) {
            printSolution(dp,i,k);
            printSolution(dp,k+1,j);
            return;
        }
    }
}

void DP(vvi& dp)
{
    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            dp[i][j]=maxInf;

            if(match(s[i],s[j])) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);

            for(int k=i; k<j; k++) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
        }
    }
    //fin(i,0,n){ fin(j,0,n) cout << dp[i][j] << " "; nl;}
}

int main()
{
	#ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif

    fastt;
    int t;
    cin>>t;
    cin.ignore();

    while(t--){
        cin.ignore();
        getline(cin,s);
        n= sz(s);
        vvi dp(n+5,vi(n+5));

        fin(i,0,n) dp[i][i]=1, dp[i+1][i]=0;
        DP(dp);
        printSolution(dp, 0, n-1);
        nl;
        if(t>0) nl;
    }
    

	return 0;
}

/*
4

([(]



([[)]][

(())
*/