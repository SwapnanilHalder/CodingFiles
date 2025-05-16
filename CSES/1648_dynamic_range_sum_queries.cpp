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

class SegmentTree {
    public:
        int len;
        vector<int> t;

        SegmentTree(int n) {
            t.resize(4*n);
        }

        void build(vector<int> &a, int tl, int tr, int v) {
            if(tl == tr) {
                t[v] = a[tl];
                return;
            }
            int tm = (tl + tr)/2;
            build(a, tl, tm, v*2);
            build(a, tm+1, tr, v*2+1);
            t[v] = (t[v*2] + t[v*2+1]);
        }
        void print() {
            pv(t);
        }

        int query(int v, int tl, int tr, int ql, int qr) {
            if(tr < ql || qr < tl) {
                return 0;
            }
            if(tl >= ql && qr >= tr) {
                return t[v];
            }
            int tm = (tl + tr)/2;
            int leftAns = query(v*2, tl, tm, ql, qr);
            int rightAns = query(v*2+1, tm+1, tr, ql, qr);
            return (leftAns+rightAns);
        }

        void update(int v, int tl, int tr, int pos, int new_val) {
            // deb(v); deb(tl); deb(tr); deb(pos); deb(new_val); pl("");
            if(tl == tr) {
                t[v] = new_val;
                return;
            }
            int tm = (tl+tr)/2;
            if(pos <= tm) {
                update(v*2, tl, tm, pos, new_val);
            } else {
                update(v*2+1, tm+1, tr, pos, new_val);
            }
            t[v] = t[v*2] + t[v*2+1];
        }
};

void solve() {
    inpt(n); inpt(q);
    SegmentTree* st = new SegmentTree(n);

    vector<int> arr(n);
    For(i, 0, n) {
        inpt(x);
        arr[i] = x;
    }
    st->build(arr, 0, n-1, 1);
    // st->print();
    For(i, 0, q) {
        inpt(x); inpt(y); inpt(z);
        switch (x)
        {
        case 1:
            st->update(1, 0, n-1, y-1, z);
            // st->print();
            break;

        case 2:
            pl(st->query(1, 0, n-1, y-1, z-1));
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