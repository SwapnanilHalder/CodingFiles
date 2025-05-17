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

int secondMSB(int n) {
    int count = 0;
    int head = n;
    while(head > 0) {
        head >>=1;
        count++;
    }
    // int temp = 1 << count;
    // while(temp > n) {
    //     temp >>=1;
    //     count--;
    // }
    return count-1;

    // head = n;
    // head ^= (1<<(count-1));
    // count=0;
    // while(head > 0) {
    //     head >>=1;
    //     count++;
    // }
}

int countSetBit(int n) {
    // deb(n);
    if(n == 0) return 0;
    int m = secondMSB(n);
    // deb(m);
    if(n == (1LL << (m+1))-1) return (m+1)*(1 << m);
    n = n - (1LL << m);

    return  n+1 +  countSetBit(n)  + m*(1LL<<(m-1)) ;
}

void solve() {
    inpt(n);
    pl(countSetBit(n));
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