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

bool cmp (const pair<int,int> &a, const pair<int,int> &b) {
    if(a.first == b.first) {
        return (a.second < b.second);
    }
    return (a.first < b.first);
}

void solve() {
    inpt(n); inpt(x);
    vector<pair<int,int>> arr(n);
    For(i, 0, n) {
        inpt(x);
        arr[i] = {x, i+1};
    }

    map<int, int> idx;
    
    sort(arr.begin(), arr.end(), cmp);

    For(p1, 0, n-2) {
        int p2 = p1+1;
        int p3 = n-1;
        while(p2 < p3) {
            int sum = arr[p1].first+arr[p2].first+arr[p3].first;
            if(sum == x) {
                cout << arr[p1].second << " " << arr[p2].second << " " << arr[p3].second << endl; return;
            }
            if(sum < x) {
                p2++;
            } else {
                p3--;
            }
        } 
    }
    pl("IMPOSSIBLE");
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