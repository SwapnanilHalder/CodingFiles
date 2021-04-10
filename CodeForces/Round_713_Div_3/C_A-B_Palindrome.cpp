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
    inpt(a); inpt(b);
    int n =a+b;
    string str;
    cin >> str;
    int c_0=0, c_1=0, c_what = 0;
    For(i, 0, n) {
        if(str[i] == '0') 
            c_0 ++;
        if(str[i] == '1') 
            c_1 ++;
        if(str[i] == '?') 
            c_what ++;
    } 
    if( (n %2) != 0) {
        if (str[n/2] == '0') {
            a--;
        }
        if (str[n/2] == '1') {
            b--;
        }
    }
    For(i, 0, (n/2) ) {
        if (b < 0 || a < 0) {
            pl("-1"); return;
        }
        if ( str[i] == '0' ) {
            if(str[n-1-i] == '1') {
                pl("-1"); return;
            }
            if(str[n-1-i] == '0') {
                a -= 2; continue;
            }
            if(str[n-1-i] == '?') {
                str[n-1-i] = '0';
                a -= 2; continue;
            }
        } 

        if ( str[i] == '1' ) {
            if(str[n-1-i] == '0') {
                pl("-1"); return;
            }
            if(str[n-1-i] == '1') {
                b -= 2; continue;
            }
            if(str[n-1-i] == '?') {
                str[n-1-i] = '1';
                b -= 2; continue;
            }
        } 

        if ( str[i] == '?' ) {
            if(str[n-1-i] == '0') {
                str[i] = '0';
                a-=2; continue;
            }
            if(str[n-1-i] == '1') {
                str[i] = '1';
                b-=2; continue;
            }
        }
    }
    if (b < 0 || a < 0) {
        pl("-1"); return;
    }
    // pl(str);
    // deb(a); deb(b);
    For(i, 0, (n/2)) {
        if(str[i] == '?' ) {
            if (a > 1) {
                str[i] = '0';
                str[n-1-i] = '0';
                a -= 2;
                continue;
            }
            else if (b > 1) {
                str[i] = '1';
                str[n-1-i] = '1';
                b -= 2;
                continue;
            }
        }
    }
    if ( (n%2) != 0) {
        if(str[(n-1) / 2] == '?') {
            if (a > 0) {
                str[(n-1) / 2] = '0';
                a--;
            }
            else if (b > 0) {
                str[(n-1) / 2] = '1';
                b--;
            }
        }
    }
    
    // deb(a); deb(b);
    if (a!= 0 || b != 0) {
        pl("-1"); return;
    }
    pl(str);
}

int32_t main() {
    // system("clear");
    inpt(t);
    while(t--) {
        sol();
    }
}