#include <stdio.h>
#include <string.h>
char str[21];
int p, m, i, l;

int mirror()
{
    switch(str[i])
    {
    case 'A':
    case 'H':
    case 'I':
    case 'M':
    case 'O':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case '1':
    case '8':
        if(str[l-i-1] != str[i]){m=0;}
        return;
    case 'E':
        if(str[l-i-1] != '3'){m=0;}
        return;
    case '3':
        if(str[l-i-1] != 'E'){m=0;}
        return;
    case 'J':
        if(str[l-i-1] != 'L'){m=0;}
        return;
    case 'L':
        if(str[l-i-1] != 'J'){m=0;}
        return;
    case 'S':
        if(str[l-i-1] != '2'){m=0;}
        return;
    case '2':
        if(str[l-i-1] != 'S'){m=0;}
        return;
    case 'Z':
        if(str[l-i-1] != '5'){m=0;}
        return;
    case '5':
        if(str[l-i-1] != 'Z'){m=0;}
        return;
    default:
        m=0;
        return;
    }
}


int main()
{
    while(gets(str))
    {
        l= strlen(str);

        for(i=0, p=1, m=1; i<=l/2; i++)
        {
            if (p==1)
            {
                if(str[i] != str[l-i-1])
                    p=0;
            }
            if(m==1)
            {
                mirror();
            }
        }
        if(m==0 && p==0)
            printf("%s -- is not a palindrome.\n\n", str);
        else if(m==0 && p==1)
            printf("%s -- is a regular palindrome.\n\n", str);
        else if(m==1 && p==0)
            printf("%s -- is a mirrored string.\n\n", str);
        else if(m==1 && p==1)
            printf("%s -- is a mirrored palindrome.\n\n", str);
    }
    return 0;
}
