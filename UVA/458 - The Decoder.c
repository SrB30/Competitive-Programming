#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *a;

    a= (char*) malloc(1);
    while (scanf("%c", a) != EOF)
    {
        if (*a != '\n')
            printf("%c", (*a-7));
        else
            printf("\n");
    }
    free(a);
    return 0;
}
