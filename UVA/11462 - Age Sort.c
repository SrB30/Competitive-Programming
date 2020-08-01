#include <stdio.h>

int main()
{
    int n, i, j, temp, max, cnt;

    while(scanf("%d", &n))
    {
        if(n==0)
            return 0;

        int age[101]={0};

        for(i=1, max=0; i<=n; i++)
        {
            scanf("%d", &temp);

            if(temp<=100)
            {
                age[temp]++;
                if(temp>max)
                    max=temp;
            }
        }

        for(i=1, cnt=0; i<=max; i++)
        {
            if(age[i]>0)
            {
                for(j=1; j<=age[i]; j++)
                {
                    if(cnt > 0)
                        printf(" ");
                    cnt=1;

                    printf("%d", i);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
