#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define pii pair<int,int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;

bool comp(const vector<int> &a, const vector<int> &b) {
    if(a[0] != b[0]) {
        return (a[0] < b[0]);
    } else {
        if(a[1] != b[1]) {
            return (a[1] < b[1]);
        } else {
            return (a[2] < b[2]);
        }
    }
}

void solve() {
    inpt(n);
    vector<int> dp(n+1, 0);
    vector<vector<int>> arr(n);
    For(i, 0, n) {
        inpt(x); inpt(y); inpt(z);
        arr[i] = {x, y, z};
    }
    vector<pair<int, int>> find(n+1);
    find[0] = {0, 0};
    For(i, 0, n) {
        find[i+1] = {arr[i][1], i+1};
    }
    sort(find.begin(), find.end());

    // sort(arr.begin(), arr.end(), comp);

    // For(i, 0, n+1) {
    //     cout << find[i].first << ", " << find[i].second << endl;
    // }
    dp[0] = 0LL;
    For(i, 1, n+1) {
        vector<int> curr = arr[find[i].second-1];
        // deb(curr[0]);
        auto it = lower_bound(find.begin(), find.begin()+i, make_pair(curr[0],LLONG_MIN), [](const pii &a, const pii &b){return a<b;});
        it--;
        // cout << "found: " << it->first << " , " << it->second << endl;
        dp[i] = max(dp[i-1], dp[it-find.begin()] + curr[2]);
        // pv(dp);
    }
    pl(dp[n]);
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