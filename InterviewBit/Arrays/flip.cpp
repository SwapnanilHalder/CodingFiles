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
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
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
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
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


using namespace std;

class Solution {
public:
    vector<int> flip(string A) {
        int n = A.size();
        int start{0},start1{0},end1{0}, start_idx{-1}, count_start{0}, count_end{0}, end{0}, len{0}, count{0}, min_count = (1<<30);
        for(int i{0}; i<n; i++) {
            
            if(A[i] == '0') {
                count--;
                end1 = count;
                if( (end1-start1) < min_count) {
                    min_count = -(start1-end1);
                    end = i;
                    start = start_idx;
                }
            }
            if(A[i] == '1') {
                count++;
                if(count > start1) {
                    start1 = count;
                    start_idx = i;
                } 
            } 
            // if( (end1-start1) < min_count) {
            //     min_count = -(start1-end1);
            //     end = i;
            //     start = start_idx;
            // }
            // deb(i);
            // deb(start1);
            // deb(end1);
            // deb(start_idx);
            // deb(start);
            // deb(end);
            // deb(min_count);
        }
        if(min_count == (1 << 30)) {
            return {};
        }
        return {start+2, end+1};
    }
  
};


int main() {
    Solution mySolution;
    // vector<int> arr{4,2,3,0,3,1,2};

    string arr = "0101111001000";
    int start = 5;
    cout << "Answer : " << endl;
    pv(mySolution.flip(arr));
}