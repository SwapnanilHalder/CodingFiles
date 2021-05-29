#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max = -(1<<30);
        for(int i = 0; i< n/2; i++) {
            if(nums[i] + nums[n-1-i] > max) {
                max = nums[i] + nums[n-1-i];
            }
        }
        return max;
    }
};


int main() {
    Solution mySolution;
    vector<int> arr{3,5,4,2,4,6};
    int start = 5;
    cout << "Answer : " << mySolution.minPairSum(arr) << endl;
}