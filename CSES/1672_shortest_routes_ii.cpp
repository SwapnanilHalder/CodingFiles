#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
#define MAX 1000000000000
using namespace std;

void solve() {
    inpt(n); inpt(m); inpt(q);
    
    vector<vector<int>> weight(n+1, vector<int>(n+1, MAX));
    For(i, 0, m) {
        inpt(x); inpt(y); inpt(z);
        weight[x][y] = min(weight[x][y], z);
        weight[y][x] = min(weight[x][y], z);
    }
    For(i, 1, n+1) {
        weight[i][i] = 0;
    }

    For(k, 1, n+1) {
        For(i, 1, n+1) {
            For(j, 1, n+1) {
                weight[i][j] = min(weight[i][j], weight[i][k]+weight[k][j]);
            }
        }
    }
    For(i, 0, q) {
        inpt(x); inpt(y);
        cout << (weight[x][y] == MAX ? -1 : weight[x][y]) << endl;
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