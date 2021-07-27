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

class Solution {
public:
int peakElement(vector<int> &arr, int n)
{
   // Your code here
   int start = 0, end = n-1, mid =0;
   if(n == 1) {
       return 0;
   }
   while(start <= end) {
       mid = start + (end-start)/2;
       cout << "Start :" << arr[start] << " ; End : " << arr[end] << " ;; Mid : " << arr[mid] << endl; 
       if(mid == 0) {
           if(arr[mid] >= arr[mid+1]) {
               return mid;
           }
       }
       if(mid == n-1) {
           if(arr[mid] >= arr[mid-1]) {
               return mid;
           }
       }
       if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]) {
           return mid;
       }
       if(arr[mid] >= arr[mid-1] && arr[mid] <= arr[mid+1]) {
           start = mid+1;
       }
       if(arr[mid] <= arr[mid-1] && arr[mid] >= arr[mid+1]) {
           end = mid-1;
       }
       else {
           end = mid-1; // less than less than situation : 5 4 [2] 6 9
       }
   }
}
    
};


int main() {
    Solution mySolution;
    vector<int> arr{ 1,2,3  };
    int start = 5;
    string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.peakElement(arr, arr.size()) << endl;
}
