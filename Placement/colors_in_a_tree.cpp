
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define max_color 1000005
#define maxn 100005
using namespace std;

int bit[maxn], vis_time[maxn], end_time[maxn];
int flat_tree[2 * maxn];
vector<int> tree[maxn];
vector<int> table[max_color];
int traverser[max_color];

bool vis[maxn];
int tim = 0;

vector< pair< pair<int, int>, int> > queries;

int ans[maxn];

void update(int idx, int val)
{
    while ( idx < maxn )
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx)
{
    int res = 0;
    while ( idx > 0 )
    {
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}

void dfs(int v, int color[])
{
    vis[v] = 1;

    vis_time[v] = ++tim;

    flat_tree[tim] = color[v];

    vector<int>::iterator it;
    for (it=tree[v].begin(); it!=tree[v].end(); it++)
        if (!vis[*it])
            dfs(*it, color);


    end_time[v] = ++tim;

    flat_tree[tim] = color[v];
}

void addEdge(int u, int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void hashMarkFirstOccurrences(int n)
{
    for (int i = 1 ; i <= 2 * n ; i++)
    {
        table[flat_tree[i]].push_back(i);

        if (table[flat_tree[i]].size() == 1)
        {
            update(i, 1);

            traverser[flat_tree[i]]++;
        }
    }
}

void processQueries()
{
    int j = 1;
    for (int i=0; i<queries.size(); i++)
    {

        for ( ; j < queries[i].first.first ; j++ )
        {
            int elem = flat_tree[j];

            update( table[elem][traverser[elem] - 1], -1);

            if ( traverser[elem] < table[elem].size() )
            {

                update(table[elem][ traverser[elem] ], 1);
                traverser[elem]++;
            }
        }

        ans[queries[i].second] = query(queries[i].first.second);
    }
}

void countDistinctColors(int color[], int n, int qVer[], int qn)
{
    dfs(1, color);

    for (int i=0; i<qn; i++)
        queries.push_back(make_pair(make_pair(vis_time[qVer[i]],
                                    end_time[qVer[i]]), i) );

    sort(queries.begin(), queries.end());

    hashMarkFirstOccurrences(n);

    processQueries();

    for (int i=0; i<queries.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n; 
    n = 5;
    // int color[n]; 
    int x, y;
    int color[] = {2,3,2,2,1};
    
    // for(int i=0; i<n; i++) {
    //     cin >> x;
    //     color[i] = x;
    // } 
    // x=0, y=0;
    // for(int i=0; i<n-1; i++) {
    //     cin >> x >> y;
    //     addEdge(x, y);
    // }
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    addEdge(3, 5); 


    int qVer[] = {1,2,3,4,5};
    // for(int i=0; i<n; i++) {
    //     qVer[i] = i+1;
    // }
    int qn = n;

    countDistinctColors(color, n, qVer, qn);

    return 0;
} 