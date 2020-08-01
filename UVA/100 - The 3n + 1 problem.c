#include <stdio.h>

int main()
{
    int i, j, i1, j1, k, l, m, max, temp;

    while(scanf("%d%d", &i, &j) != EOF)
    {
        if (i>j)
        {
            i1=j;
            j1=i;
        }
        else
        {
            i1=i;
            j1=j;
        }

        int cnt;

        max = 0;

        for(k=i1, l=1; k<=j1; k++, l++)
        {
            m=k;
            cnt =0;

            while (m != 1)
            {
                if (m%2 != 0)
                    m = 3*m +1;

                else
                    m= m/2;

                cnt++;
            }

            if (m==1)
                cnt++;

            if (cnt > max)
            {
                max = cnt;
            }
        }
        printf("%d %d %d\n", i, j, max);
    }

    return 0;
}
