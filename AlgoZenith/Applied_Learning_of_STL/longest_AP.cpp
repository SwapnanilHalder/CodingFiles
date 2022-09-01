#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int count=1, diff=arr[1]-arr[0], max_count = INT_MIN;
    for(int i=1; i<n; i++) {
        if( (arr[i]-arr[i-1]) != diff ) {
            diff = (arr[i]-arr[i-1]);
            max_count = max(count, max_count);
            count=2; 
            continue;
        }
        else
            count++;
    }
    max_count = max(count, max_count);
    cout << max_count << endl;
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