#include <stdio.h>
#include <math.h>

int main()
{
    int T, n=0;
    double u,v,a,s,t;

    while(1) {
        scanf("%d", &T);
        if(T==0)
            break;
        n++;
        switch(T)
        {
        case 1:
            scanf("%lf%lf%lf", &u, &v, &t);
            s= ((u+v)/2)*t;
            a= (v-u)/t;
            printf("Case %d: %.3lf %.3lf\n", n, s,a);
            break;
        case 2:
            scanf("%lf%lf%lf", &u, &v, &a);
            s= ((v*v)-(u*u))/(2*a);
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n", n, s,t);
            break;
        case 3:
            scanf("%lf%lf%lf", &u, &a, &s);
            v= sqrt((u*u)+(2*a*s));
            t= (2*s)/(u+v);
            printf("Case %d: %.3lf %.3lf\n", n, v,t);
            break;
        case 4:
            scanf("%lf%lf%lf", &v, &a, &s);
            u= sqrt((v*v)-(2*a*s));
            t= (v-u)/a;
            printf("Case %d: %.3lf %.3lf\n", n, u,t);
            break;
        default:
            break;
        }
    }
    return 0;
}
