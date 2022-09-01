#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    int x; cin >> x;
    int count=0;
    // for(int i=1; i<=x; i++) {
    //     if(i%5 == 0) {
    //         count += floor((log(i)/log(5)));
    //     }
    // }
    // cout << count << endl;
    int div = 5;
    while(x >= div) {
        count += floor(x/div);
        div *= 5;
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