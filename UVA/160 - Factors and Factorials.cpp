#include<bits/stdc++.h>
using namespace std;
map <int,int> listt[101];

void primestore( map <int, int> & pr)
{
    for(int m=12; m<=100; m++)
    {
        if(pr.find(m) != pr.end()) { listt[m][m]=1; continue; }

        int n=m, d = sqrt(m), c=0;
        while(n%2==0)   { listt[m][2] = ++c; n /= 2; }


        for(int i=3; i<=d && n>1; i+=2)
        {
            c=0;
            while(n%i==0) { listt[m][i] = ++c; n /= i; }
        }

        if(n>1) listt[m][n]=1;
    }
}

int main()
{
    int n;

    map <int, int> pr;
    {
        pr[2] = 0;
        pr[3] = 1;
        pr[5] = 2;
        pr[7] = 3;
        pr[11] = 4;
        pr[13] = 5;
        pr[17] = 6;
        pr[19] = 7;
        pr[23] = 8;
        pr[29] = 9;
        pr[31] = 10;
        pr[37] = 11;
        pr[41] = 12;
        pr[43] = 13;
        pr[47] = 14;
        pr[53] = 15;
        pr[59] = 16;
        pr[61] = 17;
        pr[67] = 18;
        pr[71] = 19;
        pr[73] = 20;
        pr[79] = 21;
        pr[83] = 22;
        pr[89] = 23;
        pr[97] = 24;
    }

    listt[2][2] = 1;
    listt[3][3] = 1;
    listt[4][2] = 2;
    listt[5][5] = 1;
    listt[6][2] = 1;
    listt[6][3] = 1;
    listt[7][7] = 1;
    listt[8][2] = 3;
    listt[9][3] = 2;
    listt[10][2] = 1;
    listt[10][5] = 1;
    listt[11][11] = 1;
    primestore( pr);

    while(cin >> n)
    {
        if(n == 0) break;
        map <int, int> m;

        for(int i=2; i<=n; i++)
        {
            for(auto j=listt[i].begin(); j!=listt[i].end(); j++)
                m[j->first] += j->second;
        }

        cout << setw(3) << n;
        cout << "! =";

        auto j= m.begin();
        for(int k=0; j!=m.end(); j++)
        {
            cout << setw(3) << j->second;
            if(++k==15) break;
        }
        cout << endl;

        if(m.size()<16) continue;
        cout << setw(9) << (++j)->second;

        for(j=++j; j!=m.end(); j++)
            cout << setw(3) << j->second;
        cout << endl;
    }

    return 0;
}
