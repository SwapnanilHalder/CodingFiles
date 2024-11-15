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
    inpt(n); cinbuffer;
    vi initial = input1l();
    vi occupied(n, 0);
    int i=0, temp =0, temp_step = 0, count = 0, succ = 0;
    while(i < n) {
        if(initial[i] == 1) {
            temp_step = 1;
            succ = 0;
            while( (i + temp_step <= n-1) || (i - temp_step) >= 0 ) {
                deb(temp_step);
                if ( (i - temp_step) >= 0 ) {
                    if(initial[(i - temp_step)] == 0 && occupied[(i - temp_step)] == 0) {
                        occupied[(i - temp_step)] = 1;
                        count += temp_step;
                        succ = 1;
                        break;
                    }
                }
                if( (succ == 0) && ( (i + temp_step) <= n-1 ) ) {
                    if(initial[(i + temp_step)] == 0 && occupied[(i + temp_step)] == 0) {
                        occupied[(i + temp_step)] = 1;
                        count += temp_step;
                        succ = 1;
                        break;
                    }
                }
                temp_step++;
            }
        }

        i++;
    }
    pv(occupied);
    deb(count);
    pl(count);return;
}

int32_t main() {
    SPEED;
    // inpt(t); 
    // while(t--) {
    //     sol();
    // }
    sol();
}