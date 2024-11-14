#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int start = 0, end = n-1;
    int count = 0;
    while(start <= end) {
        if(arr[start] + arr[end] <= x) {
            count++;
            start++;
            end--;
        }
        else {
            count++;
            end--;
        }
    }

    cout << count << endl;
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