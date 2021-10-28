#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a; i<b; i++)
using namespace std;

void sol() {
    int n; cin >> n;
    vector<pair<int, int>> pp(n);
    For(i, 0, n) {
        cin >> pp[i].first >> pp[i].second;
    }
    sort(pp.begin(), pp.end());
    int maxm = - std::numeric_limits<int>::max();
    int temp;
    For(i, 0, n-1) {
        temp = 0;
        For(j, i+1, n) {
            if(pp[j].first <= pp[i].second) {
                temp++;
            }
        }
        maxm = max(maxm, temp);
    }
    cout << maxm+1 << endl;
}

int32_t main() {
    int t; cin >> t;
    while(t--) {
        sol();
    }
}

