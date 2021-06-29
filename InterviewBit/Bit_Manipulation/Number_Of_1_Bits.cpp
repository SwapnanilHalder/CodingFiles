#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
int numSetBits(unsigned int A) {
    int n=0;
    while(A > 0) {
        cout << "Entered\n";
        n += (A&1);
        A = A >> 1;
    }
    return n;
}
    
};


int main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.numSetBits(11) << endl;
}