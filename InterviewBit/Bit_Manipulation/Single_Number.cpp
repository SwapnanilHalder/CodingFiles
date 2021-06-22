#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define For(i, a, b) for(int i=a; i<b; i++)
class Solution {
public:
    int answer(const vector<int> &A) {
        int res = A[0];
        For(i, 1, A.size()) {
            res = res ^ A[i];
        }
        return res;
    }
    
};


int main() {
    Solution mySolution;
    vector<int> arr{2,1,3,1,2};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.answer(arr) << endl;
}