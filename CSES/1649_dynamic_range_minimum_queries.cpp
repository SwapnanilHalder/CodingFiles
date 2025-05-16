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

class SegTree {
public:
    vector<int> t;

    SegTree(int n) {
        t.resize(4*n);
    }

    void build(vector<int> &a, int tl, int tr, int v) {
        if(tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl+tr)/2;
        build(a, tl, tm, 2*v);
        build(a, tm+1, tr, 2*v+1);
        t[v] = min(t[2*v], t[2*v+1]); 
    }

    int query(int tl, int tr, int v, int ql, int qr) {
        if(ql > tr || tl > qr) {
            return INT_MAX;
        }
        if(ql <= tl && qr >= tr) {
            return t[v];
        }
        int tm = (tl+tr)/2;
        int leftAns = query(tl, tm, 2*v, ql, qr);
        int rightAns = query(tm+1, tr, 2*v+1, ql, qr);
        return min(leftAns, rightAns);
    }

    void update(int tl, int tr, int v, int pos, int val) {
        if(tl == tr) {
            t[v] = val;
            return;
        }
        int tm = (tl+tr)/2;
        if(pos <= tm) {
            update(tl, tm, 2*v, pos, val);
        } else {
            update(tm+1, tr, 2*v+1, pos, val);
        }
        t[v] = min(t[2*v], t[2*v+1]);
    }

};


void solve() {
    inpt(n); inpt(q);
    vector<int> a(n);
    For(i, 0, n) {
        cin >> a[i];
    }

    SegTree* st = new SegTree(n);
    st->build(a, 0, n-1, 1);

    For(i, 0, q) {
        inpt(x); inpt(y); inpt(z);
        switch(x) {
            case 1:
                st->update(0, n-1, 1, y-1, z);
                break;
            case 2:
                pl(st->query(0, n-1, 1, y-1, z-1));
                break;
            default:
                break;
        }
    }
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