#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[202], c;
    int t, let[27], i, max, s;

    scanf("%d", &t);
    getchar();
    while(t--)
    {
        for(i=0; i<26; i++)
            let[i] = 0;

        gets(text);
        for(i=0, max=0, s=0; text[i]!='\0'; i++)
        {
            if((text[i]>64 && text[i]<91) || (text[i]>96 && text[i]<123)) {
                c=tolower(text[i]);
                s= ++let[c-97];
            }

            if(max<s)
                max = s;
        }

        for(i=0; i<26; i++)
        {
            if(let[i] == max)
                printf("%c", i+97);
        }
        printf("\n");
    }

    return 0;
}
