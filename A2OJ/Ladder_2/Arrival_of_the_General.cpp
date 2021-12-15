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

void sol() {
    int n; cin >> n;
    vi arr(n);
    For(i, 0, n) {
        cin >> arr[i];
    }
    int mini = *min_element(all(arr));
    int maxi = *max_element(all(arr));
    int mini_pos, maxi_pos;
    For(i, 0, n) {
        if(arr[i] == maxi) {
            maxi_pos = i;
            break;
        }
    }
    for(int i = n-1; i>=0; i--) {
        if(arr[i] == mini) {
            mini_pos = i;
            break;
        }
    }
    int total = (n-1 - mini_pos) + (maxi_pos);
    if(mini_pos < maxi_pos )
        total--;
    pl(total);
    return;
}

int main() {
    SPEED1;
    sol();
}