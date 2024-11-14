#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    string str; cin >> str;
    vector<int> count(26, 0);
    for(int i=0; i<str.size(); i++) {
        count[str[i]-'A']++;
    }
    int odds=-1;
    For(i, 0, 26) {
        if(count[i]%2 != 0) {
            if(odds == -1) odds = i;
            else {
                cout << "NO SOLUTION" << endl;
                return;
            }
        }
    }
    string ans;
    For(i, 0, 26) {
        if(count[i] > 0 && count[i] %2 == 0 && i != odds) {
            For(j, 0, count[i]/2) {
                ans += ('A'+i);
            }
        }
    }
    int sz = ans.size();
    if(odds != -1) {
        For(i, 0, count[odds]) {
            ans += ('A'+odds);
        }
    }
    for(int i=sz-1; i>=0; i--) {
        ans.push_back(ans[i]);
    }
    cout << ans << endl;
    return;
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