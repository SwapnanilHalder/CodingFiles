#include <bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x
#define deb(x) cout << #x << " => " << x << "  ;  " 


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mapped;
        int start=0, end=0, len=0, max_len = 0;
        For(i, 0, s.size()) {
            if(mapped.find(s[i]) != mapped.end()) {
                start = max(mapped[s[i]] + 1, start);
            }
            deb(i); deb(end); deb(start);
            len = end-start+1;
            mapped[s[i]] = i;
            max_len = max(len, max_len);
            end++;
        }
        return max_len;
    }  
};


int main() {
    SPEED;
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    string str = "abba";
    cout << "Answer : " << endl;
    cout << mySolution.lengthOfLongestSubstring(str) << endl;
}