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
#define MAX 13

int adj_Mat[MAX][MAX];
int V,E;
int outPut[MAX];

// Function to make a 0 arr
void zero_Arr(int arr[], int n){
	for(int i=0;i<n; i++)
		arr[i] = 0;
}

// if an edge is covered by any vertices already checked, return 0,  if not checked yet, return 1
int is_Covered(int st[]){
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			if(adj_Mat[i][j])
				if(st[i]==0 and st[j]==0)
					return 0;
	return 1;
}

int32_t main(){

	//input

	V = 7; // vertex will be 0,1,....V-1
	E = 7;
	int first_point[] = {1,1,2,2,3,3,5};
	int second_point[] = {2,4,3,5,6,7,6};

    

	for(int i=0; i<E; i++){
		int u,v;
		u = first_point[i];
		v = second_point[i];
		adj_Mat[u][v]=adj_Mat[v][u]=1;
	}

	int st[MAX];
	int ans = V;
	for(int i=1; i < (1LL<<V); i++){
		int cnt = 0;
		zero_Arr(st,V);

		for(int j=0; j<V; j++){
			if((1LL<<j)&(i)){
				cnt++;
				st[j]=1;
			}
		}
		if(is_Covered(st) and ans>cnt){
			ans = cnt;
			for(int i1=0;i1<V;i1++)
				outPut[i1] = st[i1];
		}
	}
	cout<<"min vertex cover size = "<<ans<<"\n";
	cout<<"outPut vertex cover\n";
	for(int i=0;i<V;i++)
	{
		if(outPut[i])
			cout<<i<<" ";
	}END;
}