#include <stdio.h>
#include <string.h>

int main()
{
    char c[110], d[110], a[110];
    int n, l1, l2, len, k, j, i, carry, sum;


    scanf("%s", a);

    j= strlen(a);
    for(i=j-1, k=0; i>=0; i--,k++)
        c[k]= a[i];
    c[j] = '\0';


    while(scanf("%s", d))
    {
        if(d[0] == '0')
            break;

        l1 = j;
        l2 = strlen(d);

        for(i=l2-1, k=0; i>=0; i--, k++)
            a[k]= d[i];


        if(l1>l2)
        {
            for(i=l2; i<l1; i++)
                a[i] = '0';
            l2 = l1;
        }
        else if(l2>l1)
        {
            for(i=l1; i<l2; i++)
                c[i] = '0';
            l1 = l2;
        }


        for (i=0, j=0, carry = 0; i<l1; i++, j++)
        {
            sum = carry + (c[i]-48) + (a[i]-48);
            carry = sum/10;
            d[j] = (sum%10 + 48);
        }

        if (carry == 1)
            d[j++] = '1';
        d[j] = '\0';

        strcpy(c, d);
    }


    for(i=j-1, k=0; i>=0; i--, k++)
        a[k]= c[i];
    a[k] = '\0';

    printf("%s\n", a);


    return 0;
}

