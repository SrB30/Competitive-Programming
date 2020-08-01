#include <stdio.h>

int main()
{
    int time, speed;
    double liters;
    scanf("%d%d", &time, &speed);

    liters = (time*speed) / 12.0;
    printf("%.3lf\n", liters);

    return 0;
}
