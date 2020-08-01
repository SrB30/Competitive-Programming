#include <stdio.h>

int main()
{
    double N, A;
    int n, m, n100, n50, n20, n10, n5, n2, c50, c25, c10, c05, c01;
    scanf("%lf", &N);
    n = N;

    printf("NOTAS:\n");


    n100 = n/100;
    printf("%d nota(s) de R$ 100.00\n", n100);
    n= n%100;

    n50 = n/50;
    printf("%d nota(s) de R$ 50.00\n", n50);
    n=n%50;

    n20 = n/20;
    printf("%d nota(s) de R$ 20.00\n", n20);
    n=n%20;

    n10= n/10;
    printf("%d nota(s) de R$ 10.00\n", n10);
    n= n%10;

    n5= n/5;
    printf("%d nota(s) de R$ 5.00\n", n5);
    n= n%5;

    n2= n/2;
    printf("%d nota(s) de R$ 2.00\n", n2);
    n= n%2;

    A = N*100;
    m = A;

    printf("MOEDAS:\n");


    printf("%d moeda(s) de R$ 1.00\n", n);
    m= m%100;

    c50= m/50;
    printf("%d moeda(s) de R$ 0.50\n", c50);
    m= m%50;

    c25= m/25;
    printf("%d moeda(s) de R$ 0.25\n", c25);
    m= m%25;

    c10= m/10;
    printf("%d moeda(s) de R$ 0.10\n", c10);
    m= m%10;

    c05= m/5;
    printf("%d moeda(s) de R$ 0.05\n", c05);
    m= m%5;

    c01 = m/1;
    printf("%d moeda(s) de R$ 0.01\n", c01);

    return 0;
}
