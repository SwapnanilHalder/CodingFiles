#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int count =0 ;
        for(int i = 0; i < n-2; i++) {
            if(s[i] != s[i+1]) {
                if(s[i+1] != s[i+2]) {
                    if(s[i] != s[i+2]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }  
};


int main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string s = "aababcabc";
    cout << "Answer : " << mySolution.countGoodSubstrings(s) << endl;
}