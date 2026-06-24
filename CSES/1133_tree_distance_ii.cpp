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

vector<int> children;
vi score;
vector<vi> arr;
int n;

void dfs1(int x, int parent) {
    // deb(parent);deb(x); cout << endl;
    for(auto &child: arr[x]) {
        if(child == parent) continue;
        dfs1(child, x);
        children[x] += children[child]+1;
        score[x] += score[child] + children[child]+1;
    }
}

void dfs2(int x, int parent) {
    for(auto &child: arr[x]) {
        if(child == parent) continue;
        score[child] = score[x] - children[child] + (n-1-children[child]-1);
        dfs2(child, x);
    }
}

void solve() {
    cin >> n;
    children.resize(n+1, 0);
    score.resize(n+1, 0);
    // score1.resize(n+1, 0);
    arr = vector<vi> (n+1);
    For(i, 0, n-1) {
        inpt(x); inpt(y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    // pv2d(arr);

    dfs1(1, 0);
    // pv(children);
    // pv(score);
    // cout << endl;
    dfs2(1, 0);
    // pv(children);
    // pv(score);

    For(i, 1, n+1) {
        cout << score[i] << " ";
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