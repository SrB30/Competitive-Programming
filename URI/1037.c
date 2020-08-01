#include <stdio.h>

int main()
{
    double N;
    scanf("%lf", &N);

    if (N>=0 && N<=100) {
        if (N>=0 && N<=25.0) {
            printf("Intervalo [0,25]\n");
        }
        if (N>25.0 && N<=50.0) {
            printf("Intervalo (25,50]\n");
        }
        if (N>50.0 && N<=75.0) {
            printf("Intervalo (50,75]\n");
        }
        if (N>75.0 && N<=100.0) {
            printf("Intervalo (75,100]\n");
        }
    }
    else
        printf("Fora de intervalo\n");

    return 0;
}
