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
    vector<vector<int>> arr(n+1);
    vector<int> visited(n+1, -1);
    For(i, 0, m) {
        inpt(x); inpt(y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    queue<int> q;
    int curr = 1;
    for(int x=1; x<n+1; x++) {
        if(visited[x] == -1) {
            curr = 0;
            q.push(x);
            while(!q.empty()) {
                curr ^= 1;
                queue<int> temp;
                while(!q.empty()) {
                    // pl("36");
                    if(visited[q.front()] == -1) {
                        temp.push(q.front());
                        visited[q.front()] = curr^1;
                        q.pop();
                    } else {
                        if(visited[q.front()] == curr) {
                            pl("IMPOSSIBLE");
                            return;
                        }
                        q.pop();
                    }
                }
                while(!temp.empty()) {
                    // pl("49");
                    for(auto y: arr[temp.front()]) {
                        q.push(y);
                    }
                    temp.pop();
                }
            }
        }
    }
    for(int x=1; x<n+1; x++) {
        cout << visited[x]+1 << " ";
    }
    pl("");
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