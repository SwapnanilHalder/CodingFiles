#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >>arr[i];
    }
    int sum = INT_MIN, maxSum = arr[0];
    For(i, 0, n) {
        sum += arr[i];
        if(sum < arr[i]) sum = arr[i];
        maxSum = max(maxSum, sum);
    }
    pl(maxSum); return;
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