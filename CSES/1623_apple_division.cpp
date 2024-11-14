#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define pl(x) cout << x << endl
#define endl '\n'
#define deb(x) cout << '\t'<<#x << " = " << x << endl
using namespace std;

int nearest = INT_MAX;
int totalB = 0;

int backtrack(vector<int> &arr, int target_sum, int sum_1, int sum_2, int idx) {
    if(idx == arr.size()-1) return abs(sum_1 - sum_2);

    // cout << endl << endl << endl;
    // totalB++;
    // deb(totalB);
    // deb(target_sum); 
    // deb(curr_sum); 
    // deb(idx);
    // deb(nearest);
   
    // For(i, 0, a.size()) {
    //     cout << a[i] << " ";
    // } cout << endl;
    // For(i, idx+1, arr.size()) {
        // if(curr_sum + arr[i] > target_sum) {
        //     nearest = max(nearest, curr_sum);
        //     deb(nearest);
        // } else {
        // a.push_back(arr[i]);
        // a.pop_back();
        // }
        int a = backtrack(arr, target_sum, sum_1+arr[idx+1], sum_2, idx+1);
        int b = backtrack(arr, target_sum, sum_1, sum_2+arr[idx+1], idx+1);
    return min(a, b);
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
    int total_sum = accumulate(arr.begin(), arr.end(), 0) ;
    // deb(total_sum);
    int target_sum = total_sum / 2;
    // deb(target_sum);
    // For(i, 0, arr.size()) {
    int ans = backtrack(arr, target_sum, 0, 0, -1);
        // backtrack(arr, target_sum, 0, 0);
    cout << ans << endl;
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // int __t; cin >> __t; while(__t--)
    solve();
}