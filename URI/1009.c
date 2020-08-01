#include <stdio.h>

int main()
{
    double salary, tsold, total;
    char name;
    scanf("%s", &name);
    scanf("%lf%lf", &salary, &tsold);

    total = salary + (tsold*0.15);
    printf("TOTAL = R$ %.2lf\n", total);

    return 0;
}
