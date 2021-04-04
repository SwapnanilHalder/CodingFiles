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

void sol(int ind) {
    inpt(x); inpt(y);
    string str;
    cin >> str;
    int n = str.length();
    // if(x > y ) {
    //     For(i, 0, str.size()) {
    //         if(str[i] == 'C') {
    //             str[i] = 'J';
    //         }
    //         if(str[i] == 'J') {
    //             str[i] = 'C';
    //         }
    //     }
    // }
    if(x >= 0 && y >= 0) {

        int cj{0}, jc{0}, sum{0}; 
        For(i, 0, n-1) {
            if(str[i] == 'C' && str[i+1] == '?') {
                str[i+1] = 'C';
            }
            if(str[i] == 'J' && str[i+1] == '?') {
                str[i+1] = 'J';
            }
        }
        For(i, 0, n-1) {
            if(str[i] == 'C' && str[i+1] == 'J') {
                cj++;
            }
            if(str[i] == 'J' && str[i+1] == 'C') {
                jc++;
            }
        }
        // deb(cj); deb(jc);
        sum = (cj * x) + (jc * y);
        // deb(str);
        cout << "Case #"<<ind<<": "<<sum<<endl;
        cout << 

    } 
    else {

    }

/*
        1 : ....C????C.....
        2 : ....J?????J.....
        3 : .....C?????J....
        4 : .....J?????C....
        5 : .....C?????
        6 : .....J?????
        7 : ?????C.....
        8 : ?????J.....
*/


}

int32_t main() {
    // system("clear");
    inpt(t);
    For(i, 0, t) {
        sol(i+1);
    }
}