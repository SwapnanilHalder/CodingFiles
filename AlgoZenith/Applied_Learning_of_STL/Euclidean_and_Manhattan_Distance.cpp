#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    double eucDist=0, manDist=0;
    eucDist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    manDist = abs(x1-x2) + abs(y1-y2);

    cout << fixed << setprecision(7) << eucDist << " " << manDist << endl;
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