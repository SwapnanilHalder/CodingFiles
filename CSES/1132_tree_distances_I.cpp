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

vector<int> firstMax;
vi secondMax;
vi maxPath;
vector<vi> arr;

void dfs1(int x, int parent) {
    // deb(parent);deb(x); cout << endl;
    for(auto &child: arr[x]) {
        if(child == parent) continue;
        dfs1(child, x);
        if(firstMax[child]+1 > firstMax[x]) {
            secondMax[x] = firstMax[x];
            firstMax[x] = firstMax[child]+1;
            maxPath[x] = child;
            // deb(x); deb(child);
            // pv(maxPath);
        } else {
            secondMax[x] = max(firstMax[child]+1, secondMax[x]);
        }
    }
}

void dfs2(int x, int parent) {
    for(auto &child: arr[x]) {
        if(child == parent) continue;
        if(maxPath[x] == child) {
            if(secondMax[x]+1 > firstMax[child]) {
                secondMax[child] = firstMax[child];
                firstMax[child] = secondMax[x]+1;
                maxPath[child] = x;
            } else {
                secondMax[child] = max(secondMax[x]+1, secondMax[child]);
            }
        } else {
            if(firstMax[x]+1 > firstMax[child]) {
                secondMax[child] = firstMax[child];
                firstMax[child] = firstMax[x]+1;
                maxPath[child] = x;
            } else {
                secondMax[child] = max(firstMax[x]+1, secondMax[child]);
            }
        }
        dfs2(child, x);
    }
}

void solve() {
    inpt(n);
    firstMax.resize(n+1, 0);
    secondMax.resize(n+1, 0);
    maxPath.resize(n+1, -1);
    arr = vector<vi> (n+1);
    For(i, 0, n-1) {
        inpt(x); inpt(y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    // pv2d(arr);

    dfs1(1, 0);
    // pv(firstMax);
    // pv(maxPath);
    // pv(secondMax);
    // cout << endl;
    dfs2(1, 0);
    // pv(firstMax);
    // pv(maxPath);
    // pv(secondMax);

    For(i, 1, n+1) {
        cout << firstMax[i] << " ";
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