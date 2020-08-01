#include <stdio.h>
#include <string.h>

int main()
{
    char str[101];
    int i, mod17, l;

    while(scanf("%s", str))
    {
        if(str[0] == '0')
            return 0;
        l = strlen(str);

        for(i=0, mod17=0; i<l; i++)
        {
            mod17 = ((mod17*10) + (str[i]-48)) % 17;
        }
        if(mod17 == 0)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
