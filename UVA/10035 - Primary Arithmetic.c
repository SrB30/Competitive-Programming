#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char a[11], b[11];
    int i, cnt, l, t;

    while (1)
    {
        char c[11]= "0000000000", d[11]= "0000000000";
        scanf("%s%s", a, b);
        if (a[0] == '0' && b[0] == '0')
            return 0;

        l = 10 - strlen(a);
        c[l] = '\0';
        strcat((c+l), a);


        l = 10 - strlen(b);
        d[l] = '\0';
        strcat((d+l), b);

        for (i=9, cnt=0, t=0; i>=0; i--)
        {
            if ((t + (c[i]-48) + (d[i]-48)) > 9)
            {
                t = 1;
                cnt++;
            }
            else
                t=0;
        }
        if (cnt != 0)
        {
            if (cnt > 1)
                printf("%d carry operations.\n", cnt);

            else
                printf("%d carry operation.\n", cnt);
        }
        else
            printf("No carry operation.\n");
    }
}
