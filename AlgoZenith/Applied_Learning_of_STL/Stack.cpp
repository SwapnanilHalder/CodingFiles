#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
using namespace std;

void solve() {
    stack<int> st;
    int n, x; cin>>n; string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        if(s == "add") {
            cin >> x;
            st.push(x);
        }
        if(s == "print") {
             cout << ((!st.empty()) ? st.top() : 0) << endl;
        }
        if(s == "remove") {
            if(!st.empty()) st.pop();
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