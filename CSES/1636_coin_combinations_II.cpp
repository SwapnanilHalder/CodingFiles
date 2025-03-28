#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define MOD 1000000007
using namespace std;
const int maxN = 2e6 + 1;

int dp[maxN];

void solve() {
    memset(dp, 0, sizeof(dp));
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
    dp[0] = 1;
    For(i, 0, n) {
        for(int j = arr[i]; j <= x; j++) {
            dp[j] = dp[j] + dp[j-arr[i]];
            dp[j] %= MOD;
        }
    }
    cout << dp[x] << endl;
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //int __t; cin >> __t; while(__t--)
    solve();
}


// 0 1 2 3 4 5 6 7 8 9
// 1 0 1 0 1 0 1 0 1 0
// 1 0 1 1 1 1 2 1 2 2
// 1 0 1 1 1 2 2 2 3 3