

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

void solve() {
    int n, k; cin >> n >> k;
    vector<int> setbit(n, 0);
    For(i, 0, k) {
        string s; cin >> s;
        For(j, 0, n) {
            setbit[j] |= 1 << (s[j]-'a');
        }
    }
    // pv(setbit);

    vector<int> divisors;
    for(int i=1; i*i<= n; i++) {
        if(n%i == 0) {
            divisors.pb(i);
            if(i*i != n) divisors.pb(n/i);
        }
    }
    // pv(divisors);
    sort(all(divisors));

    for(int &d: divisors) {
        bool possible = 1;
        string ans = "";
        for(int i=0; i<d; i++) {
            int common_mask = (1<<26)-1;
            for(int j=i; j<n; j+= d) {
                common_mask &= setbit[j];
            }
            if(common_mask == 0) {
                possible = 0;
                break;
            }
            int idx = 0;
            for(;idx<26; idx++) {
                if(common_mask & (1<<idx)) {
                    break;
                }
            }
            ans += (char)('a'+idx);
        }
        if(possible) {
            string final = "";
            for(int i=0; i<n/d; i++) {
                final += ans; 
            }
            pl(final);
            return;
        }
    }


}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int __t; cin >> __t; while(__t--)
    solve();
}

/*


i-> 0 1 2 3 6
n -> 0 1 3 4 5 7 8
f -> 2 4 5 6 7 8


a -> 0 1 2
b-> 0 1
c -> 2

*/