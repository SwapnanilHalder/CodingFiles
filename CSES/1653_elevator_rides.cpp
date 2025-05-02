#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;

void solve() {
    inpt(people);
    inpt(max_weight);
    vi arr(people);
    For(i, 0, people) {
        cin >> arr[i];
    }
    vector<pair<int, int>> dp(1 << people, {people+1, max_weight+1});
    dp[0] = {1, 0};
    For(mask, 0, 1 << people) {
        For(i, 0, people) {
            if(mask & 1 << i) {
                auto prev = dp[mask ^ (1<<i)];
                int completed_rides = prev.first;
                int curr_weight = prev.second;

                if(curr_weight + arr[i] <= max_weight) {
                    curr_weight += arr[i];
                } else {
                    completed_rides++;
                    curr_weight = arr[i];
                }
                dp[mask] = min(dp[mask], {completed_rides, curr_weight});
            }
        }
    }
    pl(dp[(1<<people) - 1].first);
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