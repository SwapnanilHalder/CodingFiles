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
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
using namespace std;

vi input1l(){
    vi input(0);
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while(getline(X, num, ' ')) {
        input.pb(stoll(num));
    }
    //pv(input);
    return input;
}

int maxSubArraySum(vi &a)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    For(i, 0, a.size()) {
        deb(i); deb(max_ending_here); deb(max_so_far);
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

vi store;

int maxSubArrayStoreSum(vi &a)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    For(i, 0, a.size()) {
        deb(max_ending_here); deb(max_so_far);
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            store.pb(max_ending_here);
        }
 
        if (max_ending_here < 0) {
            max_ending_here = 0;
            max_so_far = INT_MIN;
        }
            
    }
    pv(store);
    return max_so_far;
}

void sol() {
    inpt(n); inpt(k); cinbuffer;
    vi arr = input1l();
    if(k == 1) {
        int ans = maxSubArraySum(arr);
        pl(ans); return;
    }
    if(k == 2) {
        int ans = maxSubArrayStoreSum(arr);
    }
    // int ended = n;
    // int ind = n-1;
    // int pos_sum = -((1<<31) - 1);
    // int max_sum = -((1<<31) - 1);
    // store.clear();
    // store = vi(k+1, 0);
    // ford(multiplicity, k, 1) {
    //     ind = ended-1;
    //     store[k] = arr[ind];
    //     for(;ind >= )
    // }
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}


/*

2
5 1
1 2 -1 3 1
5 1
-1 2 11 -23 12

*/