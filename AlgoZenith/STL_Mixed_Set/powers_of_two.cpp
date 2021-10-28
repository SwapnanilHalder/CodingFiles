#include <bits/stdc++.h>
#define For(i, a, b) for(int i=a; i<b; i++)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n];
    map<int, int> mapped;
    For(i, 0, n) {
        cin >> arr[i];
        mapped[arr[i]]++;
    }
    int x = 1, count = 0;
    For(j, 0, 32) {
        For(i, 0, n) {
            mapped[arr[i]]--;
            if(mapped.count(x-arr[i])) {
                count += mapped[x-arr[i]];
            }
        }
        For(i, 0, n) {
            mapped[arr[i]]++;
        }
        x <<=1;
    }
    cout << count << endl;
}

int32_t main() {
    SPEED1;
    int t; cin >> t;
    while(t--) {
        solve();
    }
}