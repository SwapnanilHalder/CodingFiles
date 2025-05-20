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
using namespace std;

int dp[19][10][2][2];

int findAns(string &num, int place, int placedNum, bool leading_zeros, bool tight) {
    if(dp[place][placedNum][leading_zeros][tight] != -1) return dp[place][placedNum][leading_zeros][tight];
    if(place == 0) return 1; 

    int lb = 0;
    int ub = (!tight) ? 9 : num[num.size()-place]-'0';

    int count = 0;
    For(i, lb, ub+1) {
        if(i == placedNum && !leading_zeros) continue;
        count += findAns(num, place-1, i, (leading_zeros & (i==0)), (tight & (i==ub)));
    }
    return (dp[place][placedNum][leading_zeros][tight] = count);
}

void solve() {
    inpt(x); inpt(y);
    string A = to_string(x-1);
    string B = to_string(y);

    memset(dp, -1, sizeof(dp));
    int ans1 = findAns(A, A.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    int ans2 = findAns(B, B.size(), -1, 1, 1);
    pl(ans2-ans1);
    return;
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