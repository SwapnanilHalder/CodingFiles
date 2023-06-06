// #pragma GCC optimize("Ofast","inline","-ffast-math")
// #pragma GCC target("avx,mmx,sse2,sse3,sse4")

#include <iostream>
#include <vector>
#include <string>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

using namespace std;

class Solution {
public:
    void answer() {
        vector<vector<int>> dp(5, vector<int> (13, 6));
        for(int i=0; i<5; i++) {
            for(int j=0; j<13; j++) {
                dp[i][j] = (i+1)*(j+1);
            }
        }
        auto it = (*(dp.begin())).begin();
        for(auto v=it; v != (*(dp.end())).begin()  ; v++)
        cout << *v << endl;
    }
};


int main() {
    SPEED1;
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    mySolution.answer();
}