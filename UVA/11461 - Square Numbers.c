#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, cnt, i;
    double sq;
    while(scanf("%d%d", &a, &b))
    {
        if(a==0 && b==0)
            return 0;

        for(i=a, cnt=0; i<=b; i++)
        {
            if((sq=sqrt(i)) == floor(sq))
                cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
