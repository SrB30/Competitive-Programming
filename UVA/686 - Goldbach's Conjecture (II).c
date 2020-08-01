#include <stdio.h>
#include <math.h>

int main()
{
    int siv[32770]={1,1,0}, i, j, t=32766, k, n, mul=0;

    for(j=2; (2*j)<=t; j++)
    {
        siv[2*j]= 1;
    }

    k = sqrt(t);

    for(i=3; i<=k; i+=2)
    {
        if(siv[i] == 0)
        {
            for(j=3; (i*j)<=t; j++)
            {
                siv[i*j]= 1;
            }
        }
    }

    while(scanf("%d", &n) ==1)
    {
        if(n==0)
            return 0;
        j=0;

        if(siv[n-2]==0)
            j++;

        k= n/2;
        for(i=3; i<=k; i+=2)
        {
            if(siv[i]==0)
                if(siv[n-i]==0)
                    j++;
        }
        printf("%d\n", j);
    }

    return 0;
}
