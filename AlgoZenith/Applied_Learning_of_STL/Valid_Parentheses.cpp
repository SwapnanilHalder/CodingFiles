#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
using namespace std;

void solve() {
    stack<char> st;
    string s; cin >> s; int n=s.size();
    int count=0;
    For(i, 0, n) {
        if(s[i] == '(') {
            st.push(s[i]);
        }
        else {
            if(!st.empty() && st.top() == '(') {
                st.pop();
            }
            else {
                count++;
            }
        }
    }
    count += st.size();
    cout << count << endl;
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