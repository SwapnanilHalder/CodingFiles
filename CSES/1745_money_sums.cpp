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
    int n; cin >> n;
    vector<int>arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<int> dp(sum+1, 0);
    set<int> s;
    for(int i=0; i<n; i++) {
        set<int> s1 = s;
        s.insert(arr[i]);
        for(auto x: s1) {
            s.insert(x+arr[i]);
        }
    }
    cout << s.size() << endl;
    for(auto x: s) {
        cout << x << " ";
    } cout << endl;
}

signed main() {
    SPEED1;
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    //int __t; cin >> __t; while(__t--)
    solve();
}