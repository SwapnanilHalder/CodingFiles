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

deque<int> findPath(vector<vector<int>> &dp, vector<int> &a, vector<int> &b) {
    int m = dp.size()-1, n = dp[0].size()-1;
    deque<int> dq;
    while(m > 0 && n > 0 && dp[m][n] != 0) {
        // deb(m); deb(n);
        if(a[m-1] == b[n-1]) {
            dq.push_front(a[m-1]);
            m--; n--;
        } else if(dp[m-1][n] > dp[m][n-1]) {
            m--;
        } else {
            n--;
        }
    }
    return dq;
}

void solve() {
    inpt(m); inpt(n);
    vector<int> a(m), b(n);
    For(i, 0, m) {
        cin >> a[i];
    }
    For(i, 0, n) {
        cin >> b[i];
    }

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    For(i, 1, m+1) {
        For(j, 1, n+1) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } 
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
        pv2d(dp); cout << endl;
    }

    deque<int> ans = findPath(dp, a, b);
    pl(dp[m][n]);
    while(!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop_front();
    }
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