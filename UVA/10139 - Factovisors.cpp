#include<bits/stdc++.h>

#define pb push_back
#define sz(xx) xx.size()
#define dbg(args...) do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
///Geometry
#define distance(x1,y1,x2,y2) ((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))
#define triangleArea(a,b,c,s) sqrt(s*(s-a)*(s-b)*(s-c))
#define triAngle(a,b,c) cosi((b*b+c*c-a*a)/(2*b*c))

using namespace std;

/*typedef*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef pair<int,int> pii;
typedef vector<pii> vii;
/*typedef*/

template< typename T >
void print(const T& v) {
    cerr << v << ' ' ;
}

template< typename T1, typename... T2 >
void print( const T1& first, const T2&... rest ){
    print(first);
    print(rest...) ;
}
/*********************************************************************************************************/
/*********************************************************************************************************/

int n;

bool isdivides(int f, int s)
{
    int p = n, d=0;
    while(p>=f)
        d += (p/=f);
    if(d<s) return false;

    return true;
}


bool primefact(int m)
{
    int sq = sqrt(m), p=m;

    int d=0;
    while(p%2==0)
    {
        d++;
        p /= 2;
    }
    //primes.pb(pii(2,d));
    if(d>0) if(!isdivides(2, d)) return false;

    for (int i=3; i<=sq && p>1 ; i+=2 )
    {
        d=0;
        while(p%i==0)
        {
            d++;
            p /= i;
        }
        if(d>0) if(!isdivides(i, d)) return false;
    }
    if(p>1)
        if(!isdivides(p, 1)) return false;

    return true;
}




int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    /* Code */

    int m;
    while(cin >>n >> m)
    {
        vii primes;

        bool check = primefact(m);

        if(check)
            cout << m << " divides " << n << "!" << endl;
        else cout << m << " does not divide " << n << "!" << endl;
    }


    return 0;
}
