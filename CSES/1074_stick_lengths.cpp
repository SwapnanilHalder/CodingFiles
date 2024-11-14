#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n); 
    For(i, 0, n) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int total = 0, total1= 0;

    int mid = arr[(int)(n/2)];
    For(i, 0, n) {
        total += abs(arr[i] - mid);
    }
    if(n%2 == 0) {
        mid = arr[(int)(n/2) + 1];
        For(i, 0, n) {
            total1 += abs(arr[i] - mid);
        }
        pl(min(total1, total)); return;
    }
    pl(total);
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