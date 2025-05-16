#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n= nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int gap=2; gap<n; gap++) {
            for(int start=0; start < n-gap; start++) {
                int end = start+gap;
                dp[start][end] = 0;

                for(int k=start+1; k < end; k++) {
                    int cost = dp[start][k] + dp[k][end] + nums[start]*nums[k]*nums[end];
                    dp[start][end] = max(dp[start][end], cost);
                }
            }
        }
        return dp[0][n-1];
    }
};


int main() {
    Solution mySolution;
    vector<int> arr{3,1,5,8};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.maxCoins(arr) << endl;
}