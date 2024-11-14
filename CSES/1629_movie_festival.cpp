#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int x; cin >> x;
    multimap<int, int> mp;
    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> gq; 
    For(i, 0, x) {
        int a, b; cin >> a >> b;
        mp.insert({b, a});
        gq.push({b, a});
    }
    int count = 1;
    auto head = gq.top();
    gq.pop();
    while(!gq.empty()) {
        if(gq.top().second < head.first ) {
            gq.pop();
        } else {
            count++;
            head = gq.top();
            gq.pop();
        }
    }
    pl(count);
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