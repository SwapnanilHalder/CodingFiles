#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define int unsigned long int
class Solution {
public:
    int answer(int n) {
        int x = 0;
        int c = 31;
        while(n > 0) {
            if ( n & 1 == 1) {
                x += ((long long)1 << c);
            }
            n >>=1;
            c--;
        }
        // cout << ((long long)1 << 31) << endl;
        return (x);
    }
    
};


int32_t main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.answer(3) << endl;
}