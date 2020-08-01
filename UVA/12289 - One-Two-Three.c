#include <stdio.h>
#include <string.h>

int main()
{
    char a[10];
    int n, i=1, len;
    scanf("%d", &n);

    while (i<=n)
    {
        scanf("%s", a);
        len = strlen(a);
        if (len == 5)
            printf("3\n");
        else
        {
            if ((a[0]=='o' && a[1] == 'n') || ((a[0]=='o' && a[2] == 'e') || ((a[1]=='n' && a[2] == 'e'))))
                                               printf("1\n");
            else
                printf("2\n");
        }
        i++;
    }

    return 0;
}
