#include <stdio.h>          ///efficient
#include <stdlib.h>

int main()
{
    int n, m, i, j, a;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d ", &m);

        char *num1 = (char*) malloc(sizeof(char)*(m+1));
        char *num2 = (char*) malloc(sizeof(char)*(m+1));
        char *res = (char*) malloc(sizeof(char)*(m+2));

        for(i=0; i<m; i++)
        {
            scanf("%c %c ", &num1[i], &num2[i]);
        }

        for(i=m-1, j=0, a=0; i>=0; i--)
        {
            a = (a/10) + (num1[i]-48) + (num2[i]-48);
            res[j++] = (a%10)+48;
        }

        if((a/10) == 1)
            res[j] = '1';
        else j--;

        for(i=j; i>=0; i--)
        {
            printf("%c", res[i]);
        }
        printf("\n");

        if(n != 0)
            printf("\n");
    }

    return 0;
}
