#include <iostream>
#include <cstdio>
#include <math.h>
#define pi acos(-1)

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);


    int a,b,c;
    double R_in, R_out, A_tr, A_in, A_out, s, sun, vio, rose;


    while(scanf("%d%d%d", &a,&b,&c) != EOF)
    {
        s = (a+b+c) / 2.0;
        A_tr = sqrt(s*(s-a)*(s-b)*(s-c));  ///area of triangle

        R_out = (a*b*c)/(4*A_tr);
        A_out = pi * (R_out * R_out);   ///area of circum circle

        sun = A_out - A_tr;

        R_in = A_tr/s;
        A_in = pi * (R_in * R_in);  ///area of inscribed circle

        vio = A_tr - A_in;

        rose = A_in;


        printf("%.4lf %.4lf %.4lf\n", sun, vio, rose);
    }

    return 0;
}
