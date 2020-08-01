#include <stdio.h>

int main()
{
    int t, a, f, i=1, j, k, l;

    scanf("%d", &t);

    while (i<=t)
    {
        scanf("%d%d", &a, &f);
        for(j=1; j<=f; j++)
        {
            for(k=1; k<=a; k++)
            {
                for(l=1; l<=k; l++)
                {
                    printf("%d", k);
                }
                printf("\n");
            }

            for(k=a-1; k>=1; k--)
            {
                for(l=k; l>=1; l--)
                {
                    printf("%d", k);
                }
                printf("\n");
            }
            if (i!=t || j!=f)
                printf("\n");
        }
        i++;
    }

    return 0;
}
