#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;

void solve() {
    inpt(n); inpt(m);
    vector<vector<pair<int, int>>> weight(n+1);
    For(i, 0, m) {
        inpt(x); inpt(y); inpt(z);
        weight[x].push_back({z, y});
    }

    vector<int> dist(n+1, LLONG_MAX);
    dist[1] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();
        int prev_weight = top.first;
        int prev_idx = top.second;
        if(prev_weight > dist[prev_idx])
            continue;
        for(pair<int,int> x: weight[prev_idx]) {
            int new_weight = prev_weight + x.first;
            if(dist[x.second] > new_weight) {
                dist[x.second] = new_weight;
                pq.push({dist[x.second], x.second});
            }
            
        }
        // pv(dist);
    }
    For(i, 1, n+1) {
        cout << dist[i] << " ";
    }
    return;

}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //int __t; cin >> __t; while(__t--)
    solve();
}