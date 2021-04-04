#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define ll long long
#define lli long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << #x << "=" << x << endl
#define pl(x) cout << x << endl
using namespace std;

class Graph {
    int V; //No. of vertices
    list<int> *adj;

    public:
        Graph(int V); // Constructor (capital v)
        void addEdge(int v, int w); // Func. to add an edge to graph
        void BFS(int s); // Prints BFS traversla from a given source s
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}
void Graph::BFS(int s) {
    bool *visited = new bool[V];
    for(int i{0}; i<V; i++)
        visited[i] = false;

    list<int> queue; // Create a queue for BFS
    visited[s] = true; // Mark the current node as visited and enqueue it
    queue.push_back(s);

    list<int>::iterator i; // 'i' will be used to get all adjacent vertices of a vertex

    while(!queue.empty()) {
        s = queue.front(); // store the front node locally, dequeue
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s. 
        // If a adjacent has not been visited, then mark it visited and enqueue it.
        for (i = adj[s].begin(); i != adj[s].end(); i++) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {
    Graph g(4); // Total 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); END;
  
    return 0;
}