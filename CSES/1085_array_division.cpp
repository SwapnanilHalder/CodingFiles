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

bool isPossible(vi &arr, int k, int sum) {
    // deb(sum);
    int count = 0LL;
    int temp = 0LL;
    int i=0;
    for(; i<arr.size() && k>0LL; i++) {
        if(arr[i] > sum) return 0;
        temp += arr[i];
        if(temp > sum) {
            k--; 
            // cout << "i: " << i << " temp: " << temp << " k: " << k<< endl;
            temp = arr[i];
        }
    }

    return (k > 0LL);
}

void solve() {
    inpt(n); inpt(k);
    vi arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
    int sum = accumulate(arr.begin(), arr.end(), 0LL);
    int left_sum = sum/k, right_sum = sum;
    int ans = sum;
    while(left_sum <= right_sum) {
        int mid = (0LL + left_sum + right_sum)/2;
        if(isPossible(arr, k, mid)) {
            ans = min(mid, ans);
            right_sum = mid-1;
        } else {
            left_sum = mid+1;
        }
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