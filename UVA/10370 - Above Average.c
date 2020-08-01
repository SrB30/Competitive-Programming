#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, n, i=0, cnt, j, sum, avg;
    double above;
    int *a = (int*) malloc(sizeof(int)*1000);

    scanf("%d", &c);
    while(++i <= c)
    {
        scanf("%d", &n);
        for(j=1, sum=0; j<=n; j++)
        {
            scanf("%d", &a[j]);
            sum = sum + a[j];
        }
        avg = sum/n;
        for(j=1, cnt=0; j<=n; j++)
        {
            if(a[j] > avg)
                cnt++;
        }
        printf("%.3lf%%\n", (cnt*100.0)/n);
    }

    return 0;
}
