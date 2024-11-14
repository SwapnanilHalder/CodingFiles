#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr;
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    int count = 0;
    for(int i=0; i<n-1; i++) {
        if(arr[i] <= arr[i+1]) {
            continue;
        } else {
            count += (arr[i] - arr[i+1]);
            arr[i+1] = arr[i];
        }
    }
    cout << count << endl;
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