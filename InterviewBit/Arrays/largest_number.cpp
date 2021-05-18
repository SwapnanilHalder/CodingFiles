#include <iostream>
#include <vector>

#include <utility>
#include <algorithm>
#include <cmath>
#include <string>

#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END


using namespace std;

class Solution {
public:
    int dupli(int x, int num) {
        int now = int(log10(x) + 1);
        int temp = x;
        while (temp >= 10)
            temp /= 10;
        for(int i{0}; i < (num-now); i++) {
            x *= 10;
            x += temp;
        }
        return x;
    }
    static bool pair_sort(pair<int, int> x, pair<int, int> y ) {
        if ( to_string(y.second).append(to_string(x.second)) >  to_string(x.second).append(to_string(y.second))   ) {
            return 1;
        }
        // if ( (x.first) < (y.first) ) {
        //     return 1;
        // }
        // if ( (x.first) == (y.first) ) {
        //     if ( to_string(y.second).append(to_string(x.second)) >  to_string(x.second).append(to_string(y.second))   ) {
        //         return 1;
        //     }
        //     return 0;
        // }
        else return 0;
    }
    string largestNumber(const vector<int> &A) {

        vector<pair<int, int>> another;
        int n = A.size();
        int big = *max_element(A.begin(), A.end());
        int num = int(log10(big) + 1);
        int all_z = 1;
        for(int i{0}; i<n; i++) {
            if(A[i] != 0) {
                all_z = 0;
            }
            another.push_back({dupli(A[i], num), A[i]});
        }
        if (all_z == 1) {
            return "0";
        }
        // loop(it, another) {
        //     cout << it->first << " , " << it->second << endl;
        // }
        // return "";
        sort(another.begin(), another.end(), pair_sort);
        // loop(it, another) {
        //     cout << it->first << " , " << it->second << "\n";
        // }
        string str = "";
        for(int i{n-1}; i>=0; i--) {
            str.append(to_string(another[i].second));
        }
        return str;
    }
};


int main() {
    Solution mySolution;
    vector<int> arr{92, 929};
    int start = 5;
    cout << "Answer : " << mySolution.largestNumber(arr) << endl;
}