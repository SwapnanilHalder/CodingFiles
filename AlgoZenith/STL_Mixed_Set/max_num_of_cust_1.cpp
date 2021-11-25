#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a; i<b; i++)
#define SPEED1 cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
#define pmint(v) cout<< #v<<endl;for(auto itr = v.begin(); itr != v.end(); itr++){cout << "\t" << itr->first << " ->  " << itr->second;cout << "\n";}
using namespace std;

void solve() {
    int n; cin >> n;
    int come[n], leave[n];
    For(i, 0, n) {
        cin >> come[i] >> leave[i];
    }

    map<int, int> temp;
    For(i, 0, n) {
        temp[come[i]]++;
        temp[leave[i]]--;
    }
    // pmint(temp);
    int count = 0, max_count = - std::numeric_limits<int>::max();
    for(auto it = temp.begin(); it != temp.end(); it++) {
        count += it->second;
        max_count = max(count, max_count);
    }
    cout << max_count<<endl;

    // For(i, 1, temp.size()) {
    //     temp[i] += temp[i-1];
    // }
    // int maxm = *max_element(temp.begin(), temp.end());
    // cout << (maxm) << endl;
    return;
}   

int32_t main() {
    SPEED1;
    int t; cin >> t;
    while(t--) {
        solve();
    }
}

