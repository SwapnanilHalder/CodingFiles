#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define pi pair<int,int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;

bool isPossible(int t, const vector<int> &arr, int target) {
    long long count = 0LL;  // Explicitly use long long
    for (int i = 0; i < arr.size(); i++) {
        count += (static_cast<long long>(t) / arr[i]);
        // Early exit if count exceeds target (optimization)
        if (count >= target) return true;
    }
    return (count >= target);
}

void solve() {
    inpt(n); inpt(t);

    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }

    int l = 1, r = LLONG_MAX;
    int ans = r;
    while(l <= r) {
        int mid = l +(r-l)/2;
        if(isPossible(mid, arr, t)) {
            ans = min(ans, mid);
            r = mid-1LL;
        } else {
            l = mid+1LL;
        }
    }
    pl(ans);
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