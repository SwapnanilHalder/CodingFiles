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


class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    vi special, specials, score;
    int n, s, fixed;
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
    void printAdj();
    Graph(int n, vi &special, int ss, int fixedd) {
        vector<int> score (n+1 , 0);
        vi specials (n+1, 0);
        vi special = special;
        s = ss;
        fixed = fixedd;
    }
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    pv(special);
}

void Graph::printAdj() {

}
 
void Graph::DFS(int v)
{
    if ( v == fixed) {
        score[fixed] = 0;
        specials[fixed] = special[0];
    }
    
    // Mark the current node as visited and
    // print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

void sol() {
    inpt(n); inpt(s); inpt(fixed); cinbuffer;
    vi special = input1l();
    Graph g(n, special, s, fixed);
    int x{0}, y{0};
    For(i, 0, n-1) {
        cin >> x >> y;
        g.addEdge(x, y);
        g.addEdge(y, x);
    }
    // g.printAdj();
    g.DFS(fixed);
}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}