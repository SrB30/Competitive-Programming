#include <bits/stdc++.h>

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char str1[81], str2[81];
    int num[81];
    int n, i, j, st, f, c;
    int s1, s2;

    while(gets(str1))
    {
        for(st=0; str1[st]!= 0; st++)
        {
            if(str1[st] != 32)
                break;
        }

        for(f=strlen(str1)-1; f>-1; f--)
        {
            if(str1[f] != 32)
                break;
        }

        for(i=st, j=-1, n=-1; i<=f; i++)
        {
            str2[++j] = str1[i];

            if(isdigit(str1[i]))
            {
                num[++n] = str1[i] - 48;
            }

            else if((str1[i]!=32 && str1[i] != '-') && !(n==8 && str1[i]=='X'))
            {
                n=0;
                break;
            }
            else if((n==8 && str1[i]=='X'))
                num[++n] = 10;
        }
        if(n==0)
        {
            while(++i<=f)
                str2[++j] = str1[i];
        }
        str2[++j] = '\0';

        if((n!=9))
        {
            printf("%s is incorrect.\n", str2);
            continue;
        }


        for(i=1, s1=s2=num[0]; i<=n; i++)
        {
            s1 += num[i];
            s2 += s1;
        }

        if(s2%11 == 0)
            printf("%s is correct.\n", str2);
        else
            printf("%s is incorrect.\n", str2);
    }

    return 0;
}
