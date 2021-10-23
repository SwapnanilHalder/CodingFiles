#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<b;i++)

using namespace std;
typedef long long ll;
int main()
{
    int ta;
    cin >> ta;
    while (ta-- > 0)
    {
        int n, m;
        cin >> n >> m;
        vector<int> from(m);
        For(i, 0, m)
        {
            cin >> from[i];
        }
        vector<int> to(m);
        For(i, 0, m)
        {
            cin >> to[i];
        }
        vector<int> temp(m);
        For(i, 0, m)
        {
            cin >> temp[i];
        }
        int S, T, D;
        cin >> S >> T >> D;
        int graph[n + 5][n + 5];
        For(i, 1, n+1)
        {
            For(j, 1, n+1)
                graph[i][j] = INT_MAX;
        }
        For(i, 0, m)
        {
            graph[from[i]][to[i]] = temp[i];
        }
        int l = 0, r = 1000;
        int fans;
        while (l <= r)
        {
            ll count[n + 5][n + 5][D + 5];
            int mid = (l + r) / 2;
            For(e, 0, D+1)
            {
                For(i, 1, n+1) 
                {
                    For(j, 1, n+1)
                    {
                        count[i][j][e] = 0;
                        if (e == 0 && i == j)
                            count[i][j][e] = 1;
                        if (e == 1 && graph[i][j] <= mid)
                            count[i][j][e] = 1;
                        if (e > 1)
                        {
                            For(a, 1, n+1) 
                                if (graph[i][a] <= mid)
                                    count[i][j][e] += count[a][j][e - 1];
                        }
                    }
                }
            }
            if (count[S][T][D] != 0)
            {
                r = mid - 1;
                fans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << fans << endl;
    }
}