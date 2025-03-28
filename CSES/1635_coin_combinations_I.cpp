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

const int maxN = 2e6+1;
int dp[maxN];

void solve() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
  
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    For(i, 1, x+1) {
        // pl("Entered");
        For(j, 0, n) {
            if(i -arr[j] < 0) continue;
            dp[i] += dp[i-arr[j]];
            dp[i] %= 1000000007;
        }
        // pv(dp);
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
// 1 0 0 0 0 0 0 0 0 0
// 1 0 1 1 1 3 2 5 6 8