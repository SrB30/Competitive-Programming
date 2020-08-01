#include <stdio.h>

int main()
{
    long long int T, i, k, taxi;
    double tax;
    scanf("%lld", &T);

    for(i=1;i<=T;i++) {
        scanf("%lld", &k);

        if(k<=180000) {
            tax= 0;
        }
        if(k>180000 && k<=480000) {
            tax= ((k-180000)*0.1);
        }
        if(k>480000 && k<=880000) {
            tax= (30000+((k-480000)*0.15));
        }
        if(k>880000 && k<=1180000) {
            tax= 30000+60000+((k-880000)*0.20);
        }
        if(k>1180000){
            tax= 30000+60000+60000+((k-1180000)*0.25);
        }
        if(tax>0 && tax<2000) {
            tax= 2000;
        }
        taxi= ceil(tax);
        printf("Case %lld: %lld\n", i, taxi);
    }
    return 0;
}
