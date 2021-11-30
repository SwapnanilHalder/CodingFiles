#include <bits/stdc++.h>
#define For(i, a, b) for(int i=a; i<b; i++)
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void sol() {
    int n, x; cin >> n;
    map<int, int> mapp;
    For(i, 0, n) {
        cin >> x;
        mapp[x]++;
    }
    int count = 0;
    for(auto &it : mapp) {
        if(it.first > it.second) {
            count += it.second;
        }
        if(it.first < it.second) {
            count += (it.second - it.first);
        }
    }
    cout << count << endl;
}

int main() {
    SPEED;
    int t; cin >> t;
    while(t--) sol();
}