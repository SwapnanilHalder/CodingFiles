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

vi2d arr;
int LOG;

int query(int x, int k) {
    int ans = x;
    for(int i = LOG-1; i>=0; i--) {
        if(k & (1 << i)) {
            ans = arr[ans][i];
        }
    }
    return (ans == 0) ? -1 : ans;
}

void solve() {
    inpt(n); inpt(q);

    LOG = log2(n)+1;

    arr = vi2d (n+1, vi(LOG, 0));
    For(i, 2, n+1) {
        inpt(x);
        arr[i][0] = x;
    }
    For(j, 1, LOG) {
        For(i, 2, n+1) {
            arr[i][j] = arr[arr[i][j-1]][j-1];
        }
    }
    // pv2d(arr);

    For(i, 0, q) {
        inpt(x); inpt(k);
        pl(query(x, k));
    }

}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //int __t; cin >> __t; while(__t--)
    solve();
}