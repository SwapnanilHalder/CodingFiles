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

int minCount = INT_MAX;
const int maxN = 2e6 + 1;
int dp[maxN];

void solve() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    For(i, 0, x+1) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    For(i, 0, n) {
        for(int weight = arr[i]; weight <= x; weight++) {
            // pl("inside for loop");
            dp[weight] = min(dp[weight], dp[weight-arr[i]] + 1);
        }
        // deb(i);
        // pv(dp);
    }
    cout << ((dp[x] == INT_MAX) ? -1 : dp[x]) << endl;
}

signed main() {
    memset(dp, -1, sizeof(dp));
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //int __t; cin >> __t; while(__t--)
    solve();
}