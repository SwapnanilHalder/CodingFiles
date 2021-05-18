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

int soln(int ind, int prev, vi2d &graph, vi &degree) {
    // deb(ind); deb(prev);
    if (degree[ind] == 1 && ind != 1) {
        return 1;
    }
    vi temp;
    // For(i, 1, degree.size()) {
    //     if(graph[ind][i] == 1 && i != prev) {
    //         temp.pb(soln(i, ind, graph, degree));
    //     }
    // }
    For(i, 0, graph[ind].size()) {
        if(graph[ind][i] != prev ) {
            temp.pb(soln(graph[ind][i], ind, graph, degree));
        }
    }
    sort(all(temp), greater<int>());
    int sum = 0;
    // cout << "FOR : " << ind << " => \n";
    // pv(temp); 
    For(i,0, temp.size()) {
        sum += temp[i] * (i+1);
        // deb(sum);
    }
    return (sum + 1) ;
}

void sol() {
    inpt(n); inpt(x);
    vi2d graph(300005);
    int p,q;
    vi degree(n+1, 0);
    For(i, 0, n-1) {
        cin >> p >> q;
        // deb(p); deb(q);
        degree[p]++; degree[q]++;
        graph[p].pb(q);
        graph[q].pb(p);
        // pv2d(graph);
    }
    // pv2d(graph);
    // pv(degree);
    vi score(n+1, 1);
    int total = 0;
    // pl("Starting process");
    total = soln(1, -1, graph, degree);
    int ans = ((total % MOD ) * (x % MOD) ) % MOD;
    pl(ans); return;
}

int32_t main() {
    // SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}