#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;
 
void solve() {
    int n; cin>> n;
    while(n != 1) {
        cout << n << " ";
        if(n % 2 == 0) {
            n >>=1;
        } else {
            n *= 3;
            n += 1;
        }
    }
    cout << n << endl;
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