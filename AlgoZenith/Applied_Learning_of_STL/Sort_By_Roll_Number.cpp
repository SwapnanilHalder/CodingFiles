#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    int n; cin>>n;
    map<int, string> mapp;
    int x; string s;
    for(int i=0; i<n; i++) {
        cin >> s >> x;
        mapp.insert({x, s});
    }
    for(auto &x: mapp) {
        cout << x.second << " " << x.first << endl;
    }
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