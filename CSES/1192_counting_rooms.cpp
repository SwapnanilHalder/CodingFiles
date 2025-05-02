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
using namespace std;

int axisx[] = {1, -1, 0, 0};
int axisy[] = {0, 0, 1, -1};

void dfs(vector<string> &arr, int x, int y) {
    if(x<0 || x>=arr.size() || y<0 || y >= arr[0].size()) return;
    if(arr[x][y] == '#') return;
    arr[x][y] = '#';
    For(i, 0, 4) {
        dfs(arr, x+axisx[i], y+axisy[i]);
    }
}

void solve() {
    inpt(n); inpt(m);
    vector<string> arr;
    For(i, 0, n) {
        string s;
        cin >> s;
        arr.pb(s);
    }
    int count = 0;
    For(i, 0, n) {
        For(j, 0, m) {
            if(arr[i][j] == '.') {
                count++;
                dfs(arr, i, j);
            }
        }
    }
    pl(count); return;
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