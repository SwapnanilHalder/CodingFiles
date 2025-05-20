#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define pi pair<int,int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
#define MOD 1000000007
using namespace std;
// int dp[100000][500];
// int dp[100000][110];
vector<vector<int>> dp;

// int totalCount = 0;
// int maxx;

// int count(int targetSum, int covered) {
//     deb(targetSum); deb(covered);
//     if(dp[targetSum][covered] != -1) {
//         return dp[targetSum][covered];
//     }
//     if(targetSum == 0) {
//         pl("found");
//         totalCount++; 
//         dp[0][covered] += 1;
//         return;
//     }
//     if( (covered+1) > maxx) return;
//     if(targetSum < (covered+1)) return;

//     cout << "including: " << covered+1 << endl;
//     bool found = count(targetSum - (covered+1) , covered+1);

//     if(found) dp[targetSum - (covered+1) ][covered+1] += 1;

//     cout << "NOT including: " << covered+1 << endl;
//     found = count(targetSum, covered+1);

//     if(found) dp[targetSum][covered+1] = 1;
//     else dp[targetSum][covered+1] = 0;
//     return (dp[targetSum - (covered+1) ][covered+1] || dp[targetSum][covered+1]);
// }


int countSet(int targetSum, int left) {
    // deb(targetSum);deb(left);
    if(targetSum < 0 || left < 0) return 0;
    if(targetSum == 0) {
        dp[targetSum][left]++;
        return dp[targetSum][left];
    }
    if(targetSum > (left*(left+1)/2)) return 0;
    if(dp[targetSum][left] != 0)
        return dp[targetSum][left];

    // taking the left in consideration    
    int count1 = countSet(targetSum-left, left-1);
    int count2 = countSet(targetSum, left-1);
    dp[targetSum][left] = (count1 + count2);
    if(dp[targetSum][left] > 10000000000) 
        dp[targetSum][left] %= MOD;
    return dp[targetSum][left];
}

void solve() {
    // memset(dp, 0, sizeof(dp));
    inpt(n);
    int totalSum = (n*(n+1LL))/2LL;
    if(totalSum & 1) {
        pl("0"); return;
    } 
    int targetSum = totalSum>>1;
    dp.resize(targetSum+1, vector<int>(n+1, 0));
    // dp1.resize();
    // deb(targetSum);
    // maxx = n;
    // count(targetSum, 0);
    countSet(targetSum, n);
    cout << (dp[targetSum][n]>>1)%MOD << endl;
    // pv2d(dp);
    // deb(totalCount);
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //int __t; cin >> __t; while(__t--)
    solve();
}