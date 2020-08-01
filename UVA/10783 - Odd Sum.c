#include <stdio.h>

int main()
{
    int T, a, b, i, j=1, sum;

    scanf("%d", &T);
    while (j<=T)
    {
        scanf("%d%d", &a, &b);

        sum=0;
        for(i=a; i<=b; i++)
        {
            if(i % 2 != 0)
            {
                sum = sum + i;
            }
        }
        printf("Case %d: %d\n", j, sum);
        j++;
    }

    return 0;
}
