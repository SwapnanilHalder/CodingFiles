#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> people(m, 0), boat(n, 0);
    for(int i=0; i<m; i++) {
        cin >> people[i];
    }
    for(int i=0; i<n; i++) {
        cin >> boat[i];
    }
    sort(all(people));
    sort(all(boat));
    if(people[0] > boat[0]) {
        cout << "0\n";
        return 0;
    }
    int p_idx=0, b_idx=0;
}