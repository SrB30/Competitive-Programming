#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, cnt, tmp, ptr, i=0, l;
    int *a = (int*) malloc(sizeof(int)*50);

    scanf("%d", &l);
    while (++i <= l)
    {
        scanf("%d", &n);
        for (k=1; k<=n; k++)
        {
            scanf("%d", &a[k]);
        }

        for(k=1, cnt=0; k<n; k++)
        {
            for(ptr=1; ptr<=(n-k); ptr++)
            {
                if (a[ptr]>a[ptr+1])
                {
                    tmp = a[ptr];
                    a[ptr] = a[ptr+1];
                    a[ptr+1] = tmp;
                    cnt++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", cnt);
    }

    return 0;
}
