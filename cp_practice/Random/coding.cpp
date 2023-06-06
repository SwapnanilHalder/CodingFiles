// #pragma GCC optimize("Ofast","inline","-ffast-math")
// #pragma GCC target("avx,mmx,sse2,sse3,sse4")

#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        SPEED1;
        vector<char> ans;
        ans.push_back(chars[0]);
        int count = 1;
        for(int i=1; i<chars.size(); i++) {
            if(chars[i] != chars[i-1]) {
                if(count > 1) {
                    string temp = to_string(count);
                    for(auto &x: temp) {
                        ans.push_back(x);
                    }
                }
                ans.push_back(chars[i]);
                count = 1;
            }
            else {
                count++;
            }
        }
        if(count > 1) {
            string temp = to_string(count);
            for(auto &x: temp) {
                ans.push_back(x);
            }
        }
        chars = ans;
        return chars.size();
    }
};


int main() {
    SPEED1;
    Solution mySolution;
    vector<char> arr{"a","b","b","b","b","b","b","b","b","b","b","b","b"};
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.compress(arr)  ;
}