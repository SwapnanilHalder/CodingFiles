#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define pl(x) cout << x << "\n"
#define For(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

int getsum(int a)
{
	int rem = 0, sum = 0;
	while (a > 0) {
		rem = a % 10;
		sum += rem;
		a = a / 10;
	}
	return sum;
}

void solve(int a, int b, int c)
{
	int num, x = 0, q = 0, w = 0;
	vi store;

	For(i, 1, 82) {

		num = pow((double)i, double(a));

		num = b * num + c;

		if (num > 0 && num < 1e9) {
			x = getsum(num);

			if (x == i) {
				store.pb(num);
				q++;
				w++;
			}
		}
	}

	pl(store.size());
    pv(store);
}

int main()
{
    SPEED1;
	// int a = 3, b = 2, c = 8;
    int a, b, c;
    cin >> a >> b >> c;

	solve(a, b, c);

	return 0;
}
