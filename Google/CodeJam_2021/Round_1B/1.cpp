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

typedef long long long_long;
typedef long double long_double;

#ifdef DEBUG
#define int128 long long
#else
#define int128 __int128
#endif // DEBUG

const int128 bck11 = 15709090909091;
const int128 mod = 12*60*60* (int128)1e9;

bool f(int T_N, int128 a, int128 b, int128 c) {
    int128 t = (((b-a) * bck11) % mod + mod) % mod;
    if ((708 * t - c + b) % mod == 0) {
        long_long n = t % (long_long)1e9;
        t /= 1e9;
        long_long s = t % 60;
        t /= 60;
        long_long m = t % 60;
        long_long h = t / 60;
        cout << "Case #" << T_N << ": " << h << " " << m << " " << s << " " << n << "\n";
        return true;
    }
    else return false;
}

int32_t main() {

    int T;
    cin >> T;
    for (int T_N = 1; T_N <= T; T_N++) {
        long_long ta, tb, tc;
        cin >> ta >> tb >> tc;
        int128 a = ta, b = tb, c = tc;
        if (f(T_N, a, b, c) || f(T_N, a, c, b) || f(T_N, b, a, c) || f(T_N, b, c, a) || f(T_N, c, a, b) || f(T_N, c, b, a)) {

        }
        else {
            cerr << "Problem" << "\n";
        }
        //cout << "Case #" << T_N << ": " << res << "\n";
    }

    return 0;
}