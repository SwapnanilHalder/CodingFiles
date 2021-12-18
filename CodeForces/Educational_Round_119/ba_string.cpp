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
#define deb(x) cout << '\t'<<#x << " = " << x << " ; "
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

/*

1
6 3 15
**a***

1
5 3 62
*a*a*

*/

void sol() {
    inpt(n); inpt(k); inpt(x);
    string s; cin >> s;
    int left = x-1;
    int value = 1;
    for(int i = n-1; i>=0; i--) {
        if(left < 0) break;
        if(s[i] == '*') {
            if(k*value >= left) {
                s[i] = left/value + '0';
                break;
            }
            else {
                s[i] = k + '0';
                left-= k*value;
            }
        }
        if(s[i] == 'a') {
            value *= (x-left);
        }
        deb(i); deb(left); deb(value);END;
    }
    deb(left); deb(value);END;
    deb(s);
    For(i, 0, n) {
        if(s[i] == '*') {
            continue;
        }
        else if(s[i] == 'a') {
            cout << 'a';
        }
        else {
            For(j, 0, s[i]-'0') {
                cout << 'b';
            }
        }
    }
    END;
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}