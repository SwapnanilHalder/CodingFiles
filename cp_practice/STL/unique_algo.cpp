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

int main() {
    vi arr = {1,2,4,5,7,5,4,1,2,3,6,5,4,7,4,5,2,1,4,5,1,2};
    sort(arr.begin(), arr.end());
    pv(arr);
    int l = unique(arr.begin(), arr.end()) - arr.begin();
    pv(arr);
    deb(l);
}