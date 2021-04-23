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
int find_min(int x, int y, int pos_x, int pos_y, int k, int cost, vi2d &hori, vi2d &vert) ;

void sol() {
    inpt(n); inpt(m); inpt(k);
    vi2d hori(n, vi(m+1, -1));
    vi2d vert ( n+1, vi(m, -1));
    For(i, 0, n) {
        For(j, 1, m) {
            cin >> hori[i][j];
        }
    }
    For(i, 1, n) {
        For(j, 0, m) {
            cin >> vert[i][j];
        }
    }
    pv2d(hori); pv2d(vert);
    vi2d ans(n, vi(m, INF));
    For(i, 0, n) {
        For(j, 0, m) {
            ans[i][j] = min(ans[i][j], find_min(i, j, i, j, k, 0, hori, vert));
        }
    }
    pv2d(ans);
}

int find_min(int x, int y, int pos_x, int pos_y, int k, int cost, vi2d &hori, vi2d &vert) {
    if(k == 0 && (pos_x != x || pos_y != y)) {
        return -1;
    }
    if (k==0 && pos_x == x && pos_y == y) {
        return cost;
    }
    if(hori[pos_x][pos_y] != -1) find_min(x, y, pos_x, pos_y-1, k-1, cost+hori[pos_x][pos_y], hori, vert);
    if(hori[pos_x][pos_y+1] != -1) find_min(x, y, pos_x, pos_y+1, k-1, cost+hori[pos_x][pos_y+1], hori, vert);
    if(vert[pos_x][pos_y] != -1) find_min(x, y, pos_x-1, pos_y, k-1, cost+vert[pos_x][pos_y], hori, vert);
    if(vert[pos_x+1][pos_y] != -1) find_min(x, y, pos_x+1, pos_y, k-1, cost+vert[pos_x+1][pos_y], hori, vert);
}

int32_t main() {
    SPEED;
    // inpt(t); 
    // while(t--) {
    //     sol();
    // }
    sol();
}