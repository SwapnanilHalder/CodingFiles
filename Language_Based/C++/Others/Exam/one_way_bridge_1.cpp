#include <iostream>
#include <sstream>
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

using namespace std;
typedef long long ll;

vector<pair<int,int>>adj[55];
ll n,m;
ll from[3000],to[3000],temp[3000];
ll s,t,d;
int dp[101][101];bool vis[101][101];
int solve(int node,int k)
{
    if(k==0)
    {
        if(node!=t)
            return INT_MAX;
        return 0;
    }
    if(vis[node][k])
        return dp[node][k];
    int ans=INT_MAX;
    for(auto child:adj[node])
        ans=min(ans,max(child.second,solve(child.first,k-1)));
    vis[node][k]=true;
    return dp[node][k]=ans;
}
void test()
{
    cin>>n>>m;
    ll i;
    for(i=0;i<m;i++)
    cin>>from[i];
    for(i=0;i<m;i++)
    cin>>to[i];
    for(i=0;i<m;i++)
    cin>>temp[i];
    cin>>s>>t>>d;
    for(i=0;i<=n;i++)
    {
        adj[i].clear();
    }
    for(i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        vis[i][j]=false;
    }
    for(i=0;i<m;i++)
        adj[from[i]].push_back({to[i],temp[i]});
    int ans=solve(s,min(n,d));
    if(ans==INT_MAX)
    cout<<-1<<endl;
    else
    cout<<ans<<endl;
    
}
int main()
{
	SPEED1;
	ll t=1;
	cin>>t;
	while(t--)
	{
	    test();
	}
	return 0;
}