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
#define inpt(x) int x{}; cin >> x
using namespace std;

int fillDP(vector<int> &arr, vector<vector<int>> &dp, int x, int y) {
    if(dp[x][y] != LLONG_MIN) {
        return dp[x][y];
    }
    if( (x+1) < dp.size()) {
        dp[x][y] = max(dp[x][y], arr[x] - fillDP(arr, dp, x+1, y));
    }
    if( (y-1) >= 0) {
        dp[x][y] = max(dp[x][y], arr[y] - fillDP(arr, dp, x, y-1));
    }
    return dp[x][y];
}

void solve() {
    inpt(n);
    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, LLONG_MIN));
    For(i, 0, n) {
        dp[i][i] = arr[i];
    }
    fillDP(arr, dp, 0, n-1);
    // pv2d(dp);
    int ans = (accumulate(arr.begin(), arr.end(), 0LL) +  dp[0][n-1]) >> 1;
    pl(ans);
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