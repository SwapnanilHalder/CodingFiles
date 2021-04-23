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
    inpt(n); inpt(m);
    int temp{0};
    vi2d graph(n, vi (m, 0));
    For(i, 0, n) {
        For(j, 0, m) {
            cin >> temp;
            graph[i][j] = temp;
        } 
    }
    vi2d shorts(n, vi(m, 0));
    vi min(m, 0);
    vi tem (m, 0);
    vi max (m, 0);
    vi mint(m, 0);
    int max_ind=0, min_ind = 0;
    shorts[0] = graph[0];
    min = graph[0];
    // pv2d(shorts);
    For(i, 1, n) {
        tem = graph[i];
        mint = min;
        For(j, 0, m) {
            max_ind = max_element(all(tem)) - tem.begin();
            min_ind = min_element(all(mint)) - mint.begin();
            // deb(max_ind); deb(min_ind);
            max[min_ind] = tem[max_ind];
            min[min_ind] = std::min(tem[max_ind], mint[min_ind]);
            tem[max_ind] = -INF;
            mint[min_ind] = INF;
        }
        shorts[i] = max;
        // pv2d(shorts);
        // cout << "MIN : "; pv(min);
    }   
    pv2d(shorts);
}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}