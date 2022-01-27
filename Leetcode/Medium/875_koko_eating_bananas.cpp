#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <numeric>
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define int long long int
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << " ; "
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END

using namespace std;

class Solution {
public:

    int recur(vi &arr, int high, int low, int& h, int &done) {
        int mid, count,n = arr.size();
        // if(high == done) {
        //     return done;
        // }
        if(low <= high) {
            mid = (high+low)/2;
            count = 0;
            For(i, 0, n) {
                // deb(mid); deb(low); deb(high); deb(done);END;
                // pl(ceil(arr[i]*1.0/mid));
                count += ceil(arr[i]*1.0/mid);
            }
            if(count > h) {
                
                low = mid+1;
            }
            else {
                // pl("Done changed");
                done = mid;
                high = mid-1;
            }
        }
        else {
            return done;
        }
        return recur(arr, high, low, h, done);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int done = 0;
        int ans = recur(piles, *max_element(all(piles)) , 1, h, done);
        return ans;
    }
};


int32_t main() {
    Solution mySolution;
    vector<int> arr{30,11,23,4,20};
    int start = 6;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.minEatingSpeed(arr, start) << endl;
}