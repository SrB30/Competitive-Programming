#include <stdio.h>

int main()
{
    long long int n, fact;

    while (scanf("%lld", &n) != EOF)
    {
        if (n<0 && (n%2)!=0)
            printf("Overflow!\n");

        else if (n<0 && (n%2)==0)
            printf("Underflow!\n");

        else if (n < 8)
            printf("Underflow!\n");

        else if (n > 13)
            printf("Overflow!\n");

        else
        {
            fact = 1;
            while (n != 0)
            {
                fact = fact * n;
                n = n-1;
            }
            printf("%lld\n", fact);
        }
    }

    return 0;
}
