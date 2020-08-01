#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define pi 3.14159265
#define degree 180/pi
#define radian pi/180

using namespace std;

const double eps = 0.0000000001;
double p,q,r,s,t,u, resx;


double fx(double x)
{
    double result = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
    return result;
}

double bisection(double x1, double x2, double f1)
{
    double x0, f0, f2;

    while((x2-x1)/x2>=eps)
    {
        x0 = (x1+x2)/2;
        f0 = fx(x0);

        if(f0==0)
            return x0;


        if(f1*f0 <0)
            x2 = x0;
        else{
            x1 = x0;
            f1 = f0;
        }
      //  cout << x1<< " " << x2 << " " << f0 << endl;
    }

    //resx = min(x1,x2);
    resx = (x1+x2)/2;
    //cout << x1 << " " << x2 << endl;

    return resx;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    double x1=0, x2=1;
   // cout << setprecision(10);

    while(cin >>p>>q>>r>>s>>t>>u)
    {
        double f1 = fx(x1), f2 = fx(x2);
        double res = (f1==0) ? x1 : ((f2==0)? x2 : -1);


        if((f1*f2>0) && res==-1)
        {
            cout  << "No solution" << endl;
            continue;
        }


        if(res == -1)
            res = bisection(x1,x2, f1);
        cout << setprecision(4) << fixed << res << endl;
    }

    return 0;
}
