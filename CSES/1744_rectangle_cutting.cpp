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

void solve() {
    int a, b; cin>> a >> b;
    vector<vector<int>> dp(a+1, vector<int> (b+1, INT_MAX));
    for(int i=0; i<a+1; i++) {
        dp[i][1] = i-1;
    }
    for(int i=0; i<b+1; i++) {
        dp[1][i] = i-1;
    }
    for(int i=0; i<a+1 && i<b+1; i++) {
        dp[i][i] = 0;
    }
    for(int i=2; i<a+1; i++) {
        for(int j=2; j<b+1; j++) {
            for(int m=1; m<i; m++) {
                dp[i][j] = min(dp[i][j], dp[m][j]+dp[i-m][j]+1);
            }
            for(int n=1; n<j; n++) {
                dp[i][j] = min(dp[i][j], dp[i][n]+dp[i][j-n]+1);
            }
        }
    }
    // pv2d(dp);
    cout << dp[a][b] << endl;
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