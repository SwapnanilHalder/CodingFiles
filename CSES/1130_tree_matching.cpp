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

vector<int> edges;
vi total;
vi2d arr;

void bfs(int parent, int x) {
    if(edges[x] != 0) return;
    // if(arr[x].size() == 1 && arr[x][0] == parent && edges[parent] == 0) {
    //     total[x] = 1;
    //     total[parent] += 1;
    //     edges[x] = 1;
    //     edges[parent] = 1;
    //     return;
    // } 
    // if(arr[x].size() == 1 && arr[x][0] == parent) return;
    // deb(parent); deb(x);
    int temp_total = 0;
    For(i, 0, arr[x].size()) {
        if(arr[x][i] != parent) 
        {
            bfs(x, arr[x][i]);
            if(edges[arr[x][i]] == 0 && edges[x] == 0) {
                edges[arr[x][i]] = 1;
                edges[x] = 1;
                total[x] += (total[arr[x][i]] + 1);
                total[arr[x][i]] += 1;
            } else {
                total[x] += total[arr[x][i]];
            }
        }
    }
    // deb(parent); deb(x);
    // pv(total);
    // pv(edges);
    // cout << endl;
}

void solve() {
    inpt(n);
    edges = vi(n+1, 0);
    total = vi(n+1, 0);
    arr = vi2d(n+1);

    For(i, 0, n-1) {
        inpt(x); inpt(y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    bfs(-1, 1);
    pl(total[1]);
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