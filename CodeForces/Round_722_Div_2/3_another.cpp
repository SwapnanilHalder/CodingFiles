#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <numeric>
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define int long long int
#define END printf("\n")
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define cinbuffer cin.ignore(numeric_limitsitsits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

vector<int> graph[10004];
int ans = 0;
bool visited[10005];
int track_sum[10005][3];
vector<pair<int, int>> limits;


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

void dfs(int x)
{
    int temp = 0, temp1 = 0;
    for (auto i : graph[x])
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(i);
            if (track_sum[i][0] + abs(limits[x - 1].first - limits[i - 1].first) > track_sum[i][1] + abs(limits[x - 1].first - limits[i - 1].second))
                temp += track_sum[i][0] + abs(limits[x - 1].first - limits[i - 1].first);
            else
                temp += track_sum[i][1] + abs(limits[x - 1].first - limits[i - 1].second);
            if (track_sum[i][0] + abs(limits[x - 1].second - limits[i - 1].first) > track_sum[i][1] + abs(limits[x - 1].second - limits[i - 1].second))
                temp1 += track_sum[i][0] + abs(limits[x - 1].second - limits[i - 1].first);
            else
                temp1 += track_sum[i][1] + abs(limits[x - 1].second - limits[i - 1].second);
        }
    }
    track_sum[x][0] = temp;
    track_sum[x][1] = temp1;
    // pv2d(track_sum); END; END;
}

void sol() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            visited[i] = false;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            limits.pb({l, r});
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        visited[1] = true;
        dfs(1);
        if (track_sum[1][0] < track_sum[1][1])
            cout << track_sum[1][1] << endl;
        else
            cout << track_sum[1][0] << endl;
        for (int i = 1; i <= n; i++)
            graph[i].clear();
        limits.clear();
}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}