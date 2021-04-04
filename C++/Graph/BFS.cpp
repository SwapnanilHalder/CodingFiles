#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<unordered_map>
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
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
//#define int long long int
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
    //This class represents a directed graph using
    //adjacency list representation
    int V; //No. of vertices
    vector<list<int>> adj; //Pointer to an array containing adjacency lists
    list<list<int>> adj1;

public:
    Graph(int V); //Constructor

    //function to add edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void BFS(int s);
    void printl();
    void printadj1() {
        
    }

};

void Graph::printl()
{
    // For(i, 0, adj.size()) {
    //     cout << i << " : "; std::copy(adj[i].begin(),adj[i].end(),std::ostream_iterator<std::int32_t>(std::cout, " "));END;}
	pv2d(adj);
}

Graph::Graph(int V) {
    this->V = V;
    adj = vector<list<int>>(V, list<int>{});
    adj1 = list<list<int>> (5, list<int>(3, 9));
}

void Graph::addEdge(int v, int w)  {// two vertices
    adj[v].pb(w);
    //cout << adj.size();
}

void Graph::BFS(int s) {
    bool *visited = new bool[V]; // Mark all the vertices as not visited
    For(i, 0, V) visited[i] = false;

    // Create a queue for BFS
    list<int>queue;

    visited[s] = true;
    queue.push_back(s);

    //'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        //Get all the adjacent vertices of the dequeued 
        //vertex s. If a adjacent has not been visited, 
        //then mark it visited and enqueue it
        loop(i, adj[s]) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int32_t main() 
{ 
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
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); END;
    g.printadj1();
}