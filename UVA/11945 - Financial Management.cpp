#include <stdio.h>
#include <string.h>

int main()
{
    char res[50], res2[50];
    int i=0, j, k, cnt, dec, t;
    double bal, sum;

    scanf("%d", &t);
    while(i++<t)
    {
        for(j=0, sum=0; j<12; j++)
        {
            scanf("%lf", &bal);

            sum = sum + bal;
        }
        sum = sum/12;
        sprintf(res, "%.2lf", sum);
        for(j=strlen(res)-1, k=0, dec=0, cnt=0; j>=0; j--)
        {
            if(dec == 1)
            {
                if(cnt==3) {
                    res2[k++] = ',';
                    cnt = 0;
                }
                cnt++;
            }
            if(res[j]=='.')
                dec=1;
            res2[k++] = res[j];
        }
        for(j=k-1; j>=0; j--)
        {
            res[k-j-1] = res2[j];
        }
        res[k] = '\0';

        printf("%d $%s\n", i, res);
    }

    return 0;
}






/**#include<stdio.h>
#include <math.h>

int main()
{
    int t, i, a;
    double d, sum, avg;
    int j=0;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        for(i=0; i<12; i++)
        {
            scanf("%lf",&d);
            sum = sum + d;
        }
        avg = sum/12.00;
        printf("%d $",++j);
        if(avg<=999999999999999.0 && avg>999999999999.0)
        {
            a = avg/1000000000000.0;
            printf("%d,",a);
            avg = fmod(avg,1000000000000.0);
        }
        if(avg<=999999999999.0 && avg>999999999.0)
        {
            a = avg/1000000000.0;
            printf("%d,",a);
            avg = fmod(avg,100000000.0);
        }
        if(avg<=999999999.0 && avg>999999.0)
        {
            a = avg/1000000.0;
            printf("%d,",a);
            avg = fmod(avg,1000000.0);
        }
        if(avg<=999999.0 && avg>999.0)
        {
            a = avg/1000.0;
            printf("%d,",a);
            avg = fmod(avg,1000.0);
        }

        printf("%.2lf\n",avg);
    }
    return 0;
}
**/
