#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    if(n == 3 ) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 3 << endl;
        cout << 2 << endl;
        cout << "2 1" << endl;
        return;
    }
    int sum = 0;
    if(n%2 == 0) {
        sum = (n/2)*(n+1);
    } else {
        sum = ((n+1)/2)*n;
    }
    if(sum%2 != 0) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        sum >>=1;
        int k = n;
        vector<int> arr;
        vector<int> count(n, 0);
        while(sum > 0) {
            // if(sum >= k) {
            //     arr.push_back(k);
            //     sum -= k;
            //     k--;
            // } else {
            //     k = sum;
            //     arr.push_back(k);
            //     sum -= k;
            // }
            if(sum < k) {
                k = sum;
            }
            arr.push_back(k);
            sum -= k;
            k--;
            // cout <<"PUSHED " << k << " ; SUM: " << sum << " ; NOW k: " << k << endl;
        }
        cout << arr.size() << endl;
        for(int i=0; i<arr.size(); i++) {
            cout << arr[i] << " ";
            count[arr[i]] = 1;
        } cout << endl;
        cout << n-arr.size() << endl;
        for(int i=1; i<n; i++) {
            if(!count[i]) {
                cout<< i << " ";
            } 
        }
        cout << endl;
    }
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