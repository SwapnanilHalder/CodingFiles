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

const int maxN = 2e6+2;
int dp[maxN];

int digits(int x) {
    int k = 0;
    while(x != 0) {
        k = max(k, x%10);
        x /= 10;
    }
    return k;
}

void solve() {
    int n; cin >> n;
    // For(i, 0, sizeof(dp)) {
    //     dp[i] = INT_MAX;
    // }
    // dp[0] = 0;
    int x = n;
    int count = 0;
    while(x != 0) {
        int highest = digits(x);
        // deb(x); deb(highest);
        x -= highest;
        count++;
    }
    pl(count); return;
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