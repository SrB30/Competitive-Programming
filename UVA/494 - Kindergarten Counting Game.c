#include <stdio.h>
#include <ctype.h>
#include <string.h>
char a[1000];

int main()
{
    int i, l, cnt, isword;

    while(gets(a))
    {
        l= strlen(a);

        for(i=0, cnt=0; i<l; i++)
        {
            for(isword=0; (a[i] != 32) && (a[i] != '\0'); i++)
            {
                if(isword != 1)
                {
                    if(isalpha(a[i]))
                    {
                        isword=1;
                        cnt++;
                    }
                }

                else if(!isalpha(a[i]))
                {
                    isword=0;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
