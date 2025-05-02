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

void solve() {
    int n; cin >> n;
    vi arr(n);
    int maxn = 0;
    For(i, 0, n) {
        cin >> arr[i];
        maxn = max(maxn, arr[i]);
    }
    vi hori_dp(maxn+1), vert_dp(maxn+1);
    hori_dp[maxn] = 1;
    vert_dp[maxn] = 1;
    for(int i=maxn-1; i>=1; i--) {
        hori_dp[i] = ((2 * hori_dp[i+1])%MOD + vert_dp[i+1])%MOD;
        vert_dp[i] = ((4 * vert_dp[i+1])%MOD + hori_dp[i+1])%MOD;
    }

    For(i, 0, n) {
        int x = maxn + 1 - arr[i];
        cout << (hori_dp[x] + vert_dp[x])%MOD << endl;
    }
    
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