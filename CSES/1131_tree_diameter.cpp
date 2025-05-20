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
int maxm;

int bfs(int parent, int x) {

    int ans1 = 0, ans2 = 0;
    For(i, 0, arr[x].size()) {
        if(arr[x][i] != parent) {
            int ans = bfs(x, arr[x][i]);
            if(ans >= ans1 && ans > ans2) {
                ans2 = ans1; ans1 = ans;
            }
            if(ans < ans1 && ans > ans2) {
                ans2 = ans;
            } 
        }
    }
    maxm = max(maxm, ans1+ans2+1);
    // deb(parent); deb(x); deb(maxm);
    return ans1+1;
}

void solve() {
    inpt(n);
    arr = vi2d(n+1);
    maxm = 0;
    For(i, 0, n-1) {
        inpt(x); inpt(y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    bfs(-1, 1);
    pl(maxm-1);
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