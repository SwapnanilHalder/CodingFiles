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
#define END cout<<"\n"
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
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

void sol() {
    inpt(n);
    string str;
    cin >> str;
    // if(str == "0") {
    //     pl("BOB"); return;
    // }
    int A{0}, B{0}, As = 0;
    int fail = 0;
    int zeros = 0;
    For(i, 0, n) {
        if(str[i] == '0') {
            fail = 1;
            zeros++;
        }   
    }
    if(zeros == 1) {
        pl("BOB"); return;
    }
    if(fail == 0) {
        pl("DRAW"); return;
    }
    // if( (str.size() % 2) != 0) {
    //     if(str[str.size()/2] == 0) {
    //         // A++;
    //         // str[str.size()/2] = 1;
    //         // As = 1;
    //         pl("ALICE"); return;
    //     }
    //     else {
    //         pl("BOB"); return;
    //     }
    // }
    if(zeros % 2 != 0) {
        pl("ALICE"); return;
    }
    pl("BOB"); return;

}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}