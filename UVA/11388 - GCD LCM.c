#include <stdio.h>

int main()
{
    int t, g, l;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &g, &l);
        if((l%g)!=0)
            printf("-1\n");
        else
        {
            printf("%d %d\n", g, l);
        }
    }

    return 0;
}
