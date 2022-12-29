#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
using namespace std;

class Compare {
public:
    bool operator() (pair<int, int> &a, pair<int, int> &b) {
        if(a.first != b.first)
            return (a.first < b.first);
        else {
            return (a.second > b.second);
        }
    }
};

void print_pq(priority_queue< pair<int, int>, vector<pair<int, int>>, Compare> &pq) {
    while(!pq.empty()) {
        cout << pq.top().first << "," <<pq.top().second << " ; ";
        pq.pop();
    }
    pl('\n');
}

void solve() {
    int n, k; cin>>n>>k;
    vector<int> arr;
    priority_queue< pair<int, int>, vector<pair<int, int>>, Compare> pq;
    For(i, 0, n) {
        int x;
        cin >> x;
        arr.push_back(x);
        // pl("INput");
    }
    For(i, 0, k) {
        pq.push({arr[i], i});
        // pl("1ag");
    }
    cout << pq.top().first << " ";

    For(i, k, n) {
        pq.push({arr[i], i});
        while(!pq.empty() && (pq.top().second > i || pq.top().second < i-k+1)) {
            pq.pop();
        }
        cout << pq.top().first << " ";
    }
    cout << endl;
}

signed main() {
    // SPEED1;
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int __t; cin >> __t; while(__t--)
    solve();
}