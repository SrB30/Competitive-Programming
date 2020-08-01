#include <stdio.h>
#include <math.h>

int main()
{
    FILE *f = fopen("file.txt", "w");
    int t, n, k, sum, d1, d2, sq;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d%d", &n, &k);
        sq = sqrt(n);

        for(d1=1, sum=0; d1<=sq; d1++)
        {
            if (n%d1 == 0)
            {
                d2 = n/d1;

                if (d1%k != 0)
                    sum = sum + d1;

                if (d2%k != 0)
                    sum = sum + d2;
            }
        }
        if (sq%k!=0 && sq==d2)
            sum = sum-sq;

        fprintf(f, "%d\n", sum);
    }

    return 0;
}
