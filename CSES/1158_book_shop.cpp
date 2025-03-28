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
    int n, k; cin >> n >> k;
    vector<int> price(n), page(n);

    For(i, 0, n) {
        cin >> price[i];
    }
    For(i, 0, n) {
        cin >> page[i];
    }

    memset(dp, 0, sizeof dp);
    For(i, 0, n) {
        for(int j=k; j>= price[i]; j--) {
            dp[j] = max(dp[j], dp[j-price[i]] + page[i]);
        }
        // pv(dp);
    }
    pl(dp[k]); return;
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




// 0 1 2 3 4 5 6 7 8 9 10

// 0 0 0 0 5 5 5 5 5 5 5
// 0 0 0 0 5 5 5 5 12 12 12
// 0 0 0 0 5 8 


// dp[i] = max(dp[i-price[j]] + page[j] , dp[i])