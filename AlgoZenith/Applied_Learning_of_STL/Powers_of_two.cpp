#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    int total=0, temp;
    vector<int> arr(n);
    For(i, 0,n) {
        cin >> arr[i];
    }
    int sum = accumulate(arr.begin(), arr.end(), 0);
    // vector<int> count(sum+2, 0 );
    map<int, int> m;
    for(int i=0; i<n; i++) {
        // cout << "first for\n";
        for(int x=2; x<=((long long)1<<32) && x <= sum; x<<=1) {
            temp = x-arr[i];
            if(temp >= 0 && m.count(temp))  {
                total += m[temp];
            }
        }
        m[arr[i]]++;
    }
    cout << total << endl;
    return;
}

signed main() {
    // SPEED1;
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int __t; cin >> __t; while(__t--)
    solve();
}