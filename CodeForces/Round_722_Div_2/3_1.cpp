#include <bits/stdc++.h>
using namespace std;
typedef long long int int64;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
vector<int> graph[100005];
int64 ans = 0;
bool vis[100005];
int64 track_sum[100005][3];
vector<pair<int64, int64>> lim;
void dfs(int x)
{
    int64 temp = 0, temp1 = 0, temp3 = 0, temp4 = 0;
    for (auto i : graph[x])
    {
        if (vis[i] == false)
        {
            vis[i] = true;
            dfs(i);
            if (track_sum[i][0] + abs(lim[x - 1].first - lim[i - 1].first) > track_sum[i][1] + abs(lim[x - 1].first - lim[i - 1].second))
                temp += track_sum[i][0] + abs(lim[x - 1].first - lim[i - 1].first);
            else
                temp += track_sum[i][1] + abs(lim[x - 1].first - lim[i - 1].second);
            if (track_sum[i][0] + abs(lim[x - 1].second - lim[i - 1].first) > track_sum[i][1] + abs(lim[x - 1].second - lim[i - 1].second))
                temp1 += track_sum[i][0] + abs(lim[x - 1].second - lim[i - 1].first);
            else
                temp1 += track_sum[i][1] + abs(lim[x - 1].second - lim[i - 1].second);
        }
    }
    track_sum[x][0] = temp;
    track_sum[x][1] = temp1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ta;
    cin >> ta;
    while (ta-- > 0)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            vis[i] = false;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            lim.push_back({l, r});
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vis[1] = true;
        dfs(1);
        if (track_sum[1][0] < track_sum[1][1])
            cout << track_sum[1][1] << endl;
        else
            cout << track_sum[1][0] << endl;
        for (int i = 1; i <= n; i++)
            graph[i].clear();
        lim.clear();
    }
}