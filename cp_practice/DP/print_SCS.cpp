

#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define For(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) cout << i << " "; cout<<"\n"
#define pv2d(k) for(const auto &j: k) pv(j); cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


/*
 * Complete the 'longestCommonSubsequence' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int shortestCommonSupersequence(string a, string b)
{
    vector<vector<int>> dp(a.size()+1, vector<int> (b.size()+1, 0));
    for(int i=1; i< a.size()+1; i++) {
        for(int j=1; j<= b.size(); j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string ans;
    int x=a.size(), y=b.size();
    while (x >= 1 && y >= 1) {
        if(a[x-1] == b[y-1]) {
            x--; y--;
            ans.push_back(a[x]);
        }
        else {
            if(dp[x][y-1] > dp[x-1][y]) {
                y--;
                ans.push_back(b[y]);
            }
            else {
                x--;
                ans.push_back(a[x]);
            }
        }
    }
    while(y > 0) {
        y--;
        ans.push_back(b[y]);
    }
    while(x > 0) {
        x--;
        ans.push_back(a[x]);
    }
    reverse(ans.begin(), ans.end());
    cout << "The String : " << ans << endl;
    return ans.size();
}

int main() {
    int ans = shortestCommonSupersequence("acbcf", "abcdaf");
    pl(ans);
}