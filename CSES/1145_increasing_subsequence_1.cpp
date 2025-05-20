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

class SegTree {
public:
    vector<int> t;

    SegTree(int n) {
        t = vector<int>(4*n, 0);
    }

    void update(int tl, int tr, int v, int pos, int val) {
        if(tl == tr) {
            t[v] = val; return;
        }
        int tm = (tl+tr)/2;
        if(pos <= tm) {
            update(tl, tm, 2*v, pos, val);
        } else {
            update(tm+1, tr, 2*v+1, pos, val);
        }
        t[v] = max(t[2*v], t[2*v+1]);
    }

    int query(int tl, int tr, int v, int ql, int qr) {
        if(ql > qr) return 0;
        if(tl >= ql && qr >= tr) {
            return t[v];
        }
        if(ql > tr || tl > qr) {
            return 0;
        }
        int tm = (tl+tr)/2;
        int ans1 = query(tl, tm, v<<1, ql, qr);
        int ans2 = query(tm+1, tr, (v<<1)+1, ql, qr);
        return max(ans1, ans2);
    }

};

void solve() {
    inpt(n);
    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
    SegTree* t = new SegTree(n);
    vector<pi> store;
    For(i, 0, n) {
        store.push_back({arr[i], i});
    }
    auto cmp = [&](const pi& a, const pi& b){
        if(a.first == b.first) {
            return (a.second > b.second);
        }
        return (a.first < b.first);
    };

    sort(store.begin(), store.end(), cmp);
    For(i, 0, n) {
        cout << store[i].first << " , " << store[i].second << endl;
    }
    vector<int> ans(n, -1);
    int maxm = 0;
    For(i, 0, n) {
        int temp = t->query(0, n-1, 1, 0, store[i].second-1);
        ans[store[i].second] = temp+1;
        maxm = max(maxm, temp+1);
        t->update(0, n-1, 1, store[i].second, temp+1);
    }
    pv(ans);
    pl(maxm);
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