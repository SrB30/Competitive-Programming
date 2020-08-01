#include <stdio.h>
#include <string.h>

int main()
{
    char str[12];
    int i, s, sum, l;
    while (gets(str))
    {
        if (str[0] == '0')
            return 0;

        l= strlen(str);
        for(i=0, sum=0; i<l; i++)
        {
            sum = sum + (str[i]-48);
        }

        while(sum > 9)
        {
            s=sum;
            sum=0;
            while(s != 0)
            {
                sum = sum + s%10;
                s = s/10;
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
