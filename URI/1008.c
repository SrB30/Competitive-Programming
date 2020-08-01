#include <stdio.h>

int main()
{
    int number, hour;
    double amount, salary;
    scanf("%d%d%lf", &number, &hour, &amount);

    salary = hour * amount;
    printf("NUMBER = %d\nSALARY = U$ %.2lf\n", number, salary);

    return 0;
}
