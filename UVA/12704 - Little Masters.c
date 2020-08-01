#include <stdio.h>
#include <math.h>

int main()
{
    int T, x, y, r;
    double shrt, lng;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &x, &y, &r);

        shrt = (double) (r - sqrt((x*x) + (y*y)));
        lng = (double) (r + sqrt((x*x) + (y*y)));
        printf("%.2lf %.2lf\n", shrt, lng);
    }

    return 0;
}
