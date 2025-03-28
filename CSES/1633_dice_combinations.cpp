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
#define MOD 1000000007
#define all(x) x.begin(), x.end()
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> dp(6, 0);
    dp[0] = 1;
    For(i, 1, n+1) {
        int ans = 0;
        For(j, 0, 6) {
            ans += dp[j];
            // deb(ans);
            ans %= MOD;
        }
        // deb(i); deb(ans);
        dp[i%6] = ans;
    }
    cout << dp[n%6] << endl;
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