#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str, sortstr, nextstr;
    while(cin >> str)
    {
        if(str[0] == '#')
            break;
        sortstr = nextstr = str;

        next_permutation(nextstr.begin(), nextstr.end());

        sort(sortstr.begin(), sortstr.end());
        //reverse(tmp.begin(), tmp.end());
        //cout << sortstr << endl;

        if(nextstr!=sortstr && sortstr!=nextstr) cout << nextstr << endl;
        else cout << "No Successor" << endl;
    }

    return 0;
}
