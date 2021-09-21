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
    double x = 4.54, y = 4.35, z = 4.99, w = 4.0001; // let us take b = 1.0000
    int a = 10; // Give us floor, ceil and round of a/b
    int b = 3;
    cout << "floor is => " << (int)(a/b) << endl;
    cout << "ceil is => " <<  (int)((a+b-1)/b) << endl;
    cout << "Round is => " << (int) ( (2*a+b) / (2*b) ) << endl;           // Formula : floor(a/b + 1/2)
}