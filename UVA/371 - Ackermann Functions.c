#include <stdio.h>

int main()
{
    long long int L, H, V, S, cnt, temp, temp1, i;

    while (scanf("%lld%lld", &L, &H))
    {
        if (L == 0 && H == 0)
            return 0;

        if (L > H)
        {
            temp1 = L;
            L = H;
            H = temp1;
        }

        S = 0;

        for (i=L; i<=H; i++)
        {
            temp = i;
            cnt = 0;

            do
            {
                temp = ((temp%2 != 0) ? ((3*temp) + 1) : (temp / 2));
                cnt++;
            }
            while (temp > 1);

            if (S < cnt)
            {
                S=cnt;
                V=i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", L, H, V, S);
    }
}
