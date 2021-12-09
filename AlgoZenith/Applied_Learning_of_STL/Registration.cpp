#include <bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int n; cin >> n;
    string inp;
    map<string, int> mapp;
    for(int i=0; i<n; i++) {
        cin >> inp;
        if(mapp.find(inp) == mapp.end()) {
			cout << "OK\n";
        }
        else {
            cout << inp << mapp[inp] << endl;
        }
        mapp[inp]++;
    }
    return;
}

int main() {
    int t; cin>>t;
    while(t--) solve();
}