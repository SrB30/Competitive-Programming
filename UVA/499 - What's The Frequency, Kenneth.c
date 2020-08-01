#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[1000], c;
    int t, let[53], i, max, s;

    while(gets(text))
    {
        for(i=0; i<52; i++)
            let[i] = 0;


        for(i=0, max=0, s=0; text[i]!='\0'; i++)
        {
            if(text[i]>64 && text[i]<91)
                s= ++let[text[i]-65];

            else if (text[i]>96 && text[i]<123)
                s= ++let[text[i]-71];


            if(max<s)
                max = s;
        }

        for(i=0; i<52; i++)
        {
            if(let[i] == max)
                printf("%c", (i<26) ? i+65 : i+71);
        }

        printf(" %d\n", max);
    }

    return 0;
}

