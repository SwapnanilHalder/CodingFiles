#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

#define MOD 100000009
#define ll unsigned long long int

void solve() {
    int n; cin>>n; int x;
    ll total=1;
    for(int i=0;i<n;i++) {
        cin >> x;
        total = (total * (ll)x) % MOD;
    }
    cout << total << endl;
    return;
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int __t; cin >> __t; while(__t--)
    solve();
}