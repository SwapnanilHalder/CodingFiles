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

void sol() {
    inpt(n); inpt(k);
    string str;
    cin >> str; cinbuffer;
    vi arr = input1l();
    // pv(arr);
    For(i, 0, k) {
        arr[i] -= 1;
    }
    int len = 0;
    For(i, 0, n-1) {
        if(str[i] != str[i+1]) {
            len += 1;
        }
        else {
            len += 2;
        }
    }
    // deb(len);
    if(n == 1) {
        For(i, 0, k) {
            pl(0);
        }
        return;
    }
    For(i, 0, k) {
        if( str[arr[i] ] == '1') {
            str[arr[i]] = '0';
        }
        else {
            str[arr[i] ] = '1';
        }
        if(arr[i] == 0) {
            if(str[arr[i] + 1] != str[arr[i]]) {
                len -= 1;
            }
            else {
                len += 1;
            }
            pl(len);
            continue;
        }
        if(arr[i] == n-1) {
            if(str[arr[i] - 1] != str[arr[i]]) {
                len -= 1;
            }
            else {
                len += 1;
            }
            pl(len);
            continue;
        }
        if(str[arr[i] -1] != str[arr[i] ]) {
            len -= 1;
        }
        else {
            len += 1;
        }
        if(str[arr[i] + 1] != str[arr[i]]) {
            len -= 1;
        }
        else {
            len += 1;
        }
        pl(len);
    }
    return;
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}