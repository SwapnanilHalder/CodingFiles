#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int isPalindrome(string A) {
        string str;
        int n = A.size();
        for(int i{0}; i<n; i++) {
            if(A[i] >= 'A' && A[i] <= 'Z') {
                str.push_back(A[i] + 'a'-'A');
            }
            if(A[i] >= 'a' && A[i] <= 'z') {
                str.push_back(A[i]);
            }
            if(A[i] >= '0' && A[i] <= '9') {
                str.push_back(A[i]);
            }
        }
        // cout << str;
        n = str.size();
        for(int i{0}; i<n/2; i++) {
            if(str[i] != str[n-1-i]) {
                return 0;
            }
        }
        return 1;
    }
};


int main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "A man, a plan, a canal: Panama";
    string str1 = "race a car";
    string str2 = "1a2";
    cout << "Answer : " << mySolution.isPalindrome(str2) << endl;
}