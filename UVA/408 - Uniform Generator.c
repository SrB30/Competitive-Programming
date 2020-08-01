#include <stdio.h>

int main()
{
    int step, mod, x, cnt;

    while (scanf("%d%d", &step, &mod) != EOF)
    {
        x = 0;
        cnt = 0;

        do
        {
            cnt++;
            x = (x + step) % mod;
        }
        while (x != 0);

        if (cnt == mod)
            printf("%10d%10d    Good Choice\n\n", step, mod);
        else
            printf("%10d%10d    Bad Choice\n\n", step, mod);
    }

    return 0;
}
