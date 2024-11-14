#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int x, target; cin >> x >> target;
    // vector<int> arr(x);
    vector<pair<int, int>> arr;
    int k;
    For(i, 0, x) {
        cin >> k;
        arr.push_back({k, i+1});
    }
    sort(arr.begin(), arr.end());

    int i=0, j=x-1;
    while(i < j) {
        if(arr[i].first + arr[j].first == target) {
            cout << arr[i].second << " " << arr[j].second << endl;return;
        }
        if(arr[i].first + arr[j].first > target) {
            j--; continue;
        }
        if(arr[i].first + arr[j].first < target) {
            i++; continue;
        }
    }
    pl("IMPOSSIBLE");
    return;
}


signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
}