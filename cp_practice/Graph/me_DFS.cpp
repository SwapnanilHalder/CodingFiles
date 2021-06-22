#include <iostream>
#include <string>
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
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define int long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " :  " << itr->second;END;}
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

class Graph {
    int V;
    vector<li> adj;
    void DFSutil(int s, vector<bool> &visited);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void printl(){pv2d(adj);}
        void DFS(); 
};

Graph::Graph(int V) {
    this->V = V;
    adj = vector<li> (V, li{});
}

void Graph::addEdge(int v, int w) {
    adj[v].pb(w);
}

void Graph::DFSutil(int s, vector<bool> &visited) {
    visited[s] = true;
    cout << s << " ";

    loop(it, adj[s]) {
        if(!visited[*it]) {
            DFSutil(*it, visited);
        }
    }
}

void Graph::DFS() {
    vector<bool> visited(V, false);

    For(i, 0, adj.size()) {
        if(visited[i] == false) DFSutil(i, visited);
    }
}

int32_t main() {
    timestart;
    system("clear");
    cout << flush;
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 3);
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.printl();
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 0, covering all disconnected graph) \n"; 
    g.DFS(); END;
    timestop;
}