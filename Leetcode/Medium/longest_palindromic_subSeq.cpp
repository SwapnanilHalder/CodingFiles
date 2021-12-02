#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pv(v) for(const auto &i: v){cout<<i<<" ";}cout << "\n"
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""

class Solution {
public:
    string longestPalindromeSubSeq(string s) {
        int n = s.size();
        string sr = s;
        reverse(sr.begin(), sr.end());
        cout << s << endl;
        cout << sr << endl;
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        For(i, 1, n+1) {
            For(j, 1, n+1) {
                if(s[i-1] == sr[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        pv2d(dp);
        string ans = "";
        int i=n, j = n;
        while(i!= 0 and j!= 0) {
            if(s[i-1] == sr[j-1]) {
                ans.push_back(s[i-1]);
                i--; j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    i--;
                }
                else {
                    j--;
                }
            }
        }
        
        return ans;
    }
    
};


int main() {
    SPEED;
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "aacabdkacaa";
    cout << "Answer : " << endl;
    cout << mySolution.longestPalindromeSubSeq(str) << endl;
}
