#include <stdio.h>

int main()
{
    int k, c1, c2, c3, c4, c5, c6, i=0, n[51];

    while(scanf("%d", &k)==1)
    {
        if(k==0)
            return 0;

        if(i>0)
            printf("\n");
        i=1;

        for(c1=1; c1<=k; c1++)
            scanf("%d", &n[c1]);

        for(c1=1; c1<=(k-5); c1++)
        {
            for(c2=c1+1; c2<=(k-4); c2++)
            {
                for(c3=c2+1; c3<=(k-3); c3++)
                {
                    for(c4=c3+1; c4<=(k-2); c4++)
                    {
                        for(c5=c4+1; c5<=(k-1); c5++)
                        {
                            for(c6=c5+1; c6<=k; c6++)
                            {
                                printf("%d %d %d %d %d %d\n", n[c1], n[c2], n[c3], n[c4], n[c5], n[c6]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
