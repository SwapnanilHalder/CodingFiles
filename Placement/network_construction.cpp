// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// DSU data structure
// path compression + rank by union

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
    parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function 
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }

    int kruskals_mst()
    {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << endl;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Take this edge in MST if it does
            // not forms a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w
                     << endl;
            }
        }

        return ans;
    }
};

// Driver's code
int main()
{
    /* Let us create following weighted graph
                10
            0--------1
            | \	 |
            6| 5\ |15
            |	 \ |
            2--------3
                4
                n = 3,
                x=[2,4,8]
                y = [6,10,9] 6,9,10

                */
    Graph g(3);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(0, 2, 6);

    // Function call

    Graph h(3);
    g.addEdge(0, 1, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 3);
    int x_ans = g.kruskals_mst();
    // int y_ans = h.kruskals_mst();
    cout << "Minimum Cost Spanning Tree: " << x_ans << endl ;
    return 0;
}
