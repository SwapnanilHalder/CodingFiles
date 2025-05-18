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

void solve() {
    inpt(n);
    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }

    vector<int> dp(n+2, INT_MAX);
    dp[0] = INT_MIN;
    For(i, 0, n) {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        *it = arr[i];
    }
    auto it = lower_bound(dp.begin(), dp.end(), INT_MAX);
    pl((it-dp.begin())-1);
    return;
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