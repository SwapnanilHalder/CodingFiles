#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
using namespace std;

// string return_postfix(string &s, int st, int en) {
//     stack<string> st;
//     For(i, st, en) {

//     }
// }

int presedence(char c) {
    if(c == '+' || c == '-') 
        return 1;
    if(c == '*' || c == '/')
        return 2;
    if(c == '^')
        return 3;
    else
        return 0;
}

void solve() {
    string s, ans=""; 
    // cout << "Enter the str\n";
    cin >> s;
    int pending=0;
    stack<char> st;
    // pl("Starting");
    For(i, 0, s.size()) {
        // pl(i);
        if(islower(s[i])) {
            ans.push_back(s[i]);
        } 
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans.push_back(st.top());
                st.pop();
            }
            if(!st.empty() && st.top() == '(') st.pop();
        }
        else {
            // cout << "Entered : " << s[i] << endl;
            if(!st.empty() && st.top() == '(') {
                st.push(s[i]);
            }
            else {
                while(!st.empty() && presedence(st.top()) >= presedence(s[i])) {
                    ans.push_back(st.top());
                    // pl(ans);
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        // pl(ans);
    }
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    pl(ans); return;
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

// abc^
// *(+

// e-)d+c^b(*a
// abc^d+*e-
// a*(b+d^c)-e
// abdc^+*
// *+^
// bd+c^
// bdc^+
// b+d-c
// bd+c-
// c^d+b

