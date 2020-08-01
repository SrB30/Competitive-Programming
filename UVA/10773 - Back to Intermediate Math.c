#include <stdio.h>
#include <math.h>

int main()
{
    int T, d, u, v, i=0;
    double short_t, long_t, diff_t;
    scanf("%d", &T);

    while ((++i) <=T)
    {
        scanf("%d%d%d", &d, &v, &u);    /// v = flow of river, u = velocity of boat

        if (u==0 || u<=v || v==0)
        {
            printf("Case %d: can't determine\n", i);
        }

        else
        {
            short_t = (double) d/u;
            long_t = (double) d / sqrt(pow(u,2) - pow(v,2));
            diff_t = long_t - short_t;
            printf("Case %d: %.3lf\n", i, diff_t);
        }
    }

    return 0;
}

/**
#10773 - Back to Intermediate Math

Algorithms Used:    2D geometry math

Solution: 	The fastest way to cross is to just aim for the other shore and not care about how far the river pushes you downstream. So the time for the fastest path is just d / u.

The shortest way to cross is of course a straight line, so you must aim the boat upstream such that you exactly counteract the river's flow. The leftover power will get you across, so by Pythagoras, the time for the shortest path is d / sqrt(u^2 - v^2).

As we can see from the above equations, if u == 0, or u < v, then you can't determine the difference because you have undefined or unreal results. Also, you cannot determine the difference if v == 0 because then the two paths would not be different, as the problem requires.*/
