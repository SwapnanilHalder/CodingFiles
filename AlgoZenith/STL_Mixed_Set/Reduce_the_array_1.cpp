#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define For(i, a, b) for(int i=a; i<b; i++)

void sol() {
    int n, x; cin >> n;
    priority_queue<int> q;
    int mini = numeric_limits<int>::max();
    For(i, 0, n) {
        cin >> x;
        mini = min(mini, x);
        q.push(x);
    }
    // sort(arr.begin(), arr.end());
    // int sum = 0;
    // For(i, 0, n) {
    //     sum += arr[i] * (n-i);
    // }
    int sum = 0, j = 1;
    while(!q.empty()) {
        sum += q.top() * j;
        // cout << sum << " ; ";
        q.pop();
        j++;
    }
    sum -= mini;
    cout << sum << endl;
}

int32_t main() {
    int t; cin >> t;
    while(t--) sol();
}