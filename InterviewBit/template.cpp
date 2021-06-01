#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int answer() {
        return 123456789;
    }
    
};


int main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.answer() << endl;
}