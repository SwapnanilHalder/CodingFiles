#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define pii pair<int,int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;

class SegTree {
public:
    vector<pair<int, int>> t;

    SegTree(int n) {
        t.resize(4*n);
    }

    void build(vector<int> &a, int tl, int tr, int v) {
        if(tl == tr) {
            t[v] = {a[tl], tl};
            return;
        }
        int tm = (tl+tr)/2;
        build(a, tl, tm, 2*v);
        build(a, tm+1, tr, 2*v+1);
        t[v] = max(t[2*v], t[2*v+1]);
    }

    pair<int,int> query(int tl, int tr, int v, int l, int r) {
        // deb(l); deb(r);
        if(r < l) {
            return {INT_MIN, -1};
        }
        if(l > tr || tl > r) {
            return {INT_MIN, -1};
        }
        if(tl >= l && r >= tr) {
            return t[v];
        }
        int tm = (tl+tr)/2;
        pair<int, int> left = query(tl, tm, 2*v, l, r);
        pair<int, int> right = query(tm+1, tr, 2*v+1, l, r);
        return max(left, right);
    }
};

int maxGlide(SegTree* t, pair<int,int> &head, vector<int> &dp, int l, int r) {
    // pl("\nEntered maxGlide");
    // deb(head.first); deb(head.second);
    int val = head.first;
    int idx = head.second;

    if(l == r) {
        return dp[l];
    }

    pii left = t->query(0, dp.size()-1, 1, l, idx-1);
    pii right = t->query(0, dp.size()-1, 1, idx+1, r);
    // deb(left.first); deb(left.second); deb(right.first); deb(right.second);
    int ans1 = INT_MIN, ans2 = INT_MIN;

    if(left.second != -1) {
        ans1 = maxGlide(t, left, dp, l, idx-1);
    }
    if(left.first < val) dp[idx] = max(dp[idx], ans1+1);
    else dp[idx] = max(dp[idx], ans1);

    if(right.second != -1) {
        ans2 = maxGlide(t, right, dp, idx+1, r);
    }
    if(right.first < val) dp[idx] = max(dp[idx], ans2+1);
    else dp[idx] = max(dp[idx], ans2);

    return dp[idx];
}

void solve() {
    inpt(n);
    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
    SegTree* t = new SegTree(n);
    t->build(arr, 0, n-1, 1);

    // deb(t->query(0, n-1, 1, 0, n-1).first);
    // deb(t->query(0, n-1, 1, 0, n-1).second);
    // deb(t->query(0, n-1, 1, 0, n-2).first);
    // deb(t->query(0, n-1, 1, 0, n-2).second);

    pair<int,int> head = t->query(0, n-1, 1, 0, n-1);
    vector<int> dp(n, 1);
    int ans = maxGlide(t, head, dp, 0, n-1);
    // pv(dp);
    pl(ans);
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

