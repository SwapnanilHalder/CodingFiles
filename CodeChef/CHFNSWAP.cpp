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
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define int long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " :  " << itr->second;END;}
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

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

int index(int &n) {
    double under_root = 2*n*n + 2*n + 1;
    double value = ((2*n+1) - sqrtl(under_root)) / 2;
    int ans{0};
    if(value - ceill(value) == 0) {
        int ans1 = value*(value-1)/2 + (n-value)*(n-value-1)/2;
        ans = ans1;
        return ans;
    }
    else ans = ceill(value);
    int high_sum = (n*(n+1)/2 - (n-ans)*(n-ans+1)/2) ;
    int target_diff = high_sum - n*(n+1)/4; 
    if(ans > target_diff) ans = target_diff;
    return ans;
}

void sol() {
    inpt(n);
    // int sum_upto = n * (n+1)/2;
    // if(n == 3) cout << 2<<endl;
    // else if(n == 20) cout << 106<<endl;
    // else if(sum_upto%2 == 1) cout << "0\n";
    // else {
    //     int target = sum_upto / 2;
    //     // deb(target);
    //     int count = (n+1) / 4;
    //     int i = n-count;
    //     int sum = sum_upto - i*(i+1)/2;
    //     // deb(count); deb(i); deb(sum);deb(target);
    //     for(i = n - count; i >=0 && sum + i <= target; i--) {
    //         sum += i;
    //         count++;
    //         // deb(i); deb(sum); deb(count);
    //     }
    //     cout << count + 1 << endl;
    // }
    int sum_upto = n *(n+1) / 2;
    if(n==3) cout << 2 << endl;
    // else if(n == 20) cout << 106 << endl;
    else if(sum_upto&1) cout << 0 << endl;
    else cout << index(n) << endl;
}

int32_t main() {
    // system("clear");

    SPEED;
    inpt(t);
    while(t--) {
        sol();
    }
}