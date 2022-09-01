#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    int n, x; cin>>n;
    int count=0, last_big=0;
    for(int i=0; i<n; i++) {
        cin >> x;
        if(i==0) 
            last_big = x;
        if(x > last_big) {
            last_big = x;
        }
        if(x < last_big) {
            count += (last_big-x);
        }
    }
    cout << count << endl;
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