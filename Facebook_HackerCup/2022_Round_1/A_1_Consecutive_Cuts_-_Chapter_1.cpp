#include <iostream>
#include <string>
#include <sstream>
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
#define int long long int
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

void sol() {
    inpt(n); inpt(k); cinbuffer;
    vi arr1 = input1l();
    vi arr2 = input1l();
    if(k == 0) {
        if(arr1 != arr2) {
            pl("NO"); return;
        }
        pl("YES"); return;
    }
    if(k == 1) {
        if(arr1 == arr2) {
            pl("NO"); return;
        }
    }
    if(n == 2) {
        if(!(k&1)) {
            if(arr1 != arr2) {
                pl("NO"); return;
            }
            else {
                pl("YES"); return;
            }
        }
        else {
            if(arr1 != arr2) {
                pl("YES"); return;
            }
            else {
                pl("NO"); return;
            }
        }
    }
    int start = find(all(arr2), arr1[0]) - arr2.begin();
    // int flag = 1;
    int i1=0, i=start;
    for(;i<n; i++, i1++) {
        // cout << arr1[i1] << " , " << arr2[i] << endl;
        if(arr2[i] != arr1[i1]) {
            pl("NO"); return;
        }
    }
    i = 0;
    for(;i1<n; i++, i1++) {
        // cout << arr1[i1] << " , " << arr2[i] << endl;
        if(arr2[i] != arr1[i1]) {
            pl("NO"); return;
        }
    }
    pl("YES"); return;
}

int32_t main() {
    // system("clear");
    #ifndef ONLINE_JUDGE 
        freopen("consecutive_cuts_chapter_1_input.txt", "r", stdin);
        freopen("consecutive_cuts_chapter_1_output.txt", "w", stdout);
    #endif
    inpt(t);
    For(i, 1, t+1) {
        cout<< "Case #" << i<<": ";
        sol();
    }
}

// 1 2 3 4
// 1 2 3
// 2 3 1
// 3 1 2
// 1 2 3 4
// 2 3 4 1
// 3 4 1 2
// 4 1 2 3

