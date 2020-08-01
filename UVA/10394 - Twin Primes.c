#include <stdio.h>
#include <math.h>
#define max 18409203
int siv[max+10];
int main()
{
    int twin[100001]= {0, 3, 5, 11, 17, 29, 41};
    int k, i, j, n, l;
    k = sqrt(max);

    for(i=3; i<=k; i+=2)
    {
        if(siv[i] == 0)
        {
            for(j=3; max>=(n=(i*j)); j+=2)
            {
                siv[n]= 1;
            }
        }
    }

    for(i=47, j=7; i<max && j<=100000; i+=2)
    {
        if(siv[i] == 0)
        {
            if(siv[i+2] == 0)
            {
                twin[j++] = i;
            }
        }
    }

    while(scanf("%d", &n) != EOF)
    {
        printf("(%d, %d)\n", twin[n], twin[n]+2);
    }

    return 0;
}
