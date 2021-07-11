#include <bits/stdc++.h>
using namespace std;
typedef long long int i64;
const int maxn = 1e+3;
int main()
{
    int ta;
    cin >> ta;
    int tc = 1;
    while (ta-- > 0)
    {
        int a[3][3];
        for (int i = 0; i < 3; i++)
        {
            if (i == 1)
            {
                cin >> a[1][0] >> a[1][2];
            }
            else
            {
                for (int j = 0; j < 3; j++)
                {
                    cin >> a[i][j];
                }
            }
        }
        map<int, int> m1;
        if (abs(a[1][2] - a[1][0]) % 2 == 0)
        {
            int t = a[1][0] + (a[1][2] - a[1][0]) / 2;
            m1[t]++;
        }
        if (abs(a[0][1] - a[2][1]) % 2 == 0)
        {
            int t = a[0][1] + (a[2][1] - a[0][1]) / 2;
            m1[t]++;
        }
        if (abs(a[0][0] - a[2][2]) % 2 == 0)
        {
            int t = a[0][0] + (a[2][2] - a[0][0]) / 2;
            m1[t]++;
        }
        if (abs(a[0][2] - a[2][0]) % 2 == 0)
        {
            int t = a[0][2] + (a[2][0] - a[0][2]) / 2;
            m1[t]++;
        }
        int mx = 0;
        for (auto x = m1.begin(); x != m1.end(); x++)
        {
            if (x->second > mx)
                mx = x->second;
        }
        if (a[0][0] - a[0][1] == a[0][1] - a[0][2])
            mx++;
        if (a[0][0] - a[1][0] == a[1][0] - a[2][0])
            mx++;
        if (a[2][0] - a[2][1] == a[2][1] - a[2][2])
            mx++;
        if (a[0][2] - a[1][2] == a[1][2] - a[2][2])
            mx++;
        cout << "Case #" << tc << ": " << mx << endl;
        tc++;
    }
}