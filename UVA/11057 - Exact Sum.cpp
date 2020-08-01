#include <bits/stdc++.h>
using namespace std;
int n;

int bsearchmid( vector<int>& arr, int m)
{
    int lo=0, hi=n-1;
    int mid = (lo+hi)/2;

    while(lo<=hi)
    {
        if(arr[mid] == m)   return mid;

        if(arr[mid] < m) lo = mid+1;
        else hi = mid-1;

        mid = (lo+hi)/2;
    }
    return lo-1;
}

void SearchAns(vector<int> & arr, int& m, int& mid, int& ansi, int& ansj)
{
    int i=0, j=n-1;
    int sum;
    while(i<=mid && j>=mid+1)
    {
        sum = arr[i]+arr[j];
        if(sum == m) {
            ansi=arr[i++]; ansj=arr[j--];
            if(arr[i]==arr[j]) return;
        }
        else if(sum<m) i++;
        else j--;
    }
    if(i<mid && arr[mid]+arr[mid-1]==m)
        { ansi= arr[mid-1]; ansj=arr[mid]; }

    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    int m;

    while(cin >> n)
    {
        vector<int> arr(n);

        for(int i=0, j=0; i<n; i++)
                cin >> arr[i];

        cin >> m;
        cin.ignore();
        cin.ignore();

        sort(arr.begin(), arr.end());

        int mid = bsearchmid(arr, m/2);
        int ansi, ansj;
        SearchAns(arr, m, mid, ansi, ansj);

        cout << "Peter should buy books whose prices are "<<  ansi << " and " << ansj << "." << endl<<endl;
    }

    return 0;
}
