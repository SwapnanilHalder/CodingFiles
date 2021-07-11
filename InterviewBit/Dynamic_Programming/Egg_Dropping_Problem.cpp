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
using namespace std;



vector<vector<int>> dp;

int recur(int e, int f) {
    if(dp[e][f] != -1) {
        return dp[e][f];
    }
    if (e == 1) {
        dp[e][f] = f;
        return f;
    }
    if(f == 0 || f == 1) {
        dp[e][f] = f;
        return f;
    }
    int ans1, ans2;
    int temp, mn = INT_MAX;
    for(int k=1; k <= f; k++) {
        if (dp[e-1][k-1] == -1) {
            ans1 = recur(e-1, k-1);
            dp[e-1][k-1] = ans1;
        } else {
            ans1 = dp[e-1][k-1];
        } 
        if (dp[e][f-k] == -1) {
            ans2 = recur(e, f-k);
            dp[e][f-k] = ans2;
        } else {
            ans2 = dp[e][f-k];
        } 
        // ans2 = (dp[e][f-k] == -1) ? recur(e, f-k) : dp[e][f-k];
        temp = 1 + max(ans1, ans2  );
        mn = min(mn, temp);
    }
    dp[e][f] = mn;
    return mn;
}


int ssolve(int e, int f) {
    dp.clear();
    dp = vector<vector<int>> (e+5, vector<int> (f+5, -1));
    int answer = recur(e, f);
    return answer;
}

// int solve(int e, int f) {
//     dp.clear();
//     dp = vector<vector<int>> (e+1, vector<int> (f+1, 10000));
//     For(i, 1, f+1) {
//         dp[1][i] = i;
//     }
//     For(i, 1, e+1) {
//         dp[i][0] = 0;
//         dp[i][1] = 1; 
//     }
//     // pv2d(dp);
//     For(i, 2, e+1) {
//         For(j, 2, f+1) {
//             For(k, 1, j+1) {
//                 dp[i][j] = min( dp[i][j] , 1+ max( dp[i-1][j-1] , dp[i][j-k]  )  );
//             }
//         }
//     }
//     // pv2d(dp);

//     return dp[e][f];
// }

int main() {
    int e = 10 , f = 100;
    int answer = solve(e, f);
    cout << "The Answer is : " << answer << endl;
}