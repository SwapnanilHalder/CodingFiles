#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <numeric>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

#include <numeric>
class Solution {
public:
    int TargetSum(vector<int> &nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        // if(n == 1)
        int s = (sum - target) / 2;
        if(s == 0) {
            return 1;
        }
        vector<vector<int>> dp (n+1, vector<int> (s+1, 0));
        for(int i{0}; i< n+1; i++) {
            dp[i][0] = 1;
        }
        vector<int> ans (s+1, 0);
        for(int i{1}; i<n+1; i++) {
            for(int j{1}; j<s+1; j++) {
                // deb(i); deb(j); deb(dp[i-1][j-nums[i-1]]);
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j) {
                    if(dp[i-1][ j-nums[i-1]] >= 1) {
                        ans[j] += dp[i-1][ j-nums[i-1]];
                        dp[i][j] += dp[i-1][ j-nums[i-1]];
                    }
                }
            }
            // pv(ans);
        }
        // END; pv2d(dp);
        return ans[s];
    }
    
};


int main() {
    Solution mySolution;
    vector<int> arr{1,0};
    int start = 1;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.TargetSum(arr, start) << endl;
}