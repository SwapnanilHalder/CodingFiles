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


 // } Driver Code Ends

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	// Your code here
        int count = 0;
        int idx = 0;
        int temp1 = arr[0];
        int temp2 = 0;
        int prev_idx = 0;
        int rev_idx = 0;

        while(count < n/2) {
            if(idx < (n+1)/2) {
                pl("1:"); deb(idx);
                temp2 = arr[ 2*idx + 1 ];
                arr[2 * idx + 1 ] = temp1;
                temp1 = temp2;
                idx = 2 * idx + 1;
            }
            else {
                pl("2:");deb(idx);
                rev_idx = (n-idx - 1);
                temp2 = arr[rev_idx * 2];
                arr[rev_idx * 2] = temp1;
                temp1 = temp2;
                idx = rev_idx * 2;
            }
            count++;
        }
        idx = 2;
        temp1 = arr[2];
        temp2 = 0;
        prev_idx = 0;
        rev_idx = 0;

        while(count < n) {
            if(idx < (n+1)/2) {
                pl("1:"); deb(idx);
                temp2 = arr[ 2*idx + 1 ];
                arr[2 * idx + 1 ] = temp1;
                temp1 = temp2;
                idx = 2 * idx + 1;
            }
            else {
                pl("2:");deb(idx);
                rev_idx = (n-idx - 1);
                temp2 = arr[rev_idx * 2];
                arr[rev_idx * 2] = temp1;
                temp1 = temp2;
                idx = rev_idx * 2;
            }
            count++;
        }
    	 
    }
};

/*

1
6
1 2 3 4 5 6

1
8
1969 2677 3142 4631 4764 5748 6476 6487

1
11
1 2 3 4 5 6 7 8 9 10 11

*/



// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends