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

pair<int, int> subArraySum(vector<int> &arr, int x, int y, int sum)
{
    // int n = y-x+1;
    
    int currentSum = arr[x], start = x, i;
    for (i = x+1; i <= y+1; i++) {
        while (currentSum > sum && start < i - 1) {
            currentSum = currentSum - arr[start];
            start++;
        }
        if (currentSum == sum) {
            // cout << "\nSum found between indexes " << start << " and " << i - 1 << " for sum : " << sum << endl;
            return {start, i-1};
        }
        if (i <= y)
            currentSum = currentSum + arr[i];
    }
    // if (currentSum == sum) {
    //     cout << "\nSum found between indexes " << start<< " and " << i - 1 << " for sum : " << sum << endl;
    //     return {start, i-1};
    // }
    // cout << "No subarray found for : " << sum << " From " << start  << " to " << i-1 << endl;
    return {-1, -1};
}

void sol() {
    inpt(n); inpt(p); inpt(q); inpt(r); cinbuffer;
    vi arr = input1l();
    pair<int, int> tt, pp, qq, rr;
    auto st = arr.begin(), en = arr.end();
    int i=0;
    while(i < n-3) {
        tt = subArraySum(arr, i, n-1,  p+q+r);
        if(tt.first == -1) {
            pl("No\n"); return;
        }
        i = tt.first+1;
        pp = subArraySum(arr, tt.first, tt.second, p);
        if(pp.first == -1) {
            continue;
        }
        // pp.first += tt.first;
        // pp.second += tt.first;
        qq = subArraySum(arr, pp.second+1, tt.second, q);
        if(qq.first == -1 || qq.first != (pp.second+1)) {
            continue;
        }
        // qq.first += pp.first;
        // qq.second += pp.first;
        rr = subArraySum(arr, qq.second+1, tt.second, r);
        if(rr.first == -1 || rr.first != (qq.second+1)) {
            // return;
            continue;
        }   
        cout << "Yes\n"; return;     
    }
    pl("No"); return;
}

int32_t main() {
    SPEED1;
    // inpt(t); 
    // while(t--) {
    //     sol();
    // }
    sol();
}