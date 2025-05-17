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

void dfs(vector<string> &a, vector<vector<string>> &dp, int x, int y) {
    if(dp[x][y] != "") {
        return; 
    }
    if(x == 0 || y == 0) {
        return;
    }
    dfs(a, dp, x-1, y);
    dfs(a, dp, x, y-1);
    dp[x][y] = min(dp[x-1][y], dp[x][y-1]) + a[x][y];
    return;
}

void solve() {
    inpt(n);
    vector<string> a(n);
    For(i, 0, n) {
        cin >> a[i];
    }

    vector<vector<string>> dp(n, vector<string>(n, ""));
    dp[0][0] = a[0][0];
    For(i, 1, n) {
        dp[0][i] = dp[0][i-1] + a[0][i];
        dp[i][0] = dp[i-1][0] + a[i][0];
    }
    dfs(a, dp, n-1, n-1);
    pl(dp[n-1][n-1]);
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