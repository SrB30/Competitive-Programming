#include <stdio.h>
#include <math.h>
int siv[999999]={1,1};

int main()
{
    int i, j, t=999997, k, n;

    k = sqrt(t);

    for(i=3; i<=k; i+=2)
    {
        if(siv[i] == 0)
        {
            for(j=3; t>=(n= i*j); j+=2)
            {
                siv[n]= 1;
            }
        }
    }

    while(scanf("%d", &n) ==1)
    {
        if(n==0)
            return 0;
        j=0;

        k= n/2;
        for(i=3; i<=k; i+=2)
        {
            if(siv[i]==0)
                if(siv[n-i]==0) {
                    printf("%d = %d + %d\n", n, i, n-i);
                    break;
                }
        }
        if(i>k)
            printf("Goldbach's conjecture is wrong.\n", j);

    }

    return 0;
}

