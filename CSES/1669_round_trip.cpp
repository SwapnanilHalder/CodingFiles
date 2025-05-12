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

bool detectCycle(vector<vector<int>> &graph, vector<int> &color, vector<int> &parent, int head, deque<int> &ans) {
    // deb(head);
    // pv2d(graph);
    color[head] = 1;
    for(auto x: graph[head]) {
        if(color[x] == 0) {
            parent[x] = head;
            // cout << "Sending x: " << x << " of head: " << head << endl;
            if(detectCycle(graph, color, parent, x, ans)) {
                // pl("DETECTED");
                // deb(x);
                // ans.push_front(x);
                return 1;
            }
        } else if(color[x] == 1) {
            if(parent[head] != x) {
                // pv(parent);
                // pv(color);
                // deb(x);
                // deb(head);
                // pl("DETECTED FIRST: ");
                ans.push_front(x);
                ans.push_front(head);
                while(head != x) {
                    head = parent[head];
                    ans.push_front(head);
                }
                // ans.push_front(x);
                return 1;
            }
        }
    }
    color[head] = 2;
    return 0;
}


void solve() {
    inpt(n); inpt(m);
    vector<vector<int>> graph(n+1);
    For(i, 0, m) {
        inpt(x); inpt(y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> color(n+1, 0);
    vector<int> parent(n+1, -1);
    deque<int> ans;
    For(i, 1, n+1) {
        if(color[i] == 0) {
            if(detectCycle(graph, color, parent, i, ans)) {
                int sz = ans.size();
                // int last = ans.front();
                pl(sz);
                while(!ans.empty()) {
                    cout << ans.front() << " ";
                    ans.pop_front();
                }
                // pl(last);
                return;
            }
        }
    }
    pl("IMPOSSIBLE");
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

// 5 6
// 1 3
// 1 2
// 5 3
// 1 5
// 2 4
// 4 5

// 1 -> 2 3 5
// 2 -> 1 4
// 3 -> 1 5
// 4 -> 2 5
// 5 -> 1 3

// 1 -> 2 -> 4 -> 5 -> 1