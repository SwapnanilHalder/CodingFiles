#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n+1, 0);
    int x, y;
    For(i, 0, n) {
        cin >> x;
        arr[i+1] = arr[i] + x;
    }
    For(i, 0, q) {
        cin >> x >> y;
        cout << arr[y] - arr[x-1] << endl;
    }
    return;
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