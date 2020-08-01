#include <stdio.h>
#include <math.h>
int nc;
int nod[64730];
int flag[1005], prime[170];


int main()
{
    int t, a=0, b, x, y, ans, tc=1, add,i,j, pow, cnt, k,mid,beg=0,end;

    prime[a++]=2;

    for(b=3; b<1000; b+=2)
    {
        if(flag[b]==0)
        {
            prime[a++]=b;
            if((1000/b) >= b)
            {
                y=b*2;
                for(x=b*b; x<1000; x+=y)
                    flag[x]=1;
            }
        }
    }



    nod[0] = 1;
    nod[1] = 2;
    for(nc=2; nod[nc-1]<1000005; nc++)
    {
        x = nod[nc-1];
        cnt=1;
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

        nod[nc] = nod[nc-1] + cnt;
    }



    scanf("%d", &t);

    while(tc<=t)
    {
        scanf("%d%d", &x, &y);


        beg=0;
        end=nc;
        b=0;

        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nod[mid]==x)
            {
                b=mid;
                break;
            }
            if(nod[mid]<x)
                beg=mid+1;
            else end=mid-1;
        }
        if(b==0 && beg!=0)
            b=beg;



        beg=0;
        end=nc;
        a=0;

        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nod[mid]==y)
            {
                a=mid;
                break;
            }
            if(nod[mid]<y)
                beg=mid+1;
            else end=mid-1;
        }
        if(a==0 && beg!=0)
            a=beg;


        ans=a-b+1;

        if(nod[a]>y)
            ans--;
        if(nod[b]< x)
            ans--;

        printf("Case %d: %d\n", tc,ans);
        tc++;
    }

    return 0;
}
