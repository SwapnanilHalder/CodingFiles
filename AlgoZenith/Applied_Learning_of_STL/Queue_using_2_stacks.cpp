#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n; cin>>n;
    string s; int x;
    stack<int> s1, s2;
    For(i, 0, n) {
        cin >> s;
        if(s == "push") {
            cin >> x;
            s1.push(x);
        }
        else if(s == "front") {
            if(s2.empty()) {
                if(s1.empty()) {
                    cout << 0 << endl; continue;
                }
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            cout << s2.top() << endl;
        }
        else if(s=="pop") {
            if(s2.empty()) {
                if(s1.empty()) {
                    cout << 0 << endl; continue;
                }
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            cout << s2.top() << endl;
            s2.pop();
        }
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