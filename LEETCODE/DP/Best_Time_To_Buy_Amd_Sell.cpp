#include <iostream>
#include <vector>
#include <cstdio>
#define INF 1000000007

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_diff = 0;
        int min_elt = prices[0];
        for(int i{1}; i< prices.size(); i++) {
            if ( (prices[i] - min_elt) > max_diff ) {
                max_diff = prices[i] - min_elt;
            }
            if (prices[i] < min_elt) {
                min_elt = prices[i];
            }
        }
        return max_diff;
    } 
};


int main() {
    Solution mySolution;
    vector<int> arr{7,6,4,3,1};
    int start = 5;
    cout << "Answer : " << mySolution.maxProfit(arr) << endl;
}