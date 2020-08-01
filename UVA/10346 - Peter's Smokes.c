#include <stdio.h>

int main()
{
    int n, k, q, sum;

    while (scanf("%d%d", &n, &k) != EOF)
    {
        sum = n;
        q = n;
        while (q != 0)
        {
            q = n/k;
            sum = sum + q;
            n= q + (n%k);
        }
        printf("%d\n", sum);
    }

    return 0;
}
