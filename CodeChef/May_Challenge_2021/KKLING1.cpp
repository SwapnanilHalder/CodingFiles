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
#include <numeric>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define END cout<<"\n"
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
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

struct TreeNode {
    int data, lvl;
    vector<TreeNode *> child;
    TreeNode(int x) {
        data = x;
        lvl = 0;
    }
};

void buildTree(TreeNode *root, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[root->data] = 1;
    for(int i=0; i< adj[root->data].size(); i++) {
        if ( ! visited[adj[root->data][i]]) {
            TreeNode *temp = new TreeNode(adj[root->data][i]);
            root->child.push_back(temp);
        }
    }
    for(int i=0; i< root->child.size(); i++) {
        buildTree(root->child[i], adj, visited);
    }
}

void DFS(TreeNode *root, int l) {
    root->lvl = l;
    for(int i = 0; i < root->child.size(); i++) {
        TreeNode *current = root->child[i];
        DFS(current, l+1);
    }
}

vector<pair<int, int>> leaves;

void DFS2(TreeNode *root) {
    for(int i = 0; i < root->child.size(); i++) {
        TreeNode *current = root->child[i];
        DFS2(current);
    }
    if(root->child.size() == 0) {
        leaves.push_back({root->lvl, root->data + 1});
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i =0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    TreeNode *root = new TreeNode(0);
    vector<bool> visited(n, 0);
    buildTree(root, adj, visited);
    DFS(root, 0);
    vector<pair<int, int>> ans;
    for(int i=0; i < root->child.size(); i++) {
        DFS2(root->child[i]);
        vector<pair<int, int>> v;
        pair<int, int> p;
        bool f = 0;
        sort(leaves.begin(), leaves.end());
        p = leaves[0];
        v.push_back(p);
        int val = p.first;
        int j = 1; 
        while(j < leaves.size()) {
            while(j < leaves.size() && leaves[j].first == val) {
                if (f) {
                    v.push_back({p.first + 1, leaves[j].second});
                }
                else {
                    v.push_back(leaves[j]);
                }
                j++;
            }
            if (j < leaves.size() ) {
                v.clear();
                f = 1;
                p.second = leaves[j].second;
                v.push_back({p.first+1, leaves[j].second});
                val = leaves[j].first;
                j++;
            }
        }
        leaves.clear();

        for(auto x : v) {
            ans.push_back(x);
        }
    }

    sort(ans.begin(), ans.end());

    int day = ans[0].first;
    // deb(day);
    vector<int> Ans_Array;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].first == day) {
            Ans_Array.push_back(ans[i].second);
        }
        // else {
        //     break;
        // }
    }
    cout << Ans_Array.size() << " " << day << "\n";
    for(auto x : Ans_Array) {
        cout << x << " ";
    }
    cout << "\n";
}

int32_t main () {
    SPEED;
    inpt(t);
    while(t--) {
        solve();
    }
}