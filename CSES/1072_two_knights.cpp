#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

int comb(int x) {
    x *= x;
    return (x*(x-1))/2;
}

void solve() {
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        int total = comb(i);
        cout << total - 8*((i-1)*(i-2)/2) << endl;
    }
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int __t; cin >> __t; while(__t--)
    solve();
}

// 8
// 1
// 15
// 22
// 19


// 300
// 3 -> 8
// 4 -> 24
// 5 -> 48    2 3 4 3 2 
//             2 3 3 2 .


//             2 3 4 4 3 2
//              2 3 4 3 2

//              6 -> 80 : 32


//              2 3 3 2
//              2 2 2

//              8 -> 8+8+8 -> 8+8+8+8+8+
//              1 -> 3 -> 6 -> 10 -> 15 : 5*6/2