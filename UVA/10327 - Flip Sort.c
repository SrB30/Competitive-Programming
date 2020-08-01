#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, cnt, tmp, ptr;
    int *a = (int*) malloc(sizeof(int)*1000);

    while (scanf("%d", &n) != EOF)
    {
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
        printf("Minimum exchange operations : %d\n", cnt);
    }

    return 0;
}
