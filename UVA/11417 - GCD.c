#include <stdio.h>

int GCD(int a,int b)
{
    if(b!=0)
    {
        return GCD(b, a%b);
    }
    else
        return a;
}

int main()
{
    int N, i, j, G;
    while(scanf("%d", &N))
    {
        if(N==0)
            return 0;

        G=0;
        for(i=1; i<N; i++)
        {
            for(j=i+1; j<=N; j++)
            {
                G+=GCD(j,i);
            }
        }
        printf("%d\n", G);
    }
}
