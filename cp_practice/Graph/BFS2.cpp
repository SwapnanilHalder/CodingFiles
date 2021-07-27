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
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
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


class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
    void BFS(vector<int> adj[], int s, vector<int> &visited, vector<int> &sol) {
        visited[s] = true;
        queue<int> q;
        q.push(s);
        int u=0;
        // pl("check 1");
        while(!q.empty()) {
            // pl("check 2");
            u = q.front();
            // q.pop();
            deb(u);
            // cout << adj[u].size() << endl;
            sol.push_back(u);
	        for(int j=0; j < adj[u].size(); j++) {
	            if(!visited[adj[u][j]]) {
	                visited[adj[u][j]] = 1;
	                q.push(adj[u][j]);
	            }
	        }
            // cout << "HERE : " << q.front() << endl;
            q.pop();    
        }
        return;
    }
    
	vector<int> bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> sol;
	    vector<int> visited(V+1, 0);

        for(int i=0; i<V; i++) { 
            if(!visited[i]) {
                deb(i);
                BFS(adj, i, visited, sol);
            }
        }
	    return sol;
	}   
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends



// int main() {
//     Solution mySolution;
//     vector<int> arr{4,2,3,0,3,1,2};
//     int start = 5;
//     string str = "abcdefg";
//     cout << "Answer : " << endl;
//     vector<int> graph[5];
//     graph[0] = vector<int> {1,2,3};
//     graph[2] = vector<int> {4};
//     cout << mySolution.answer() << endl;
// }


/*

1
5 4
0 1
0 2
0 3
2 4

*/
