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
 
int axisX[] = {1, -1, 0, 0};
int axisY[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};
 
string dfs(vector<string> &arr, int x, int y, string path, char d) {
    deb(x); deb(y); deb(path);
    if(x<0 || x >= arr.size() || y<0 || y >= arr[0].size()) return "";
    if(arr[x][y] == '#') return "";
    if(arr[x][y] == 'B') return path+d;
    string ans(10000, 'A');
    if(arr[x][y] == '.') {
        arr[x][y] = '#';
        For(i, 0, 4) {
            string ans1 = dfs(arr, x+axisX[i], y+axisY[i], path+d, dir[i]);
            ans = (ans1.size()>0 && ans.size() > ans1.size()) ? ans1 : ans;
        }
        arr[x][y] = '.';
        return ans;
    }
    return "";
}
 
bool isValid(vector<string> &arr, int x, int y, vector<vector<int>>& visited) {
    if(x >= 0 && x < arr.size() && y >= 0 && y < arr[0].size() && arr[x][y] == '.' && visited[x][y] == -1) {
        return 1;
    }
    return 0;
}
 
string findPath(vector<string> &arr, int x, int y, pair<int, int> &dest) {
    queue<pair<int,int>> q;
    vector<vector<int>> visited(arr.size(), vector<int>(arr[0].size(), -1 ));
    q.push( {x, y});
    visited[x][y] = 5;
    bool found = 0;
    while(!q.empty()) {
        if(found) break;
        int n = q.size();
        vector<pair<int,int>> temp;
        For(i, 0, n) {
            temp.push_back(q.front());
            q.pop();
        }
        for(pair<int,int> x: temp) {
            if (found) break;
            pair<int, int> coord = x;
            For(i, 0, 4) {
                if(coord.first+axisX[i] == dest.first && coord.second+axisY[i] == dest.second) {
                    visited[coord.first+axisX[i]][coord.second+axisY[i]] = i;
                    found = 1;
                    break;
                }
                if( isValid(arr, coord.first+axisX[i], coord.second+axisY[i], visited)) {
                    visited[coord.first+axisX[i]][coord.second+axisY[i]] = i;
                    q.push({coord.first+axisX[i], coord.second+axisY[i]});
                }
            }
        }
    }
    // pv2d(visited);
    if(found) {
        x = dest.first, y=dest.second;
        deque<char> path;
        path.push_front(dir[visited[x][y]]);
        while( !(visited[x][y] == 5) ) {
            // cout << x << " " << y << "\n";
            switch(dir[visited[x][y]]) {
                case 'D':
                    x -= 1;
                    break;
                case 'U':
                    x += 1;
                    break;
                case 'L':
                    y += 1;
                    break;
                case 'R' :
                    y -= 1;
                    break;
            }
            path.push_front(dir[visited[x][y]]);
        }
        string ans;
        while(!path.empty()) {
            ans.push_back(path.front());
            path.pop_front();
        }
        return ans;
    }
    return "";
}
 
pair<int, int> findDest ( vector<string>& arr) {
    For(i, 0, arr.size()) {
        For(j, 0, arr[0].size()) {
            if(arr[i][j] == 'B') {
                return pair<int, int>{i, j};
            }
        }
    }
}
 
void solve() {
    inpt(m); inpt(n);
    vector<string> arr;
    For(i, 0, m) {
        string s;
        cin >> s;
        arr.pb(s);
    }
    pair<int, int> dest = findDest(arr);
    
 
    For(i, 0, m) {
        For(j, 0, n) {
            if(arr[i][j] == 'A') {
                // arr[i][j] = '#';
                string ans = findPath(arr, i, j, dest);
                if(ans.size()) {
                    pl("YES");
                    string ans1 = ans.substr(1, ans.size()-1);
                    pl(ans1.size());
                    pl(ans1);
                } else {
                    pl("NO");
                }
                return;
            }
        }
    }
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