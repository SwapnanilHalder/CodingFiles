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
    vi arr = input1l();
    vi2d dp(n+2, vi(n+2, 0));
    For(i, 0, n+2) {
        dp[i][0] = -1;
        dp[n+1][i] = -1;
        dp[0][i] = -1;
        dp[i][n+1] = -1;
    }
    // pv2d(dp);
    For(i, 0, n) {
        dp[i+1][i+1] = arr[i];
    }
    int rest = 0, top = 1, bottom = n, ii=0, jj=0;
    For(i, 0, n) {
        if(i%2 == 0) {
            rest = arr[top-1] - 1;
            // deb(rest);
            ii = top;
            jj = top;
            while(rest > 0) {
                if(dp[ii][jj-1] == 0) {
                    jj--;
                }
                else if(dp[ii+1][jj] == 0) {
                    ii++;
                }
                else {
                    pl("-1"); return;
                }

                dp[ii][jj] = arr[top-1];
                rest--;
            }
            top++;
        }
        else {
            rest = arr[bottom-1] - 1;
            ii = bottom;
            jj = bottom;
            while(rest > 0) {
                if(dp[ii+1][jj] == 0) {
                    ii++;
                }
                else if(dp[ii][jj-1] == 0) {
                    jj--;
                }
                else {
                    pl("-1"); return;
                }
                dp[ii][jj] = arr[bottom-1];
                rest--;
            }
            bottom--;
        }
    }
    For(i, 1, n+1) {
        For(j, 1, i+1) {
            cout << dp[i][j] << " ";
        }
        END;
    }
}

int32_t main() {
    SPEED;
    // inpt(t); 
    // while(t--) {
    //     sol();
    // }
    sol();
}