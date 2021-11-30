#include <bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define For(i, a, b) for(int i=a; i<b; i++) 
#define all(v) v.begin(), v.end()
#define int long long int

void sol() {
    int n, x; cin >> n;
    // cout << "4 ";
    vector<int> arr1(n), diff(n);
    For(i, 0, n) {
        cin >> arr1[i];
    }
    For(i, 0, n) {
        cin >> x;
        diff[i] = arr1[i] - x;
    }
    // cout << "2 ";
    sort(diff.begin(), diff.end());
    // cout << "3 ";
    int sum = 0, pos=0;
    For(i, 0, n) {
        // cout << "1 ";
        if(diff[i] > 0) {
            sum += (n-i-1);
        }
        if(diff[i] == 0) {
            sum += n - (upper_bound(all(diff), 0) - diff.begin() );
        }
        if(diff[i] < 0) {
            sum += n - (upper_bound(all(diff), -diff[i]) - diff.begin() );
        }
    }
    cout << sum << endl;
}

int32_t main() {
    SPEED;
    int t; cin >> t;
    while(t--) sol();
}