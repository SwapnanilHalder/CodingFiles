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



vector<int> hashVal;
vector<int> pPow;

const int base = 7;
const int MOD = 1e9+7;

void setpPow(int n) {
    For(i, 1, n) {
        pPow[i] = (pPow[i-1]*base)%MOD;
    }
}

void setHashVal(string s, int n) {
    For(i, 1, n+1) {
        hashVal[i] = (hashVal[i-1]+ (s[i-1]*pPow[i-1])%MOD) % MOD;
    }
}

int getHash(int l, int r) {
    return (hashVal[r+1] - (hashVal[l]*pPow[r+1-l])%MOD +MOD) % MOD;
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    hashVal.resize(n+1, 0);
    pPow.resize(n, 1);

    setpPow(n);

    setHashVal(s, n);
    pv(pPow);
    pv(hashVal);

    For(i, 0, n) {
        int cur_idx = 0;
        bool ok = 1;
        while(cur_idx < n && ok) {
            int len = min(i+1, n-cur_idx);
            ok &= (getHash(0, len-1) == getHash(cur_idx, cur_idx+len-1));
            cur_idx += len;
        }
        if(ok) {
            cout << i+1 << " ";
        }
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