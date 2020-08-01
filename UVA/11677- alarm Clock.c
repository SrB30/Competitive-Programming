#include <stdio.h>

int main()
{
    int H1, M1, H2, M2, M11, M22, time;
    while(scanf("%d%d%d%d", &H1, &M1, &H2, &M2)==4) {
        if(H1==0 && M1==0 && H2==0 && M2==0)
            break;
        else {
            if((H1<H2) || (H1==H2 && M1<=M2)) {
                M11= (H1*60)+M1;
                M22= (H2*60)+M2;
                time= M22-M11;
            }
            if((H1>H2) || (H1==H2 && M1>M2)) {
                M11= 1440-((H1*60)+M1);
                M22= (H2*60)+M2;
                time= M22+M11;
            }
            printf("%d\n", time);
        }
    }
    return 0;
}
