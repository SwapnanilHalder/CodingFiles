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

int gcd(int a, int b) {return b ? gcd(b, a%b): a;}

void sol() {
    int a,b,c;
    cin >> a>>b>>c;
    if(c==0) {
        pl("Yes"); return;
    }
    int n = gcd(a, b);
    if (c%n){pl("No");} else  {pl("Yes");};
    return;
}

int main() {
    SPEED1;
    int t; cin >> t;
    while(t--) sol();
}
