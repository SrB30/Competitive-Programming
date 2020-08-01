#include <stdio.h>
#include <string.h>

int main()
{
    char s[15];
    int T=0, r;

    while(++T)
    {
        scanf("%s", s);

        if(s[0] == '#')
            return 0;

        if (strcmp(s, "HELLO")==0)
            printf("Case %d: ENGLISH\n", T);

        else if (strcmp(s, "HOLA")==0)
            printf("Case %d: SPANISH\n", T);

        else if (strcmp(s, "HALLO")==0)
            printf("Case %d: GERMAN\n", T);

        else if (strcmp(s, "BONJOUR")==0)
            printf("Case %d: FRENCH\n", T);

        else if (strcmp(s, "CIAO")==0)
            printf("Case %d: ITALIAN\n", T);

        else if (strcmp(s, "ZDRAVSTVUJTE")==0)
            printf("Case %d: RUSSIAN\n", T);
        else
            printf("Case %d: UNKNOWN\n", T);
    }
}
