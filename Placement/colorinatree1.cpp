#include <iostream>
#include <string>
#include <sstream>
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
	//mark the node visited
	vis[v] = 1;

	//set visiting time of the node v
	vis_time[v] = ++tim;

	//use the color of node v to fill flat_tree[]
	flat_tree[tim] = color[v];

	vector<int>::iterator it;
	for (it=tree[v].begin(); it!=tree[v].end(); it++)
		if (!vis[*it])
			dfs(*it, color);


	// set ending time for node v
	end_time[v] = ++tim;

	// setting its color in flat_tree[] again
	flat_tree[tim] = color[v];
}

//function to add an edge(u, v) to the tree
void addEdge(int u, int v)
{
	tree[u].push_back(v);
	tree[v].push_back(u);
}

//function to build the table[] and also add
//first occurrences of elements to the BIT
void hashMarkFirstOccurrences(int n)
{
	for (int i = 1 ; i <= 2 * n ; i++)
	{
		table[flat_tree[i]].push_back(i);

		//if it is the first occurrence of the element
		//then add it to the BIT and increment traverser
		if (table[flat_tree[i]].size() == 1)
		{
			//add the occurrence to bit
			update(i, 1);

			//make traverser point to next occurrence
			traverser[flat_tree[i]]++;
		}
	}
}

//function to process all the queries and store their answers
void processQueries()
{
	int j = 1;
	for (int i=0; i<queries.size(); i++)
	{
		//for each query remove all the occurrences before its li
		//li is the visiting time of the node
		//which is stored in first element of first pair
		for ( ; j < queries[i].first.first ; j++ )
		{
			int elem = flat_tree[j];

			//update(i, -1) removes an element at ith index
			//in the BIT
			update( table[elem][traverser[elem] - 1], -1);

			//if there is another occurrence of the same element
			if ( traverser[elem] < table[elem].size() )
			{
				//add the occurrence to the BIT and
				//increment traverser
				update(table[elem][ traverser[elem] ], 1);
				traverser[elem]++;
			}
		}

		//store the answer for the query, the index of the query
		//is the second element of the pair
		//And ri is stored in second element of the first pair
		ans[queries[i].second] = query(queries[i].first.second);
	}
}

// Count distinct colors in subtrees rooted with qVer[0],
// qVer[1], ...qVer[qn-1]
void countDistinctColors(int color[], int n, int qVer[], int qn)
{
	// build the flat_tree[], vis_time[] and end_time[]
	dfs(1, color);

	// add query for u = 3, 2 and 7
	for (int i=0; i<qn; i++)
		queries.push_back(make_pair(make_pair(vis_time[qVer[i]],
									end_time[qVer[i]]), i) );

	// sort the queries in order of increasing vis_time
	sort(queries.begin(), queries.end());

	// make table[] and set '1' at first occurrences of elements
	hashMarkFirstOccurrences(n);

	// process queries
	processQueries();

	// print all the answers, in order asked
	// in the question
	for (int i=0; i<queries.size() ; i++)
	{
		cout << "Distinct colors in the corresponding subtree"
		"is: " << ans[i] << endl;
	}
}

//driver code
int main()
{
	/*
			1
		/ \
		2 3
		/|\ | \
		4 5 6 7 8
			/| \
			9 10 11 */
	int n = 5;
	int color[] = {1,2,1,1,0};

	// add all the edges to the tree
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(3, 4);
	addEdge(3, 5);


	int qVer[] = {1,2,3,4,5};
	int qn = sizeof(qVer)/sizeof(qVer[0]);

	countDistinctColors(color, n, qVer, qn);

	return 0;
}
