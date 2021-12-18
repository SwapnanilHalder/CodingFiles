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
#define int long long int

int power(int x, int y, int p) {
    int ans = 1, power_figure = x;
    // 2^5 = 2^1 * 2^4 5 = 101
    while(y>0) {
        if(y&1) {
            ans = (ans * power_figure) % p;
        }
        power_figure = (power_figure * power_figure)% p;
        y >>=1;
    }
    return ans;
}
#undef int

int main() {
    int x = 2;
    int y = 1e9+5;
    int p = 1e9+7;
    cout << "Power is " << power(x, y, p) << endl;
    printf("%x\n", 256);
    return 0;
}