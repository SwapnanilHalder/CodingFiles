#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    queue<int> q1, q2;
    For(i, 1, n+1) {
        q1.push(i);
    }
    int rem = n;
    bool flag = 0;
    while(n>0) {
        while(!q1.empty()) {
            // pl("in first loop");
            if(!flag) {
                q2.push(q1.front());
                q1.pop();
            } else {
                cout << q1.front() << " ";
                q1.pop(); n--;
            }
            flag = !flag;
        }
        while(!q2.empty()) {
            // pl("In second loop"            );
            q1.push(q2.front());
            q2.pop();
        }    
        // pl("1 round done");
    }
    cout << endl; return;
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