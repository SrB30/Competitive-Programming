#include <stdio.h>
#include <math.h>
int nc;
int nod[64730];
int flag[1005], prime[170];

void sieve(void)
{
    int c=0,add,i,j;

    prime[c++]=2;

    for(i=3; i<1000; i+=2)
    {
        if(flag[i]==0)
        {
            prime[c++]=i;
            if((1000/i) >= i)
            {
                add=i*2;
                for(j=i*i; j<1000; j+=add)
                    flag[j]=1;
            }
        }
    }
    return;
}


int n_nod(int x)
{
    int k,pow,cnt=1;
    for(k=0; prime[k]<=sqrt(x); k++)
    {
        pow=0;
        if(x%prime[k]==0)
        {
            while(x%prime[k]==0)
            {
                pow++;
                x/=prime[k];
            }
            cnt*=pow+1;
        }
    }
    if(x>1)
        cnt*=2;

    return cnt;
}

int binary(int key)
{
    int mid,beg=0,end=nc;

    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(nod[mid]==key)
            return mid;
        if(nod[mid]<key)
            beg=mid+1;
        else end=mid-1;
    }
    return beg;
}

int main()
{
    int t, a, b, x, y, ans, tc=1;
    sieve();

    nod[0] = 1;
    nod[1] = 2;
    for(nc=2; nod[nc-1]<1000005;nc++)
    {
        nod[nc] = nod[nc-1] + n_nod(nod[nc-1]);
    }

    scanf("%d", &t);

    while(tc<=t)
    {
        scanf("%d%d", &x, &y);
        a=binary(y);
        b=binary(x);
        ans=a-b+1;

        if(nod[a]>y)
            ans--;
        if(nod[b]< x)
            ans--;

        printf("Case %d: %d\n",tc,ans);
        tc++;
    }

    return 0;
}
