#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    srand(time(0));
    priority_queue<int, vector<int>, less<int> > pq;
    For(i, 0, 5) {
        pq.push( (int)(100*(float)rand()/(float)RAND_MAX) );
    }
    For(i, 0, 5) {
        cout << pq.top() << endl;
        pq.pop();
    }
}

signed main() {
    // SPEED1;
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    // int __t; cin >> __t; while(__t--)
    solve();
}