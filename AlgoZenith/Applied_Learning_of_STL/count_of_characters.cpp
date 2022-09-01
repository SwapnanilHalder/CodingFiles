#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void solve() {
    string s; getline(cin, s);
    map<char, int> mapp;
    for(int i='a'; i<='z'; i++) {
        mapp[char(i)] = 0;
    }
    for(auto &x: s) {
        if(isupper(x))
            x = tolower(x);
        if(islower(x))
            mapp[x]++;
    }
    for(auto &x : mapp) {
        cout << x.second << " ";
    }
    cout << '\n';
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int __t; cin >> __t; string s;
    getline(cin, s);
    while(__t--)
    solve();
}