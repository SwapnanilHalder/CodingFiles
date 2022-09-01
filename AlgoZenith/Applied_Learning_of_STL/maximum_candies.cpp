#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    int n, b; cin>>n>>b;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int count=0, score=0;
    for(int i=0; i<n; i++) {
        count += arr[i];
        score++;
        if(count > b) {
            count -= arr[i];
            score--;
            break;
        }
    }
    cout << score << endl;
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