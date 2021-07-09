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


int Solution::solve(int e, int f) {
    dp.clear();
    dp = vector<vector<int>> (e+5, vector<int> (f+5, -1));
    int answer = recur(e, f);
    return answer;
}