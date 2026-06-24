#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define pi pair<int,int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;

void solve() {
    inpt(n); inpt(x); inpt(y);
    vector<int> arr (n,0);
    vector<int>arr1(n, 0);
    For(i, 0, n) {
        cin >> arr[i];
        arr1[i] = arr[i]-(arr[i]/x)*y;
    }
    int total = 0;
    // pv(arr1);
    int maxm = INT_MIN, maxIdx = -1;
    For(i, 0, n) {
        if(arr1[i] > maxm) {
            maxm = arr1[i];
            maxIdx = i;
        }
    }
    total += arr[maxIdx];
    For(i, 0, n) {
        if(i == maxIdx) continue;
        total += arr[i]/x*y;
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
    int __t; cin >> __t; while(__t--)
    solve();
}