#include <stdio.h>
#include <math.h>

int main()
{
    int h, m;
    double ang;

    while(1)
    {
        scanf("%d:%d", &h, &m);
        if(h==0 && m==0)
            return 0;

        ang = ((h*30) + m/2.0) - (m*6);

        if(ang < 0) ang = ang * (-1);


        if (ang>180)
            ang = 360-ang;


        printf("%.3lf\n", ang);
    }

    return 0;
}
