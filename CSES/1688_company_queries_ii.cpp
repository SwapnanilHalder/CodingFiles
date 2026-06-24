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

vector<int> height;
vector<int> euler;
vi segment;
vi first;
vi2d arr;
int eulerLen;

void dfs(int x, int parent, int h) {
    height[x] = h;
    first[x] = euler.size();
    euler.push_back(x);
    // deb(x); deb(parent); deb(h);
    // pv(euler);
    for(auto &child: arr[x]) {
        if(child == parent) continue;
        dfs(child, x, h+1);
        euler.push_back(x);
    }
}

void buildSegment(int tl, int tr, int v) {
    if(tl == tr) {
        segment[v] = euler[tr];
        return;
    }
    int mid = (tl+tr)/2;
    buildSegment(tl, mid, 2*v);
    buildSegment(mid+1, tr, 2*v+1);
    int l = segment[v << 1], r = segment[v << 1 | 1];
    segment[v] = (height[l] < height[r]) ? l : r;
}

int query(int tl, int tr, int v, int ql, int qr) {
    if(ql <= tl && tr <= qr) {
        return segment[v];
    }
    if(ql > tr || tl > qr) {
        return -1;
    }
    int mid = (tl+tr)/2;
    int ans1 = query(tl, mid, 2*v, ql, qr);
    int ans2 = query(mid+1, tr, 2*v+1, ql, qr);
    if(ans1 == -1) return ans2;
    if(ans2 == -1) return ans1;
    return (height[ans1] < height[ans2]) ? ans1: ans2;
}

int rangeQuery(int q1, int q2) {
    int u = first[q1], v = first[q2];
    if(u > v) {
        return query(0, eulerLen-1, 1, v, u);
    }
    return query(0, eulerLen-1, 1, u, v);
}

void solve() {
    inpt(n); inpt(q);
    height = vector<int>(n+1, -1);
    arr.resize(n+1);
    first.resize(n+1);
    For(i, 2, n+1) {
        inpt(x);
        arr[i].push_back(x);
        arr[x].push_back(i);
    }
    // pv2d(arr);
    
    dfs(1, -1, 0);
    // pv(euler);
    // pv(height);
    eulerLen = euler.size();
    segment.resize(4*eulerLen);
    // deb(eulerLen);
    buildSegment(0, eulerLen-1, 1);
    // pv(segment);
    For(i, 0, q) {
        inpt(x); inpt(y);
        pl(rangeQuery(x, y));
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