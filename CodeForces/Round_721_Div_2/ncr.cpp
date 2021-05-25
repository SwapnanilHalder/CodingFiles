// CPP program To calculate The Value Of nCr
#include <bits/stdc++.h>
#define int long long int

using namespace std;

int fact(int n);

int nCr(int n, int r)
{
	return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
int fact(int n)
{
	int res = 1;
	for (int i = 2; i <= n; i++)
		res = res * i;
	return res;
}

// Driver code
int32_t main()
{
	int n = 99999, r = 2;
	cout << nCr(n, r) << endl;
	return 0;
}
