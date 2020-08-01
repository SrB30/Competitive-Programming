#include <stdio.h>
#include <string.h>

int main()
{
    long long int T, i, j, k, total=0;
    char str[10];

    scanf("%lld", &T);

    for(i=1;i<=T;) {
        for(j=1;j<=2;j++) {
            scanf("%s", &str);
            if(strcmp(str, "donate")==0) {
                scanf("%lld", &k);
                total= total+k;

            }

            if((strcmp(str, "report"))== 0) {
                printf("%lld\n", total);

            }
            i=i+1;
            if(i>T)
                break;
        }
    }
    return 0;
}
