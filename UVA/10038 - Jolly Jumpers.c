#include <stdio.h>
#include <math.h>

int main()
{
    int n,i,l,d, a[3000];

    while (scanf("%d", &n) != EOF)
    {
        int c[3000] = {0};

        for (i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        l = n-1;
        for (i=0; i<l; i++)
        {
            d = abs((a[i+1] - a[i]));

            if (d > l)
            {
                printf("Not jolly\n");
                break;
            }
            c[d] = c[d] +1;
            if (c[d] > 1)
            {
                printf("Not jolly\n");
                break;
            }
        }
        if (i == n-1)
            printf("Jolly\n");
    }

    return 0;
}
