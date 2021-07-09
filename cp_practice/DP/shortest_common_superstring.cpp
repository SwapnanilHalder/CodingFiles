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



int LCS(string &a, string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    for(int i = 1; i < m+1; i++) {
        for(int j = 1; j < n + 1 ;j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1 ;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    cout << dp[m][n] << endl;
    return dp[m][n];
}


int solve(vector<string> &A) {
    int count = A[0].size(), temp_count = 0;
    for(int i= 1; i < A.size(); i++) {
        temp_count = 0;
        for(int j = i-1; j >= 0; j--) {
            temp_count = max(temp_count , LCS (A[j], A[i]) );
        }
        count += (A[i].size() - temp_count);
    }
    cout << count << endl;
    return count;
}

int main() {
    vector<string> A = { "abcd", "fgh", "cdef", "de"      };
    int ans = solve(A);
    cout << " The answer is  : " << ans << endl;
}