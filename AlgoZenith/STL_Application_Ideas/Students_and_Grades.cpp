#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n, m, x; cin>>n>>m;
    unordered_set<int> s;
    For(i, 0, n) {
        cin >> x;
        s.insert(x);
    }
    For(i, 0, m) {
        cin >> x;
        if(find(s.begin(), s.end(), x) == s.end()) {
            pl("NO");
        }
        else {
            pl("YES");
        }
        s.insert(x);
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