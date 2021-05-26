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
#define END cout << "\n"
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define inpt(x) int x{}; cin >> x
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

vi2d range, val, graph;
vi visited;

void BFS(int idx, int sel_val, int sum) {
    For(i, 0, graph[idx].size()) {
        if(visited[ graph[idx][i] ] == 1 ) {
            return;
        }
        visited[ graph[idx][i] ] = 1;
        if( abs(range[graph[idx][i]][0] - sel_val) > abs(range[graph[idx][i]][1] - sel_val)  ) {
            if(val[graph[idx][i]][0] != -1) {
                if( abs(range[graph[idx][i]][0] - sel_val) > abs(range[graph[idx][i]][1] - sel_val)  )
            }
        }
    }
}

void sol() {
    inpt(n);
    range.clear(); val.clear(); visited.clear();
    range = vi2d(n, vi(2));
    visited = vi(n, 0);
    val= vi2d(n, vi(2, -1));
    int x,y;
    For(i, 0, n) {
        cin >> x >> y;
        range[i][0] = x;
        range[i][1] = y;
    }
    graph= vi2d(n);
    For(i, 0, n-1) {
        cin >> x >> y;
        x--; y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    pv2d(range); pv2d(val); pv2d(graph);
    BFS(0, range[0][0], 0);
    BFS(0, range[0][1], 0);
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}