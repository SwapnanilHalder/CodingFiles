#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
using namespace std;

void solve() {
    int n;cin>>n;
    string s; int x;
    queue<int> q;
    For(i, 0, n) {
        cin >> s;
        if(s == "add") {
            cin >> x;
            q.push(x);
        }
        else if(s == "print") { 
                cout << ((!q.empty()) ? q.front() : 0) << endl;
        }
        else if(s == "remove") {
            if(!q.empty()) 
                q.pop();
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
