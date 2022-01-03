#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define For(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

int main() {
    int n; cin >> n;
    vi arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    } 
    sort(all(arr));
    For(i, 1, n+1) {
        if(arr[i-1] != i) {
            pl(i);return 0;
        }
    }
    pl(n+1); return 0;
}