#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int x,y;
    cin>>x>>y;
    int m = max(x, y);
    int mid = m*m - (m-1);
    if (x == y) {
        cout << mid << endl;
    } else {
        if(m % 2 == 0) {
            cout << (mid + x-y) << endl;
        } else {
            cout << (mid - x+y) << endl;
        }
        
    }
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