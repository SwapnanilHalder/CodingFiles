#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include <numeric>

class Solution {
public:
    int MinimumSubsetSumDifference(vector<int> &A) {
        int n = A.size();
        int sum = accumulate(A.begin(), A.end(), 0) ;
        int b = sum/ 2;
        vector<vector<int>> dp(n+1 , vector<int> (b+1, 0));
        int maxm = 0;
        for(int i {0}; i < n+1; i++) {
            dp[i][0] = 1;
        }
        for(int i{1}; i< n+1; i++) {
            for(int j{1}; j<b+1; j++) {
                if(A[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - A[i-1]] ;
                }
                else {
                    dp[i][j] = dp[i-1][j] ;
                }
            }
        }
        for(int j = b; j>= 0; j--) {
            if(dp[n][j] == 1) {
                return (sum - 2*j);
            }
        }
        return -1;
    }
    
};


int main() {
    Solution mySolution;
    vector<int> arr{5, 12356};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.MinimumSubsetSumDifference(arr) << endl;
}