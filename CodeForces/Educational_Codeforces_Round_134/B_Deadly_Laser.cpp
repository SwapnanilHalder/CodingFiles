#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int m, n, x, y, s;
    cin >> m>>n>>x>>y>>s;
    // x--, y--;
    // if(x>y) {
    //     if((y+s) < n) {
    //         pl(m+n-2);
    //     }
    //     else {
    //         pl("-1");
    //     }
    //     return;
    // }
    // else if(y>x) {
    //     if((x+s) < m) {
    //         pl(m+n-2);
    //     }
    //     else {
    //         pl("-1");
    //     }
    //     return;
    // }
    // else if(x == y) {
    //     if((x+s) < m) {
    //         pl(m+n-2);
    //     }
    // }
    if((x-1) > s && (y+s) < n) {
        pl(m+n-2);
    }
    else if ((y-1) > s && (x+s) < m) {
        pl(m+n-2);
    }
    else {
        pl("-1");
    }
    return;
    // if((y-1) <= d && (x+s) < m)
    // if((y+s) < n || (x+s) < m) {
    //     pl(m+n-2);
    // }
    // else {
    //     pl("-1");
    // }
    // return;
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