#include <iostream>
#include <string>
#include <sstream>
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

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pb push_back
#define inpt(x) int x{}; cin >> x
#define For(i,a,b) for(int i=a;i<b;i++)
#define MOD 1000000007
#define int long long int
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl

#define pl(x) cout << x << endl

using namespace std;

void sol() {
    inpt(n);
    vector<pair<int128_t, int128_t>> tree(n);
    For(i, 0, n) {
        cin >> tree[i].first >> tree[i].second;
    }
    inpt(q);
    vector<pair<int128_t, int128_t>> well(q);
    For(i, 0, q) {
        cin >> well[i].first >> well[i].second;
    }
    int128_t total = 0;
    int128_t sq_tree_x=0, sq_well_x=0, tree_x=0, well_x=0;
    int128_t sq_tree_y=0, sq_well_y=0, tree_y=0, well_y=0;
    For(i, 0, n) {
        sq_tree_x += ((tree[i].first*tree[i].first)%MOD);
        sq_tree_x %= MOD;
        tree_x += tree[i].first;
        tree_x %= MOD;
        sq_tree_y += ((tree[i].second*tree[i].second)%MOD);
        sq_tree_y %= MOD;
        tree_y += tree[i].second;
        tree_y %= MOD;
    }
    For(i, 0, q) {
        sq_well_x += ((well[i].first*well[i].first)%MOD);
        sq_well_x %= MOD;
        well_x += well[i].first;
        well_x %= MOD;
        sq_well_y += ((well[i].second*well[i].second)%MOD);
        sq_well_y %= MOD;
        well_y += well[i].second;
        well_y %= MOD;
    }

    // deb(sq_tree_x); deb(sq_tree_y); deb(sq_well_x); deb(sq_well_y);
    // deb(tree_x); deb(tree_y); deb(well_x); deb(well_y);

    sq_tree_x *= q; sq_tree_x %= MOD;
    sq_well_x *= n; sq_well_x %= MOD;
    sq_tree_y *= q; sq_tree_y %= MOD;
    sq_well_y *= n; sq_well_y %= MOD;

    tree_x *= well_x; tree_x %= MOD;
    tree_x *= 2; tree_x %= MOD;
    tree_y *= well_y; tree_y %= MOD;
    tree_y *= 2; tree_y %= MOD;

    total += sq_tree_x; total %= MOD;
    total += sq_well_x; total %= MOD; 
    total += MOD; total -= tree_x;  total %= MOD;
    total += sq_tree_y; total %= MOD;
    total += sq_well_y; total %= MOD; 
    total += MOD; total -= tree_y; total %= MOD;
    
    pl(total); return;
}

int32_t main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("watering_well_chapter_2_input.txt", "r", stdin);
        freopen("watering_well_chapter_2_output.txt", "w", stdout);
    #endif
    inpt(t);
    For(i, 1, t+1) {
        cout<< "Case #" << i<<": ";
        sol();
    }
}
