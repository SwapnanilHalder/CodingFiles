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
using namespace std;
#define MOD 1000000007


void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m+1, 0));

    int x; cin >> x;
    if(x == 0) {
        For(i, 1, m+1) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][x] = 1;
    }
    For(i, 1, n) {
        cin >> x;
        if(x == 0) {
            For(j, 1, m+1) {
                for(int k=j-1; k <= j+1; k++) {
                    if(k>=0 && k<=m) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        } else {
            for(int k=x-1; k <= x+1; k++) {
                if(k>=0 && k<=m) {
                    dp[i][x] += dp[i-1][k];
                    dp[i][x] %= MOD;
                }
            }
        }
        // pv2d(dp);
        // cout << endl << endl;
    }
    int ans = 0;
    For(i, 0, m+1) {
        ans += dp[n-1][i];
        ans %= MOD;
    }
    pl(ans); return;
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



// 0 1 2

// 2 0 0 2

//   0 1 2 3
// 1 0 1 2 0
// 2 1 1 3 7
// 3 0 1 2 0
// 4 0 0 1 0