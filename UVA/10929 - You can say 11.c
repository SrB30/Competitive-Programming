#include <stdio.h>
#include <string.h>

int main()
{
    char str[1002];
    int i, mod11, l;

    while(scanf("%s", str))
    {
        if(strcmp(str, "0") == 0)
            return 0;
        l = strlen(str);

        for(i=0, mod11=0; i<l; i++)
        {
            mod11 = ((mod11*10) + (str[i]-48)) % 11;
        }
        if(mod11 == 0)
            printf("%s is a multiple of 11.\n", str);
        else
            printf("%s is not a multiple of 11.\n", str);
    }

    return 0;
}

