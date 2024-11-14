#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int m, n; cin >> m >> n;
    multiset<int>  ticket_price ;
    int x;
    For(i, 0, m) {
        cin >> x;
        ticket_price.insert(x);
    }
    For(i, 0, n) {
        // pl(i);
        cin >> x;
        auto it = ticket_price.upper_bound(x);
        if(it == ticket_price.begin()) {
            pl("-1"); continue;
        }
        auto found = it--;
        pl(*it);
        ticket_price.erase(it);
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