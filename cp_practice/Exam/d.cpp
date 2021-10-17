#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define For(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;

int findMin(vi &arr)
{
    int n = arr.size();
    int sum = accumulate(all(arr), 0);
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, 0)); 
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
                dp[i][j] != dp[i - 1][j - arr[i - 1]];
        }
    }
    int diff = INT_MAX;
    for (int j = sum / 2; j >= 0; j--) {
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}
void sol() {
    inpt(n);
    vi arr(n, 0);
    For(i, 0, n) {
        cin >> arr[i];
    }
    pl(findMin(arr));
}
int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}
