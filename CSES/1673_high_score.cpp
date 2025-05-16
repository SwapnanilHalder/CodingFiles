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
#define MIN -10000000000000
using namespace std;

void solve() {
    inpt(n); inpt(m);
    vector<vector<int>> paths;
    For(i, 0, m) {
        inpt(x); inpt(y); inpt(z);
        paths.push_back({x, y, z});
    }
    vector<int> score(n+1, MIN);
    score[1] = 0;
    For(i, 0, n-1) {
        For(j, 0, m) {
            int source = paths[j][0];
            int dest = paths[j][1];
            int weight = paths[j][2];
            if(score[source] != MIN && score[source] + weight > score[dest]) {
                score[dest] = score[source]+weight;
            }
        }
    }
    unordered_set<int> in_cycle;
    For(i, 0, n) {
        For(j, 0, m) {
            int source = paths[j][0];
            int dest = paths[j][1];
            int weight = paths[j][2];
            if(score[source] != MIN && score[source] + weight > score[dest]) {
                in_cycle.insert(dest);
                score[dest] = score[source]+weight;
            }
        }
    }
    queue<int> q;
    for(auto &x: in_cycle) q.push(x);
    bool can_reach_n = 0;
    vector<bool> visited(n+1, 0);
    while(!q.empty()) {
        int source = q.front();
        q.pop();
        if(source == n) {
            can_reach_n = 1;
            break;
        }
        For(i, 0, m) {
            if(paths[i][0] == source && !visited[paths[i][1]]) {
                visited[paths[i][1]] = 1;
                q.push(paths[i][1]);
            }
        }
    }
    if(can_reach_n) {
        pl("-1"); return;
    }
    pl(score[n]); 
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