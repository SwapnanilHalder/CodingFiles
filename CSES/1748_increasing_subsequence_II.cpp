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

int curr_idx = -1;

bool comp (const vi& a, const vi& b) {
    return(a[0] > b[0]);
};

class SegTree {
public:
    vector<vi> t;
    int n;

    SegTree(int n) {
        this->n = n;
        t = vi2d(4*n, {0,-1,0});
    }



    void update(int tl, int tr, int v, int pos, vi val) {
        if(tl == tr) {
            t[v] = val; return;
        }
        int tm = (tl+tr)/2;
        if(pos <= tm) {
            update(tl, tm, 2*v, pos, val);
        } else {
            update(tm+1, tr, 2*v+1, pos, val);
        }
        t[v] = max(t[2*v], t[2*v+1], comp);
        t[v] = {max(t[2*v][0], t[2*v+1][0]), val[1], t[2*v][2]+t[2*v+1][2]};
    }

    void print() {
        For(i, 0, 4*n) {
            cout << "("<<t[i][0] << ","<<t[i][1] << "," << t[i][2] << ") ";
        } cout << endl;
    }

    vi query(int tl, int tr, int v, int ql, int qr) {
        if(ql > qr) return {0,curr_idx,0};
        if(tl >= ql && qr >= tr) {
            return t[v];
        }
        if(ql > tr || tl > qr) {
            return {0,curr_idx,0};
        }
        int tm = (tl+tr)/2;
        vi ans1 = query(tl, tm, v<<1, ql, qr);
        if(curr_idx == 3) {
            deb(tl); deb(tm); deb(v<<1);
            pv(ans1);
        }
        vi ans2 = query(tm+1, tr, (v<<1)+1, ql, qr);
        if(curr_idx == 3) {
            deb(tm+1); deb(tr); deb((v<<1)+1);
            pv(ans2);
        }
        vi ans = vi{max(ans1[0], ans2[0]), curr_idx, 0};
        if(curr_idx > ans1[1]) {
            ans[2] += ans1[2];
        }
        if(curr_idx > ans2[2]) {
            ans[2] += ans2[2];
        }
        return ans;
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
    int anss = 0;
    For(i, 0, n) {
        curr_idx = store[i].second;
        deb(curr_idx);
        vi temp = t->query(0, n-1, 1, 0, store[i].second-1);
        pv(temp);
        anss += temp[2]+1; 
        t->update(0, n-1, 1, store[i].second, {temp[0]+1, temp[1], temp[2]+1});
        t->print();
    }
    pv(ans);
    pl(anss);
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