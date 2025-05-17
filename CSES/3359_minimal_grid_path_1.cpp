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
    inpt(n);
    vector<string> a(n);
    For(i, 0, n) {
        cin >> a[i];
    }

    vector<vector<string>> dp(n, vector<string>(n, ""));
    dp[0][0] = a[0][0];
    class GridPath {
    public:
        string path;
        int x;
        int y;
    };
    vector<vector<int>> dir = {{0, 1}, {1, 0}};

    auto cmp = [&](GridPath& a, GridPath& b){return (a.path>b.path);};
    priority_queue<GridPath, vector<GridPath>, decltype(cmp)> pq(cmp); 

    pq.push({dp[0][0], 0, 0});
    int count = 0;
    while(!pq.empty() && dp[n-1][n-1] == "" && count < 5) {
        // pl("1");
        auto temp = pq.top();
        pq.pop();
        // deb(temp.x); deb(temp.y);
        For(i, 0, 2) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x < n && y < n) {
                string newPath = temp.path + a[x][y];
                if(dp[x][y] == "" || dp[x][y] > newPath) {
                    dp[x][y] = newPath;
                    pq.push({newPath, x, y});
                }
            }
        }
        // For(i, 0, n) {
        //     For(j, 0, n) {
        //         if(dp[i][j] != "") {
        //             cout << dp[i][j] << " ";
        //         }
        //     }
        // }
        // count++;
    }
    pl(dp[n-1][n-1]);
}

signed main() {
    // SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //int __t; cin >> __t; while(__t--)
    solve();
}