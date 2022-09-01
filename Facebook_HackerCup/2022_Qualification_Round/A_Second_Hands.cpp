#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n, k; cin >>n>>k;
    vector<int> arr(n);
    For(i, 0, n) cin>>arr[i];
    if(2*k < n) {
        pl("NO"); return;
    }
    map<int, int> m;
    For(i, 0, n) {
        m[arr[i]]++;
        if(m[arr[i]] > 2) {
            pl("NO"); return;
        }
    }
    pl("YES"); return;
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int __t; cin >> __t; 
    For(i, 1, __t+1) {
        cout << "Case #" << i<<": ";
        solve();
    }
}