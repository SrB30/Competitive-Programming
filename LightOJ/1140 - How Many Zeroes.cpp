#include<bits/stdc++.h>
using namespace std;

#define     pb                  push_back
#define     sz(xx)              (int) xx.size()
#define     mem(x,v)            memset(x,v,sizeof x)
#define     kase(x)             cout << "Case " << x <<": "
#define     fastt               ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<int> vi;


///idx = current digit index of the number
///tight =  restriction of digits or represents using digit isSmall than digit[idx]
    ///tight = 1 = upper bound of usable digit is restricted, range is (0 <= digitToBeUsed <= digit[idx])
    ///tight = 0 = upper bound of usable digit is not restricted, range is (0 <= digitToBeUsed <= 9)
///isStart
    ///isStart = 1 = starting integer, starting from 0, the number is 0000...0
    ///isStart = 0 = non starting integer, integer > 0 the number is 0000...1..
///sum = count of 0 so far

ll dp[12][12][12][2];
ll digitDp(int idx, int digitTaken, ll sum, int isStart, bool tight, vi& digit)
{
    if(idx==-1) return (sum+isStart);
    if(!tight && dp[idx][digitTaken][sum][isStart] != -1){return dp[idx][digitTaken][sum][isStart];}

    ll count=0;
    int k = (tight) ? digit[idx] : 9;

    for(int i=0; i<=k; i++)
        count += digitDp(idx-1, i, sum+(!isStart && (i==0)), (isStart && (i==0)), (tight && (i==digit[idx])), digit);

    if(!tight) dp[idx][digitTaken][sum][isStart]=count;
    return count;
}

void getDigit(ll n, vi& digit)
{
    if(n==0) {digit.pb(0); return;}
    while(n>0) { digit.pb(n%10); n /= 10; }
}

int main()
{
    fastt;
    ll n,m, t, i=0;
    cin>>t;
    while(t--){
        cin>>m>>n;

        vi digitA, digitB;

        if(m>10) getDigit(m-1,digitA);
        mem(dp,-1);
        ll ans1 = (m<=10) ? ((m==0)? 0 : 1) : digitDp(sz(digitA)-1, digitA[sz(digitA)-1], 0, 1, 1, digitA);

        if(n>=10) getDigit(n,digitB);
        mem(dp,-1);
        ll ans2 = (n<10) ? 1 : digitDp(sz(digitB)-1, digitB[sz(digitB)-1], 0, 1, 1, digitB);

        kase(++i); cout << ans2 - ans1 << endl;
    }

	return 0;
}
