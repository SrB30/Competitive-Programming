#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[1000], cng[1000], c;
    int i=0, j, k, cnt =0;

    do
    {
        j=0, k=0;
        do
        {
            if (scanf("%c", &text[j]) == EOF)
                return 0;

            c = text[j];
            if (c == '"')
            {
                if ((++cnt & 1) == 1) {
                    cng[k++] = '`';
                    cng[k++] = '`';
                }

                else
                {
                    cng[k++] = 39;
                    cng[k++] = 39;
                }
            }

            else
                cng[k++] = c;
        }
        while (text[j++] != '\n');
        cng[--k] = '\0';

        printf("%s\n", cng);
    }
    while(1);

    return 0;
}
