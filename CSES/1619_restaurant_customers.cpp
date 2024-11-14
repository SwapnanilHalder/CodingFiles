#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int x; cin >> x;
    vector<int> arrival(x), departure(x);
    vector<pair<int, int>> timing;
    int a, b;
    For(i, 0, x) {
        cin >> a >> b;
        arrival.push_back(a);
        departure.push_back(b);
        timing.push_back({a, 1});
        timing.push_back({b, -1});
    }
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    sort(timing.begin(), timing.end());

    int count = 0, max_count = 0;
    For(i, 0, 2*x) {
        count += timing[i].second;
        max_count  = max(max_count, count);
    }
    pl(max_count);
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