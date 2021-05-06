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

bool check_pos(int i, int j, int prev_x, int prev_y, vi2d &dp) {
    // deb(i); deb(j); deb(prev_x); deb(prev_y);
    if (dp[i][j] != 0) {
        return 0;
    }
    else if (i == prev_x && ( (j == prev_y-1) || (j == prev_y+1) ) ) {
        return 0;
    }
    else if (j == prev_y && ( (i == prev_x-1) || (i == prev_x+1) ) ) {
        return 0;
    }
    else {
        return 1;
    }
}

void sol() {
    inpt(n);
    vi2d dp (n+2, vi(n+2, 0));
    For(i, 0, n+2) {
        dp[0][i] = -1;
        dp[i][0] = -1;
        dp[n+1][i] = -1;
        dp[i][n+1] = -1;
    }
    // pv2d(dp);
    if (n == 1) {
        pl("1"); return;
    }
    if (n == 2) {
        pl("-1"); return;
    }
    int target = pow(n, 2);
    dp[1][1] = 1;
    int prev_x = 1, prev_y = 1, success = 0;
    For(x, 1, target) {
        success = 0;
        For(i, 1, n+1) {
            if (success == 1)
                break; 
            For(j, 1, n+1) {
                if (success == 1)
                    break; 
                if (check_pos(i, j, prev_x, prev_y, dp) ) {
                    dp[i][j] = x+1;
                    prev_x = i;
                    prev_y = j;
                    success = 1;
                    break;
                }
            }
        }
    }
    pv2d(dp);
}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}