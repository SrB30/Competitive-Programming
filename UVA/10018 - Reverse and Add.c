#include <stdio.h>
#include <string.h>

int main()
{
    char str[13], temp[14];
    int i, j, t, l, h, cnt, isp, carry, sum;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%s", str);
        l = strlen(str);


        cnt = 0;
        while(++cnt)
        {

            for(i=0, carry=0; i<l; i++)
            {
                sum = carry + (str[i]-48) + (str[l-i-1]-48);
                carry = sum/10;
                temp[i] = (sum%10) + 48;
            }
            --i;
            if(carry==1)
                temp[++i] = '1';
            temp[++i] = '\0';


            h = i/2;
            for(j=0, isp=1; j<h; j++)
            {
                if(temp[j] != temp[i-j-1])
                {
                    isp = 0;
                    break;
                }
            }
            if(isp==1)
            {
                printf("%d %s\n", cnt, temp);
                break;
            }

            strcpy(str, temp);
            l=i;
        }
    }


    return 0;
}
