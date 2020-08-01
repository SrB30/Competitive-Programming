#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char a[10002], b[101][101];
    int t, l, i, k, j, d;
    double sq;

    scanf("%d ", &t);

    while(t--)
    {
        gets(a);
        l = strlen(a);
        sq = sqrt(l);

        if (sq == (d=floor(sq)))
        {
            for(i=0, k=0; i<d; i++)
            {
                for(j=0; j<d; j++)
                {
                    b[i][j] = a[k++];
                }
            }

            for(i=0; i<d; i++)
            {
                for(j=0; j<d; j++)
                {
                    printf("%c", b[j][i]);
                }
            }
            printf("\n");
        }
        else
            printf("INVALID\n");
    }

    return 0;
}
