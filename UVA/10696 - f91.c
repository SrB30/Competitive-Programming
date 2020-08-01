#include <stdio.h>

int main()
{
    int a;
    char c[9];
    while(gets(c))
    {
        if(c[0]=='0')
            return 0;
        sscanf(c, "%d", &a);
        if(a>100)
            printf("f91(%d) = %d\n", a, a-10);
        else
            printf("f91(%d) = 91\n", a);
    }

    return 0;
}
