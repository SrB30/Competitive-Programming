# include <stdio.h>
# include <string.h>
int main()
{
    int test,num,son,sum, val[102], i,j,k,l;
    double real;
    char str[10004],a,b,s, ch[102];


    scanf("%d",&test);

    for(i=1; i<=test; i++)
    {
        scanf("%d%c",&num,&a);

        for(j=0; j<num; j++)
            scanf("%c %d%c", &ch[j], &val[j], &s);

        scanf("%d%c",&son,&b);
        sum = 0;
        for(k=1; k<=son; k++)
        {
            gets(str);
            for(j=0; j<num; j++)
            {
                for(l=0; str[l]; l++)
                {
                    if(str[l]==ch[j])
                        sum+=val[j];
                }

            }
        }
        real = (double)sum/100;
        printf("%.2lf$\n",real);
    }
    return 0;
}
