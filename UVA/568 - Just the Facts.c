#include <stdio.h>
#define max 10001

int n, facts[max];


int main()
{
    int i, fact ;

    facts[0] = facts[1] = fact = 1 ;

    for (i=2; i<=max; i++)
    {
        fact = fact * i;

        while (fact%10==0)
            fact /= 10;

        fact = fact%100000 ;

        facts[i] = fact%10 ;
    }


    while (scanf("%d", &n) != EOF)
        printf("%5d -> %d\n", n, facts[n]);

    return 0;
}
