#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for(int i=1; i < (n/2)+1; i++) {
            s[i*2-1] = s[i*2-2] + (s[i*2-1] - '0') ;
        }
        return s;
    }
};


int main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    string s = "a1b2c3d4e";
    int start = 5;
    cout << "Answer : " << mySolution.replaceDigits(s) << endl;
}