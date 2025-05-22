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

void buildlps(vector<int> &lps, string &pattern) {
    int prevlps = 0, i = 1;
    while(i < pattern.size()) {
        if(pattern[prevlps] == pattern[i]) {
            lps[i] = prevlps+1;
            prevlps++;
            i++;
        } else {
            if(prevlps != 0) {
                prevlps = lps[prevlps-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> ans;

void findMatching(string &str, vector<int> &lps, string &pattern) {
    int i=0, j=0;
    while(i < str.size()) {
        if(str[i] == pattern[j]) {
            i++;
            j++;

            if(j == pattern.size()) {
                ans.push_back(i-pattern.size());
                j = lps[j-1];
            }

        } else {
            if(j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
}


void solve() {
    string str, pattern;
    cin >> str >> pattern;

    vector<int> lps(pattern.size(), 0);

    buildlps(lps, pattern);
    pv(lps);
    findMatching(str, lps, pattern);
    pl(ans.size());
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