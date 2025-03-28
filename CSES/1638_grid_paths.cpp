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

const int maxN = 2e3+1;
int dp[maxN][maxN];


void solve() {
    int n; cin >> n;
    vector<string> arr(n, "");
    For(i, 0, n) {
        cin >> arr[i];
    }
    memset(dp, 0, sizeof(dp));
    if(arr[0][0] == '.') {
        dp[0][0] = 1;
    }
    For(i, 0, n) {
        For(j ,0, n) {
            if(arr[i][j] == '*') {
                continue;
            }
            if((j-1) >= 0) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= 1000000007;
            }
            if((i-1) >= 0) {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= 1000000007;
            }
        }
    }
    // pv2d(dp);
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