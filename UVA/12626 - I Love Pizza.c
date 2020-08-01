#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = (char*) malloc(sizeof(char)*601);
    char ig;
    int i=0, t, j, min;

    scanf("%d ", &t);

    while (++i <= t)
    {
        int cnt[6] ={0};

        j=0;
        do
        {
            scanf("%c", &str[j]);

            if (str[j] == 'A')
                cnt[0]++;

            else if (str[j] == 'M')
                cnt[1]++;

            else if (str[j] == 'R')
                cnt[2]++;

            else if (str[j] == 'G')
                cnt[3]++;

            else if (str[j] == 'I')
                cnt[4]++;

            else if (str[j] == 'T')
                cnt[5]++;
        }
        while (str[j] != '\n');

        cnt[0] = cnt[0]/3;
        cnt[2] = cnt[2]/2;

        min = cnt[0];
        for (j=1; j<=5; j++)
        {
            if (cnt[j] < min)
            {
                min = cnt[j];
            }
        }
        printf("%d\n", min);
    }

    return 0;
}
