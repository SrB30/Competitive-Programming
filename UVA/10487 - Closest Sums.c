#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int cmp(const void *a, const void *b)
{
    return (*((int*) a) - *((int*) b));
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, cn=0, sum[500000], q, d1,d2, qn, i, j, k, beg, end, mid, res, num[1002];

    while(scanf("%d", &n) == 1)
    {
        if(n==0)
            return 0;

        for(i=0; i<n; i++)
            scanf("%d", &num[i]);

        for(i=0, k=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
                sum[k++] = num[i] + num[j];
        }

        qsort(sum, k, sizeof(int), cmp);

        printf("Case %d:\n", ++cn);
        scanf("%d", &q);

        for (i=0, res=0; i<q; i++)
        {
            scanf("%d", &qn);

            beg=0;
            end=k-1;
            while (beg <=end)
            {
                mid = (beg+end)/2;
                if(sum[mid] == qn)
                {
                    res = sum[mid];
                    break;
                }
                else if(sum[mid] < qn)
                    beg = mid+1;
                else
                    end = mid-1;
            }



            if(res!=qn)
            {
                if(end >-1 && beg < k)
                {
                    if((d1=abs(qn-sum[beg])) == (d2=abs(qn-sum[end])))
                        res = sum[beg];

                    else if(d1<d2)
                        res = sum[beg];

                    else
                        res = sum[end];
                }
                else if(end<0)
                    res = sum[0];

                else
                    res = sum[k-1];
            }

            printf("Closest sum to %d is %d.\n", qn, res);
        }
    }

    return 0;
}
