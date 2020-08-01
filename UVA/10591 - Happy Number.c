#include <stdio.h>
#include <math.h>

int main()
{
    int t, n, sos, i=0, j, sum, rem, root;
    scanf("%d", &t);

    while(++i <= t)
    {
        scanf("%d", &n);
        sos=n;

        while (sos  != 1)
        {
            sum=sos;
            sos = 0;
            while (sum != 0)
            {
                rem = sum%10;
                sos = sos + (rem*rem);
                sum = sum/10;
            }
            if (sos==61 || sos==110 || sos==952 || sos==121 || sos==54 || sos==604 || sos ==37 || sos==89 || sos==16 || sos==729 || sos==134 || sos==58 || sos==145 || sos==81 || sos==65 || sos==29 || sos==42 || sos==20 || sos==21 || sos==74 || sos==145)
            {
                printf("Case #%d: %d is an Unhappy number.\n", i, n);
                break;
            }
        }
        if (sos == 1)
            printf("Case #%d: %d is a Happy number.\n", i, n);
    }

    return 0;
}
