#include <stdio.h>

int n, noc[50000], height;
int beg1, beg2;


void bsearch()
{
    int end1, end2, mid1, mid2;

    beg1=beg2 = 0;
    end1=end2 = n-1;

    mid1 = mid2 = (beg1+end1)/2;

    while(beg1<=end1 || beg2<=end2)
    {
        if(beg1<=end1) {
            if(height <= noc[mid1])
                end1 = mid1-1;
            else
                beg1 = mid1+1;
            mid1 = (beg1+end1)/2;
        }

        if(beg2<=end2) {
            if(height >= noc[mid2])
                beg2 = mid2+1;
            else
                end2 = mid2-1;
            mid2 = (beg2+end2)/2;
        }
    }
    beg1 = beg1-1;

    return;
}

int main()
{
    int i, query;
    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d", &noc[i]);

    scanf("%d", &query);
    for(i=0; i<query; i++)
    {
        scanf("%d", &height);
        bsearch();

        if(beg1>=0 && beg1<n) {
            printf("%d ", noc[beg1]);
        }
        else
            printf("X ");

        if(beg2>=0 && beg2<n) {
            printf("%d\n", noc[beg2]);
        }
        else
            printf("X\n");
    }

    return 0;
}
