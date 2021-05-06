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
    if (n == 1) {
        pl("1"); return;
    }
    else if (n == 2) {
        pl("-1"); return;
    }
    vi2d arr = { {2,9,7}, {4,6,3}, {1,8,5}};
    // pv2d(arr);
    int x = 0, y = 0;
    For(t, 4, n+1) {
        int start = pow(t-1, 2), end = pow(t, 2);
        vi new_arr (end - start, 0);
        int now = start+1;
        int index = 0;
        while(now != end+1) {
            new_arr[index] = now;
            index += 2;
            index %= (end-start);
            now++;
        }
        // pv(new_arr);
        vi2d arr1(t, vi (t, 0));
        For(i, 0, t-1) {
            For(j, 0, t-1) {
                arr1[i][j] = arr[i][j];
            }
        }
        For(i, 0, t) {
            arr1[i][t-1] = new_arr[i];
        }
        For(i, t, 2*t-1) {
            arr1[t-1][(2*t-2) - i] = new_arr[i];
        }
        
        arr = arr1;
    }
    pv2d(arr);


    // For(t, 4, n+1) {
    //     // vi2d arr1 (i+1, vi (i+1, 0));
    //     // For(p, 0, i-1) {
    //     //     For(q, 0, i-1) {
    //     //         arr1[p][q] = arr[p][q];
    //     //     }
    //     // }
    //     For(i, 0, t-1) {
    //         arr[i].pb(0); arr[i].pb(-1);
    //     }
    //     arr.pb(vi(t, 0));
    //     arr[t-1].pb(-1);
    //     arr.pb(vi(t+1, -1));
    //     pv2d(arr);

    //     int x = 0; int y = t-1;
    //     int start = pow(t-1, 2), end = pow(t, 2);
    //     arr[x][y] = start+1;
    //     For(i, start+2, end+1) {
    //         if(y == t-1) {
    //             if (arr[x+1][y] == -1) {
    //                 y -= 2;
    //             }
    //             else if (arr[x+2][y] == -1) {
    //                 y -= 1;
    //                 x += 1;
    //             }
    //             else {
    //                 x += 2;
    //             }
    //         }
    //         else if(x == t-1) {
    //             if (arr[x+1][y] == -1) {
    //                 y -= 2;
    //             }
    //             else if (arr[x+2][y] == -1) {
    //                 y -= 1;
    //                 x += 1;
    //             }
    //         }
    //     }
    // }
 
}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}