#include <bits/stdc++.h>
#define SPEED1                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
#define int long long int
#define For(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x << "= " << x << endl
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v)               \
    for (const auto &i : v) \
    {                       \
        cout << i << " ";   \
    }                       \
    cout << "\n"
#define pv2d(k)             \
    for (const auto &j : k) \
    {                       \
        pv(j);              \
    }                       \
    cout << ""
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

void min_segment(vector<int> &arr, vector<int> &segment, int low, int high, int idx)
{
    // deb(low); deb(high); deb(idx);
    if (low == high)
    {
        // deb(arr[low]);
        segment[idx] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    // deb(mid); deb(2*idx+1); deb(2*idx+2);
    min_segment(arr, segment, low, mid, 2 * idx + 1);
    min_segment(arr, segment, mid + 1, high, 2 * idx + 2);

    segment[idx] = min(segment[2 * idx + 1], segment[2 * idx + 2]);
    // deb(idx);deb(segment[idx]);
}

int query(vector<int> &segment, int low, int high, int x, int y, int idx)
{
    // deb(low);deb(high);deb(x);deb(y);cout << endl<<endl;
    if (low >= x && high <= y)
    {
        return segment[idx];
    }
    if (low > y || high < x)
    {
        return INT_MAX;
    }
    int mid = low + ((high - low) / 2);
    return min(query(segment, low, mid, x, y, 2 * idx + 1), query(segment, mid + 1, high, x, y, 2 * idx + 2));
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n, 0);
    int x, y;
    For(i, 0, n)
    {
        cin >> arr[i];
    }
    int limit = ((int)1 << (int)(ceil(log2(n)) + 1)) - 1;
    // deb(limit);
    vector<int> segment(limit, 0);

    min_segment(arr, segment, 0, n - 1, 0);
    For(i, 0, q)
    {
        cin >> x >> y;
        cout << query(segment, 0, n - 1, x - 1, y - 1, 0) << endl;
    }
}

signed main()
{
    SPEED1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // int __t; cin >> __t; while(__t--)
    solve();
}

// #include <bits/stdc++.h>
// using namespace std;
// const int maxN = 2e5 + 1;
// const int logN = 19;
// int N, Q, a, b, l, k, x[maxN][logN];
// int main()
// {
//     scanf("%d %d", &N, &Q);
//     for (int i = 0; i < N; i++)
//         scanf("%d", &x[i][0]);
//     for (int i = 1; i < logN; i++)
//         for (int j = 0; j <= N - (1 << i); j++)
//             x[j][i] = min(x[j][i - 1], x[j + (1 << (i - 1))][i - 1]);
//     for (int q = 0; q < Q; q++)
//     {
//         scanf("%d %d", &a, &b);
//         a--;
//         b--;
//         l = b - a + 1;
//         k = log2(l);
//         printf("%d\n", min(x[a][k], x[b - (1 << k) + 1][k]));
//     }
// }