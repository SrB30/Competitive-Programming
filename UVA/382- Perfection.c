#include <stdio.h>

int main()
{
    int a[102], i=0, j, sum;
    do
    {
        scanf("%d", &a[++i]);
    }
    while (a[i] != 0);
    printf("PERFECTION OUTPUT\n");

    for(i=1; a[i] != 0; i++)
    {
        sum=0;
        for(j=1; j<=(a[i]/2); j++)
        {
            if(a[i] % j == 0)
            {
                sum = sum + j;
            }
        }
        if(sum < a[i])
            printf("%5d  DEFICIENT\n", a[i]);
        else if(sum > a[i])
            printf("%5d  ABUNDANT\n", a[i]);
        else
            printf("%5d  PERFECT\n", a[i]);
    }
    printf("END OF OUTPUT\n");

    return 0;
}
