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
    vector<int> prev(n+1, -1);
    For(i, 0, m) {
        inpt(x); inpt(y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    bool found = 0;
    while(!q.empty()) {
        if(found) break;
        queue<int> temp;
        while(!q.empty()) {
            temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()) {
            if(found) break;
            for(auto x: graph[temp.front()]) {
                if(prev[x] == -1) {
                    prev[x] = temp.front();
                    q.push(x);
                }
                if(x == n){
                    found = 1;
                    break;
                }
            }
            temp.pop();
        }
    }
    if(found) {
        deque<int> dq;
        int x = n;
        dq.push_front(x);
        while(x != 1) {
            x = prev[x];
            dq.push_front(x);
        }
        pl(dq.size());
        while(!dq.empty()) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        return;
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