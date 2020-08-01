#include <stdio.h>

int main()
{
    int i=0, t, dc, mc, yc, db, mb, yb, age;

    scanf("%d", &t);

    while (++i <= t)
    {
        scanf("%d/%d/%d%d/%d/%d", &dc, &mc, &yc, &db, &mb, &yb);

        if ((yb>yc) || (yb==yc && mb>mc) || ((yb==yc && mb==mc) && db>dc))
            printf("Case #%d: Invalid birth date\n", i);

        else
        {
            age = yc-yb;

            if ((mc<mb) || (mc==mb && dc<db))
                age = age-1;

            if (age > 130)
                printf("Case #%d: Check birth date\n", i);

            else
                printf("Case #%d: %d\n", i, age);
        }
    }

    return 0;
}
