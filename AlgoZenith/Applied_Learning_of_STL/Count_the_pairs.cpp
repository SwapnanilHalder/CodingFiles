#include <bits/stdc++.h>
#define int long long int
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    int n,x; cin>>n>>x;
    vector<int> a(n); auto ai = a.begin();
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(ai, ai+n);
    int count=0, k;
    for(int i=1; i<n; i++) {
        k = upper_bound(ai, ai+i, (x-a[i])) - ai;
        // cout << k << " for : " << a[i] << endl;
        count += k;
    }
    cout << (count<<1) << endl;
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