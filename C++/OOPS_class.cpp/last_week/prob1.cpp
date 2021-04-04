// C++ implementation of the approach 
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
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

const int MAX = 100; 

// Stores the vertices 
int store[MAX], n; 

// Graph 
int graph[MAX][MAX]; 

// Degree of the vertices 
int d[MAX]; 

// Function to check if the given set of 
// vertices in store array is a clique or not 
bool is_clique(int b) 
{ 

	// Run a loop for all set of edges 
	for (int i = 1; i < b; i++) { 
		for (int j = i + 1; j < b; j++) 

			// If any edge is missing 
			if (graph[store[i]][store[j]] == 0) 
				return false; 
	} 
	return true; 
} 

// Function to find all the sizes 
// of maximal cliques 
int maxCliques(int i, int l) 
{ 
	// Maximal clique size 
	int max_ = 0; 

	// Check if any vertices from i+1 
	// can be inserted 
	for (int j = i + 1; j <= n; j++) { 

		// Add the vertex to store 
		store[l] = j; 

		// If the graph is not a clique of size k then 
		// it cannot be a clique by adding another edge 
		if (is_clique(l + 1)) { 

			// Update max 
			max_ = max(max_, l); 

			// Check if another edge can be added 
			max_ = max(max_, maxCliques(j, l + 1)); 
		} 
	} 
	return max_; 
} 

// Driver code 
int32_t main() 
{ 
	int edges[][2] = { {1,2}, {1,3}, {1,6}, {2,3}, {2,4}, {2,5}, {2,6}, {3,4}, {3,6}, {4,5}  }; 
	int size = sizeof(edges) / sizeof(edges[0]); 
	n = 4; 

	for (int i = 0; i < size; i++) { 
		graph[edges[i][0]][edges[i][1]] = 1; 
		graph[edges[i][1]][edges[i][0]] = 1; 
		d[edges[i][0]]++; 
		d[edges[i][1]]++; 
	} 

	cout << maxCliques(0, 1); END;
    For(i, 0, MAX) {
        cout << d[i] << " ";
    } END;

	return 0; 
} 
