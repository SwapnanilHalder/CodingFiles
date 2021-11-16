#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a; i<b; i++)
using namespace std;

void solve() {
    int n; cin >> n;
    int come[n], leave[n];
    For(i, 0, n) {
        cin >> come[i] >> leave[i];
    }

    vector<int> temp(std::numeric_limits<int>::max(), 0);
    For(i, 0, n) {
        temp[come[i]]++;
        temp[leave[i]]--;
    }
    For(i, 1, temp.size()) {
        temp[i] += temp[i-1];
    }
    int maxm = *max_element(temp.begin(), temp.end());
    cout << (maxm) << endl;
    return;
}   

int32_t main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}