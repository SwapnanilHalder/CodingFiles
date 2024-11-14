#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    string str; cin >> str;
    int count=0, max_count=INT_MIN;
    for(int i=0; i<str.size()-1; i++) {
        if(str[i] == str[i+1]) count++;
        else {
            max_count=max(max_count, count+1);
            count = 0;
        }
    }
    max_count=max(max_count, count+1);
    cout << max_count << endl;
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