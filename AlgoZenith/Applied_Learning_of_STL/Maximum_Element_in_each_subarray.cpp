#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    For(i, 0,n)
        cin >> arr[i];
    if(k>=n) {
        cout << *max_element(arr.begin(), arr.end()) << endl; return;
    }
    int f = 0, s = k-1, max = *max_element(arr.begin(), arr.begin()+k), 
    max_pos = max_element(arr.begin(), arr.begin()+k) - arr.begin();
    cout << max << " ";
    For(f, 1, n-k) {
        s++;
        if(arr[s] >= max) {
            max = arr[s];
            max_pos = s;
        }
        cout << max << " ";
    }
    cout << endl; return;
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