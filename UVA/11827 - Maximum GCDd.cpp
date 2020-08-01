#include<bits/stdc++.h>

using namespace std;

int callgcd(int a, int b)
{
    if(b==0)
        return a;
    else return callgcd(b, a%b);
}


int main()
{
    int t,arr[1050];
    scanf("%d",&t);
    getchar();
    string s;
    while(t--)
    {
        getline(cin,s);
        stringstream ss(s);
        int j=0;
        while(ss>>arr[j])
            ++j;
        int gcd=0;
        for(int i=0; i<j; i++)
        {
            for(int l=i+1; l<j; l++)
            {
                gcd = max(gcd,callgcd(arr[i], arr[l]));

            }
        }
        printf("%d\n",gcd);
    }
    return 0;
}



















/*#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{


    int n, num[101], i, j, k, maxx, A, B, r;
    char numstr[101][11];

    scanf("%d ", &n);


    while(n--)
    {

        i=0;
        do
        {
            j=0;
            do
            {
                scanf("%c", &numstr[i][j]);

                if(numstr[i][j]=='\n' || numstr[i][j]== 32)
                    break;

            }
            while(++j);

            if(numstr[i][j] == '\n')
            {
                numstr[i][j] = '\0';
                num[i] = atol(numstr[i]);
                printf("%d\n", num[i]);
                break;
            }

            numstr[i][j] = '\0';
            num[i] = atol(numstr[i]);
            printf("%d\n", num[i]);
        }
        while(++i);

        for(j=0, maxx=0; j<=i-1; j++)
        {
            for(k=j+1; k<=i; k++)
            {
                A = __gcd(num[j], num[k]);


                if(maxx< A)
                    maxx = A;
            }
        }
        printf("%d\n", maxx);
    }

    return 0;
}*/
