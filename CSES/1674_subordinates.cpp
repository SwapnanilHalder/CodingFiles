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

vector<vector<int>> child;
vector<int> total;

int bfs(int x) {
    if(child[x].size() == 0) return 0;
    // if(total[x] != -1) return total[x];
    // int ans = (x == 1)? 0 : 1;
    int ans = 0;
    For(i, 0, child[x].size()) {
        ans += bfs(child[x][i]) + 1;
    }
    total[x] = ans;
    return total[x];
}

void solve() {
    inpt(n);
    child = vector<vector<int>> (n+1);
    total = vector<int> (n+1, 0);
    total[1] = 0;
    For(i, 0, n-1) {
        inpt(x);
        child[x].push_back(i+2);
    }
    // pv2d(child);
    bfs(1);
    For(i, 1, n+1) {
        cout << total[i] << " ";
    } cout << endl;
    return;
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