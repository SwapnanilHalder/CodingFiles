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
#define int long long
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

struct TreeNode {
    int data, lvl;
    vector<TreeNode *> child;
    TreeNode (int x) {
        data = x;
        lvl = 0;
    }
};

void buildTree(TreeNode *root, vi2d &adj, vector<bool> &visited) {
    visited[root->data] = 1;
    For(i, 0, adj[root->data].size()) {
        if(! visited[adj[root->data][i]]) {
            TreeNode *temp = new TreeNode (adj[root->data][i]);
            root->child.pb(temp);
        }
    }
    For(i, 0, root->child.size()) {
        buildTree(root->child[i], adj, visited);
    }
}

void DFS(TreeNode *root, int l) {
    root->lvl = l;
    For(i, 0, root->child.size()) {
        TreeNode *current = root->child[i];
        DFS(current, l+1);
    }
}

vector<pair<int, int>> leaves;

void DFS2(TreeNode *root) {
    For(i, 0, root->child.size()) {
        TreeNode *current = root->child[i];
        DFS2(current);
    }
    if(root->child.size() == 0) {
        leaves.pb({root->lvl, root->data + 1});
    }
}

void sol () {
    inpt(n);
    vi2d adj(n);
    For(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    TreeNode *root = new TreeNode(0);
    vector<bool> visited(n, 0) ;
    buildTree(root, adj, visited);
    DFS(root, 0);
    vector<pair<int, int>> ans;
    For(i, 0, root->child.size()) {
        DFS2(root->child[i]);
        vector<pair<int, int>> v;
        pair<int, int> p;
        bool f = 0;
        sort(all(leaves));
        p = leaves[0];
        v.pb(p);
        int val = p.first;
        int j = 1;
        while(j < leaves.size()) {
            while(j < leaves.size() && leaves[i].first == val) {
                if (f == 1) {
                    v.pb({p.first + 1, leaves[j].second});
                }
                else {
                    v.pb(leaves[j]);
                }
                j++;
            }
            if (j < leaves.size() ) {
                v.clear();
                f = 1;
                p.second = leaves[j].second;
                v.pb({p.first+1, leaves[j].second});
                val = leaves[j].first;
                j++;
            }
        }
        leaves.clear();

        for(auto x : v) {
            ans.pb(x);
        }
    }

    sort(all(ans));
    pl("ANS : ");
    loop(it, ans) {
        cout << it->first << " , " << it->second <<"\n";
    }
    int day = ans[ans.size()-1].first;
    deb(day);
    vi AA;
    For(i, 0, ans.size()) {
        deb(ans[i].first);
        if(ans[i].first == day) {
            AA.pb(ans[i].second);
            pl(ans[i].second);
        }
        // else {
        //     break;
        // }
    }
    cout << AA.size() << " " << day << "\n";
    pv(AA);
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}