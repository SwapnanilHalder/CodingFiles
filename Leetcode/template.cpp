#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string answer(string str) {
        return str;
    }
};


int main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << mySolution.answer(str) << endl;
}