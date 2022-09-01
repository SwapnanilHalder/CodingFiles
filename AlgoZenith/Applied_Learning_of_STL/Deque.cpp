#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    string s; int x;
    deque<int> dq;
    For(i, 0, n) {
        cin >> s;
        if(s == "insertback") {
            cin >> x;
            dq.push_back(x);
        }
        if(s == "insertfront") {
            cin >> x;
            dq.push_front(x);
        }
        if(s == "printback") {
            cout << (!dq.empty()? dq.back() : 0) << endl; 
        }
        if(s == "printfront") {
            cout << (!dq.empty()? dq.front() : 0) << endl; 
        }
        if(s == "eraseback") {
            if(!dq.empty()) {
                dq.pop_back();
            }
        }
        if(s == "erasefront") {
            if(!dq.empty()) {
                dq.pop_front();
            }
        }
        if(s == "print") {
            cin >> x;
            if(!dq.empty() && x >=0 && x < dq.size()) {
                cout << dq.at(x) << endl;
            }
            else {
                cout << 0 << endl;
            }
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