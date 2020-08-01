#include <stdio.h>      ///not efficient
#include <stdlib.h>

int main()
{
    int n, m, i, j, carry, a;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &m);

        int *num1 = (int*) malloc(sizeof(int)*(m+2));
        int *num2 = (int*) malloc(sizeof(int)*(m+2));
        int *res = (int*) malloc(sizeof(int)*(m+3));

        for(i=1; i<=m; i++)
        {
            scanf("%d%d", &num1[i], &num2[i]);
        }

        for(i=m, j=0, carry=0; i>0; i--)
        {
            a = carry + num1[i] + num2[i];
            res[++j] = a%10;
            carry = a/10;
        }

        if(carry == 1)
            res[++j] = 1;

        for(i=j; i>0; i--)
        {
            printf("%d", res[i]);
        }
        printf("\n");
        if(n != 0)
            printf("\n");
    }

    return 0;
}
