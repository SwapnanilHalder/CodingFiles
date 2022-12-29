#include <iostream>
#include <sstream>
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
#define pv(v) for(const auto &i: v){cout<<i<<" ";}cout << "\n"
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;for(auto itr = v.begin(); itr != v.end(); itr++){cout << "\t" << itr->first << " ->  " << itr->second;cout << "\n";}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";cout << "\n"
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

int total=0;

bool check(vector<string> &arr, int x, int y) {
    // cout << "Entered : " << x << " , " << y << endl;
    int x1=x, y1=y;
    int i, j;
    for(i=x1, j=y1; i>=0; i--) {
        // pl("1");
        if(arr[i][j] == 'q') return 0;
    }
    for(i=x1, j=y1; i>=0 && j>=0; i--, j--) {
        // pl("2");
        if(arr[i][j] == 'q') return 0;        
    }
    for(i=x1 , j=y1; i>=0 && j<8; i--, j++) {
        // pl("3"); pl(i); pl(j);
        if(arr[i][j] == 'q') return 0;        
    }
    // cout << "Returning 1\n";
    return 1;
}

void nqueen(vector<string> &arr, int level ) {
    // cout << "Entered level : " << level << endl;
    if(level == 8) {
        total++;
        // pv2d(arr);
        return;
    }
    For(i, 0, 8) {
        // cout << "Entered col : " << i << endl;
        if(arr[level][i] == '*')
            continue;
        // arr[level][i] = 'q';
        if(check(arr, level, i)) {
            arr[level][i] = 'q';
            nqueen(arr, level+1);
            arr[level][i] = '.';
        }
    }
    return;
}

void solve() {
    total = 0;
    vector<string> arr(8);
    For(i, 0, 8) {
        cin >> arr[i];
    } 
    nqueen(arr, 0);
    cout << total << endl;
}

signed main() {
    SPEED1;
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    // int __t; cin >> __t; while(__t--)
    solve();
}