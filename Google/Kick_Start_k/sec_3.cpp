#include <bits/stdc++.h>
using namespace std;
typedef long long int i64;
typedef unsigned long long int u64;
const int maxn = 1e+9;
int main()
{
    int ta;
    cin >> ta;
    int tc = 1;
    while (ta-- > 0)
    {
        i64 n;
        i64 c;
        cin >> n >> c;
        vector<pair<i64, i64>> v1;
        map<i64, i64> m1;
        i64 st = 0;
        i64 en = 1;
        for (i64 i = 1; i <= n; i++)
        {
            i64 l, r;
            cin >> l >> r;
            v1.push_back({l + 1, 1});
            v1.push_back({r, -1});
        }

        sort(v1.begin(), v1.end());
        for (int i = 0; i < v1.size(); i++)
        {
            m1[st] += v1[i].first - en;
            st += v1[i].second;
            en = v1[i].first;
        }

        i64 ans = n;
        if (c != 0)
        {
            for (auto x = m1.rbegin(); x != m1.rend(); x++)
            {
                if (x->second <= c)
                {
                    ans += (x->second) * (x->first);
                    c -= (x->second);
                }
                else
                {
                    ans += (c * x->first);
                    c = 0;
                }
            }
        }
        cout << "Case #" << tc << ": ";
        cout << ans << "\n";
        tc++;
    }
}