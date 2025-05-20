#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define pi pair<int,int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
#define MOD 1000000007
using namespace std;

vector<vector<int>> dp;
int m, n;

void fill_dp(int column, int col_pos, int curr_mask, int next_mask) {
    // deb(column); deb(col_pos); deb(bitset<10>(curr_mask)); deb(bitset<10>(next_mask));
    if(col_pos == n) {
        // cout <<"completed full current col\n";
        dp[column+1][next_mask] = (dp[column+1][next_mask] + dp[column][curr_mask])%MOD;
        return;
    }
    int x = curr_mask & (1 << col_pos);
    int y = curr_mask & (1 << (col_pos+1)); 

    // fill up and pass
    if(x == 0) {
        if(col_pos+1 < n && y == 0) {
            //fill up vertically, but jump two steps
            fill_dp(column, col_pos+2, curr_mask, next_mask);
        } 
        //fill up horizontally, jump one step, we can do this everytime
        fill_dp(column, col_pos+1, curr_mask, next_mask | (1<<col_pos));
        
    } else {
        // already filled up from previous col, jump to next step
        fill_dp(column, col_pos+1, curr_mask, next_mask); 
    }

}


void solve() {
    cin >> n >> m; 
    dp.resize(1001, vector<int> (1<<n, 0));
    dp[0][0] = 1;

    For(column, 0, m) {
        For(mask, 0, 1<<n) {
            if(dp[column][mask] != 0) {
                fill_dp(column, 0, mask, 0);
            }
        }
    }
    // pv2d(dp);
    pl(dp[m][0]);
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