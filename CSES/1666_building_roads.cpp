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
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1);
    For(i, 0, m) {
        inpt(x); inpt(y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<pair<int, int>> roads;
    queue<int> q;
    q.push(1);
    For(i, 1, n+1) {
        if(!visited[i]) {
            if(i != 1) {
                roads.push_back({1, i});
                q.push(i);
            }
            while(!q.empty()) {
                queue<int> temp;
                while(!q.empty()) {
                    if(visited[q.front()]) {
                        q.pop();
                        continue;
                    }
                    visited[q.front()] = 1;
                    // cout << "pushing: " << q.front() << endl;
                    temp.push(q.front());
                    q.pop();
                }
                while(!temp.empty()) {
                    for(auto x: graph[temp.front()]) {
                        // cout << "Child of " << temp.front() << " : " << x << endl;
                        q.push(x);
                    }
                    temp.pop();
                }
            }
        }
    }
    pl(roads.size());
    for(auto x: roads) {
        cout << x.first << " " << x.second << "\n";
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