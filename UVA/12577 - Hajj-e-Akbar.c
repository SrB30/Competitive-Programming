#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t=0;
    char *str = (char*) malloc(6);

    while (scanf("%s", str))
    {
        if (str[0] == '*')
            return 0;
        if (str[0] == 'H')
            printf("Case %d: Hajj-e-Akbar\n", ++t);
        else
            printf("Case %d: Hajj-e-Asghar\n", ++t);
    }
    return 0;
}
