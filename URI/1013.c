#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, Max_ab, greatest;
    scanf("%d%d%d", &a, &b, &c);

    Max_ab = (a+b+ abs(a-b))/2;

    greatest = (Max_ab+c+ abs(Max_ab-c))/2;
    printf("%d eh o maior\n", greatest);

    return 0;
}
