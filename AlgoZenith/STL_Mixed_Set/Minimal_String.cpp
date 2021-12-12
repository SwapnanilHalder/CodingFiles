#include <bits/stdc++.h> 
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define SPEED ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pv(v) for(const auto &i: v){cout<<i<<" ";}cout << "\n"
#define pmint(v) cout<< #v<<endl;for(auto itr = v.begin(); itr != v.end(); itr++){cout << "\t" << itr->first << " ->  "; pv(itr->second);}
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)


void sol() {
    string S, T, U; cin >> S;
    // reverse(S.begin(), S.end());
    int tail = 0, n = S.size();
    map<char, vector<int>> mapp;
    For(i, 0, n) {
        mapp[S[i]].pb(i);
    }
    // pmint(mapp);
    int last = -1;
    loop(it, mapp) {
        if(last == n-1) 
            break;
        loop(itv, it->second) {
            if(*itv > last) {
                U.pb(it->first);
                S[*itv] = '0';
                last = *itv;
            }
        }
    }
    for(int i=n-1; i>= 0; i--) {
        if(S[i] != '0')
            U.pb(S[i]);
    }
    cout << U << endl;
}

int main() {
    int t; cin >> t;
    while(t--) sol();
}



/*

5
bdab
sss
gtddb
cab
acdb


abdb
sss
bddtg
abc
abdc

*/