#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
#define MOD 1000000007
using namespace std;

int power(int x, int y) {
    int temp;
    if(y == 0) return 1;
    temp = power(x, y/2);
    if(y %2 == 0) {
        return (temp*temp)%MOD;
    } else {
        return (x * temp * temp)%MOD;
    }
}

void solve() {
    int n; cin >> n;
    cout << power(2, n) << endl;
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int __t; cin >> __t; while(__t--)
    solve();
}