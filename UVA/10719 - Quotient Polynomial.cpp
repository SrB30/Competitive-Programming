#include<bits/stdc++.h>

using namespace std;

int extractInt(string& s, vector<int>& a)
{
	stringstream ss(s);

	int x, cnt=0;
	while(ss >> x)
	{
		a.push_back(x);
		cnt++;
	}

	//cout << cnt << endl;

	return cnt;
}


int quotientPolynomial(vector<int>& a, vector<int>& b, int k, int n)
{
	b.push_back(0);

	for(int i=1; i<n; i++)
	{
		int x = a[i-1] + (k*b[i-1]);
		b.push_back(x);
	}

	int m  = b[n-1] * (-1) * k;
	int rem = a[n-1] - m;

	return rem;
}

int main()
{
	int k;

	while(cin >> k)
	{
		cin.ignore();

		string s;
		vector<int> a, b;

		getline(cin, s);
		int n = extractInt(s, a);

		int rem = quotientPolynomial(a, b, k, n);

		cout << "q(x):";
		for(int i=1; i<n; i++)
			cout << " " << b[i];
		cout << endl;

		cout << "r = " << rem << endl << endl;
	}

	return 0;
}
