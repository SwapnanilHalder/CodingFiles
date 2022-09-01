#include <bits/stdc++.h>
#define SPEED1                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
using namespace std;

void solve()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        if(isupper(str[i]))
            str[i] = tolower(str[i]);
        else
            str[i] = toupper(str[i]);
    }
    cout << str << endl;
}

signed main()
{
    SPEED1;
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int __t;
    cin >> __t;
    cin.ignore();
    while (__t--)
        solve();
}