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

vi generateSubset(vi &arr) {
    int len = arr.size();
    vector<int> ans;
    For(i, 0, 1<<len) {
        int tempSum = 0;
        For(j, 0, len) {
            if(i & 1<<j) {
                tempSum += arr[j];
            }
        }
        ans.push_back(tempSum);
    }
    return ans;
}

void solve() {
    inpt(n); inpt(targetSum);
    vector<int> arr1, arr2;
    For(i, 0, n) {
        inpt(x);
        if(i < n/2) {
            arr1.push_back(x);
        } else {
            arr2.push_back(x);
        }
    }

    vector<int> ans1 = generateSubset(arr1);
    vector<int> ans2 = generateSubset(arr2);

    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());

    // pv(ans1); pv(ans2);

    int ans = 0;
    For(i, 0, ans1.size()) {
        auto lower = lower_bound(ans2.begin(), ans2.end(), targetSum-ans1[i]);
        auto upper = upper_bound(ans2.begin(), ans2.end(), targetSum-ans1[i]);
        ans += (upper - lower);
    }
    pl(ans);

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